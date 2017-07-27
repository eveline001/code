#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int M[605][605];
int Px[600], Py[600];

int main()
{
    int n, ans, detX, detY;

    while(scanf("%d", &n) != EOF){
        memset(M, 0, sizeof(M));
        for(int i = 0; i < n; i++){
            scanf("%d%d", &Px[i], &Py[i]);
            M[Px[i] + 300][Py[i] + 300] = 1;
        }
        ans = 0;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                detX = Px[i] - Px[j], detY = Py[i] - Py[j];
                if(M[Px[i] - detY + 300][Py[i] + detX + 300] && M[Px[j] - detY + 300][Py[j] + detX + 300]) ans++;
                if(M[Px[i] + detY + 300][Py[i] - detX + 300] && M[Px[j] + detY + 300][Py[j] - detX + 300]) ans++;
            }
        }
        printf("%d\n", ans / 4);
    }
    return 0;
}
