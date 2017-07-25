#include <iostream>

using namespace std;

int city[1024];

int ReSet(int a[], int n)
{
    for(int i = 1; i <= n; i++)
        a[i] = i;
    return 1;
}

int FindFather(int x)
{
    if(city[x] == x) return x;
    return city[x] = FindFather(city[x]);
}

int Link(int a, int b)
{
    int Fa = FindFather(a),
        Fb = FindFather(b);
    if(Fa > Fb)
    {
        city[Fa] = Fb;
        return 0;
    }
    city[Fb] = Fa;
    return 1;
}

int main()
{
    int N, M, i, a, b, count;

    while(cin >> N)
    {
        if(N == 0) break;
        cin >> M;
        count = 0;
        ReSet(city, N);
        for(i = 0; i < M; i++)
        {
            cin >> a >> b;
            Link(a, b);
        }
        for(i = 1; i <= N; i++)
            if(city[i] == i) count++;
        cout << count-1 << '\n';
    }
    return 0;
}
