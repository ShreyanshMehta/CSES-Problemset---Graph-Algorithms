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

struct DSU{

    vector<int> parent, siz;
    int components;

    DSU(int n){
        for(int i=0;i<n;++i){
            parent.push_back(i);
            siz.push_back(1);
        }
        components = n;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    int getSiz(int node){
        return siz[find_set(node)];
    }

    bool union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);

        if(a==b) return false;

        if(siz[a] > siz[b]) swap(a, b);
        parent[a] = b;
        siz[b] += siz[a]; 

        components--;
        return true;
    }
};

void nikal_pehli_fursat_mai(){
    int n, m;
    cin>>n>>m;

    vector<pair<ll, pll>>edges;

    fi(0, m){
        ll u, v, w;
        cin>>u>>v>>w;
        u--; v--;
        edges.push_back({w, {u, v}});
    }

    sort(edges.begin(), edges.end());
    ll ans = 0;
    DSU st(n);

    fi(0, edges.size()){
        if(st.union_sets(edges[i].ss.ff, edges[i].ss.ss)) 
            ans += edges[i].ff;
    }

    if(st.components!=1) cout<<"IMPOSSIBLE"<<endl;
    else cout<<ans<<endl;
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
