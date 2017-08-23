#include <iostream>
#include <cstdio>

using namespace std;

bool M[3000][3000];

int main()
{
    int T, n;
    bool ans;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d", &n);
        if(n > 6){printf("Bad Team!\n"); continue;}  //Ramsey theorem
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1, x; j < n; j++){
                scanf("%d", &x);
                if(x) M[i][j] = M[j][i] = true;
                else M[i][j] = M[j][i] = false;
            }
            M[i][i] = true;
        }
        ans = true;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n - 1; j++) if(M[i][j]){
                for(int k = j + 1; k < n; k++){
                    if(M[i][k]) if(M[j][k]){ans = false; break;}
                }
                if(!ans) break;
            }
            if(!ans) break;
            for(int j = i + 1; j < n - 1; j++) if(!M[i][j]){
                for(int k = j + 1; k < n; k++){
                    if(!M[i][k]) if(!M[j][k]){ans = false; break;}
                }
                if(!ans) break;
            }
            if(!ans) break;
        }
        printf("%s Team!\n", ans ? "Great" : "Bad");
    }
    return 0;
}
