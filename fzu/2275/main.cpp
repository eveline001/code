#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char A[100007], B[100007], C[100007];
int Next[100007];

bool kmp(char* ori, char* sub){
    int n = strlen(ori), m = strlen(sub);
    memset(Next, 0, sizeof(Next));
    for(int i = 0; i < m; i++){
        int j = i;
        while(j > 0){
            j = Next[j];
            if(sub[i] == sub[j]){
                Next[i + 1] = j + 1;
                break;
            }
        }
    }
    for(int i = 0, j = 0; i < n; i++){
        if(j < m && ori[i] == sub[j]) j++;
        else{
            while(j > 0){
                j = Next[j];
                if(ori[i] == sub[j]){
                    j++;
                    break;
                }
            }
        }
        if(j == m) return true;
    }
    return false;
}

int main()
{
    int T, len;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%s%s", A, B);
        len = strlen(B);
        if(len == 1){
            printf("Alice\n");
            continue;
        }
        for(int i = 0; B[i] != '\0'; i++) C[len - 1 - i] = B[i];
        C[len] = '\0';
        printf("%s\n", kmp(A, B) || kmp(A, C) ? "Alice" : "Bob");
    }
    return 0;
}
