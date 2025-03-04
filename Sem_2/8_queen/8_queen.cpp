#include <iostream> 
using namespace std;


int n = 0;
int* aN = &n;

bool check(int a[][8], int i, int j)
{
    for (int q = 0; q < 8; q++) 
    {
        if (a[q][j] != 0) { return false; }
    }

    

    bool side = true;
    int tmp, n, max = i, min = j;
    if (i < j) { max = j; min = i; side = false; }
    tmp = max - min;
    n = 8 - tmp;
    if (side)
    {
        for (int q = 0; q < n; q++)
        {
            if (a[tmp + q][q] != 0) { return false; }
        }
    }
    else
    {
        for (int q = 0; q < n; q++)
        {
            if (a[q][tmp + q] != 0) { return false; }
        }
    }

    if (max + min >= 8)
    {
        while (max != 7) { max++; min--; }
        n = max - min + 1;
        for (int q = 0; q < n; q++)
        {
            if (a[max - q][min + q] != 0) { return false; }
        }

    }
    else
    {
        tmp = max + min;
        n = tmp + 1;
        for (int q = 0; q < n; q++)
        {
            if (a[tmp - q][q] != 0) { return false; }
        }
    }

    return true;
}


int solution(int a[][8], int f)
{
    if (f == 8)
    { 
        for (int i = 0; i < 8; i++)
        {
            cout << endl;
            for (int j = 0; j < 8; j++)
            {
                cout << a[i][j];
            }
        }
        cout << endl;
        *aN = n++;
        cout << n << endl;
        return 0;
    }


    for (int j = 0; j < 8; j++)
    {
        if (check(a, f, j))
        {
            a[f][j] = 1;
            if (solution(a, f + 1)) { return 1; }
            a[f][j] = 0;
        }
    }
    return 0;
}


int main()
{
    int a[8][8] = {  {0,0,0,0,0,0,0,0} ,
                     {0,0,0,0,0,0,0,0} ,
                     {0,0,0,0,0,0,0,0} ,
                     {0,0,0,0,0,0,0,0} ,
                     {0,0,0,0,0,0,0,0} ,
                     {0,0,0,0,0,0,0,0} ,
                     {0,0,0,0,0,0,0,0} ,
                     {0,0,0,0,0,0,0,0} };

    solution(a, 0);

    return 0;
}