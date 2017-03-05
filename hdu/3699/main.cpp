#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int A, B, C, D, E;

struct sta{
    long long a, b;
    int op;

    bool operator < (const sta& b) const{
        if(this->a != b.a) return this->a < b.a;
        else if(this->b != b.b) return this->b < b.b;
        else return this->op < b.op;
    }

    bool operator == (const sta& b) const{
        if(this->a == b.a && this->b == b.b && this->op == b.op) return true;
    }

    bool operator > (const sta& b) const{
        return b < *this;
    }

    bool operator <= (const sta& b) const{
        return *this == b || *this < b;
    }

    bool operator >= (const sta& b) const{
        return b < *this || *this == b;
    }

    bool operator != (const sta& b) const{
        return !(*this == b);
    }

    sta(const long long a, const long long b, const int op) : a(a), b(b), op(op){}
};

set<sta> S;

int getn(char c)
{
    if(c == 'A') return A;
    if(c == 'B') return B;
    if(c == 'C') return C;
    if(c == 'D') return D;
    if(c == 'E') return E;
}

long long get(char s[])
{
    if(getn(s[0]) == 0 && strlen(s) != 1) return -1;
    long long res = 0;
    for(int i = 0; i < strlen(s); i++)
        res = res * 10 + getn(s[i]);
    return res;
}

int main()
{
    int T;
    long long na, nb, nc;
    char a[10],b[10],c[10];

    scanf("%d", &T);
    while(T--)
    {
        S.clear();
        scanf("%s%s%s", a, b, c);
        for(A = 0; A <= 9; A++){
            for(B = 0; B <= 9; B++){ if(A == B) continue;
                for(C = 0; C <= 9; C++){ if(C == B || C == A) continue;
                    for(D = 0; D <= 9; D++){ if(D == C || D == B || D == A) continue;
                        for(E = 0; E <= 9; E++){ if(E == D || E == C || E == B || E == A) continue;
                            na = get(a);
                            nb = get(b);
                            nc = get(c);
                            if(na == -1 || nb == -1 || nc == -1) continue;
                            if(na + nb == nc) S.insert(sta(na, nb, 0));
                            if(na - nb == nc) S.insert(sta(na, nb, 1));
                            if(na * nb == nc) S.insert(sta(na, nb, 2));
                            if(nb != 0 && na / nb == nc && na % nb == 0) S.insert(sta(na, nb, 3));
                        }
                    }
                }
            }
        }
        printf("%d\n", S.size());
    }
    return 0;
}
