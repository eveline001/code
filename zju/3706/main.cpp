#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>

using namespace std;

set<int> s;

int main()
{
    int T, x, y, ans, a, b;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d", &x, &y);
        ans = 0;
        for(int i = 1; i <= (y + 1) >> 1; i++){
            a = y - i, b = i, s.clear();;
            s.insert(x + y);
            s.insert(x + a);
            s.insert(x + b);
            s.insert(y);
            s.insert(x + abs(a - b));
            s.insert(abs(x - abs(a - b)));
            s.insert(abs(x - y));
            s.insert(x);
            s.insert(a);
            s.insert(b);
            s.insert(abs(x - a));
            s.insert(abs(x - b));
            s.insert(abs(a -b));
            if(s.size() > ans) ans = s.count(0) ? s.size() - 1 : s.size();
        }
        swap(x, y);
        for(int i = 1; i <= (y + 1) >> 1; i++){
            a = y - i, b = i, s.clear();
            s.insert(x + y);
            s.insert(x + a);
            s.insert(x + b);
            s.insert(y);
            s.insert(x + abs(a - b));
            s.insert(abs(x - abs(a - b)));
            s.insert(abs(x - y));
            s.insert(x);
            s.insert(a);
            s.insert(b);
            s.insert(abs(x - a));
            s.insert(abs(x - b));
            s.insert(abs(a -b));
            if(s.size() > ans) ans = s.count(0) ? s.size() - 1: s.size();
        }
        printf("%d\n", ans);
    }
    return 0;
}