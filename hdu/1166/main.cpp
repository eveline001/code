#define DEBUG
#define STDIO
#include <iostream>
#include <string>
#ifdef STDIO
#include <cstdio>
#endif // STDIO
#ifdef DEBUG
#include <cstdlib>
#endif // DEBUG

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

int C[50010];

int main()
{
    int T, i, j;
    #ifdef STDIO
    char S[5];
    #else
    string S;
    #endif // STDIO
    int a, b, N;

    #ifndef STDIO
    ios_base::sync_with_stdio(false);
    #endif // STDIO

    #ifdef STDIO
    scanf("%d", &T);
    #else
    cin >> T;
    #endif // STDIO
    for(i = 1; i <= T; i++)
    {
        #ifdef STDIO
        scanf("%d", &N);
        printf("Case %d:\n", i);
        #else
        cin >> N;
        cout << "Case " << i << ":\n";
        #endif // STDIO
        Reset(C, N, 0);
        for(j = 1; j <= N; j++)
        {
            #ifdef STDIO
            scanf("%d", &a);
            #else
            cin >> a;
            #endif // STDIO
            Update(C, j, a, N);
        }
        #ifdef STDIO
        while(scanf("%s", S) != EOF)
        {
            if(S[0] == 'E') break;
            scanf("%d%d", &a, &b);
            if(S[0] == 'A') Update(C, a, b, N);
            else if(S[0] == 'S') Update(C, a, -b, N);
            else if(S[0] == 'Q') printf("%d\n", Sum(C, a-1, b));
        }
        #else
        while(cin >> S)
        {
            if(S == "End") break;
            cin >> a >> b;
            if(S == "Add") Update(C, a, b, N);
            else if(S == "Sub") Update(C, a, -b, N);
            else if(S == "Query") cout << Sum(C, a-1, b) << endl;
        }
        #endif // STDIO
    }

    #ifdef DEBUG
    system("pause");
    #endif // DEBUG

}
