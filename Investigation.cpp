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

long long power(long long x, long long y) {
    long long res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1)
            res = (res*x) % MOD;
        y = y>>1;
        x = (x*x) % MOD;
    }
    return res;
}

long long modInverse(ll x){
  return power(x, MOD-2);
}

long long modAdd(long long a, long long b){
  return (a%MOD + b%MOD + 2*MOD)%MOD;
}

long long modMult(long long a,long long b){
  return (a%MOD * b%MOD) % MOD;
}

long long modDiv(long long a,long long b){
  return (a%MOD * modInverse(b)) % MOD;
}

struct node{
    ll dis = 1e18;
    ll ways = 0;
    int mx = 0;
    int mi = 0;
};

const int N = 1e5+10;

vii adj[N];
vector<node>ans(N);
vector<bool>vis(N);

void nikal_pehli_fursat_mai(){
    int n, m;
    cin>>n>>m;

    fi(0, m){
        int u, v, w;
        cin>>u>>v>>w;
        u--; v--;
        adj[u].push_back({v, w});
    }

    ans[0].ways = 1;
    ans[0].mx = ans[0].mi = ans[0].dis = 0;

    priority_queue<pll, vll, greater<pll>>q;
    q.push({0, 0});

    while(!q.empty()){
        int u = q.top().ss;
        q.pop();

        if(vis[u]) continue;
        vis[u] = 1;

        for(auto it: adj[u]){
            if(ans[it.ff].dis > ans[u].dis + it.ss){
                ans[it.ff].dis = ans[u].dis + it.ss;
                ans[it.ff].ways = ans[u].ways;
                ans[it.ff].mx = ans[u].mx + 1;
                ans[it.ff].mi = ans[u].mi + 1;

                q.push({ans[it.ff].dis, it.ff});
            }
            else if(ans[it.ff].dis == ans[u].dis + it.ss){
                ans[it.ff].ways = modAdd(ans[u].ways, ans[it.ff].ways);
                ans[it.ff].mx = max(ans[it.ff].mx, ans[u].mx + 1);
                ans[it.ff].mi = min(ans[it.ff].mi, ans[u].mi + 1);

                q.push({ans[it.ff].dis, it.ff});
            }
        }
    }

    cout<<ans[n-1].dis<<" "<<ans[n-1].ways<<" "<<ans[n-1].mi<<" "<<ans[n-1].mx<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc=1;
    // cin>>tc;
    while(tc--){
    nikal_pehli_fursat_mai();
    }
}
