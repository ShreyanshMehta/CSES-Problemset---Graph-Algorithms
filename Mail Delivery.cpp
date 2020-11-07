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


struct eulerGraph{
    int n, m, odd = 0;
    vector<bool>vis;
    vector<set<int>>adj;
    vi ans;

    //n--Vertices   m--Edges
    eulerGraph(int n, int m){
        this->n = n;
        this->m = m;
        adj.assign(n, set<int>({}));
        vis.assign(n, 0);
    }

    void addEdge(int u, int v){
        adj[u].insert(v);
        adj[v].insert(u);
    }

    void findPath(int start_node){
        int node = start_node;
        stack<int>st;
        while(!st.empty() or adj[node].size()){
            if(adj[node].size()==0){
                ans.push_back(node);
                node = st.top();
                st.pop();
            }
            else{
                int u = *adj[node].begin();
                adj[node].erase(adj[node].begin());
                adj[u].erase(adj[u].find(node));
                st.push(node);
                node = u;
            }
        }
        if(odd==0)
            ans.push_back(start_node);
    }

    bool getAns(int start_node){
        fi(0, n){
            if(adj[i].size()%2) odd++;
        }
        findPath(start_node);
        if(ans.size()!=m+1 or odd>2) return 0;
        else return 1;
    }
};


void nikal_pehli_fursat_mai(){
    int n, m;
    cin>>n>>m;
    
    eulerGraph G(n, m);

    fi(0, m){
        int u, v;
        cin>>u>>v;
        u--; v--;
        G.addEdge(u, v);
    }

    if(G.getAns(0)){
        for(auto i: G.ans)
        cout<<i+1<<" ";
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
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
