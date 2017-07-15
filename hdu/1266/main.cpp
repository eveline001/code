#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char in[32], out[32];

int main()
{
    int T, ptrin, ptrout, endingzero, status;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%s", in);
        ptrin = (in[0] == '-' ? 1 : 0);
        ptrout = 0, endingzero = 0, status = 1;
        for(int i = strlen(in) - 1; i >= ptrin; i--){
            if(in[i] == '0'){
                if(status) endingzero++;
                else out[ptrout++] = in[i];
            }else{
                status = 0;
                out[ptrout++] = in[i];
            }
        }
        out[ptrout] = '\0';
        if(ptrin != 0) printf("-");
        printf("%s", out);
        for(int i = 0; i < endingzero; i++) printf("0");
        printf("\n");
    }
    return 0;
}
