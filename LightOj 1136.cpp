// Problem name : 1136 - Division by 3
// Algorithm : Counting
// Contest/Practice : Off Line Practice
// Source : Light Oj
// Comment : Whenever you start to believe  yourself, people also start to believe in you
// Date : 13-Oct-14

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
#define check(x,w) (x&(1<<w))==(1<<w)?true:false
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

#ifndef ONLINE_JUDGE
#  define p(x) cout<<x<<endl;
#else if
#  define print(x) 0;
#endif

//.......Code start from here ! ......

inline ll c(ll n)
{
    ll count=0;

    while(n>0)
    {
        count+=(n%10);
        n/=10;
    }
    return count%3;
}

int main()
{
    int t,tcase=1;
    ll n,m,a,b,count;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%lld %lld",&a,&b);

        count=((b-a+1)/3)*2;
        n=c(a);
        m=c(b);

        //printf("%lld %lld %lld\n",n,m,count);
        if(n==0)
        {
            if( (m==0 || m==1) && (b-a+1)%3!=0 )
                count++;

        }

        else if(n==1)
        {
            if(m==2 && (b-a+1)%3!=0)
                count++;
        }

        else if(n==2)
        {
            if(m==2 && (b-a+1)%3!=0)
                count++;
            else if(m==0 && (b-a+1)%3!=0)
                count+=2;
        }

        printf("Case %d: %lld\n",tcase++,count);
    }
    return 0;
}

