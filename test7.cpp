#include <iostream>
 
int used[10];
 
int ans[9];
 
int col[3],lin[3],dia[2];
 
void dfs(int m);
 
bool meetcond();    //判断解是否满足条件
 
void output();  //输出一组可行解
 
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
 
bool meetcond()     //判断解是否满足条件
{
    //清空
    for(int i=0; i<3; i++)
    {
        col[i]=lin[i]=0;
        if(i<2)
        {
            dia[i]=0;
        }
    }
 
    //计算行列斜线和
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
 
    //判断是否满足解
    for(int i=0; i<3; i++)
    {
        if(col[i]!=15||lin[i]!=15) //行列判断
        {
 
            return false;
        }
        else if(i<2&&dia[i]!=15)    //斜线判断
        {
            return false;
        }
    }
    return true;
}
 
void output()   //输出一组可行解
{
    for(int m=0; m<9; m++)
    {
        if(m%3==0||m%3==1)  //第一、二列
        {
            cout<<ans[m]<<' ';
        }
        else    //第三列
        {
            cout<<ans[m]<<endl;
        }
    }
    cout<<endl;
}
