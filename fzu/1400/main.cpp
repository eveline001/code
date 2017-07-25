#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int Count[32];
int arr[30010];
int Sum[30010][32];

int main()
{
    int n, m, maxlen, pos;
    bool suit;

    while(scanf("%d%d", &n, &m) != EOF && (n || m)){
        memset(Count, 0, sizeof(Count));
        memset(Sum, 0, sizeof(Sum));
        for(int i = 0; i < n; i++) scanf("%d", &Count[i]);
        for(int i = 0; i < m; i++) scanf("%d", &arr[i]);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) Sum[i + 1][j] = Sum[i][j];
            for(int j = 0; j < n; j++){
                if(arr[i] == 1) break;
                while(arr[i] && arr[i] % Count[j] == 0)
                    Sum[i + 1][j] ^= 1, arr[i] /= Count[j];
            }
        }
        maxlen = 0, pos = 1;
        for(int i = 1; i <= m; i++){
            for(int j = m - i + 1; j > maxlen; j--){
                suit = true;
                for(int k = 0; k < n; k++) if(Sum[i - 1][k] ^ Sum[i - 1 + j][k]){suit = false; break;}
                if(suit){maxlen = j; pos = i; break;}
            }
        }
        if(maxlen == 0) printf("None\n");
        else printf("%d %d\n", pos, pos - 1 + maxlen);
    }
    return 0;
}
