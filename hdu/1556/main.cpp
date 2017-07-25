#include <iostream>

using namespace std;

void Reset(int Arr[], int n, int x){
    for(int i = 1; i <= n; i++) Arr[i] = x;
}

int Lowbit(int pos){
    return pos & (-pos);
}

void Update(int Arr[], int pos, int delta, int n){
    while(pos <= n)
    {
        Arr[pos] += delta;
        pos += pos & (-pos);
        //pos += pos & (pos xor (pos-1));
    }
}

int Pre(int Arr[], int pos){
    int Pre = 0;
    while(pos > 0)
    {
        Pre += Arr[pos];
        pos -= pos & (-pos);
        //pos -= pos & (pos xor (pos-1));
    }
    return Pre;
}

int Sum(int Arr[], int begin, int end){
    return Pre(Arr, end) - Pre(Arr, begin);
}

int C[100010];

int main()
{
    int N, i, a, b;

    ios_base::sync_with_stdio(false);

    while(cin >> N)
    {
        if(N == 0) break;
        Reset(C, N, 0);
        for(i = 1; i <= N; i++)
        {
            cin >> a >> b;
            Update(C, a, 1, N);
            Update(C, b+1, -1, N);
        }
        for(i = 1; i < N; i++) cout << Pre(C, i) << ' ';
        cout << Pre(C, N) << endl;
    }
}
