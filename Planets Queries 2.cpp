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

int mxH = 20;

vector<vi>adj;
vector<vi>binLift;
vector<set<int>>par;
vi parent, color, cycle_id, cycle_pos, in, out;
int start_node, end_node;
vector<bool> visited;
map<int,int>sz;
vector<int> topo;
int id = 0, tym = 0;

void dfs1(int node, int p){
    in[node] = ++tym;
    visited[node] = 1;
    binLift[0][node] = p;
    for(int i=1;i<=mxH;i++){
        if(binLift[i-1][node]!=-1){
            binLift[i][node] = binLift[i-1][binLift[i-1][node]];
        }
    }
    for(auto it: par[node]) dfs1(it, node);
    out[node] = ++tym;
}

bool dfs(int v) {
    color[v] = 1;
    bool r = 0;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u)){
                r = 1;
                break;
            }
        } 
        else if (color[u] == 1) {
            end_node = v;
            start_node = u;
            r = 1;
            break;
        }
    }
    color[v] = 2;
    return r;
}

void inti(int n){
    start_node = -1, end_node = -1;
    adj.assign(n+1, vi{});
    parent.assign(n+1, -1);
    color.assign(n+1, 0);
    cycle_id.assign(n+1, -1);
    cycle_pos.assign(n+1, -1);
    par.assign(n+1, set<int>{});
    in.assign(n+1, 0);
    out.assign(n+1, 0);
    binLift.assign(mxH+1, vi(n+1, -1));
    visited.assign(n+1, false);
    topo.clear();
}

void getCycle(int n){
    fi(1, n+1){
        if(color[i]==0 and dfs(i) and start_node!=-1){
            vi ans;
            ans.push_back(start_node);
            for(int v = end_node; v != start_node; v = parent[v] ){
                ans.push_back(v);
            }
            reverse(ans.begin(), ans.end());
            fj(0, ans.size()){
                cycle_id[ans[j]] = id;
                cycle_pos[ans[j]] = j;
                par[ans[j]].erase(par[ans[j]].find(ans[(j-1+ans.size())%ans.size()]));
            }
            sz[id++] = ans.size();
            id++;
            start_node = -1;
            end_node = -1;
        }
    }    
}

void dfs2(int v) {
    visited[v] = true;
    for (int u : par[v]) {
        if (!visited[u])
            dfs2(u);
    }
    topo.push_back(v);
}

void topological_sort(int n) {
    for (int i = 1; i < n+1; ++i) {
        if (!visited[i])
            dfs2(i);
    }
    reverse(topo.begin(),topo.end());
}


bool isAncestor(int u, int v){
    return in[u]<=in[v] and out[u]>=out[v];
}


void nikal_pehli_fursat_mai(){
    int n, q;
    cin>>n>>q;
    
    inti(n);
    vi v(n+1);

    fi(1, n+1){
        cin>>v[i];
        adj[i].push_back(v[i]);
        par[v[i]].insert(i);
    }

    getCycle(n);

    // pr(cycle_pos);

    topological_sort(n);

    for(auto i: topo){
        if(!in[i]) dfs1(i, -1);
    }
    // pr(in);
    // pr(out);

    // fi(1, n+1){
    //     cout<<i<<endl;
    //     fj(0, 3) cout<<binLift[j][i]<<" ";
    //     cout<<endl;
    // }
    
    while(q--){
        int u, v;
        cin>>u>>v;
        if(u==v) cout<<0<<endl;
        else if(cycle_id[u]!=-1) {
            if(cycle_id[u]!=cycle_id[v]) cout<<-1<<endl;
            else cout<<(sz[cycle_id[u]] + cycle_pos[v] - cycle_pos[u])%sz[cycle_id[u]]<<endl;
        }
        else if(isAncestor(v, u)){
            ll jump=0;
            for(int i=mxH;i>=0;i--){
                if(binLift[i][u]!=-1 and !isAncestor(binLift[i][u], v)) { 
                    u = binLift[i][u]; 
                    jump += (1LL<<i); 
                }
            }   
            cout<<jump+1<<endl;
        }
        else{
            ll jump = 0;
            for(int i=mxH;i>=0;i--){
                if(binLift[i][u]!=-1) { 
                    u = binLift[i][u]; 
                    jump += (1LL<<i); 
                }
            }
            if(cycle_id[u]==cycle_id[v]){
                cout<<jump + (sz[cycle_id[u]] + cycle_pos[v] - cycle_pos[u])%sz[cycle_id[u]]<<endl;
            }
            else cout<<-1<<endl;
        }
    }

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
