/*
 *  Another BFS problem to find shortest path by knight[SSSP]
 *  same logic/ same code
 *  Problem Link ::     https://www.codechef.com/problems/PRGCUP01
 * 
 */

#include<algorithm>
#include<bits/stdc++.h>
#define ll long long 
#define dd long double
#define loop(i,ed) for(ll i=0;i<ed;i++)
#define rloop(i,ed) for(ll i=ed-1;i>=0;i--)
#define aloop(it,a) for(auto it:a)
#define test(tc) ll tc;cin>>tc;while(tc--)
#define IOS ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define vi vector<ll>
#define sz size()
#define setBits(n)  __builtin_popcountll(n)
#define mod 1000000007LL
#define yos cout<<"YES"<<endl
#define nos cout<<"NO"<<endl
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define tos to_string
#define sp " "
#define VP vector<pair<ll,ll>>
#define SS string
#define imax INT_MAX
#define imin INT_MIN
#define debug(a) cout<< #a <<" " << a<<endl;
#define lba(a,n,t) lower_bound(a,a+n,t)
#define lbv(v,t) lower_bound(all(v),t)
#define uba(a,n,t) upper_bound(a,a+n,t)
#define ubv(v,t) upper_bound(all(v),t)
#define endl "\n"
using namespace std;

// a->97  A->65 " "->32  
//  RUSH === WA on TC2

bool isPrime(ll  n)   
{
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

bool IsPalindrome(string s)
{
    SS t=s; reverse(all(t));
    return (s==t);
}

dd ipow(dd x, ll y)   // Negative Exponetiation
{ 
      dd temp; 
    if(y == 0) 
        return 1; 
    temp = ipow(x, y / 2); 
    if (y % 2 == 0) 
        return temp * temp; 
    else
    { 
        if(y > 0) 
            return x * temp * temp; 
        else
            return (temp * temp) / x; 
    } 
} 


ll binpow(ll a, ll b, ll  m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll XX[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
ll YY[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

ll dx[]={-1LL,0LL,1LL,0LL};
ll dy[]={0LL,1LL,0LL,-1LL};
SS tot="abcdefghijklmnopqrstuvwxyz";

     ll N=200005LL;

void precompute(){


}

 vector<ll>adj[200005LL];
 ll v[10][10];
 ll in[200005LL];
ll g[2021][2021];

ll KX[8]={2,2,-2,-2,1,1,-1,-1};
ll KY[8]={1,-1,1,-1,2,-2,2,-2};
ll n=8;


  ll bfs(ll& x1, ll& y1, ll& x2,ll& y2,ll steps)
  {
       
   queue<pair<pair<ll,ll>,ll>>Q;
   Q.push({{x1,y1},steps});


   while(Q.sz)
   {
       auto it=Q.front();
       Q.pop();
       ll fx=it.F.F,fy=it.F.S;
       ll dis=it.S;
       if(fx==x2 && fy==y2)
       {
          // cout<<dis<<endl;
           return dis;


       }
    
    if(fx<1 || fy<1 || fx>8 || fy>8 || v[fx][fy]==1)continue;

    v[fx][fy]++;

      loop(i,8)Q.push({{fx+KX[i],fy+KY[i]},dis+1});

   }
   return -69;

  }





 void G(){

  memset(g,0,sizeof g);
  SS a,b;
  cin>>a>>b;

  ll x1=a[0]-'a'+1;
  ll y1=a[1]-'0';
  ll x2=b[0]-'a'+1;
  ll y2=b[1]-'0';

loop(i,8)
{
    loop(j,8)v[i+1][j+1]=0;
}

  cout<<bfs(x1,y1,x2,y2,0)<<endl;




}




signed main(){
   IOS;

    precompute();

          test(tc){

      //  cout<<fixed<<setprecision(10);
 
      memset(v,0,sizeof v);

            G();
 
         }

return 0;

}

