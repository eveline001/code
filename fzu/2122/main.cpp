#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char S1[110], S2[110];
int pLen;
char S[50010];
int last, sLen;
char ans[5000010];
int ptr;
int Next[110];

void Down(){
    for(int i = 0; S1[i] != '\0'; i++){
        if(S1[i] < 'a'){
            S1[i] += 'a' - 'A';
        }
    }
}

void GetNext(){
    int len = strlen(S2);
    int k = -1, j = 0;

    Next[0] = -1;
    while(j < len - 1){
        if(k == -1 || S1[j] == S1[k]){
            Next[++j] = ++k;
        }else{
            k = Next[k];
        }
    }
}

void AnsPush(int pos){
    for(int i = last; i <= pos; i++){
        ans[ptr++] = S[i];
    }
    for(int i = 0; S2[i] != '\0'; i++){
        ans[ptr++] = S2[i];
    }
    ans[ptr] = '\0';
}

int main()
{
    int i, j;

    while(gets(S1) != NULL){
        gets(S2);
        gets(S);
        GetNext();
        Down();
        i = j = ptr = last = 0;
        memset(ans, 0, sizeof(ans));
        pLen = strlen(S1);
        sLen = strlen(S);
        while(S[i] != '\0'){
            j = 0;
            while(i < sLen && j < pLen){
                if(j == -1 || S[i] == S1[j] || S[i] == S1[j] - ('a' - 'A')){
                    i++;
                    j++;
                }else{
                    j = Next[j];
                }
            }
            if(j == pLen){
                AnsPush(i - j - 1);
                last = i;
            }else{
                break;
            }
        }
        for(int i = last; S[i] != '\0'; i++){
            ans[ptr++] = S[i];
        }
        printf("%s\n", ans);
    }
    return 0;
}
