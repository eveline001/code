#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class Tree{
public:
    void insert(char* s){
        return insert(root, s);
    }

    void del(char* s){
        return del(root, s);
    }

    bool search(char* s){
        return search(root, s);
    }

    Tree(){
        root = new Node;
    }
private:
    struct Node{
        bool  isleaf;
        Node* next[26];

        Node(){
            isleaf = false;
            for(int i = 0; i < 26; i++) next[i] = NULL;
        }
    };

    Node *root = NULL;

    void insert(Node*& p, char* s){
        if(*s == '\0') return;
        if(p->next[*s - 'a'] == NULL){
            p->next[*s - 'a'] = new Node;
            if(*(s + 1) == '\0') p->next[*s - 'a']->isleaf = true;
            insert(p->next[*s - 'a'], s + 1);
        }else{
            if(*(s + 1) == '\0') p->next[*s - 'a']->isleaf = true;
            insert(p->next[*s - 'a'], s + 1);
        }
    }

    void del(Node*& p, char* s){
        if(*s == '\0') return;
        if(p->next[*s - 'a'] != NULL){
            if(*(s + 1) == '\0'){
                delete p->next[*s - 'a'];
                p->next[*s - 'a'] = NULL;
            }
            else del(p->next[*s - 'a'], s + 1);
        }
        return;
    }

    bool search(Node*& p, char* s){
        if(*s == '\0' && haveleaf(p)) return true;
        if(p->next[*s - 'a'] != NULL) return search(p->next[*s - 'a'], s + 1);
        else return false;
    }

    bool haveleaf(Node*& p){
        if(p == NULL) return false;
        if(p->isleaf) return true;
        for(int i = 0; i < 26; i++){
            if(haveleaf(p->next[i])) return true;
        }
        return false;
    }
};

Tree T;

int main()
{
    int N;
    char s[40];

    scanf("%d", &N);
    getchar();
    for(int i = 0; i < N; i++)
    {
        gets(s);
        if(s[0] == 'i') T.insert(s + 7);
        else if(s[0] == 'd') T.del(s + 7);
        else if(T.search(s + 7)) printf("Yes\n"); else printf("No\n");
    }
    return 0;
}
