#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int a[101];

int main()
{
    int n, mina, pos;

    while(scanf("%d" , &n) != EOF && n){
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            if(i == 0){
                mina = a[i];
                pos = 0;
            }else if(a[i] < mina){
                mina = a[i];
                pos = i;
            }
        }
        swap(a[pos], a[0]);
        printf("%d", a[0]);
        for(int i = 1; i < n; i++){
            printf(" %d", a[i]);
        }
        printf("\n");
    }
    return 0;
}
