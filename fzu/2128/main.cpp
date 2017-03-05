#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

vector< pair< int, int > > R;
vector< pair< int, int > >::iterator ptr, pre, it;
char s[1000010];

bool comp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main()
{
    int n, pos, ans;
    char ss[110];
    char* p;

    while(gets(s) != NULL){
        R.clear();
        ans = 0;
        scanf("%d", &n);
        getchar();
        for(int i = 0; i < n; i++){
            gets(ss);
            p = strstr(s, ss);
            while(p != NULL && *p != '\0'){
                pos = (p - s);
                R.push_back(make_pair(pos, pos + (int)strlen(ss) - 1));
                p = strstr(p + 1, ss);
            }
        }
        if(R.size() == 0){
            printf("%d\n", strlen(s));
        }else if(R.size() == 1){
            ptr = R.begin();
            printf("%d\n", max(ptr->second, (int)strlen(s) - 1 - ptr->first));
        }else{
            sort(R.begin(), R.end(), comp);
            for(pre = R.begin(), it = pre + 1; it != R.end(); ++pre, ++it){
                ans = max(ans, it->second - pre->first - 1);
            }
            printf("%d\n", ans);
        }
    }
}
