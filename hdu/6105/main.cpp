#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[20002];
int  d[20002];

int GetDis(char a, char b){
    int res = a - b;
    return res > 0 ? res : -res;
}

int main()
{
    int T, m, ed, maxlen, curlen, lst, led, rst, red, dis;

    scanf("%d", &T);
    for(int cas = 1 ; cas <= T; cas++){
        scanf("%d", &m);
        scanf("%s", s + 1);
        ed = strlen(s + 1), maxlen = 0;
        for(int mid = ed / 2; mid < ed - maxlen + 1; mid++){
            lst = led = mid, rst = red = mid, curlen = dis = 0;
            while(1 <= lst && lst <= led && red <= rst && rst <= ed){
                if((lst > 1 && rst < ed) && (curlen == 0 || dis <= m)) lst--, rst++, curlen++, dis += (d[lst] = GetDis(s[lst], s[rst]));
                else led--, red++, curlen--, dis -= d[led];
                if(dis <= m){if(curlen > maxlen) maxlen = curlen; if(lst == 1 || red == ed) break;}
            }
            lst = led = mid + 1, rst = red = mid, curlen = dis = 0;
            while(1 <= lst && lst <= led && red <= rst && rst <= ed){
                if((lst > 1 && rst < ed) && (curlen == 0 || dis <= m)) lst--, rst++, curlen++, dis += (d[lst] = GetDis(s[lst], s[rst]));
                else led--, red++, curlen--, dis -= d[led];
                if(dis <= m){if(curlen > maxlen) maxlen = curlen; if(lst == 1 || red == ed) break;}
            }
        }
        for(int mid = ed / 2; mid > maxlen; mid--){
            lst = led = mid, rst = red = mid, curlen = dis = 0;
            while(1 <= lst && lst <= led && red <= rst && rst <= ed){
                if((lst > 1 && rst < ed) && (curlen == 0 || dis <= m)) lst--, rst++, curlen++, dis += (d[lst] = GetDis(s[lst], s[rst]));
                else led--, red++, curlen--, dis -= d[led];
                if(dis <= m){if(curlen > maxlen) maxlen = curlen; if(lst == 1 || red == ed) break;}
            }
            lst = led = mid + 1, rst = red = mid, curlen = dis = 0;
            while(1 <= lst && lst <= led && red <= rst && rst <= ed){
                if((lst > 1 && rst < ed) && (curlen == 0 || dis <= m)) lst--, rst++, curlen++, dis += (d[lst] = GetDis(s[lst], s[rst]));
                else led--, red++, curlen--, dis -= d[led];
                if(dis <= m){if(curlen > maxlen) maxlen = curlen; if(lst == 1 || red == ed) break;}
            }
        }
        printf("%d\n", maxlen);
    }
    return 0;
}

// I don't like this but it's faster
/**
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[20002];
int  d[20002];

int GetDis(char a, char b){
    int res = a - b;
    return res > 0 ? res : -res;
}

int main()
{
    int T, m, ed, maxlen, curlen, lst, led, rst, red, dis;

    scanf("%d", &T);
    for(int cas = 1 ; cas <= T; cas++){
        scanf("%d", &m);
        scanf("%s", s + 1);
        ed = strlen(s + 1), maxlen = 0;
        for(int mid = 1; mid <= ed; mid++){
            lst = led = mid, rst = red = mid, curlen = dis = 0;
            while(1 <= lst && lst <= led && red <= rst && rst <= ed){
                if((lst > 1 && rst < ed) && (curlen == 0 || dis <= m)) lst--, rst++, curlen++, dis += (d[lst] = GetDis(s[lst], s[rst]));
                else led--, red++, curlen--, dis -= d[led];
                if(dis <= m){if(curlen > maxlen) maxlen = curlen; if(lst == 1 || red == ed) break;}
            }
            lst = led = mid + 1, rst = red = mid, curlen = dis = 0;
            while(1 <= lst && lst <= led && red <= rst && rst <= ed){
                if((lst > 1 && rst < ed) && (curlen == 0 || dis <= m)) lst--, rst++, curlen++, dis += (d[lst] = GetDis(s[lst], s[rst]));
                else led--, red++, curlen--, dis -= d[led];
                if(dis <= m){if(curlen > maxlen) maxlen = curlen; if(lst == 1 || red == ed) break;}
            }
        }
        printf("%d\n", maxlen);
    }
    return 0;
}
*/
