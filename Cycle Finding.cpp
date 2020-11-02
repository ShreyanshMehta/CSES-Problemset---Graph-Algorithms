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
    adj.assign(n, vll({}));
 
    fi(0, m){
        int u, v, w;
        cin>>u>>v>>w;
        u--; v--;
        adj[u].push_back({v, w});
    }
 
    int vertex = -1;
    vl dis(n, 1e18);
    vi parent(n);
    dis[0] = 0;
    fj(0, n){
        vertex = -1;
        fi(0, n){
            for(auto it: adj[i]){
                if(dis[it.ff]>dis[i]+it.ss) {
                    dis[it.ff] = dis[i] + it.ss;
                    parent[it.ff] = i;
                    vertex = it.ff;
                }
            }
        }
    }
    if(vertex==-1){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    fi(0, n) vertex = parent[vertex];
    vi cycle;
    for(int u = vertex; ; u = parent[u]){
        cycle.push_back(u+1);
        if(u==vertex and cycle.size()>1) break;
    }
    reverse(cycle.begin(), cycle.end());
    pr(cycle);
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
