#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 107;
const int MIN = -1e9 - 7;

int arr[MAX][MAX];
int sub[MAX];

int main()
{
    int N, curMax, finMax, tolMax;

    while(scanf("%d", &N) != EOF){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                scanf("%d", &arr[i][j]);
            }
        }
        tolMax = MIN;
        for(int b = 0; b < N; b++){
            memset(sub, 0, sizeof(sub));
            for(int r = b; r < N; r++){
                for(int l = 0; l < N; l++) sub[l] += arr[r][l];
                curMax = finMax = MIN;
                for(int i = 0; i < N; i++){
                    if(curMax < 0) curMax = sub[i];
                    else curMax += sub[i];
                    if(finMax < curMax) finMax = curMax;
                }
                if(tolMax < finMax) tolMax = finMax;
            }
        }
        printf("%d\n", tolMax);
    }
    return 0;
}
