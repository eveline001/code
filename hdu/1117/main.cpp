//unfinished
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int letter[27];

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
    int T, N, a, b, num, i, inedge, outedge;
    int in[27], out[27];
    string s;
    bool flag;

    cin >> T;
    while(T--)
    {
        cin >> N;
        memset(letter, 0, sizeof(letter));
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        while(N--)
        {
            cin >> s;
            in[a = s[0] - 'a']++;
            out[b = s[s.length()-1] - 'a']++;
            Merge(letter, a, b);
        }
        num = 0;
        for(i = 0; i < 26; i++)
        {
            if((in[i] || out[i]) && letter[i] == i) num++;
        }
        if(num != 1)
        {
            cout << "The door cannot be opened.\n";
            continue;
        }
        flag = false;
        inedge = 0;
        outedge = 0;
        for(i = 0; i < 26; i++)
        {
            if(in[i] != out[i])
            {
                if(in[i] - out[i] == 1) inedge++;
                if(out[i] - in[i] == 1) outedge++;
                if(in[i] - out[i] >=2 || out[i] - in[i] >= 2)
                {
                    flag = true;
                    cout << "The door cannot be opened.\n";
                    break;
                }
            }
        }
        if(flag) continue;
        if((inedge == 0 && outedge == 0) || (inedge == 1 && outedge == 1)) cout << "Ordering is possible.\n";
        else cout << "The door cannot be opened.\n";
    }
    return 0;
}
/*
isEulerLoop=true;
isEulerPath=true;
for(int i=0;i<maxn;i++)
{
    if(in[i]!=out[i])
    {
        isEulerLoop=false;
    }
}
if(!isEulerLoop)
{
    int flaga=0;
    int flagb=0;
    for(int i=0;i<maxn;i++)
    {
        if(in[i]!=out[i])
        {
            if(in[i]-out[i]==1) flaga++;
            else if(out[i]-in[i]==1) flagb++;
            else
            {
                isEulerPath=false;
                break;
            }
        }
    }
    if(flaga!=1 || flagb!=1) isEulerPath=false;
}
if(isEulerLoop)
{
    printf("Ordering is possible.n");
}
else if(isEulerPath)
{
    printf("Ordering is possible.n");
}
else
{
    printf("The door cannot be opened.n");
}
*/
