#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

namespace fastIO {
    #define BUF_SIZE 10 * 1024 * 1024
    bool IOerror = 0;
    inline char nc() {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
        if(p1 == pend) {
            p1 = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            if(pend == p1) {
                IOerror = 1;
                return -1;
            }
        }
        return *p1++;
    }
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    inline bool read(int &x) {
        char ch;
        while(blank(ch = nc()));
        if(IOerror) return false;
        for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
        if(IOerror) return false;
        return true;
    }
    #undef BUF_SIZE
};
using namespace fastIO;

int a[1000010], b[1000010];

int main()
{
    int n;

    while(read(n)){
        for(int i = 1; i <= n; i++) read(a[i]);
        a[0] = a[n];
        for(int i = 1; i <= n; i++) read(b[i]);
        b[0] = b[n];
        int cur = a[1] - b[1], tol = a[1], pos = 1, maxtol = 0, maxpos = 1;
        for(int i = 1; i < n + n; i++){
            if(i - pos + 1 > n) cur += b[pos % n] - a[pos % n], tol -= a[pos % n], pos = (pos + 1) == n ? n : (pos + 1) % n;
            if(tol > maxtol) maxtol = tol, maxpos = pos;
            if(cur >= 0) cur += a[(i + 1) % n] - b[(i + 1) % n], tol += a[(i + 1) % n];
            else cur = a[(i + 1) % n] - b[(i + 1) % n], tol = a[(i + 1) % n], pos = (i + 1) == n ? n : (i + 1) % n;
        }
        printf("%d\n", maxpos == 0 ? n - 1 : maxpos - 1);
    }
    return 0;
}
