#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

const double eps = 1e-16;

struct Point{
    double x, y;

    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    Point& operator = (const Point& other){
        this->x = other.x, this->y = other.y;
        return *this;
    }

    bool operator < (const Point& other) const{
        if(this->x == other.x) return this->y < other.y;
        return this->x < other.x;
    }
};

Point P[6];

inline int dbcmp(const double& k){
    return fabs(k) < eps ? 0 : k > 0 ? 1 : -1;
}

inline double cross(const Point& O, const Point& A, const Point& B){
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

int Judge(){
    int tol, cnt, temp;
    sort(P, P + 3);
    if(P[1].y > P[2].y || (P[1].y == P[2].y && P[1].x < P[2].x)) swap(P[1], P[2]);
    tol = 0;
    for(int i = 3; i < 6; i++){
        cnt = 0;
        for(int j = 0; j < 3; j++){
            temp = dbcmp(cross(P[i], P[j], P[j == 2 ? 0 : j + 1]));
            if(temp == 1) cnt++;
            else if(temp == 0
                    && P[i].x >= min(P[j].x, P[j == 2 ? 0 : j + 1].x)
                    && P[i].x <= max(P[j].x, P[j == 2 ? 0 : j + 1].x)) return 0;
        }
        if(cnt == 3) tol++;
    }
    if(tol == 3) return 1;
    else if(tol > 0) return 0;
    sort(P + 3, P + 6);
    if(P[4].y > P[5].y || (P[4].y == P[5].y && P[4].x < P[5].x)) swap(P[4], P[5]);
    tol = 0;
    for(int i = 0; i < 3; i++){
        cnt = 0;
        for(int j = 3; j < 6; j++){
            temp = dbcmp(cross(P[i], P[j], P[j == 5 ? 3 : j + 1]));
            if(temp == 1) cnt++;
            else if(temp == 0
                    && P[i].x >= min(P[j].x, P[j == 5 ? 3 : j + 1].x)
                    && P[i].x <= max(P[j].x, P[j == 5 ? 3 : j + 1].x)) return 0;
        }
        if(cnt == 3) tol++;
    }
    if(tol == 3) return 1;
    else if(tol > 0) return 0;
    return -1;
}

int main()
{
    int T, ans;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        for(int i = 0; i < 6; i++) scanf("%lf%lf", &P[i].x, &P[i].y);
        ans = Judge();
        if(ans == 1) printf("contain\n");
        else if(ans == 0) printf("intersect\n");
        else printf("disjoint\n");
    }
    return 0;
}
