#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 10000;
const double eps = 1e-8;

int tol, pn, dq[MAXN], n;

struct Point{
    double x, y;

    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    Point& operator = (const Point& other){
        this->x = other.x, this->y = other.y;
        return *this;
    }
};

Point P[MAXN];

struct Line{
    Point a, b;
    double angle;

    Line& operator = (const Line& other){
        this->a = other.a, this->b = other.b, this->angle = other.angle;
        return *this;
    }
};

Line OriL[MAXN], L[MAXN];

void AddLine(Line& L, double x1, double y1, double x2, double y2){
    L.a = Point(x1, y1), L.b = Point(x2, y2), L.angle = atan2(y2 - y1, x2 - x1);
}

inline int dbcmp(const double& k){
    return fabs(k) < eps ? 0 : k > 0 ? 1 : -1;
}

inline double cross(const Point& O, const Point& A, const Point& B){
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

inline bool cmp(const Line& L1, const Line& L2){
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
    return dbcmp(cross(GetIntersect(L1, L2), L0.a, L0.b)) < 0;
}

void HalfPlaneIntersect(){
    int j = 0, top, bot;

    sort(L, L + tol, cmp);
    for(int i = 0; i < tol; i++) if(dbcmp(L[i].angle - L[j].angle) > 0) L[++j] = L[i];
    tol = j + 1, dq[0] = 0, dq[1] = 1, top = 1, bot = 0;
    for(int i = 2; i < tol; i++){
        while(top > bot && judge(L[i], L[dq[top]], L[dq[top - 1]])) top--;
        while(top > bot && judge(L[i], L[dq[bot]], L[dq[bot + 1]])) bot++;
        dq[++top] = i;
    }
    while(top > bot && judge(L[dq[bot]], L[dq[top]], L[dq[top - 1]])) top--;
    while(top > bot && judge(L[dq[top]], L[dq[bot]], L[dq[bot + 1]])) bot++;
    pn = top - bot + 1;
    //dq[++top] = dq[bot], pn = 0;
    //for(int i = bot; i < top; i++, pn++) P[pn] = GetIntersect(L[dq[i + 1]], L[dq[i]]);
}

double GetArea(){
    if(pn < 3) return 0.0;
    double area = 0.0;
    for(int i = 1; i < pn - 1; i++) area += cross(P[0], P[i], P[i + 1]);
    return area < 0 ? -area / 2.0 : area / 2.0;
}

double GetCircumcircleRadius(){
    double detX12 = P[0].x - P[1].x,
           detY12 = P[0].y - P[1].y,
           detX13 = P[0].x - P[2].x,
           detY13 = P[0].y - P[2].y;
    double C12 = P[0].x * P[0].x - P[1].x * P[1].x + P[0].y * P[0].y - P[1].y * P[1].y,
           C13 = P[0].x * P[0].x - P[2].x * P[2].x + P[0].y * P[0].y - P[2].y * P[2].y;
    double E = (C12 * detX13 - C13 * detX12) / (detY13 * detX12 - detY12 * detX13);
    double D = (C12 * detY13 - C13 * detY12) / (detX13 * detY12 - detX12 * detY13);
    double F = -(P[0].x * P[0].x + P[0].y * P[0].y + D * P[0].x + E * P[0].y);
    return sqrt(D * D - 4.0 * F + E * E) / 2.0;
}

void Narrow(const Line& L1, Line& L2, double len){
    double a = (L1.a.x - L1.b.x),
           b = (L1.a.y - L1.b.y),
           c = sqrt(a * a + b * b);
    double detX = b / c * len,
           detY = a / c * len;
    L2.a = Point(L1.a.x + detX, L1.a.y - detY);
    L2.b = Point(L1.b.x + detX, L1.b.y - detY);
}

double GetInscribedCircleRadius(double range){
    double l = 0.0, r = range, mid;
    Line temp;
    while(r - l > eps){
        mid = (l + r) / 2.0;
        for(int i = 0; i < n; i++){
            Narrow(OriL[i], temp, mid);
            AddLine(L[i], temp.a.x, temp.a.y, temp.b.x, temp.b.y);
        }
        tol = n;
        HalfPlaneIntersect();
        if(pn < 3) r = mid;
        else l = mid;
    }
    return mid;
}

int main()
{
    int x0, y0, x1, y1, x2, y2;

    while(scanf("%d", &n) != EOF && n){
        tol = 0;
        scanf("%d %d", &x0, &y0);
        x1 = x0, y1= y0;
        for(int i = 1; i < n; i++){
            scanf("%d %d", &x2, &y2);
            AddLine(OriL[tol++], x1, y1, x2, y2);
            x1 = x2, y1 = y2;
        }
        AddLine(OriL[tol++], x1, y1, x0, y0);
        printf("%.6f\n", GetInscribedCircleRadius(20000.0));
    }
    return 0;
}
