#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

int main()
{
    string str, buf;

    while(getline(cin, str)){
        if(str == "#"){
            return 0;
        }
        stringstream s(str);
        set<string> dict;
        while(s >> buf){
            dict.insert(buf);
        }
        cout << dict.size() << endl;
    }
}
