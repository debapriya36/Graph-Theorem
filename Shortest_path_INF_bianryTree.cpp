// https://www.codechef.com/problems/BINTREE
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

ll inverseMod(ll a,ll p)
{
    return binpow(a,p-2,p);
}

ll dx[]={-1LL,0LL,1LL,0LL};
ll dy[]={0LL,1LL,0LL,-1LL};
SS tot="abcdefghijklmnopqrstuvwxyz";


void precompute(){

   




}

  //  const ll N=6e5;


/*


Node 10 in binary is 1010, here first 1 is root node, next is 0, means a left turn, next 1 means are right child, next 0 means a left child.
We convert i,j to base 2 (without leading zeroes)
Let i in base 2 be = a1a2…an
Let j in base 2 be = b1b2…bm
If ap=bp for all p<=k, means their Lowest Common Ancestor(LCA) in binary is a0a1…ak. So the distance between i and j is dist(i,LCA(i,j))+dist(j,LCA(i,j)).
Since i in base 2 has n digits, the distance between i and LCA(i,j) will be (n-k). Since those are the extra steps taken from LCA moving towards node.
Therefore our answer is (n-k)+(m-k).



*/
void Target1100(){


  ll l,r;
  cin>>l>>r;

  ll c=0;
  while(l!=r)
  {
      if(l>r)c++,l/=2;
      if(r>l)c++,r/=2;

  }

cout<<c<<endl;








 }



signed main(){

 IOS;


 precompute();



     test(tc){

  //   cout<<fixed<<setprecision(10);

        Target1100();
  


      }

return 0;
}


