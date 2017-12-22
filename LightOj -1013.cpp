// Problem name : 1013 - Love Calculator
// Algorithm : LCS
// Contest/Practice : Off Line Practice
// Source : Light Oj
// Comment :
// Date : 9-Oct-14

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<assert.h>


#define pause system("pause")
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
#define check(x,w) (x&(1<<w))==(1<<w)?true:false
#define all(x) (x).begin(),(x).end()
#define pf printf

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
inline void memset1(vector<T>&v,int s,T value)
{
    for(int i=0;i<s;i++)
        v[i]=value;
}

template<class T>
inline void memset2(vector<vector<T> >&v,int s1,int s2,T value)
{
    for(int i=0;i<s1;i++)
        for(int j=0;j<s2;j++)
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

#ifndef ONLINE_JUDGE
#  define p(x) cout<<x<<endl;
#else if
#  define print(x) 0;
#endif

//.......Code start from here ! .......




string x,y;
ll len;
int dp1[35][35];
ll dp[35][35][65];

void clr()
{
    for(int i=0;i<35;i++)
        for(int j=0;j<35;j++)
                dp1[i][j]=-1;
    for(int i=0;i<35;i++)
        for(int j=0;j<35;j++)
            for(int k=0;k<65;k++)
                dp[i][j][k]=-1;
}

int re1(int p,int q)
{
    if(p>=sz(x) || q>=sz(y))
    {
        return 0;
    }

    if(dp1[p][q]!=-1) return dp1[p][q];

    int r=0;

    if(x[p]==y[q])
        r=1+re1(p+1,q+1);
    else
    {
        r=max(re1(p+1,q),re1(p,q+1) ) ;
    }
    return dp1[p][q]=r;
}


ll re(int p,int q,int count)
{
    if(p>=sz(x))
    {
        if(sz(y)-q+count==len)
            return 1;
        else return 0;
    }
    if(q>=sz(y))
    {
        if(sz(x)-p+count==len)
            return 1;
        else return 0;
    }
    if(dp[p][q][count]!=-1) return dp[p][q][count];

    ll r=0;

    if(x[p]==y[q])
        r=re(p+1,q+1,count+1);
    else
    {
        r+=re(p+1,q,count+1);
        r+=re(p,q+1,count+1);
    }

    return dp[p][q][count]=r;
}

int main()
{
    int t,tcase=1;
    scanf("%d",&t);
    while(t--)
    {
        cin>>x>>y;
        clr();
        len=(ll) sz(x)+ (ll)sz(y)-(ll) re1(0,0);
        printf("Case %d: %lld %lld\n",tcase++,len,re(0,0,0));
    }
    return 0;
}

