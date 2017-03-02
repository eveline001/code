#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, thisfloor, nextfloor, totaltime;

    while(scanf("%d", &n) != EOF && n){
        thisfloor = 0;
        totaltime = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &nextfloor);
            if(nextfloor == thisfloor){
                totaltime += 5;
            }else if(nextfloor > thisfloor){
                totaltime += (nextfloor - thisfloor) * 6 + 5;
                thisfloor = nextfloor;
            }else{
                totaltime += (thisfloor - nextfloor) * 4 + 5;
                thisfloor = nextfloor;
            }
        }
        printf("%d\n", totaltime);
    }
    return 0;
}
