#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 10000;
const double eps = 1e-8;
const double inf = 1e10;

int tol, dq[MAXN], n;

struct Point{
    double x, y;

    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    Point& operator = (const Point& other){
        this->x = other.x, this->y = other.y;
        return *this;
    }
};

struct Line{
    Point a, b;
    double angle;

    Line& operator = (const Line& other){
        this->a = other.a, this->b = other.b, this->angle = other.angle;
        return *this;
    }
};

Line L[MAXN];

void AddLine(Line& L, double x1, double y1, double x2, double y2){
    L.a = Point(x1, y1), L.b = Point(x2, y2), L.angle = atan2(y2 - y1, x2 - x1);
}

int dbcmp(const double& k){
    return fabs(k) < eps ? 0 : k > 0 ? 1 : -1;
}

double cross(const Point& O, const Point& A, const Point& B){
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

bool cmp(const Line& L1, const Line& L2){
    int d = dbcmp(L1.angle - L2.angle);
    return d ? d < 0 : dbcmp(cross(L1.a, L2.a, L2.b)) > 0;
}

Point GetIntersect(const Line& L1, const Line& L2){
    double A1 = L1.b.y - L1.a.y,
           B1 = L1.b.x - L1.a.x,
           A2 = L2.b.y - L2.a.y,
           B2 = L2.b.x - L2.a.x;
    double C1 = B1 * L1.a.y - A1 * L1.a.x,
           C2 = B2 * L2.a.y - A2 * L2.a.x;
    return Point((C1 * B2 - C2 * B1) / (A2 * B1 - A1 * B2), (C1 * A2 - C2 * A1) / (A2 * B1 - A1 * B2));
}

bool judge(const Line& L0, const Line& L1, const Line& L2){
    return dbcmp(cross(GetIntersect(L1, L2), L0.a, L0.b)) <= 0.0;
}

bool HalfPlaneIntersect(){
    int j = 0, top, bot;

    sort(L, L + tol, cmp);
    for(int i = 1; i < tol; i++) if(dbcmp(L[i].angle - L[j].angle) > 0) L[++j] = L[i];
    tol = j + 1, dq[0] = 0, dq[1] = 1, top = 1, bot = 0;
    for(int i = 2; i < tol; i++){
        while(top > bot && judge(L[i], L[dq[top]], L[dq[top - 1]])) top--;
        while(top > bot && judge(L[i], L[dq[bot]], L[dq[bot + 1]])) bot++;
        dq[++top] = i;
    }
    while(top > bot && judge(L[dq[bot]], L[dq[top]], L[dq[top - 1]])) top--;
    while(top > bot && judge(L[dq[top]], L[dq[bot]], L[dq[bot + 1]])) bot++;
    return top - bot > 1 ? true : false;
}

double V[110], U[110], W[110];

bool Judgement(int x){
    double A, B, C;
    int dA, dB, dC;
    tol = 0;
    AddLine(L[tol++], 0, 0, inf, 0);
    AddLine(L[tol++], inf, 0, inf, inf);
    AddLine(L[tol++], inf, inf, 0, inf);
    AddLine(L[tol++], 0, inf, 0, 0);
    for(int i = 0; i < n; i++){
        if(i == x) continue;
        A = (V[x] - V[i]) / (V[x] * V[i]);
        B = (U[x] - U[i]) / (U[x] * U[i]);
        C = (W[x] - W[i]) / (W[x] * W[i]);
        dA = dbcmp(A), dB = dbcmp(B), dC = dbcmp(C);
        if(dB > 0){
            if(dA != 0) AddLine(L[tol++], 0, - C / B, 1, - (A + C) / B);
            else AddLine(L[tol++], 0, - C / B, 1, - C / B);
        }else if(dB == 0){
            if(dA > 0) AddLine(L[tol++], - C / A, 0, - C / A, -1);
            else if(dA == 0){if(dC <= 0) return false;}
            else{if(dC <= 0) return false; else AddLine(L[tol++], - C / A, 0, - C / A, 1);}
        }else{
            if(dA != 0) AddLine(L[tol++], 0, - C / B, -1, - (C - A) / B);
            else{if(dC <= 0) return false; else AddLine(L[tol++], 0, - C / B, -1, - C / B);}
        }
    }
    return HalfPlaneIntersect();
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%lf%lf%lf", &V[i], &U[i], &W[i]);
    for(int i = 0; i < n; i++) printf("%s\n", Judgement(i) ? "Yes" : "No");
    return 0;
}
