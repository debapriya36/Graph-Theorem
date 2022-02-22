// Dijkstra Algorithm : 
// minimun dis from source node to other nodes .
// not work for -ve Cycle
const ll N=2e5;
vector<ll>dis(N,1e18);

void Dijkstra_PQ(ll source, ll n)
{
    
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;

    pq.push({0,source});
    dis[source]=0;

    while(pq.size())
    {
        auto node=pq.top();
        pq.pop();
        ll val=node.F;
        ll dis=node.S;

        for(auto it: adj[node])
        {
            ll wt=it.S;
            ll Node=it.F;
            if(dis[Node]>dis[node]+wt)
            {
                dis[Node]=dis[node]+wt;
                pq.push({dis[Node],Node});
            }
        }
    }

    for(ll i=0;i<n;i++)cout<<dis[i]<<" ";
    cout<<endl;


}
