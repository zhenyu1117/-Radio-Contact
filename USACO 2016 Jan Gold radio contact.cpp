#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,fx,fy,bx,by;
char s1[1001],s2[1001];
int f[1001][1001],dis[1001][1001];
int h1[1001],h2[1001],z1[1001],z2[1001];
void pre(){
    h1[0]=fx;z1[0]=fy;h2[0]=bx;z2[0]=by;
    for(int i=1;i<=n;i++){
        if(s1[i-1]=='W')    h1[i]=h1[i-1]-1,z1[i]=z1[i-1];
        if(s1[i-1]=='N')    h1[i]=h1[i-1],z1[i]=z1[i-1]+1;
        if(s1[i-1]=='S')    h1[i]=h1[i-1],z1[i]=z1[i-1]-1;
        if(s1[i-1]=='E')    h1[i]=h1[i-1]+1,z1[i]=z1[i-1];
    }
    for(int i=1;i<=m;i++){
        if(s2[i-1]=='W')    h2[i]=h2[i-1]-1,z2[i]=z2[i-1];
        if(s2[i-1]=='N')    h2[i]=h2[i-1],z2[i]=z2[i-1]+1;
        if(s2[i-1]=='S')    h2[i]=h2[i-1],z2[i]=z2[i-1]-1;
        if(s2[i-1]=='E')    h2[i]=h2[i-1]+1,z2[i]=z2[i-1];
    }    
}
int main(){
    scanf("%d%d",&n,&m);
    scanf("%d%d",&fx,&fy);
    scanf("%d%d",&bx,&by);
    scanf("%s",s1);
    scanf("%s",s2);
    pre();
    memset(f,0x7f,sizeof(f));
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            dis[i][j]=(h1[i]-h2[j])*(h1[i]-h2[j])+(z1[i]-z2[j])*(z1[i]-z2[j]);
    f[0][0]=0;
    for(int i=1;i<=m;i++)    f[0][i]=f[0][i-1]+dis[0][i];
    for(int i=1;i<=n;i++)    f[i][0]=f[i-1][0]+dis[i][0];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            f[i][j]=min(f[i-1][j],min(f[i-1][j-1],f[i][j-1]))+dis[i][j];
    cout<<f[n][m];
}
