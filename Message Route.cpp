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
int dis[N];
int n,m;

void bfs(){
    fi(1, n) dis[i] = 1e9;
    vector<bool>vis(n, 0);
    priority_queue<pii>q;
    q.push({0, 0});

    while(!q.empty()){
        int d = abs(q.top().ff);
        int to = q.top().ss;
        q.pop();
        if(vis[to]) continue;
        vis[to] = 1;

        for(auto it: adj[to]){
            if(d+1<dis[it]){
                dis[it] = d+1;
                q.push({-dis[it], it});
            }
        } 
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
    bfs();
    vi ans;
    if(dis[n-1]==1e9){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    int temp = n-1;
    while(temp!=0){
        ans.push_back(temp+1);
        for(auto it: adj[temp]){
            if(dis[it]==dis[temp]-1){
                temp = it;
                break;
            }
        }
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
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
