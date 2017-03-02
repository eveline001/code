#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cstdio>

using namespace std;

map<string, vector<int>> RE;

int main()
{
    int T, n, val;
    char* str;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d" , &n);
        for(int i = 0; i < n; i++){
            scanf("%s %d", str, &val);
            string name(str);
            RE[name].push_back(val);
        }
        for(auto& it : RE){
            sort(it.second.begin(), it.second.end());
        }
    }
}
