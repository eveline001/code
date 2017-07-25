#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

vector<pair<int, int>> R;
vector<pair<int, int>>::iterator ptr, pre, it;

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


//http://www.xuebuyuan.com/1897775.html

//用strstr判断子串是否存在于母串中。

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000005;

struct MARK{
	int begin, end;
	bool operator < (const MARK& cmp) const{
		return end < cmp.end;
	}
};

MARK mark[maxn];
char s[maxn], t[1005][105];
int  n, cnt, next[105];

void work(const char str[], const char sub[]){
	int exp = 0, from, len = strlen(sub);
	while(strstr(str + exp, sub) != NULL){
		from = strstr(str + exp, sub) - str;
		mark[cnt].begin = from;
		mark[cnt].end = from + len - 1;
		cnt++;
		exp = from + len - 1;
	}
}

int main(){
	while (scanf("%s", s) == 1){
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%s", t[i]);
		}
		cnt = 0;
		for(int i = 0; i < n; i++){
			work(s, t[i]);
		}
		mark[cnt].begin = mark[cnt].end = strlen(s);
		cnt++;
		sort(mark, mark + cnt);
		int ans = -1;
		for(int i = 0; i < cnt - 1; i++){
			int len = mark[i + 1].end - mark[i].begin - 1;
			if (len > ans){
				ans = len;
			}
		}
		printf("%d\n", ans == -1 ? strlen(s) : ans);
	}
}

//kmp

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000005;

struct MARK{
	int begin, end;
	bool operator < (const MARK& cmp) const{
		return end < cmp.end;
	}
};

MARK mark[maxn];
char s[maxn], t[1005][105];
int  n, cnt, next[105];

void get_next(const char* sub, int* next){
	int len = strlen(sub);
	int i, k;
	next[0] = k = -1;
	for(i = 0; i < len;){
		if k == -1 || sub[i] == sub[k]){
			k++;
			i++;
			if(sub[k] != sub[i]){
				next[i] = k;
			}else{
				next[i] = next[k];
			}
		}else{
			k = next[k];
        }
	}
}

int KMP(const char* str, const char* sub, const int* next){
	int i, j, len1 = strlen(str), len2 = strlen(sub);
	for(i = 0, j = 0; i < len1 && j < len2;){
		if (j == -1 || str[i] == sub[j]){
			i++;
			j++;
		}else{
			j = next[j];
		}
	}
	if(j == len2){
		return i - len2;
	}
	return -1;
}

void work(const char str[], const char sub[]){
	get_next(sub, next);
	int exp = 0, from = 0, len = strlen(sub);
	while((from = KMP(str + exp, sub, next)) != -1){
		mark[cnt].begin = from + exp;
		mark[cnt].end = from + exp + len - 1;
		cnt++;
		exp += from + len - (len == 1 ? 0 : 1);
	}
}

int main(){
	while(scanf("%s", s) == 1){
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%s", t[i]);
		}
		cnt = 0;
		for(int i = 0; i < n; i++){
			work(s, t[i]);
		}
		mark[cnt].begin = mark[cnt].end = strlen(s);
		cnt++;
		sort(mark, mark + cnt);
		int ans = -1;
		for(int i = 0; i < cnt - 1; i++){
			int len = mark[i + 1].end - mark[i].begin - 1;
			if (len > ans)
				ans = len;
		}
		printf("%d\n", ans == -1 ? strlen(s) : ans);
	}
}

//http://blog.csdn.net/c1106543196/article/details/51055339

///ACAutomata

#include <cstring>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <set>

using namespace std;
int Next[101000][26],f[101000],tot;
int fg[101000];
int newnode()
{
    memset(Next[tot],0,sizeof(Next[tot]));
    fg[tot]=0;
    return tot++;
}
void Insert(int p,char *s)//构造字典树
{
    int i;
    for(i=0; s[i]; ++i)
    {
        int a=s[i]-'a';
        if(!Next[p][a])
            Next[p][a]=newnode();
        p=Next[p][a];
    }
    fg[p]=i;
}
void wa()//构造失配指针
{
    f[0]=0;
    queue<int>q;
    for(int i=0; i<26; ++i)
    {
        f[Next[0][i]]=0;
        if(Next[0][i])
            q.push(Next[0][i]);
    }
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int i=0; i<26; ++i)
        {
            if(Next[p][i])
            {
                f[Next[p][i]]=Next[f[p]][i];
                q.push(Next[p][i]);
            }
            else Next[p][i]=Next[f[p]][i];
        }
    }
}
int ac(char *s)
{
    int p=0;
    int ans=0;
    int low=0,i;
    for(i=1; s[i]; ++i)
    {
        int a=s[i]-'a';
        p=Next[p][a];
        int temp=p;
        while(temp)
        {
            if(fg[temp])
            {
//                printf("%d:%d\n",i,low);
                ans=max(i-low-1,ans);//取最大的那个len
                low=max(low,i-fg[temp]+1);//取最靠近i的low
                /*
                    low不取最大的话，对于数据
                    aaaab
                    2
                    aaaab
                    a
                    会出现在匹配了aaaab之后，low会回到1的位置
                */
            }
            temp=f[temp];
        }
    }
    return max(ans,i-low-1);
}
char s[1010000];
char a[120];
int main()
{
    int n;
//    freopen("input.txt","r",stdin);
    while(~scanf("%s",s+1))
    {
        tot=0;
        newnode();
        scanf("%d",&n);
        for(int i=0; i<n; ++i)
        {
            scanf("%s",a);
            Insert(0,a);
        }
        wa();
        printf("%d\n",ac(s));
    }
    return 0;
}

