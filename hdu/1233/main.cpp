//²¢²é¼¯
#include <iostream>
#include <set>

using namespace std;

int Points[101];

class Edge{
public:
    Edge(int x, int y, int Weight) : x(x), y(y), Weight(Weight){
    }

    int x;
    int y;
    int Weight;

    Edge operator = (const Edge& a){
        x = a.x;
        y = a.y;
        Weight = a.Weight;
    }

    bool operator == (const Edge& b) const{
        if(this->x == b.x && this->y == b.y && this->Weight == b.Weight) return true;
        return false;
    }

    bool operator < (const Edge& b) const{
        if(this->Weight < b.Weight) return true;
            else if(this->Weight == b.Weight){
                if(this->x < b.x) return true;
                    else if(this->x == b.x) return this->y < b.y;
                        else return false;
                }else return false;
    }

    bool operator > (const Edge& b) const{
        return b < *this;
    }

    bool operator <= (const Edge& b) const{
        return !(*this > b);
    }

    bool operator >= (const Edge& b) const{
        return !(*this < b);
    }

    bool operator != (const Edge& b) const{
        return !(*this == b);
    }
};

set<Edge> E;

void ReSet(int arr[], int n){
    for(int i = 1; i <= n; i++) arr[i] = i;
}

int FindFather(int arr[], int x){
    if(arr[x] == x) return x;
    return arr[x] = FindFather(arr, arr[x]);
}

int Merge(int arr[], int a, int b){
    int fa = FindFather(arr, a),
        fb = FindFather(arr, b);

    if(fa != fb) return arr[fb] = arr[fa];
    return -1;
}

int main()
{
    int N, i, A, B, cost, ans;

    while((cin >> N) && N)
    {

        if(N == 1){cout << "0\n";continue;}
        for(i = 0; i < N*(N-1)/2; i++)
        {
            cin >> A >> B >> cost;
            E.insert(Edge(A, B, cost));
        }
        ans = 0;
        ReSet(Points, N);
        for(auto it = E.begin(); it != E.end(); ++it)
        {
            if(FindFather(Points, it->x) != FindFather(Points, it->y))
            {
                ans += it->Weight;
                Merge(Points, it->x, it->y);
            }
        }
        E.clear();
        cout << ans << endl;
    }
}
