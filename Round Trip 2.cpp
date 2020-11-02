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
vi parent(N);
vi color(N);
 
int start_node=-1, end_node=-1;
 
bool dfs(int node,int pre){
    color[node] = 1;
    for(auto it: adj[node]){
        // if(it==pre) continue;
        if(color[it]==0){
            parent[it] = node;
            if(dfs(it, node)) return 1;
        }
        else if(color[it]==1){
            start_node = it;
            end_node = node;
            return 1;
        }
    }
    color[node] = 2;
    return 0;
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
        if(color[i]==0 and dfs(i, 0) and start_node!=-1){
            ans.push_back(start_node);
            for(int v = end_node; v != start_node; v = parent[v] ){
                ans.push_back(v);
            }
            ans.push_back(start_node);
            reverse(ans.begin(), ans.end());
            cout<<ans.size()<<endl;
            pr(ans);
            return;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
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
