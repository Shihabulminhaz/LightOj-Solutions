/*
 Problem name : 1228 - e-Friends
 Algorithm : Bitmask DP
 Contest/Practice : Off Line Pracice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 02-Nov-14
*/

#include<bits/stdc++.h>

#define pause system("pause");
#define FOR(s,e,inc) for(int i=s;i<=e;i+=inc)
#define mod 1000000007
#define inf 1<<30
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define sz(x) ((int)x.size())
#define sqr(x) ( (x)* (x) )
#define eps 1e-9
#define gcd(x,y) __gcd(x,y)
#define on(x,w)  x=x|(1<<w)
#define check(x,w) (x&(1<<w))
#define all(x) (x).begin(),(x).end()
#define pf printf
#define reset(x,v) memset(x,v,sizeof(x));
#define AND &&
#define OR ||

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


template<class T>
inline T mod_v(T num)
{
    if(num>=0)
        return num%mod;
    else
        return (num%mod+mod)%mod;
}

template<class T>
inline void memset1(vector<T>&v,T value)
{
    for(int i=0;i<sz(v);i++)
        v[i]=value;
}

template<class T>
inline void memset2(vector<vector<T> >&v,T value)
{
    for(int i=0;i<sz(v) ;i++)
        for(int j=0;j<sz(v[i]);j++)
            v[i][j]=value;
}


template<class T>
T fast_pow(T n , T p)
{
    if(p==0) return 1;
    if(p%2)
    {
        T g=mod_v ( mod_v(n) * mod_v(fast_pow(n,p-1)) );
        return g;
    }
    else
    {
        T g=fast_pow(n,p/2);
        g=mod_v( mod_v(g) * mod_v(g) ) ;
        return g;
    }
}

template<class T>
inline T modInverse(T n)
{
    return fast_pow(n,mod-2);
}

template<class T>
inline void debug(string S1,T S2,string S3)
{
    cout<<S1<<S2<<S3;
}

template<class T>
inline T in()
{
    register char c=0;
    register T num=0;
    bool n=false;
    while(c<33)c=getchar();
    while(c>33){
        if(c=='-')
            n=true;
        else num=num*10+c-'0';
        c=getchar();
    }
    return n?-num:num;
}

#ifndef ONLINE_JUDGE
#  define p(x) cout<<x<<endl;
#else if
#  define print(x) 0;
#endif

//.......Code start from here ! ......

int n,k,p,r,num,m;
int enemy[12][12];

int dp[1<<12][12][12];
int ans[13];

inline void input()
{
    for(int i=0;i<n;i++)
    {
        m=in<int>();

        for(int j=0;j<m;j++)
        {
            num=in<int>();
            enemy[num-1][i]=1;
        }
    }
}

int re(int mask,int dis,int prv)
{
    //printf("%d %d %d %d\n",mask,dis,prv,1<<n-1);
    if((dis*k)>r) return 0;
    if(mask==(1<<n)-1)
    {
        return 1;
    }

    int &r=dp[mask][dis][prv];

    if(r!=-1) return r;

    r=0;

    if(mask==0)
    {
        for(int i=0;i<n;i++)
        {
            int smpl=mask;
            if(!check(smpl,i))
            {//printf("Hi\n");
                r+=re(on(smpl,i),0,i);
            }
        }
    }

    else
    {
        for(int i=0;i<n;i++)
        {
            int smpl=mask;
            if(!check(smpl,i))
            {
                r+=re(on(smpl,i),dis+enemy[prv][i],i);
            }
        }
    }

    return r;
}



int main()
{
    int t,tcase=1;

    t=in<int>();

    while(t--)
    {
        n=in<int>();
        k=in<int>();
        p=in<int>();

        reset(enemy,0);

        input();

        for(int i=0;i<=n;i++)
        {
            r=k*i;

            reset(dp,-1);
            ans[i]=re(0,0,0);

        }

        printf("Case %d:\n",tcase++);

        for(int i=0;i<p;i++)
        {
            num=in<int>();

            if(k==0)
                r=n;
            else
                r=num/k;

            if(r>n)
                r=n;

            printf("%d\n",ans[r]);
        }

    }

    return 0;
}

