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
vi vis(N);
int n,m;

vi ans(N);

bool dfs(int node, int color){
    if(!vis[node]){
        bool r = 1;
        vis[node] = 1;
        ans[node] = color;
        for(auto it: adj[node]){
            r &= dfs(it, !color);
        }
        return r;
    }
    else{
        if(ans[node]!=color) return 0;
        else return 1;
    }
}


void nikal_pehli_fursat_mai(){
    cin>>n>>m;

    fi(0, m){
        int u, v;
        cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fi(0, n){
        if(!vis[i]){
            if(!dfs(i, 0)){
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
        }
    }
    fi(0, n){
        cout<<ans[i]+1<<" ";
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
