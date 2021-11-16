/*
 * TopoSort in lexiographically minimum order if possible .
 *
 * if number of nodes is not equal to TopoS.size() , then there exist a cycle , so topoSort is not possible
 * 
 * Using min heap we can from lexiographically minumun topoSort array
 * 
 * problem Link :: https://www.spoj.com/problems/TOPOSORT/
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

ll dx[]={-1LL,0LL,1LL,0LL};
ll dy[]={0LL,1LL,0LL,-1LL};


     ll N=200005LL;

void precompute(){


}



vector<ll>adj[200005LL];
ll v[200005LL];
 ll dis[200005LL];
 ll cc[200005LL];
ll intime[200005LL];
ll lowtime[200005LL];
ll ind[200005LL];
vi topoS;
vector<pair<ll,ll>>ans;
 
ll cc_sz=0;
ll timer=0;
bool f=true;



void khan(ll &n)
{
    //  min heap .............................
   priority_queue<ll,vector<ll>,greater<ll>>q;

    loop(i,n)
    {
        if(!ind[i+1])q.push(i+1);
    }

    while(q.sz)
    {
        ll node=q.top();  // for PQ  .top to get topmost element
        q.pop();
        topoS.pb(node);
        for(auto it:adj[node])
        {
            ind[it]--;
            if(ind[it]<=0)q.push(it);
        }
    }


}


 void G(){

   
//TopoSort is applicable only for directed acyclic graph(DAG)

   ll n,m;
   cin>>n>>m;
   loop(i,m)
   {
       ll l,r;
       cin>>l>>r;
       adj[l].pb(r);
       ind[r]++;
   }

   topoS.clear();

   khan(n);

   if(topoS.sz==n)
   {
  //     cout<<"Lexiographically smallest possible TopoSort : \n";

       aloop(i,topoS)cout<<i<<sp;
       return;
   }
   cout<<"Sandro fails.\n";


}

signed main(){
   IOS;
 
    precompute();

    //         test(tc){

      //  cout<<fixed<<setprecision(10);
     memset(dis,0,sizeof(dis));
      memset(v,0,sizeof v);
     memset(intime,0,sizeof intime);
     memset(lowtime,0,sizeof lowtime);
      timer=0;

            G();
 
      //       }

return 0;

}



