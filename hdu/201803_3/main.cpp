#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Tree Edition
struct Tree {
public:
    Tree() {
        root = new Node();
    }

    void insert(const string& s, const string& name) {
        insert(root, s, 0, s.length(), name);
    }

    pair<string, string> match(const string& s) {
        return match(root, s, 0, s.length());
    }

private:
    struct Node {
        bool isEndNode = false;
        string val;
        string name;
        vector<Node*> next;
    };

    Node* root;

    void insert(Node* ptr, const string& s, int st, int ed, const string& name) {
        if (st == ed || (s[st] == '/' && st + 1 == ed)) {
            ptr->isEndNode = true;
            ptr->name = name;
            return;
        }
        int pos = st;
        for (;pos < ed && s[pos] != '/'; pos++);
        ptr->val = s.substr(st + 1, pos - st - 1);
        ptr->next.push_back(new Node());
        insert(ptr->next[ptr->next.size() - 1], s, pos, ed, name);
    }

    pair<string, string> match(Node* ptr, const string& s, int st, int ed) {

        return pair<string, string>("404", "");
    }
};

Tree tree;

string str0, str1;
pair<string, string> ans;

int main()
{
    int N, M;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> str0 >> str1;
        tree.insert(str0, str1);
    }
    for (int i = 0; i < M; i++) {
        cin >> str0;
        ans = tree.match(str0);
        cout << ans.first;
        if (ans.first != "404") cout << ' ' << ans.second;
        cout << endl;
    }

    return 0;
}
*/

struct Node {
    string name;
    vector<string> vals;

    void build(const string& str) {
        int st = 1, ed = 1, len = str.length;
        vals.push_back("/");
        for (i)
    }

    vector<string> match(const string& str) {
        string s;
        int st = 0, ed = str.length(), v_pos = 0;

    }
};

Node Match[110];

string str0, str1;
vector<string> ans;

int main()
{
    int N, M;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> str0 >> str1;
        Match[i].name = str1;
        Match[i].build(str0);
    }

    for (int i = 0; i < M; i++) {
        cin >> str0;
        for (int j = 0; j < N; j++) {
            ans = Match[j].match(str0);
            if (ans[0] != "404") break;
        }
        for (int j = 0, len = ans.size(); j < len; j++) cout << ans[j] << (" \n"[j == len - 1 ? 1 : 0]);
    }
}
