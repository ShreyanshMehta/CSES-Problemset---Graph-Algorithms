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

const int N = 1e5+10;
vi adj[N];
vi color(N);
 
//Checking cycles
bool dfs(int node,int pre){
    color[node] = 1;
    for(auto it: adj[node]){
        if(color[it]==0){
            if(dfs(it, node)) return 1;
        }
        else if(color[it]==1) return 1;
    }
    color[node] = 2;
    return 0;
}

vector<bool> visited;
vector<int> topo;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    topo.push_back(v);
}

void topological_sort(int n) {
    visited.assign(n, false);
    topo.clear();
    for (int i = 1; i < n+1; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(topo.begin(),topo.end());
}

 
void nikal_pehli_fursat_mai(){
    int n, m;
    cin>>n>>m;
    fi(0, m){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vi ans;
 
    fi(1, n+1){
        if(color[i]==0 and dfs(i, 0)){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
    }

    topological_sort(n);
    pr(topo);
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
