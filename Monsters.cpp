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
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
const string s = "DRUL";
//int dx[]={-1,0,1,1,1,0,-1,-1};
//int dy[]={-1,-1,-1,0,1,1,1,0};

vector<vector<char>>v;
vector<vector<int>>dis;
vector<vector<int>>dis2;
vector<vector<bool>>vis;
pii final = {-1, -1};
vector<vector<pii>>path;
vector<vector<char>>dir;

void bfs(){
    priority_queue<pair<int,pii>>q;
    
    fi(0, v.size()){
        fj(0, v[i].size()){
            if(v[i][j]=='M') q.push({0, {i, j}});
        }
    }

    while(!q.empty()){
        auto p = q.top().ss;
        auto d = abs(q.top().ff);
        q.pop();
        if(dis[p.ff][p.ss]<=d) continue;
        dis[p.ff][p.ss] = d;
        fi(0, 4){
            int x1 = p.ff+dx[i];
            int y1 = p.ss+dy[i];
            if(x1>=0 and y1>=0 and x1<dis.size() and y1<dis[x1].size() and v[x1][y1]!='#'){
                if(v[x1][y1]=='M'){
                    q.push({0, {x1, y1}});
                }
                else if(dis[x1][y1]>dis[p.ff][p.ss]+1){
                    q.push({-(dis[p.ff][p.ss]+1), {x1, y1}});
                }
            }
        }
    }
}

void bfs2(int x, int y){
    priority_queue<pair<int,pii>>q;
    q.push({0, {x, y}});
    
    path[x][y] = {1e9, 1e9};

    while(!q.empty()){
        auto p = q.top().ss;
        auto d = abs(q.top().ff);
        q.pop();
        if(vis[p.ff][p.ss] or dis[p.ff][p.ss]<=d) continue;
            
        vis[p.ff][p.ss] = 1;

        if(p.ff==0 or p.ss==0 or p.ff==v.size()-1 or p.ss==v[p.ff].size()-1) {
            final = {p.ff, p.ss};
            break;
        }

        fi(0, 4){
            int x1 = p.ff+dx[i];
            int y1 = p.ss+dy[i];
            if(x1>=0 and y1>=0 and x1<dis.size() and y1<dis[x1].size() and v[x1][y1]!='#' and d+1<dis[x1][y1] and path[x1][y1].ff==-1){
                path[x1][y1] = p;
                dir[x1][y1] = s[i];
                q.push({-(d+1), {x1, y1}});
            }
        }
    }
}

void nikal_pehli_fursat_mai(){
    int n, m;
    cin>>n>>m;
    
    v.assign(n, vector<char>(m));
    dir.assign(n, vector<char>(m, '#'));
    dis.assign(n, vector<int>(m, 1e9));
    vis.assign(n, vector<bool>(m, 0));
    path.assign(n, vector<pii>(m, {-1, -1}));

    int x,y;

    fi(0, n){
        fj(0, m) {
            cin>>v[i][j];
            if(v[i][j]=='A'){
                x = i, y = j;
            }
        }
    }

    bfs();

    // fi(0, n){
    //     fj(0, m){
    //         if(dis[i][j]==1e9) cout<<"#"<<" ";
    //         else cout<<dis[i][j]<<" ";
    //     }cout<<endl;
    // }

    bfs2(x, y);

    if(final.ff==-1){
        cout<<"NO"<<endl;
        return;
    }
    string ans = "";
    cout<<"YES"<<endl;
    int x1 = final.ff, y1 = final.ss;

    while(path[x1][y1].ff!=1e9){
        ans += dir[x1][y1];
        auto p = path[x1][y1];
        x1 = p.ff;
        y1 = p.ss;
    }

    // fi(0, n){
    //     fj(0, m){
    //         cout<<"{"<<path[i][j].ff<<" "<<path[i][j].ss<<"}"<<" ";
    //     }cout<<endl;
    // }

    cout<<ans.size()<<endl;
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
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
