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
//int dx[]={-1,0,1,1,1,0,-1,-1};
//int dy[]={-1,-1,-1,0,1,1,1,0};

int n, m;
vector<string>v(1000);
bool vis[1000][1000];

void dfs(int x, int y){
    if(!vis[x][y]){
        vis[x][y] = 1;
        fi(0, 4){
            int p = x+dx[i];
            int q = y+dy[i];
            if(p<n and q<m and p>=0 and q>=0 and v[p][q]!='#' and !vis[p][q])
                dfs(p, q);
        }
    }
}

void nikal_pehli_fursat_mai(){
    cin>>n>>m;

    fi(0, n) cin>>v[i];

    int cnt = 0;

    fi(0, n){
        fj(0, m){
            if(!vis[i][j] && v[i][j]=='.'){
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;
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
