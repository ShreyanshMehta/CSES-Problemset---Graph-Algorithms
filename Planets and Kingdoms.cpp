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

stack<int>order;
vector<bool>vis;
vi ans;
vector<vi>adj, Radj; //Adjacency list and its reverse
int sz = 0;

void dfs1(int node){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]) dfs1(it);
    }
    order.push(node);
}

void dfs2(int node){
    vis[node] = 0;
    for(auto it: Radj[node]){
        if(vis[it]) dfs2(it);
    }
    ans[node] = sz+1;
}

void init(int n){
    adj.assign(n+1, vi({}));
    Radj.assign(n+1, vi({}));
    vis.assign(n+1, 0);
    ans.assign(n, 0);
}

void nikal_pehli_fursat_mai(){
    int n, m;
    cin>>n>>m;
    
    init(n);

    fi(0, m){
        int u, v;
        cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        Radj[v].push_back(u);
    }

    fi(0, n){
        if(!vis[i]) dfs1(i);
    }

    while(!order.empty()){
        int node = order.top();
        order.pop();
        if(vis[node]) {
            dfs2(node);
            sz++;
        }
    }

    cout<<sz<<endl;
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
