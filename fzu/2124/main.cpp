//#define Debug
#ifndef Debug

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

const int inf = 1e9;

struct Site{
    int x, y;
};

Site To[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

struct Sta{
    int x;
    int y;
    bool power;

    Sta(int x = 0, int y = 0, bool power = false) : x(x), y(y), power(power) {}

    Sta operator + (const Site& b){
        Sta c = Sta(this->x + b.x, this->y + b.y, this->power);
        return c;
    }
};

Site B;
Sta  P, v, temp;
int  n, m;
char M[21][21];
int  T[21][21][2];
queue<Sta> Q;
bool Blocked;

void bfs(){
    int time;

    while(Q.size()){
        Q.pop();
    }
    Q.push(P);
    T[P.x][P.y][0] = T[P.x][P.y][1] = 0;
    while(!Q.empty()){
        v = Q.front();
        Q.pop();
        if(v.x == B.x){
            Blocked = false;
            for(int i = min(v.y, B.y); i <= max(v.y, B.y); i++){
                if(M[v.x][i] == 'X'){
                    Blocked = true;
                    break;
                }
            }
            if(!Blocked){
                if(v.power){
                    T[B.x][B.y][1] = min(T[B.x][B.y][1], T[v.x][v.y][1] + 2 * abs(v.y - B.y));
                }else{
                    T[B.x][B.y][0] = min(T[B.x][B.y][0], T[v.x][v.y][0] + 2 * abs(v.y - B.y));
                }
            }
        }else if(v.y == B.y){
            Blocked = false;
            for(int i = min(v.x, B.x); i <= max(v.x, B.x); i++){
                if(M[i][v.y] == 'X'){
                    Blocked = true;
                    break;
                }
            }
            if(!Blocked){
                if(v.power){
                    T[B.x][B.y][1] = min(T[B.x][B.y][1], T[v.x][v.y][1] + 2 * abs(v.x - B.x));
                }else{
                    T[B.x][B.y][0] = min(T[B.x][B.y][0], T[v.x][v.y][0] + 2 * abs(v.x - B.x));
                }
            }
        }
        time = v.power ? 5 : 10;

        //HERE !!!!
        for(int i = 0; i < 4; i++){
            temp = v + To[i];
            if(!(temp.x < 0 || temp.x >= n || temp.y < 0 || temp.y >= m || M[temp.x][temp.y] == 'X')){
                if(v.power && T[temp.x][temp.y][1] >= T[temp.x][temp.y][1] + time){
                    T[temp.x][temp.y][1] = T[temp.x][temp.y][1] + time;
                    Q.push(temp);
                }else if(!v.power && T[temp.x][temp.y][0] > T[temp.x][temp.y][0] + time){
                    T[temp.x][temp.y][0] = T[temp.x][temp.y][0] + time;
                    if(M[temp.x][temp.y] == 'S'){
                        T[temp.x][temp.y][1] = T[temp.x][temp.y][0];
                        Q.push(Sta(temp.x, temp.y, true));
                    }else{
                        Q.push(temp);
                    }
                }
            }
        }
    }
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF){
        getchar();
        for(int i = 0; i < n; i++){
            gets(M[i]);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(M[i][j] == 'P'){
                    P = Sta(i, j, false);
                }else if(M[i][j] == 'B'){
                    B = {i, j};
                }
                T[i][j][0] = T[i][j][1] = inf;
            }
        }
        ans = bfs();
        if(ans < inf){
            printf("%d.%d\n", ans / 10, ans % 10);
        }else{
            printf("-1\n");
        }
    }
    return 0;
}
#endif // Debug

#ifdef Debug

#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int inf = 1e9;

struct Site{
    int x, y;
};

Site To[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

struct Sta{
    int x;
    int y;
    bool power;

    Sta(int x = 0, int y = 0, bool power = false) : x(x), y(y), power(power) {}

    Sta operator + (const Site& b){
        Sta c = Sta(this->x + b.x, this->y + b.y, this->power);
        return c;
    }
};

Site B;
Sta  P, v, temp;
int  n, m, Time, ans;
char M[21][21];
int  T[21][21];
queue<Sta> Q;
bool Blocked;

struct node{
    int y,x,s;
}h,k;

int BFS(int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(M[i][j]=='P'){
                P = Sta(i, j, false);
            }else if(M[i][j]=='B'){
                B.x = i;
                B.y = j;
            }
        }
    }
    while(Q.size()){
        Q.pop();
    }
    Q.push(P);
    T[P.x][P.y] = 0;
    while(Q.size()){
        v = Q.front(), Q.pop();
        if(v.x == B.x){
            Blocked = false;
            for(int i = min(v.y, B.y); i <= max(v.y, B.y); i++){
                if(M[v.x][i] == 'X'){
                    Blocked = true;
                    break;
                }
            }
            if(!Blocked){
                T[B.x][B.y] = min(T[B.x][B.y], T[v.x][v.y] + abs(v.y - B.y) * 2);
            }
        }
        if(v.y == B.y){
            Blocked = false;
            for(int i = min(v.x, B.x); i <= max(v.x, B.x); i++){
                if(M[i][v.y] == 'X'){
                    Blocked = true;
                    break;
                }
            }
            if(!Blocked){
                T[B.x][B.y] = min(T[B.x][B.y], T[v.x][v.y] + abs(v.x - B.x) * 2);
            }
        }
        Time = v.power ? 5 : 10;
        for(int i = 0; i < 4; i++){
            temp = v + To[i];
            if(temp.x < 0 || temp.x >= n || temp.y < 0 || temp.y >= m || M[temp.x][temp.y] == 'X'){
                continue;
            }
            if(T[temp.x][temp.y] > T[v.x][v.y] + Time){
                T[temp.x][temp.y] = T[v.x][v.y] + Time;
                if(!temp.power && M[temp.x][temp.y] == 'S'){
                    temp.power = true;
                }
                Q.push(temp);
            }
        }
    }
    return T[B.x][B.y];
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF){
        getchar();
        for(int i = 0; i < n; i++){
            gets(M[i]);
        }
        ans = BFS(n,m);
        if(ans >= inf){
            printf("-1\n");
        }else{
            printf("%d.%d\n", ans / 10, ans % 10);
        }
    }
    return 0;
}
#endif
