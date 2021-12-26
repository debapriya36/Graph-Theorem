/*  
 * Example of a DFS based problem :  https://atcoder.jp/contests/abc233/tasks/abc233_c
 *
 *  Idea is to start dfs with pos_0 of first vec and currPro_1 , itertare over n vectors 
 * and takes vals if val*currPro<=x , and if pos==n && currPro==tgtPro , ans++.. 
 * 
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
#define mod 1000000007 
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

bool IsPalindrome(string &s)
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

SS intTobin(ll n)
{
    SS s="";
    while(n)
    {
        ll x=(n%2LL);
        s+=(x+'0');
        n>>=1LL;
    }
    reverse(all(s));
    return s;
}

ll dx[]={-1LL,0LL,1LL,0LL};
ll dy[]={0LL,1LL,0LL,-1LL};
SS tot="abcdefghijklmnopqrstuvwxyz";


 // ll N=2e5+10;



void precompute(){

}
ll n,x;
ll sx;


vector<vector<ll>>v;

ll c=0;

void dfs(ll pos,ll currPro)
{
   if(currPro>x)return;

  if(pos==n){
   if(currPro==x)c++;
   return;
  }
   for(auto &val : v[pos])
   {
       ll next=currPro*val;
       if(next>x)continue;
       dfs(pos+1,next);

   }

}



void Target1300(){



cin>>n>>x;



loop(i,n)
{
  ll s;
  cin>>s;
  vi p;
  loop(j,s)
  {
    ll y;
    cin>>y;
 //   if(st[y])
     p.pb(y);
  }

  v.pb(p);

}


ll currPro=1;
ll pos=0;
 c=0;


dfs(pos,currPro);


cout<<c;







}



signed main(){

 IOS;


 precompute();



 //  test(tc){

  //   cout<<fixed<<setprecision(10);

        Target1300();

   //   }

return 0;
}


