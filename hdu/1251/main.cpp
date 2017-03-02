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
        Node* next[26];
        int num;

        Node(){
            for(int i = 0; i < 26; i++){
                next[i] = NULL;
            }
            num = 0;
        }
    };

    Node* root;

    void insert(Node*& next, char* x, int pos = 0){
        if(next == NULL){
            next = new Node();
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
