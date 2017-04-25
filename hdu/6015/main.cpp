#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cstdio>

using namespace std;

struct Node{
    int a, b;

    Node(): a(0), b(0) {}

    void Push(int x){
        if(x > a){
            b = a;
            a = x;
        }else if(x > b){
            b = x;
        }
    }

    int Sum(){
        return a + b;
    }
};

map<string, Node> RE;

int main()
{
    int T, n, val, ans;
    char str[16];

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d" , &n);
        RE.clear();
        for(int i = 0; i < n; i++){
            scanf("%s %d", str, &val);
            string name(str);
            RE[name].Push(val);
        }
        ans = 0;
        for(auto& it : RE) ans += it.second.Sum();
        printf("%d\n", ans);
    }

    return 0;
}
