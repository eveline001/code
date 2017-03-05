#include <iostream>
#include <bitset>
#include <cstdio>
#include <cstring>

using namespace std;
bool isprime[1000001];
int prime[1000001];
int p;
int fac[1000001];
int cnt;

long long dfs(long long k, long long t, long long s, long long n){
    if(k == cnt){
        if(t & 1){
            return -n / s;
        }else{
            return n / s;
        }
    }
    return dfs(k + 1, t, s, n) + dfs(k + 1, t ^ 1, s * fac[k], n);
}

int main()
{
    int T, m, n, k;
    long long L, R, M, res, ans;

    memset(isprime, true, sizeof(isprime));
    p = 0;
    for(int i = 2; i <= 1000000; i++)
    {
        if(isprime[i] == true)
        {
            for(int j = i + i; j <= 1000000; j += i)
            {
                isprime[j] = false;
            }
            prime[p++] = i;
        }
    }
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        scanf("%d%d%d", &m, &n, &k);
        if(m == 1 && n == 1){
            printf("Case %d:%d\n", t, k);
            continue;
        }
        cnt = 0;
        for(int i = 0; i < p && prime[i] < max(m, n); i++){
            if(m % prime[i] == 0 || n % prime[i] == 0){
                while(m % prime[i] == 0){
                    m /= prime[i];
                }
                while(n % prime[i] == 0){
                    n /= prime[i];
                }
                fac[cnt++] = prime[i];
            }
        }
        if(m > 1){
            fac[cnt++] = m;
        }
        if(n > 1 && n != m){
            fac[cnt++] = n;
        }
        L = 1;
        R = (long long)1 << 62;
        while(L <= R){
            M = (L + R) >> 1;
            res = dfs(0, 0, 1, M);
            if(res >= k){
                ans = M;
                R = M - 1;
            }else{
                L = M + 1;
            }
        }
        printf("Case %d: %I64d\n", t, ans);
    }
}

/*
#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>

using namespace std;

bool isprime[1000001];
int prime[1000001];
int p;
int fac[1000001];
int cnt;

long long ans;

int k;

void dfs(long long k, long long t, long long s, long long n){
    if(k == cnt){
        if(t & 1){
            ans -= n / s;
        }else{
            ans += n / s;
        }
        return;
    }
    dfs(k + 1, t, s, n);
    dfs(k + 1, t ^ 1, s * fac[k], n);
}

long long Binary(){
    long long L = 1, R = (long long)1 << 62, M, res;

    while(L <= R){
        M = (L + R) >> 1;
        ans = 0;
        dfs(0, 0, 1, M);
        if(ans >= k){
            res = M;
            R = M - 1;
        }else{
            L = M + 1;
        }
    }
    return res;
}

void init(){
    memset(isprime, true, sizeof(isprime));
    p = 0;
    for(int i = 2; i <= 1000000; i++){
        if(isprime[i] == true){
            for(int j = i + i; j <= 1000000; j += i){
                isprime[j] = false;
            }
            prime[p++] = i;
        }
    }
}

int main()
{
    int T, m, n;
    //long long L, R, M, res;

    init();
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        scanf("%d%d%d", &m, &n, &k);
        if(m == 1 && n == 1){
            printf("Case %d:%d\n", t, k);
            continue;
        }
        cnt = 0;
        for(int i = 0; i < p && prime[i] < max(m, n); i++){
            if(m % prime[i] == 0 || n % prime[i] == 0){
                while(m % prime[i] == 0){
                    m /= prime[i];
                }
                while(n % prime[i] == 0){
                    n /= prime[i];
                }
                fac[cnt++] = prime[i];
            }
        }
        if(m > 1){
            fac[cnt++] = m;
        }
        if(n > 1 && n != m){
            fac[cnt++] = n;
        }
        printf("%I64d\n",Binary());
    }
    return 0;
}
*/


/*
#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>

using namespace std;
typedef long long LL;

const int N=1000005;
const LL INF=(LL)1<<62;

bool prime[N];
LL p[N];
LL fac[N];
LL k,cnt,num,ans,n,m,K;

void isprime()
{
    k=0;
    int i,j;
    memset(prime,true,sizeof(prime));
    for(i=2; i<N; i++)
    {
        if(prime[i])
        {
            p[k++]=i;
            for(j=i+i; j<N; j+=i)
            {
                prime[j]=false;
            }
        }
    }
}


void Solve(LL m,LL n)
{
    cnt=0;
    LL i;
    for(i=0; p[i]*p[i]<=n; i++)
    {
        if(n%p[i]==0)
        {
            fac[cnt++]=p[i];
            while(n%p[i]==0) n/=p[i];
        }
    }
    if(n>1)
        fac[cnt++]=n;
    for(i=0; p[i]*p[i]<=m; i++)
    {
        if(m%p[i]==0)
        {
            fac[cnt++]=p[i];
            while(m%p[i]==0) m/=p[i];
        }
    }
    if(m>1)
        fac[cnt++]=m;
}

void dfs(LL k,LL t,LL s,LL n)
{
    if(k==num)
    {
        if(t&1) ans-=n/s;
        else    ans+=n/s;
        return;
    }
    dfs(k+1,t,s,n);
    dfs(k+1,t+1,s*fac[k],n);
}

LL Binary()
{
    LL l=1,r=INF,mid,ret;
    while(l<=r)
    {
        mid=(l+r)/2;
        ans=0;
        dfs(0,0,1,mid);
        if(ans>=K)
        {
            ret=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    return ret;
}

int main()
{
    isprime();
    LL t,ct,tt=1;
    scanf("%I64d",&t);
    while(t--)
    {
        scanf("%I64d%I64d%I64d",&m,&n,&K);
        printf("Case %d: ",tt++);
        if(n==1&&m==1)
        {
            printf("%I64d\n",K);
            continue;
        }
        Solve(m,n);
        sort(fac,fac+cnt);
        num=1;
        for(LL i=1; i<cnt; i++)
        {
            if(fac[i]!=fac[i-1])
            {
                fac[num++]=fac[i];
            }
        }
        ct=num;
        printf("%I64d\n",Binary());
    }
    return 0;
}
*/
