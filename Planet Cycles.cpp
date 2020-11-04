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

vector<vi>adj, Radj;
vi parent, color, ans;
int start_node, end_node;

void dfs1(int node, int cur_depth){
    ans[node] = cur_depth;
    for(auto it: Radj[node]){
        if(!ans[it]) {
            dfs1(it, cur_depth+1);
        }
    }
}


bool dfs(int v) {
    color[v] = 1;
    bool r = 0;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u)){
                r = 1;
                break;
            }
        } 
        else if (color[u] == 1) {
            end_node = v;
            start_node = u;
            r = 1;
            break;
        }
    }
    color[v] = 2;
    return r;
}

void inti(int n){
    start_node = -1, end_node = -1;
    adj.assign(n+1, vi{});
    Radj.assign(n+1, vi({}));
    parent.assign(n+1, -1);
    color.assign(n+1, 0);
    ans.assign(n+1, 0);
}

void getCycle(int n){
    fi(1, n+1){
        if(color[i]==0 and dfs(i) and start_node!=-1){
            vi temp;
            temp.push_back(start_node);
            for(int v = end_node; v != start_node; v = parent[v] ){
                temp.push_back(v);
            }
            for(auto it: temp){
                ans[it] = temp.size();
            }
            start_node = -1;
            end_node = -1;
        }
    }    
}


void nikal_pehli_fursat_mai(){
    int n;
    cin>>n;
    
    inti(n);

    fi(1, n+1){
        int u;
        cin>>u;
        adj[i].push_back(u);
        Radj[u].push_back(i);
    }

    getCycle(n);

    fi(1, n+1){
        if(ans[i]) {
            dfs1(i, ans[i]);
        }
    }

    fi(1, n+1){
        cout<<ans[i]<<" ";
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
