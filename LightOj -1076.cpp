// Problem name : 1076 - Get the Containers
// Algorithm : Binary Search
// Contest/Practice : Off Line Practice
// Source : Light Oj
// Comment : Whenever you start to believe  yourself, people also start to believe in you
// Date : 14-Oct-14

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

int v[1005];
int n,m,mx,c,sum;
int l,r;

inline void input()
{
    scanf("%d%d",&n,&m);
    l=r=0;
    mx=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
        r+=v[i];
        mx=max(mx,v[i]);
    }
}

inline int bi_search()
{
    int mid;
    while(l<r)
    {
        mid=(l+r)>>1;
        c=sum=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]>mid)
            {
                c+=1<<28;
                break;
            }
            else if(sum+v[i]>mid)
            {
                c++;
                sum=v[i];
            }
            else
                sum+=v[i];
        }
        if(sum>0)
            c++;
        if(c<=m)
            r=mid;
        else
            l=mid+1;
    }
    return r;
}

int main()
{
    int t,tcase=1;
    scanf("%d",&t);

    while(t--)
    {

        input();
        printf("Case %d: ",tcase++);
        if(m>=n)
            printf("%d\n",mx);
        else
        {
            printf("%d\n",bi_search());
        }
    }

    return 0;
}

