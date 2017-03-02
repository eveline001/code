//#define Debug
#ifdef Debug
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int inf = 1e9;

struct Line{
    int x, y_down, y_up, flag;

    operator < (const Line& b) const{
        if(this->x == b.x){
            if(this->flag == b.flag){
                if(this->y_down == b.y_down){
                    return this->y_up < b.y_up;
                }else{
                    return this->y_down < b.y_down;
                }
            }else{
                return this->flag > b.flag;
            }
        }else{
            return this->x < b.x;
        }
    }

    Line(int x = 0, int y_down = 0, int y_up = 0, int flag = 1) : x(x), y_down(y_down), y_up(y_up), flag(flag) {}
};

struct Node{
    int cnt, segnum, len;
    bool lc, rc;

    Node(int cnt = 0, int segnum = 0, int len = 0, bool lc = false, bool rc = false) : cnt(cnt), segnum(segnum), len(len), lc(lc), rc(rc) {}
};

Line L[5000 << 1];
Node T[20000 << 2];

void PushUp(int l, int r, int rt){
    if(T[rt].cnt){
        T[rt] = Node(T[rt].cnt, 2, r + 1 - l, true, true);
    }else if(l == r){
        T[rt] = Node();
    }else{
        T[rt].len = T[rt << 1].len + T[(rt << 1) | 1].len;
        T[rt].segnum = T[rt << 1].segnum + T[(rt << 1) | 1].segnum;
        T[rt].lc = T[rt << 1].lc;
        T[rt].rc = T[(rt << 1) | 1].rc;
        if(T[rt << 1].rc && T[(rt << 1) | 1].lc){
            T[rt].segnum -= 2;
        }
    }
}

void Update(int L,int R,int v,int l, int r, int rt){
    if(L <= l && r <= R){
        T[rt].cnt += v;
        PushUp(l, r, rt);
        return;
    }
    int mid = (l + r) >> 1;
    if(L <= mid){
        Update(L, R, v, l, mid, rt << 1);
    }
    if(R > mid){
        Update(L, R, v, mid + 1, r, (rt << 1) | 1);
    }
    PushUp(l, r, rt);
}

int main()
{
    int n, x1, x2, y1, y2, top, down, ans, prelen;

    while(scanf("%d", &n) != EOF){
        top = -inf;
        down = inf;
        for(int i = 0; i < n; i++){
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            L[i << 1] = Line(x1, y1, y2, 1);
            L[(i << 1) | 1]= Line(x2, y1, y2, -1);
            top = max(top, y2);
            down = min(down, y1);
        }
        sort(L, L + (n << 1));
        ans = prelen = 0;
        for(int i = 0; i < (n << 1); i++){
            Update(L[i].y_down, L[i].y_up - 1, L[i].flag, down, top, 1);
            ans += T[1].segnum * (L[i + 1].x - L[i].x);
            ans += T[1].len - prelen > 0 ? T[1].len - prelen : prelen - T[1].len;
            prelen = T[1].len;
        }
        printf("%d\n",ans);
    }
}
#endif // Debug

#ifndef Debug
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int inf = 1e9;

struct Line{
    int x, y_up, y_down, flag;

    operator < (const Line& b) const{
        if(this->x == b.x){
            if(this->flag == b.flag){
                if(this->y_down == b.y_down){
                    return this->y_up < b.y_up;
                }else{
                    return this->y_down < b.y_down;
                }
            }else{
                return this->flag > b.flag;
            }
        }else{
            return this->x < b.x;
        }
    }

    Line(int x = 0, int y_up = 0, int y_down = 0, int flag = 1) : x(x), y_up(y_up), y_down(y_down), flag(flag) {}
};

struct Node{
    int cnt, num, len;
    bool lc, rc;

    Node(int cnt = 0, int num = 0, int len = 0, bool lc = false, bool rc = false) : cnt(cnt), num(num), len(len), lc(lc), rc(rc) {}
};

Line L[5000 << 1];
Node T[20000 << 2];

void PushUp(int l, int r, int rt){
    if(T[rt].cnt >= 1){
        T[rt] = Node(T[rt].cnt, 1, r + 1 - l, true, true);
    }else{
        if(T[rt << 1].num + T[(rt << 1) | 1].num >= 1){
            T[rt].len = (T[rt << 1].num > 0 ? 1 : 0) * T[rt << 1].len + (T[(rt << 1) | 1].num > 0 ? 1 : 0) * T[(rt << 1) | 1].len;
            T[rt].lc = T[rt << 1].lc;
            T[rt].rc = T[(rt << 1) | 1].rc;
            if(T[rt << 1].rc && T[(rt << 1) | 1].lc){
                T[rt].num = T[rt << 1].num + T[(rt << 1) | 1].num - 1;
            }else{
                T[rt].num = T[rt << 1].num + T[(rt << 1) | 1].num ;
            }
        }else{
            T[rt] = Node();
        }
    }
}

void BuildUp(int l, int r, int rt){
    if(l == r){
        T[rt] = Node();
        return;
    }
    int mid = (l + r) >> 1;
    BuildUp(l, mid, rt << 1);
    BuildUp(mid + 1, r, (rt << 1) | 1);
}

void Update(int L, int R, int v, int l, int r, int rt){
    if(L <= l && R >= r){
        T[rt].cnt += v;
        PushUp(l, r, rt);
        return;
    }
    int mid = (l + r) >> 1;
    if(L <= mid){
        Update(L, R, v, l, mid, rt << 1);
    }
    if(R > mid){
        Update(L, R, v, mid + 1, r, (rt << 1) | 1);
    }
    PushUp(l, r, rt);
}

int main()
{
    int n, x1, x2, y1, y2, top, down, ans, prelen;

    while(scanf("%d", &n) != EOF){
        top = -inf;
        down = inf;
        for(int i = 0; i < n; i++){
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            L[i << 1] = Line(x1, y2, y1, 1);
            L[(i << 1) | 1]= Line(x2, y2, y1, -1);
            top = max(top, y2);
            down = min(down, y1);
        }
        sort(L, L + (n << 1));
        ans = prelen = 0;
        BuildUp(down, top, 1);
        for(int i = 0; i < (n << 1); i++){
            Update(L[i].y_down, L[i].y_up - 1, L[i].flag, down, top, 1);
            ans += 2 * T[1].num * (L[i + 1].x - L[i].x);
            ans += T[1].len - prelen > 0 ? T[1].len - prelen : prelen - T[1].len;
            prelen = T[1].len;
        }
        printf("%d\n",ans);
    }
}
#endif
