#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int maxn = 50010;
const double pi = acos(-1);

struct complex{
    double r, i;

    complex(double r = 0, double i = 0) : r(r), i(i) {}

    complex operator + (const complex& a) const{
        return complex(r + a.r, i + a.i);
    }

    complex operator - (const complex& a) const{
        return complex(r - a.r, i - a.i);
    }

    complex operator * (const complex &a) const{
        return complex(r * a.r - i * a.i, r * a.i + i * a.r);
    }
};

void rader(complex* f, int len){
    int j = len >> 1, k;

    for(int i = 1; i < len - 1; i++){
        if(i < j){
            swap(f[i], f[j]);
        }
        k = len >> 1;
        while(j >= k){
            j -= k;
            k >>= 1;
        }
        if(j < k){
            j += k;
        }
    }
}

void FFT(complex* f, int len, int t){
    rader(f, len);
    for(int h = 2; h <= len; h <<= 1){
        complex wn(cos(-t * 2 * pi / h), sin(-t * 2 * pi / h));
        for(int j = 0; j < len; j += h){
            complex e(1, 0);
            for(int k = j; k < j + h / 2; k++){
                complex u = f[k];
                complex v = e * f[k + h / 2];
                f[k] = u + v;
                f[k + h / 2] = u - v;
                e = e * wn;
            }
        }
    }
    if(t == -1){
        for(int i = 0; i < len; i++){
            f[i].r /= len;
        }
    }
}

void Conv(complex* a, complex* b, int len){
    FFT(a, len, 1);
    FFT(b, len, 1);
    for(int i = 0; i < len; i++){
        a[i] = a[i] * b[i];
    }
    FFT(a, len, -1);
}

// 262144 == 2**17
// 50000 * 2 == 100000
// 100000 * 2 == 200000
// 2**16 < 200000 < 2**17
complex x[262144], y[262144];
int len;

char a[maxn], b[maxn];
int ans[262144];
bool PreZero;

int main()
{
    while(gets(a) != NULL){
        gets(b);
        int la = strlen(a), lb = strlen(b);
        for(int i = 0; i < la; i++){
            x[la - i - 1] = complex(a[i] - '0', 0);
        }
        for(int i = 0; i < lb; i++){
            y[lb - i - 1] = complex(b[i] - '0', 0);
        }
        len = 1;
        while(len < ((la + lb) << 1)){
            len <<= 1;
        }
        for(int i = la; i < len; i++){
            x[i] = complex(0, 0);
        }
        for(int i = lb; i < len; i++){
            y[i] = complex(0, 0);
        }
        Conv(x, y, len);
        for(int i = 0; i < len; i++){
            ans[i] = (int)(x[i].r + 0.5);
        }
        for(int i = 0; i < len; i++){
            if(ans[i] > 9){
                ans[i + 1] += ans[i] / 10;
                ans[i] %= 10;
            }
        }
        PreZero = true;
        for(int i = len - 1; i >= 0; i--){
            if(PreZero){
                if(ans[i]){
                    PreZero = false;
                    printf("%d", ans[i]);
                }
            }else{
                printf("%d", ans[i]);
            }
        }
        if(PreZero){
            printf("0");
        }
        printf("\n");
    }
    return 0;
}
