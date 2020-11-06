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
vi comp_id;
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
    comp_id[node] = sz+1;
}

void init(int n){
    adj.assign(n, vi({}));
    Radj.assign(n, vi({}));
    vis.assign(n, 0);
    comp_id.assign(n, 0);
}

void nikal_pehli_fursat_mai(){
    int n, m;
    cin>>n>>m;
    
    init(2*m);

    fi(0, n){
        char c1, c2;
        int u, v;
        cin>>c1>>u>>c2>>v;
        u--; v--;
        u = u<<1;
        v = v<<1;
        if(c1=='-') u ^= 1;
        if(c2=='-') v ^= 1;
        adj[u^1].push_back(v);
        adj[v^1].push_back(u);
        Radj[v].push_back(u^1);
        Radj[u].push_back(v^1);
    }

    fi(0, 2*m){
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

    vector<char>ans(m);
    for(int i=0;i<m;i++){
        if(comp_id[(i<<1)]==comp_id[(i<<1)+1]){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
        ans[i] = comp_id[(i<<1)] > comp_id[(i<<1)+1] ? '+' : '-';
    }
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
