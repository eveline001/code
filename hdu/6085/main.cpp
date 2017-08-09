#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct Bit{
    unsigned long long bit[782];

    void Reset(){
        memset(bit, 0, sizeof(bit));
    }

    void Filp(int pos){
        this->bit[pos >> 6] ^= (1ULL << (pos & 63));
    }

    int operator [](int pos){
        return this->bit[pos >> 6] & (1ULL << (pos & 63));
    }

};

Bit A, ans;
unsigned long long bits[64];

int main()
{
    int T, n, m, q, L, R, indexL, indexR, posL, posR;
    unsigned temp;

    bits[0] = 1;
    for(int i = 1; i < 64; i++) bits[i] = bits[i - 1] | (1ULL << i);

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d%d", &n, &m, &q);
        A.Reset();
        ans.Reset();
        for(int i = 0, x; i < n; i++){
            scanf("%d", &x);
            A.Filp(x);
            maxA = max(maxA, x);
        }
        for(int i = 0, x; i < m; i++){
            scanf("%d", &x);
            for(int j = 0; j <= maxA; j *= x){
                L = j, R = min(maxA, j + x - 1);
                indexL = L >> 6, posL = L & 63;
                indexR = R >> 6, posR = R & 63;
                if(indexL == indexR){
                    temp = A.bit[indexL] >> posL;
                    ans.bit[0] ^= (temp & bits[posR - posL]);
                }else{
                    temp = A.bit[indexL] >> posL;
                    ans.bit[0] ^= (temp & bits[63 - posL]);
                    st = 63 - posL;
                    for(int k = indexL + 1; k < indexR; k++){
                        if(st == 63){
                            ans.bit[k - indexL] ^= A.bit[k];
                        }else{

                        }
                    }
                }
            }
        }
        for(int i = 0, x; i < q; i++){
            scanf("%d", &x);
            printf("%d\n", ans[x]);
        }
    }
    return 0;
}
