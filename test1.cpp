#include<iostream>
using namespace std;
int a[100]={1,2,3,5,12,13,14,15,29,55};//�����е�������С����
int k;//Ҫ�ҵ�����
int found(int x,int y)
{
    int m=x+(y-x)/2;
    if(x>y)//�������û���ҵ��𰸣�����-1
        return -1;
    else
    {
        if(a[m]==k)
            return m;//�ҵ�!����λ��.
        else if(a[m]>k)
            return found(x,m-1);//�����
         else
            return found(m+1,y);//���ұ�
    }
}
int main()
    {
        cin>>k;//����Ҫ�ҵ�����c���԰�cin��Ϊscanf����
        cout<<found(0,9);//������a[0]��a[9]c���԰�cout��Ϊprintf����
        return 0;
    }
