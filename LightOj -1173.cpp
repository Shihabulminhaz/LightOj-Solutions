/*
 Problem name : 1173 - The Vindictive Coach
 Algorithm : DP
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 14-Nov-14
*/

#include<bits/stdc++.h>

#define pause           system("pause");
#define FOR(s,e,inc)    for(int i=s;i<=e;i+=inc)
#define mod             1LL<<63
#define inf             1<<30
#define pb              push_back
#define ppb             pop_back
#define mp              make_pair
#define F               first
#define S               second
#define sz(x)           ((int)x.size())
#define sqr(x)          ( (x)* (x) )
#define eps             1e-9
#define gcd(x,y)         __gcd(x,y)
#define lcm(x,y)        (x/gcd(x,y))*y
#define on(x,w)         x=x|(1<<w)
#define check(x,w)      (x&(1<<w))
#define all(x)          (x).begin(),(x).end()
#define pf              printf
#define pi              acos(-1.0)
#define reset(x,v)      memset(x,v,sizeof(x));
#define AND             &&
#define OR              ||

typedef long long ll;
typedef unsigned long long llu;

using namespace std;


template<class T>
inline T mod_v(T num)
{
    return num;
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
#  define p(x) 0;
#endif

/*...... ! Code start from here ! ......*/

llu dp[55][55][3];
int take[55][55][3];
int n,m,cc;

llu re(int left,int right,int od)
{//printf("%d %d %d\n",left,right,od);
    if(left+right==0) return 1;

    if(take[left][right][od]==cc) return dp[left][right][od];

    llu &r=dp[left][right][od];
    take[left][right][od]=cc;
    r=0;

    if(!od)
    {
        for(int i=1;i<=left;i++)
        {
            r+=re(i-1,right+left-i,1);
        }
    }
    else
    {
        for(int i=1;i<=right;i++)
        {
            r+=re(left+i-1,right-i,0);
        }
    }


    return r;
}


int main()
{

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
        freopen ( "out.txt", "w", stdout );
    #endif
    int t,tcase=1;
    cc=1;
    reset(dp,0);
    reset(take,0);

    t=in<int>();

    while(t--)
    {
        n=in<int>();
        m=in<int>();

        llu ans=0;

        if(n==1)
        {
            printf("Case %d: 1\n",tcase++);
            continue;
        }

        if(m==1)
        {
            for(int i=2;i<=n;i++)
            {
                ans=re(i-2,n-i,0);
                if(ans)
                    break;
            }
        }

        else
        {
            ans=re(m-1,n-m,0);
        }

        printf("Case %d: %llu\n",tcase++,ans);
        cc++;
    }

    return 0;
}
