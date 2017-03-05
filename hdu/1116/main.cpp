#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

void ReSet(int arr[], int n){
    for(int i = 1; i <= n; i++) arr[i] = i;
}

int FindFather(int arr[], int x){
    if(arr[x] == x) return x;
    return arr[x] = FindFather(arr, arr[x]);
}

int Merge(int arr[], int a, int b){
    int fa = FindFather(arr, a),
        fb = FindFather(arr, b);

    if(fa != fb) return arr[fb] = arr[fa];
    return -1;
}

int main(){
    int T, N, a, b, num, inedge, outedge;
    int letter[27];
    int in[27], out[27];
    char s[1010];
    bool flag;

    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        ReSet(letter, 26);
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        while(N--){
            scanf("%s", s);
            in[a = s[0] - 'a' + 1]++;
            out[b = s[strlen(s) - 1] - 'a' + 1]++;
            Merge(letter, a, b);
        }
        num = 0;
        for(int i = 1; i <= 26; i++) if((in[i] || out[i]) && letter[i] == i) num++;
        if(num != 1){
            printf("The door cannot be opened.\n");
            continue;
        }
        flag    = false;
        inedge  = 0;
        outedge = 0;
        for(int i = 1; i <= 26; i++)
        {
            if(in[i] != out[i])
            {
                if(in[i]  - out[i] == 1) inedge++;
                if(out[i] - in[i]  == 1) outedge++;
                if(in[i]  - out[i] >= 2 || out[i] - in[i] >= 2){
                    flag = true;
                    printf("The door cannot be opened.\n");
                    break;
                }
            }
        }
        if(flag) continue;
        if((inedge == 0 && outedge == 0) || (inedge == 1 && outedge == 1)) printf("Ordering is possible.\n");
        else printf("The door cannot be opened.\n");
    }
    return 0;
}
