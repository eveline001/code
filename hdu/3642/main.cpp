//别。。。还是先等我吃透二维扫描线。。。
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Piece{
    int x1, y1, x2, y2, z;
    bool flag;

    Piece(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, int z = 0, int flag = false) : x1(x1), y1(y1), x2(x2), y2(y2), z(z), flag(flag) {}
};

Piece P[2001];

bool comp(const Piece& a, const Piece& b){
    if(a.z == b.z){
        if(a.x1 == b.x1){
            if(a.y1 == b.y1){
                if(a.x2 == b.x2){
                    return a.y2 > b.y2;
                }
                return a.x2 > b.x2;
            }
            return a.y1 < b.y1;
        }
        return a.x1 < b.x1;
    }
    return a.z < b.z;
}

int main()
{
    int T, n, x1, y1, z1, x2, y2, z2;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
            if(x1 > x2){
                swap(x1, x2);
            }
            if(y1 > y2){
                swap(y1, y2);
            }
            if(z1 > z1){
                swap(z1, z2);
            }
            P[i << 1]    = Piece(x1, y1, x2, y2, z1, true);
            P[i <<1 | 1] = Piece(x1, y1, x2, y2, z2, false);
        }
        sort(P, P + (n << 1), comp);
        for(int i = 0; i < (n << 1); i++){

        }
    }
}
