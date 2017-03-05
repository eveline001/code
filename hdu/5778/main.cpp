#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool Judge(long long x){
    if(x <= 1) return false;

    long long temp = sqrt(x) + 1;
    for(long long i = 2; i <= temp; i++){
        if(x % i == 0){
            x /= i;
            if(x % i == 0) return false;
            if(x == 1) return true;
        }
    }

    return true;
}

int main()
{
    int T;
    long long x, z, upri, lpri;

    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        scanf("%I64d", &x);
        if(x == 1){
            printf("3\n");
            continue;
        }
        z = sqrt(x);
        lpri = z;
        upri = z + 1;
        while(!Judge(lpri)){
            lpri--;
            if(lpri < 2) break;
        }
        lpri = x - lpri * lpri;
        while(!Judge(upri)){
            upri++;
            if(upri > 1e9) break;
        }
        upri = upri * upri - x;
        if(lpri > upri){
            printf("%I64d\n", upri);
        }else{
            printf("%I64d\n", lpri);
        }
    }
    return 0;
}
