#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    double A;
    int L, curN, curD, bestN, bestD;
    double curdis, bestdis;

    while(scanf("%lf", &A) != EOF){
        scanf("%d", &L);
        curN = curD = bestN = bestD = 1;
        curdis = bestdis = fabs(A - (double)curN / curD);
        while(L > curN && L > curD){
            if((double)curN / curD < A) curN++;
            else curD++;
            curdis = fabs(A - (double)curN / curD);
            if(curdis < bestdis) bestN = curN, bestD = curD, bestdis = curdis;
        }
        printf("%d %d\n", bestN, bestD);
    }
    return 0;
}