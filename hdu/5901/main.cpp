/************************************************************
         这个模板我一点都不会，代码是从codeforces上抄的，佚名
         pi(i)表示i以内质数的个数
*************************************************************/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f[340000],g[340000],n;
///f[i]表示 pi(n/i), g[i] 表示 pi(i)
void init(){
    ll i,j,m;
    for(m=1;m*m<=n;++m)f[m]=n/m-1;
    for(i=1;i<=m;++i)g[i]=i-1;
    for(i=2;i<=m;++i){
        if(g[i]==g[i-1])continue;
        for(j=1;j<=min(m-1,n/i/i);++j){
            if(i*j<m)f[j]-=f[i*j]-g[i-1];
            else f[j]-=g[n/i/j]-g[i-1];
        }
        for(j=m;j>=i*i;--j)g[j]-=g[j/i]-g[i-1];
    }
}
int main(){
    while(scanf("%I64d",&n)!=EOF){
        init();
        cout<<f[1]<<endl;
    }
    return 0;
}
