#include <iostream>
#include<iomanip>
#include <cstdio>

using namespace std;

int fac(int x){
    int res = 1;
    for(int i = 1; i <= x; i++){
        res *= i;
    }
    return res;
}

int main()
{
    double e = 0;
    printf("n e\n- -----------\n");
    for(int i = 0; i <= 9; i++){
        e += 1.0 / fac(i);
        if(i >= 3){
            printf("%d %.9f\n", i, e);
        }else if(i == 2){
            printf("%d %.1f\n", i, e);
        }else{
            printf("%d %.f\n", i, e);
        }
    }
    return 0;
}

/*
main(){puts("n e\n- -----------\n0 1\n1 2\n2 2.5\n3 2.666666667\n4 2.708333333\n5 2.716666667\n6 2.718055556\n7 2.718253968\n8 2.718278770\n9 2.718281526");}
*/
