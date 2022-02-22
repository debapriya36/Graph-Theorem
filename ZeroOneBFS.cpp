// 0 1 BFS 
// minimum possibe dist source node to all other node from
// queue will take more time than deque , deque also maintain sorted way 
const ll N=2e5;
vector<ll>dis(N,1e18);

void ZObfs(ll source, ll n)
{
    deque<par<ll,ll>>dp;

    dq.push_front({source,0});
    dis[source]=0;

    while(dq.sz)
    {
        auto node=dp.front();
        dp.pop_front();
        ll val=node.F;
        ll dis=node.S;

        for(auto it: adj[node])
        {
            ll wt=it.S;
            ll Node=it.F;
            if(dis[Node]>dis[node]+wt)
            {
                dis[Node]=dis[node]+wt;
                if(wt==0)dq.push_front({Node,dis[Node]});
                else dq.push_back({Node,dis[Node]});
            }
        }
    }

    for(ll i=0;i<n;i++)cout<<dis[i]<<" ";
    cout<<endl;
    

}
