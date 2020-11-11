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
    int n, odd = 0;
    vector<bool>vis;
    vector<set<int>>adj;
    vi ans;

    //n--Vertices   m--Edges
    eulerGraph(int n){
        this->n = n;
        adj.assign(n, set<int>({}));
        vis.assign(n, 0);
    }

    void addEdge(int u, int v){
        adj[u].insert(v);
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
        return 1;
    }
};

//In main function
// eulerGraph G(n, m)
// G.addEdges(u, v) to add edges
// getAns to process answer in ans of G

void nikal_pehli_fursat_mai(){
    int n;
    cin>>n;
    
    if(n==1){
        cout<<"01";
        return;
    }

    eulerGraph G(1<<n);
    for(int mask=0; mask<(1<<n); mask++){
        int u = (mask>>1);
        int v = mask & ((1<<n-1)-1);
        G.addEdge(u, v);
    }

    G.getAns(1);
    string s = "";
    fi(0, n-1) s += '0';
    fi(0, G.ans.size()-1) s += '0' + G.ans[i]%2;
    cout<<s<<endl;
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
