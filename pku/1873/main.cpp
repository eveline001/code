#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const double pi = acos(-1.0);

struct Point{
    double x, y;

    int v, l;

    Point(double x = 0.0, double y = 0.0, int v = 0, int l = 0) : x(x), y(y), v(v), l(l) {}

    Point operator = (const Point& b){
        this->x = b.x, this->y = b.y, this->v = b.v, this->l = b.l;

        return *this;
    }
};

inline double Cross(Point A, Point B, Point C){
    return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
}

inline double Distance(Point A, Point B){
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

Point tolP[20], P[20], C[20];
int total;

bool comp(Point A, Point B){
    double angle = Cross(P[0], A, B);
    if(angle > 0){
        return true;
    }
    if(angle < 0){
        return false;
    }
    return Distance(P[0], A) < Distance(P[0], B);
}

int v[20], l[20];

int main()
{
    int n, num, val, resNum, tmpVal, finSta, cas = 1;
    double tmpLen, reqLen, resLen;

    while(scanf("%d", &n) != EOF && n){
        for(int i = 1; i <= n; i++){
            scanf("%lf%lf%d%d", &tolP[i].x, &tolP[i].y, &v[i], &l[i]);
        }
        val = finSta = 0, num = n + 1;
        for(int sta = 0; sta < (1 << n); sta++){
            tmpLen = 0, tmpVal = resNum = 0;
            for(int j = 0; j < n; j++){
                if((sta & (1 << j)) == 0){
                    tmpLen += l[j + 1];
                }else{
                    tmpVal += v[j + 1];
                    P[resNum++] = tolP[j + 1];
                }
            }
            if(tmpVal <= val || (tmpVal == val && num > resNum) || (tmpLen == 0 && resNum != 1)){
                continue;
            }
            if(resNum == 1){
                if(tmpLen >= 0){
                    finSta = sta;
                    val = tmpVal;
                    num = resNum;
                    resLen = tmpLen;
                }
                continue;
            }
            if(resNum == 2){
                if(tmpLen >= 2 * Distance(P[0], P[1])){
                    finSta = sta;
                    val = tmpVal;
                    num = resNum;
                    resLen = tmpLen - 2 * Distance(P[0], P[1]);
                }
                continue;
            }
            for(int i = 1; i < resNum; i++){
                if(P[i].y < P[0].y || (P[i].y == P[0].y && P[i].x < P[0].x)){
                    swap(P[i], P[0]);
                }
            }
            sort(P + 1, P + resNum, comp);
            C[0] = P[0];
            C[1] = P[1];
            total = 1;
            for(int i = 2; i < resNum; i++){
                while(total > 0 && Cross(C[total - 1], C[total], P[i]) <= 0){
                    total--;
                }
                C[++total] = P[i];
            }
            reqLen = 0;
            for(int i = 0; i < total; i++){
                reqLen += Distance(C[i], C[i + 1]);
            }
            reqLen += Distance(C[total], C[0]);
            if(tmpLen >= reqLen){
                finSta = sta;
                val = tmpVal;
                num = resNum;
                resLen = tmpLen - reqLen;
            }
        }
        if(cas != 1){
            printf("\n");
        }
        printf("Forest %d\nCut these trees:", cas);
        for(int i = 0; i < n; i++){
            if((finSta & (1 << i)) == 0){
                printf(" %d",i + 1);
            }
        }
        printf("\nExtra wood: %.2f\n", resLen);
        cas++;
    }
    return 0;
}
