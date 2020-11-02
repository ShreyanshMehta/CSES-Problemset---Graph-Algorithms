#include<bits/stdc++.h>
using namespace std;
 
#define   fi(a,b) for(int i=a;i<b;i++)
#define   fj(a,b) for(int j=a;j<b;j++)
#define   ff first
#define   ss second
#define   ll long long
#define   ld long double
#define   ull unsigned long long
#define   bp(x) __builtin_popcount(x)
#define   pr(x) for(auto it: x) cout<<it<<" "; cout<<endl;
#define   getMax(x) max_element(x.begin(),x.end())
#define   getMin(x) min_element(x.begin(),x.end())
#define   endl "\n"
typedef   vector<int> vi;
typedef   vector< pair<int,int> > vii;
typedef   vector<long long> vl;
typedef   pair<int,int> pii;
typedef   pair<ll,ll> pll;
typedef   vector< pair<ll,ll> > vll;
//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1};
//int dx[]={-1,0,1,1,1,0,-1,-1};
//int dy[]={-1,-1,-1,0,1,1,1,0};
 
vector<vll>adj;
 
void nikal_pehli_fursat_mai(){
    int n, m;
    cin>>n>>m;
    
    adj.assign(n+1, vll({}));
 
    fi(0, m){
        int u, v;
        cin>>u>>v;
        adj[u].push_back({v, -1});
    }
    
    vi parent(n+1, 0);
    priority_queue<pll, vll, greater<pll>>q;
    q.push({0, 1});
    vl dis(n+1, 1e18);
    dis[1] = 0;
 
    while(!q.empty()){
        ll u = q.top().ss;
        ll d = q.top().ff;
        q.pop();
        if(dis[u] < d) continue;
        for(auto it: adj[u]){
            if(dis[u] + it.ss < dis[it.ff]){
                dis[it.ff] = dis[u] + it.ss;
                parent[it.ff] = u;
                q.push({dis[it.ff], it.ff});
            }
        }
    }
 
    if(dis[n]==1e18){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    vi ans;
    for(auto it = n; it != 0; it = parent[it]){
        ans.push_back(it);
    }
    cout<<ans.size()<<endl;
    reverse(ans.begin(), ans.end());
    pr(ans);
}
 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc=1; 
    // cin>>tc;
    while(tc--){
        nikal_pehli_fursat_mai();
    }
}
