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

int dx[] = {2, 2, -2, -2, -1, 1, -1, 1};
int dy[] = {-1, 1, -1, 1, 2, 2, -2, -2};

vector<int>vis;

bool check(int x, int y){
    if(x>=0 and x<8 and y>=0 and y<8 and !vis[x*8+y])
        return 1;
    return 0;
}

int deg(int x, int y){
    int d = 0;
    fi(0, 8){
        int p = x + dx[i];
        int q = y + dy[i];
        d += check(p, q);
    }
    return d;
}

void dfs(int x, int y, int time){
    vis[x*8+y] = time+1;
    if(time==63){
        fi(0, 8){
            fj(0, 8) cout<<vis[i*8+j]<<" ";
            cout<<endl;
        }
        exit(0);
    }

    vector<pii>adj;
    fi(0, 8){
        if(check(x+dx[i], y+dy[i])){
            adj.push_back({x+dx[i], y+dy[i]});
        }
    }
    sort(adj.begin(), adj.end(), [](const pii &a, const pii &b){
        return deg(a.ff, a.ss)<deg(b.ff, b.ss);
    });
    for(auto it: adj){
        dfs(it.ff, it.ss, time+1);
    }
    vis[x*8+y] = 0;
}

void nikal_pehli_fursat_mai(){
    ll p, q;
    cin>>p>>q;
    vis.assign(64, 0);
    p--; q--;
    swap(p, q);
    dfs(p, q, 0);
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
