#include <iostream>

using namespace std;

void Reset(int Arr[], int n, int x){
    for(int i = 1; i <= n; i++) Arr[i] = x;
}

void Update(int Arr[], int pos, int delta, int n){
    while(pos <= n)
    {
        Arr[pos] += delta;
        pos += pos & (-pos);
    }
}

int Pre(int Arr[], int pos){
    int Pre = 0;
    while(pos > 0)
    {
        Pre += Arr[pos];
        pos -= pos & (-pos);
    }
    return Pre;
}

int Sum(int Arr[], int begin, int end){
    return Pre(Arr, end) - Pre(Arr, begin);
}

int C[5010], a[5010];

int main()
{
    int N, i, sum, ans;

    while(cin >> N)
    {
        if(N == 1){cout << "0\n";continue;}
        Reset(C, N, 0);
        for(i = 0; i < N; i++) cin >> a[i];
        ans = 0;
        for(i = N-1; i >= 0; i--){Update(C, a[i]+1, 1, N); ans += Pre(C, a[i]);}
        sum = ans;
        for(i = 0; i < N; i++){sum = sum - a[i] + (N - a[i] - 1);ans = ans < sum ? ans : sum;}
        cout << ans << endl;
    }
}
