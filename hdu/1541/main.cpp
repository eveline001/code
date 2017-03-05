#include <iostream>
#include <cstdio>

using namespace std;

void Reset(int Arr[], int n, int x){
    for(int i = 1; i <= n; i++) Arr[i] = x;
}

int Lowbit(int pos){
    return pos & (-pos);
}

void Update(int Arr[], int pos, int delta, int n){
    while(pos <= n)
    {
        Arr[pos] += delta;
        pos += pos & (-pos);
    }
}

int Pre(int Arr[], int pos){
    int Pre = 0;
    while(pos > 0)
    {
        Pre += Arr[pos];
        pos -= pos & (-pos);
    }
    return Pre;
}

int Sum(int Arr[], int begin, int end){
    return Pre(Arr, end) - Pre(Arr, begin);
}

int X[32020];
int Lev[32020];
int x, y;

int main()
{
    int N, lev, i;

    while(scanf("%d", &N) != EOF)
    {
        Reset(X, 32010, 0);
        Reset(Lev, 32010, 0);
        Lev[0] = 0;
        for(i = 1; i <= N; i++)
        {
            scanf("%d%d", &x, &y);
            Update(X, x+1, 1, 32010);
            lev = Pre(X, x+1);
            Lev[lev-1]++;
        }
        for(i = 0; i < N; i++) cout << Lev[i] << endl;
    }
}
