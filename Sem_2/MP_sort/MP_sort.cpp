#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>

using namespace std;
using namespace filesystem;

vector<int> read(const path& file)
{
    ifstream fin(file);
    vector<int> numbers;
    int num;
    while (fin >> num)
    {
        numbers.push_back(num);
    }
    return numbers;
}

void write(const path& file, const vector<int>& numbers)
{
    ofstream fout(file);
    for (int num : numbers)
    {
        fout << num << ' ';
    }
}

vector<vector<int>> split(const vector<int>& numbers)
{
    vector<vector<int>> runs;
    if (numbers.empty()) return runs;

    vector<int> currentRun = { numbers[0] };
    for (size_t i = 1; i < numbers.size(); ++i)
    {
        if (numbers[i] >= numbers[i - 1])
        {
            currentRun.push_back(numbers[i]);
        }
        else
        {
            runs.push_back(currentRun);
            currentRun = { numbers[i] };
        }
    }
    runs.push_back(currentRun);
    return runs;
}

vector<int> merge(const vector<int>& a, const vector<int>& b)
{
    vector<int> result;
    size_t i = 0, j = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j])
        {
            result.push_back(a[i++]);
        }
        else
        {
            result.push_back(b[j++]);
        }
    }

    while (i < a.size()) result.push_back(a[i++]);
    while (j < b.size()) result.push_back(b[j++]);

    return result;
}

void Sort(const path& input, const path& output)
{
    vector<int> numbers = read(input);
    if (numbers.empty()) return;

    vector<vector<int>> runs = split(numbers);

    while (runs.size() > 1)
    {
        vector<vector<int>> newRuns;

        for (size_t i = 0; i < runs.size(); i += 2)
        {
            if (i + 1 < runs.size())
            {
                newRuns.push_back(merge(runs[i], runs[i + 1]));
            }
            else
            {
                newRuns.push_back(runs[i]);
            }
        }

        runs = newRuns;
    }

    if (!runs.empty())
    {
        write(output, runs[0]);
    }
}

int main()
{
    path input = "input.txt";
    path output = "output.txt";

    write(input, { 10, 2, 5, 84, 20, 124, 0, 121, 2000, 50 });

    vector<int> before = read(input);
    for (int num : before) cout << num << ' ';
    cout << '\n';

    Sort(input, output);

    vector<int> after = read(output);
    for (int num : after) cout << num << ' ';
    cout << '\n';

    return 0;
}