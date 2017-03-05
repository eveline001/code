#include <iostream>
#include <cstdio>

using namespace std;

int Pow(int a, int x){
    if(x <= 1){
        if(x == 0){
            return 1;
        }
        if(x == 1){
            return a % 10;
        }
    }
    int temp = Pow(a, x >> 1);
    if(x & 1){
        return a % 10 * temp % 10 * temp % 10;
    }else{
        return temp % 10 * temp % 10;
    }
    return 1;
}

int main()
{
    int a, b;

    while(scanf("%d%d", &a, &b) != EOF){
        printf("%d\n", Pow(a, b));
    }
    return 0;
}
