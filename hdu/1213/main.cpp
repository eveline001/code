#include <iostream>
#include <cstring>

using namespace std;

int f[1024];

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

int main(){
    int T, a, b, N, M, i, Count;

    cin >> T;
    while(T--){
        cin >> N >> M;
        ReSet(f, N);
        Count = 0;
        for(i = 0; i < M; i++){
            cin >> a >> b;
            Merge(f, a, b);
        }
        for(i = 1; i <= N; i++){
            if(f[i] == i) Count++;
        }
        cout << Count << '\n';
    }
    return 0;
}
