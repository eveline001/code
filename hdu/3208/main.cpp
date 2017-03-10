/**
题目：https://vjudge.net/contest/152887#problem/H

题意：给出区间[a, b]，问你区间[a, b]所有数的幂的和是多少，定义一个
数的幂是这样的：对于一个数y,存在一个最小的数x,有一个最大的k，使得x^k=y,
那k就是y的幂

思路：由于要找的幂尽量大，所以我们要从高到低来枚举计算幂的贡献
       对于幂k 二分一下范围[x,y] 满足a <= x ^ k <= y ^ k <= b
       现在就是要去重了
       举个例子
       2^4 等于16 4^2也等于16 所以算完k为4的贡献后(假设为d),要除掉对k的所有约数的影响(显然影响也为d)
ps: 被 long long 相乘时判溢出 坑了几波，还是取对数靠谱一些
*/

#include<bits/stdc++.h>

using namespace std;

const double eps = 1e-6;

long long a, b, cnt[64];

/*
// 会爆long long
int compare(long long x, int k, long long other){
    long long res = 1;
    for(int i = 1; i <= k; i++){
        res *= x;
    }
    return res == other ? 0 : res > other ? 1 : -1;
}
*/

bool check1(long long x, int k){ /* if(x ^ k >= a) return true */
    long long res = 1;
    for(int i = 1; i <= k; i++){
        if(log(res) + log(x) - log(a) >= eps) return true;
        res *= x;
    }
    return res >= a;
}

long long FindL(int k){
    long long l = 1, r = b, ans = b;
    while(l <= r){
        long long mid = (l + r) >> 1;
        if(check1(mid, k)){
            ans = min(ans, mid), r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return ans;
}

bool check2(long long x,int k){ /* if(x ^ k > b) return false; */
    long long res = 1;
    for(int i = 1; i <= k; i++){
        if(log(res) + log(x) - log(b) > eps) return false;
        res *= x;
    }
    return res <= b;
}

long long FindR(int k){
    long long l = 1, r = b, ans = 1;
    while(l <= r){
        long long  mid = (l + r) / 2;
        if(check2(mid, k)){
            ans = max(ans, mid), l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return ans;
}

int main()
{
    while(scanf("%I64d%I64d", &a, &b) && (a || b)){
        memset(cnt, 0, sizeof(cnt));
        long long ans = 0;
        for(int i = 63; i >= 1; i--){
            long long x = FindL(i), y = FindR(i), d = max(y - x + 1, 0LL);
            /* 容斥 */
            if(d){
                d -= cnt[i];
                if(d){
                    ans += i * d;
                    for(int k = 1; k * k <= i; k++){
                        if(i % k == 0){
                            cnt[k] += d;
                            if(i / k != k){
                                cnt[i / k] += d;
                            }
                        }
                    }
                }
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
