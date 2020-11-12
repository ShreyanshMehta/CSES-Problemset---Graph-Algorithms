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

const int MOD=1e9+7;

vector<vi>adj;
ll cache[1<<20][20];
int n, m;

ll dfs(int node, int mask){
    if(node==n-1 and __builtin_popcount(mask)==n)
        return 1;
    else if(node==n-1)
        return 0;
    if(cache[mask][node]!=-1) 
        return cache[mask][node];

    cache[mask][node] = 0;
    for(auto i: adj[node]){
        if( (mask>>i)&1LL ) continue;
        cache[mask][node] += dfs(i, mask|(1<<i));
        cache[mask][node] %= MOD;
    }
    return cache[mask][node];
}

void nikal_pehli_fursat_mai(){
    cin>>n>>m;

    adj.assign(n, vi({}));

    fi(0, m){
        int u, v;
        cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
    }

    memset(cache, -1, sizeof(cache));
    cout<<dfs(0, 1<<0)<<endl;
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
