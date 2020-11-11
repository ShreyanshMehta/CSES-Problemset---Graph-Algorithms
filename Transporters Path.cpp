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
    vi ans, in, out;

    //n--Vertices   m--Edges
    eulerGraph(int n, int m){
        this->n = n;
        this->m = m;
        adj.assign(n, set<int>({}));
        vis.assign(n, 0);
        in.assign(n, 0);
        out.assign(n, 0);
    }

    void addEdge(int u, int v){
        adj[u].insert(v);
        in[v]++;
        out[u]++;
    }

    void findPath(int start_node){
        int node = start_node;
        stack<int>st;
        while(!st.empty() or adj[node].size()){
            if(adj[node].size()==0){
                ans.push_back(node+1);
                node = st.top();
                st.pop();
            }
            else{
                int u = *adj[node].begin();
                adj[node].erase(adj[node].begin());
                st.push(node);
                node = u;
            }
        }
    }

    bool getAns(){
        fi(0, n){
            if(i==0){
                if(in[i]+1!=out[i]) return 0;
            }
            else if(i==n-1){
                if(out[i]+1!=in[i]) return 0;
            }
            else{
                if(out[i]!=in[i]) return 0;
            }
        }
        findPath(0);
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        if(ans.size()!=m+1) return 0;
        return 1;
    }
};

//In main function
// eulerGraph G(n, m)
// G.addEdges(u, v) to add edges
// getAns to process answer in ans of G

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

    if(!G.getAns()) 
        cout<<"IMPOSSIBLE"<<endl;
    else {
        pr(G.ans);
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
