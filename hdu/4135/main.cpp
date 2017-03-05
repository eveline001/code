#include <iostream>
#include <stdlib.h>

using namespace std;

int p[4096];

long long dfs(long long n,int x,int num)
{
    long long i,ans=0;
    for(i = x; i <= num; i++)
    {
        ans += n/p[i] - dfs(n/p[i], i+1, num);
    }
    return ans;
}

long long coprime(long long a, long long b ,int n)
{
    int i,
        num = 0,
        x   = n;

    for(i = 2; i*i <= n; i++)
    {
        if(x%i == 0)
        {
            while(x%i == 0) x = x/i;
            p[++num] = i;
        }
    }
    if(x > 1) p[++num] = x;

    return (b - dfs(b, 1, num)) - (a-1 - dfs(a-1, 1, num));
}

int main()
{
    int T, i, N = 0;
    long long A, B;

    cin >> T;
    for(i = 1; i <= T; i++)
    {
        cin >> A >> B >> N;
        cout << "Case #" << i << ": " << coprime(A,B,N) << endl;
    }
}
