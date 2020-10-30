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

const int N=2501;
vll graph[N];
ll dis[N];
int n, m;
const ll INF = 1e18;

void nikal_pehli_fursat_mai(){
    cin>>n>>m;

    fi(0, m){
        int a, b, c;
        cin>>a>>b>>c;
        a--;
        b--;
        graph[a].push_back({b, -c});
    }
 
    fi(0,n) dis[i] = INF;
    
    dis[0]=0;
    
    fi(1, n){
        fj(0, n){
            for(auto it: graph[j]){
                if(dis[j]==INF) continue;
                dis[it.ff] = min(dis[it.ff], dis[j]+it.ss);
                dis[it.ff] = max(dis[it.ff], -INF);
            }
        }
    }

    fi(1, n){
        fj(0, n){
            for(auto it: graph[j]){
                if(dis[j]==INF) continue;
                dis[it.ff] = max(dis[it.ff], -INF);
                if(dis[it.ff] > dis[j]+it.ss){
                    dis[it.ff] = -INF;
                }
            }
        }
    }
    if(dis[n-1]==-INF) cout<<-1;
    else cout<<dis[n-1]*-1<<endl;
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
