/***   Effective code for finding diameter of tree</>
    Pick any vertex as a source vertex.
    Then find the distant of each vertex from the source. It can find using DFS and keeping the distance count for each vertex from the source.
    Pick the vertex with maximum distance, and repeat step 2.
    Distance between the source and the the most distant vertex from the source is diameter.

 */ 

#include<algorithm>
#include<bits/stdc++.h>
#define ll long long 
#define dd long double
#define loop(i,ed) for(ll i=0;i<ed;i++)
#define rloop(i,ed) for(ll i=ed-1;i>=0;i--)
#define aloop(it,a) for(auto &it:a)
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
#define debug(a) cout<< #a <<" -> " << a<<endl;
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


void precompute(){

}


  // const  ll N=2e5;


ll XX[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
ll YY[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

ll dx[]={-1LL,0LL,1LL,0LL};
ll dy[]={0LL,1LL,0LL,-1LL};
SS tot="abcdefghijklmnopqrstuvwxyz";

  vector<ll>adj[200005LL];
  vector<ll>trans[200005LL];

 ll v[200005LL];
 ll in[200005LL];
 ll out[200005LL];
 ll par[200005LL];
 ll dis[200005LL];
 ll col[2];
 vi ans;
stack<ll>st;




void dfs(ll node,ll c)
{
    v[node]++;
    dis[node]=c;

    for(auto &i: adj[node])
    {
        if(!v[i])
        {
            dfs(i,c+1);
        }
    }

}






 void G(){


ll n,k;
cin>>n>>k;

loop(i,n-1)
{
    ll l,r;
    cin>>l>>r;
    adj[l].pb(r);
    adj[r].pb(l);
}


dfs(1LL,0LL);

ll nax=imin,pos=-1;

loop(i,n)
{
    ll x=dis[i+1];
    if(x>nax)
    {
        nax=x;
        pos=i+1;
    }
}


memset(v,0,sizeof v);
memset(dis,-1,sizeof dis);

dfs(pos,0LL);



nax=0;

loop(i,n)
{
    nax=max(nax,dis[i+1]);
}

if(nax>k)cout<<nax-k;
else cout<<0;




  




 }


signed main(){
   IOS;

    precompute();

  //   test(tc){
          

      //  cout<<fixed<<setprecision(10);
      memset(v,0,sizeof v);
      memset(dis,-1,sizeof dis);

   //   memset(out,0,sizeof out);
    //  memset(in,0,sizeof in);
   //   memset(par,-1,sizeof par);
   //   memset(col,0,sizeof col);

            G();

 
  //   }

return 0;

}

