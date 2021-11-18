/*
 * BFS Problem : https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/jungle-run/
 * 
 * In bfs whenever asked for min steps /(...) , ans will always be the count of reaching the final state at first time....
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
 ll v[400][400];
 ll in[200005LL];
ll g[400][400];

ll steps;



ll brute_force_search(ll& n)
{
    queue<pair<pair<ll,ll>,ll>>Q;
    Q.push({{1,1},0});
    while(Q.sz)
    {
        auto it=Q.front();
        Q.pop();
        ll x=it.F.F;
        ll y=it.F.S;
         steps=it.S;
        if(g[x][y]==3)
        {
            return it.S;
        }

        if(x<1 || x>n || y<1 || y>n )continue;
        if(g[x][y]==0)continue;
        if(v[x][y])continue;
          v[x][y]++;

          loop(i,4)Q.push({{x+dx[i],y+dy[i]},steps+1});

    }

    return -1;

}

 void G(){

     memset(g,0,sizeof g);
     ll n;
     cin>>n;
     char c;

     for(ll i=1;i<=n;i++)
     {
         for(ll j=1;j<=n;j++)
         {
           cin>>c;
           if(c=='S')g[i][j]=1;    // start  
           else if(c=='P')g[i][j]=1;  // can push
           else if(c=='T')g[i][j]=0;  // cant go
           else if(c=='E') g[i][j]=3;
         }
     }

  cout<<brute_force_search(n);
}

signed main(){
   IOS;

    precompute();

      //       test(tc){

      //  cout<<fixed<<setprecision(10);
 
      memset(v,0,sizeof v);


            G();
 
       //     }

return 0;

}

