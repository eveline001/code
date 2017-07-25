#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct node
{
    int l, r;
    int ls ,rs, ms;//�ֱ��ʾ�������������ұ�����������Լ����������ڵ������������
};

node s[50050 << 2];

int n, m;
int op[50010];

void InitTree(int l,int r,int k)
{
    s[k].l = l;
    s[k].r = r;
    s[k].ls = s[k].rs = s[k].ms = r - l + 1;//�ʼ��ʱ��ȫ�������ŵġ����Գ���Ϊr-l+1
    if (l == r){
        return;
    }
    int mid = (l + r) >> 1;
    InitTree(l, mid, k << 1);
    InitTree(mid + 1, r, (k << 1) + 1);
}

void UpdataTree(int x,int flag,int k)//x��ʾ�޸������ƻ������֣�flag����������ƻ������޸�
{
    if(s[k].l == s[k].r){
        if (flag == 1){
            s[k].ls = s[k].rs = s[k].ms = 1;//�޸�
        }else{
            s[k].ls = s[k].rs = s[k].ms = 0;//�ƻ�
        }
        return;
    }
    int mid = (s[k].l + s[k].r) >> 1;
    if(x <= mid){
        UpdataTree(x, flag, k << 1);
    }else{
        UpdataTree(x, flag, (k << 1) + 1);
    }
    if(s[k << 1].ls == s[k << 1].r - s[k << 1].l + 1){//�������������=�������ĳ��ȣ���˵�����������ȫ�����������������������ˣ�������������������Ӧ�ü�����������󲿷֡�
        s[k].ls = s[k << 1].ls + s[(k << 1) + 1].ls;
    }else{
        s[k].ls = s[k << 1].ls;
    }
    if(s[(k << 1) + 1].rs == s[(k << 1) + 1].r - s[(k << 1) + 1].l + 1){//ͬ��
        s[k].rs = s[(k << 1) + 1].rs + s[k << 1].rs;
    }else{
        s[k].rs = s[(k << 1) + 1].rs;
    }
    s[k].ms = max(max(s[k << 1].ms, s[(k << 1) + 1].ms), s[k << 1].rs + s[(k << 1) + 1].ls);//���������ڵ��������ӦΪ��������������䣬������������䣬���������ϲ����м����䣬������ȡ���
}

int SearchTree(int x,int k)
{
    if(s[k].l == s[k].r
       || s[k].ms == 0
       ||s[k].ms == s[k].r - s[k].l + 1){//����Ҷ�ӽڵ���߸÷�������Ϊ�ջ�������������Ҫ��������
        return s[k].ms;
    }
    int mid = (s[k].l + s[k].r) >> 1;
    if(x <= mid)
    {
        if (x >= s[k << 1].r - s[k << 1].rs + 1){//�жϵ�ǰ������Ƿ�����������������У�����s[2*k].r-s[2*k].rs+1�����������ұ������������߽�ֵ������������������
            return s[k << 1].rs + s[(k << 1) + 1].ls;//Ҳ����SearchTree(x,2*k)+SearchTree(mid+1,2*k+1);
        }else{
            return SearchTree(x, k << 1);
        }
    }else{
        if(x <= s[(k << 1) + 1].l + s[(k << 1) + 1].ls - 1){//�жϵ�ǰ������Ƿ�����������������У�����s[2*k].r-s[2*k].rs+1�����������ұ������������߽�ֵ������������������
            return s[k << 1].rs + s[(k << 1) + 1].ls;//���ַ���SearchTree(x,2*k+1)+SearchTree(mid,2*k);Ҳ�ǿ��Եģ����ǱȽ��˷�ʱ��
        }else{
            return SearchTree(x,(k << 1) + 1);
        }
    }
}

int main()
{
    int x;
    char ch[2];

    while(scanf("%d%d", &n, &m) != EOF){
        int top = 0;
        InitTree(1, n, 1);
        while(m--){
            scanf("%s", ch);
            if(ch[0] == 'D'){
                scanf("%d", &x);
                op[top++] = x;
                UpdataTree(x, 0, 1);
            }else if(ch[0] == 'Q'){
                scanf("%d", &x);
                printf("%d\n", SearchTree(x, 1));
            }else{
                if(x > 0){
                    x = op[--top];
                    UpdataTree(x, 1, 1);
                }
            }
        }
    }
    return 0;
}
