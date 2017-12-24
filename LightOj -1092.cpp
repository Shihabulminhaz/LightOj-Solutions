/*
 Problem name : 1092 - Lighted Panels
 Algorithm : Broken Profile DP
 Contest/Practice : Off Line Practice
 Source : Light OJ
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 23-Apr-15
 Last Update : 25-Mar-2015
*/

/*
"
        আমি অনেক কষ্টে আছি
                                --- আবুল হাসান
        আমার এখন নিজের কাছে নিজের ছায়া খারাপ লাগে
        রাত্রিবেলা ট্রেনের বাঁশি শুনতে আমার খারাপ লাগে
        জামার বোতাম আটকাতে
        অমন কেন যত্ন করে লাগিয়ে দিতে?
        অমন কেন শরীর থেকে
        আস্তে আমার ক্লান্তিগুলো উঠিয়ে নিতে?
        তোমার বুকের নিশিথ কুসুম
        আমার মুখে ছড়িয়ে দিতে?
        জুতোর ফিতে প্রজাপতির মতন তুমি উড়িয়ে নিতে?
        বেলজিয়ামের আয়নাখানি কেন তুমি ঘরে না রেখে
        অমন কারুকাজের সাথে তোমার দুটি চোখের মধ্যে রেখে দিতে?
        রেখে দিতে?
        আমার এখন চাঁদ দেখতে খারাপ লাগে
        পাখির জুলুম, মেঘের জুলুম, খারাপ লাগে
        কথাবার্তায় দয়ালু আর পোশাকে বেশ ভদ্র মানুষ
        খারাপ লাগে,
        এই যে মানুষ মুখে একটা মনে একটা
        খারাপ লাগে
        খারাপ লাগে
        মোটের উপর আমি এখন কষ্টে আছি,
        কষ্টে আছি বুঝলে যুথী
        আমার দাঁতে আমার নাকে, আমার চোখে কষ্ট ভীষণ
        চতুর্দিকে দাবী আদায় করার
        মতো মিছিল তাদের কষ্ট ভীষণ
        বুঝলে যুথী,
        হাসি খুশী উড়নচন্ডী মানুষ
        আমার তাইতো এখন খারাপ লাগে
        খারাপ লাগে
        আর তাছাড়া আমি কি আর যীশু না হাবিজাবি
        ওদের মতো সব সহিষ্ণু?
        আমি অনেক
        কষ্টে আছি কষ্টে আছি কষ্টে আছি ।।
*/

#include<bits/stdc++.h>

#define pause           system("pause");
#define FOR(s,e,inc)    for(int i=s;i<=e;i+=inc)
#define mod             1000000007
#define inf             1<<30
#define pb              push_back
#define ppb             pop_back
#define mp              make_pair
#define F               first
#define S               second
#define sz(x)           ((int)x.size())
#define sqr(x)          ( (x)* (x) )
#define eps             1e-9
#define lcm(x,y)        (abs(x) /gcd(x,y))* abs(y)
#define on(x,w)         x|(1<<w)
#define check(x,w)      (x&(1<<w))
#define all(x)          (x).begin(),(x).end()
#define pf              printf
#define pi              acos(-1.0)
#define reset(x,v)      memset(x,v,sizeof(x));
#define AND             &&
#define OR              ||
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";

typedef long long ll;
typedef unsigned long long llu;

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
inline T gcd(T a,T b)
{
    a=abs(a);
    b=abs(b);

    while(b)
    {
        a=a%b;
        swap(a,b);
    }

    return a;
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

bool equalTo ( double a, double b ){ if ( fabs ( a - b ) <= eps ) return true; else return false; }
bool notEqual ( double a, double b ){if ( fabs ( a - b ) > eps ) return true; else return false; }
bool lessThan ( double a, double b ){ if ( a + eps < b ) return true; else return false; }
bool lessThanEqual ( double a, double b ){if ( a < b + eps ) return true;   else return false;}
bool greaterThan ( double a, double b ){if ( a > b + eps ) return true;else return false;}
bool greaterThanEqual ( double a, double b ){if ( a + eps > b ) return true;else return false;}


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

/******* ! Code start from here ! *******/

int kp[10];
int dp[10][260][260];
int r,c;
int x[]={1,0,-1,0,1,1,-1,-1};
int y[]={0,1,0,-1,1,-1,-1,1};

int re(int p,int nw,int prv)
{
    //printf("%d %d %d\n",p,nw,prv);

    if(p==r)
    {
        if(prv==(1<<c)-1)
            return 0;
        return inf;
    }

    if(dp[p][nw][prv]!=-1) return dp[p][nw][prv];

    dp[p][nw][prv]=inf;

    for(int i=0;i<(1<<c);i++)
    {
        int nxt=kp[p+1],now=nw,pvr=prv;
        int ct=0;
        for(int j=0;j<c;j++)
        {
            if(check(i,j))
            {
                ct++;

                now=now^(1<<j);

                for(int k=0;k<8;k++)
                {
                    int ax=p+x[k],bx=j+y[k];

                    if(ax<0 || ax>=r || bx<0 || bx>=c) continue;

                    if(x[k]==0)
                    {
                        now=now^(1<<bx);
                    }
                    else if(x[k]==-1)
                    {
                        pvr=pvr^(1<<bx);
                    }
                    else
                        nxt=nxt^(1<<bx);
                }
            }
        }
        if(p==0 || pvr==(1<<c)-1)
            dp[p][nw][prv]=min(dp[p][nw][prv],ct+re(p+1,nxt,now) );
    }

    return dp[p][nw][prv];
}


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t=in<int>(),tcase=1;

    while(t--)
    {
        r=in<int>();
        c=in<int>();

        char ch;

        reset(dp,-1);

        for(int i=0;i<r;i++)
        {
            kp[i]=0;
            for(int j=0;j<c;j++)
            {
                scanf(" %c",&ch);

                if(ch=='*')
                    kp[i]=kp[i]|(1<<j);
            }
        }

        printf("Case %d: ",tcase++);

        int res=re(0,kp[0],0);

        if(res>= inf)
            printf("impossible\n");
        else
            printf("%d\n",res);
    }

    return 0;
}

