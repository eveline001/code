/*
//C++ AC G++ MLE
#include <iostream>
#include <cstdio>

using namespace std;

struct Node{
    Node* next[26];
    int num;

    Node(){
        for(int i = 0; i < 26; i++){
            next[i] = NULL;
        }
        num = 0;
    }
};

Node* root = new Node;

void insert(Node*& next, char* x){
    if(*x == '\0'){
        return;
    }
    if(next == NULL){
        next = new Node();
        next->num++;
        if(*(x + 1) == '\0'){
            return;
        }
        insert(next->next[*(x + 1) - 'a'], x + 1);
        return;
    }
    insert(next->next[*(x + 1) - 'a'], x + 1);
    next->num++;
    return;
}

int getnum(Node*& next, char* x){
    if(next == NULL){
        if(*x == '\0'){
            return 1;
        }else{
            return 0;
        }
    }
    if(*(x + 1) == '\0'){
        return next->num;
    }else{
        return getnum(next->next[*(x + 1) - 'a'], x + 1);
    }
}

char buff[16];
char* str;

int main()
{
    while(gets(buff) != NULL && buff[0] != '\0'){
        str = buff;
        if(*str == '\0'){
            continue;
        }
        insert(root->next[*str - 'a'], str);
        root->num++;

    }
    while(gets(buff) != NULL ){
        str = buff;
        if(*str == '\0'){
            printf("%d", root->num);
            continue;
        }
        printf("%d\n", getnum(root->next[*str - 'a'], str));
    }

    return 0;
}
*/

/*
//C++ AC G++ MLE
#include <iostream>
#include <cstdio>

using namespace std;

class Tree{
public:
    void insert(char* x){
        if(*x == '\0'){
            return;
        }
        insert(root->next[*x - 'a'], x);
        root->num++;
        return;
    }

    int getnum(char* x){
        if(*x == '\0'){
            return root->num;
        }
        return getnum(root->next[*x - 'a'], x);
    }

    void clear(){
        clear(root);
        delete root;
        root = new Node;
    }

private:
    struct Node{
        char x;
        Node* next[26];
        int num;

        Node(char x) : x(x){
            for(int i = 0; i < 26; i++){
                next[i] = NULL;
            }
            num = 0;
        }

        Node(){
            for(int i = 0; i < 26; i++){
                next[i] = NULL;
            }
            num = 0;
        }
    };

    Node* root;

    void insert(Node*& next, char* x, int pos = 0){
        if(*(x + pos) == '\0'){
            return;
        }
        if(next == NULL){
            next = new Node(*(x + pos));
            next->num++;
            if(*(x + pos + 1) == '\0'){
                return;
            }
            insert(next->next[*(x + pos + 1) - 'a'], x, pos + 1);
            return;
        }
        insert(next->next[*(x + pos + 1) - 'a'], x, pos + 1);
        next->num++;
        return;
    }

    int getnum(Node*& next, char* x, int pos = 0){
        if(next == NULL){
            if(*(x + pos) == '\0'){
                return 1;
            }else{
                return 0;
            }
        }
        if(*(x + pos + 1) == '\0'){
            return next->num;
        }else{
            return getnum(next->next[*(x + pos + 1) - 'a'], x, pos + 1);
        }
    }

    void clear(Node*& next){
        if(next == NULL){
            return;
        }
        for(int i = 0; i < 26; i++){
            if(next->next[i] != NULL){
                clear(next->next[i]);
                delete next->next[i];
                next->next[i] = NULL;
            }
        }
    }
};

Tree T;

char buff[16];
char* str;

int main()
{
    T.clear();
    while(gets(buff) != NULL && buff[0] != '\0'){
        str = buff;
        T.insert(str);
    }
    while(gets(buff) != NULL ){
        str = buff;
        printf("%d\n", T.getnum(str));
    }
    return 0;
}
*/

#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
const int SIGMA_SIZE = 26;
const int MAXNODE = N;

char str[N];

struct ACAutomata{
    int ch[MAXNODE][SIGMA_SIZE];
    int f[MAXNODE], val[MAXNODE], last[MAXNODE], cnt[MAXNODE];
    int sz;

    void init(){
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
        memset(cnt, 0, sizeof(cnt));
    }

    int idx(char c){
        return c - 'a';
    }

    void _insert(char *s, int v){
        int u = 0, n = strlen(s);

        for(int i = 0; i < n; i++){
            int c = idx(s[i]);
            if(!ch[u][c]){
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
            val[u]++;
        }
    }

    int Find(char *T){
        int n = strlen(T);
        int j = 0;
        for(int i = 0; i < n; i++){
            int c = idx(T[i]);
            j = ch[j][c];
            if(!j){
                return 0;
            }
        }
        return val[j];
    }
};

ACAutomata AC;

int main(){
    int j = 0;

    AC.init();
    while(gets(str) && str[0]!='\0'){
        AC._insert(str, ++j);
    }
    while(scanf("%s",str) != EOF){
        printf("%d\n", AC.Find(str));
    }
    return 0;
}
