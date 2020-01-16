#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1010;
char x[N],y[N];
int dp[N][N];
int b[N][N];
void Print(int i,int j)
{
    if(i==0||j==0)///递归终止条件
    {
        return ;
    }
    if(b[i][j]==1)
    {
        Print(i-1,j-1);
        printf("%c",x[i-1]);
    }
    else if(b[i][j]==2)
    {
        Print(i-1,j);
    }
    else if(b[i][j]==3)
    {
        Print(i,j-1);
    }
}
int main()
{
    int lena,lenb,i,j;
    while(scanf("%s%s",x,y)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        memset(b,0,sizeof(b));
        lena=strlen(x);
        lenb=strlen(y);
        for(i=1;i<=lena;i++)
        {
            for(j=1;j<=lenb;j++)
            {
                if(x[i-1]==y[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    b[i][j]=1;///来自于左上方
                }
                else
                {
                    if(dp[i-1][j]>dp[i][j-1])
                    {
                        dp[i][j]=dp[i-1][j];
                        b[i][j]=2;///来自于左方
                    }
                    else
                    {
                        dp[i][j]=dp[i][j-1];
                        b[i][j]=3;///来自于上方
                    }
                }
            }
        }
        Print(lena,lenb);
    }
    return 0;
}
