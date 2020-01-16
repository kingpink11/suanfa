#include <iostream>
 
int used[10];
 
int ans[9];
 
int col[3],lin[3],dia[2];
 
void dfs(int m);
 
bool meetcond();    //�жϽ��Ƿ���������
 
void output();  //���һ����н�
 
using namespace std;
 
int main()
{
    dfs(0);
    return 0;
}
 
void dfs(int m)
{
    if(m==9)
    {
        if(meetcond())
        {
            output();
        }
    }
    else
    {
        for(int i=1; i<10; i++)
        {
            if(!used[i])
            {
                ans[m]=i;
                used[i]=1;
 
                dfs(m+1);
 
                used[i]=0;
            }
        }
    }
}
 
bool meetcond()     //�жϽ��Ƿ���������
{
    //���
    for(int i=0; i<3; i++)
    {
        col[i]=lin[i]=0;
        if(i<2)
        {
            dia[i]=0;
        }
    }
 
    //��������б�ߺ�
    for(int m=0; m<9; m++)
    {
        col[m/3]+=ans[m];
        lin[m%3]+=ans[m];
        if(m==0||m==4||m==8)
        {
            dia[0]+=ans[m];
        }
        if(m==2||m==4||m==6)
        {
            dia[1]+=ans[m];
        }
    }
 
    //�ж��Ƿ������
    for(int i=0; i<3; i++)
    {
        if(col[i]!=15||lin[i]!=15) //�����ж�
        {
 
            return false;
        }
        else if(i<2&&dia[i]!=15)    //б���ж�
        {
            return false;
        }
    }
    return true;
}
 
void output()   //���һ����н�
{
    for(int m=0; m<9; m++)
    {
        if(m%3==0||m%3==1)  //��һ������
        {
            cout<<ans[m]<<' ';
        }
        else    //������
        {
            cout<<ans[m]<<endl;
        }
    }
    cout<<endl;
}
