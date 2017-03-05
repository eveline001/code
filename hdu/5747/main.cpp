#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long T, n, m, ans, temp;

    ios_base::sync_with_stdio(false);

    cin >> T;
    for(int t = 0; t < T; t++)
    {
        cin >> n >> m;
        ans = 0;
        if(m == 0){cout << n << endl; continue;}
        if(m > 31) m = 31;
        while(m)
        {
            if(n >= (1 << m))
            {
                temp = n / (1 << m);
                ans += temp;
                n -= temp * (1 << m);
            }
            m--;
        }
        if(n == 1) ans++;
        cout << ans << endl;
    }
}
