<h2> Algorithm: Graph</h2>
<h2> Problem: <a href="https://codeforces.com/problemset/problem/1600/J">Robot Factory</a></h2>

```c++
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define vb vector<bool>
#define vs vector<string>
///............x...........///
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define ff first
#define ss second
#define bg begin()
#define UNIQUE(X) (X).erase(unique(all(X)), (X).end())
#define ft cout << "for test"<<endl;
#define read(v, a, n) for (int i = a; i<n; i++)cin>>v[i];
#define print(v) for (auto it : v)cout << it<<' ';cout << endl;
#define PI acos(-1.0)
#define yes cout <<"Yes"<< endl
#define no cout<<"No"<<endl
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define t_c int test, cs = 1;cin>>test;while (test--)
#define casep cout<<"Case "<< cs++<<": ";
///................function.....................///

#define D(a) (double)(a)
#define sqr(a) (a * a)
#define siz(s) (int)(s.size())
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define Min(a) *min_element(all(a))
#define mod 1000000007
///.........Graph.........///
int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};
///........constant........///
const ll N = 1e3+2;
vector<vpii>par(N,vpii(N));
vvi under(N,vi(N));
pii Find(pii a){
    if(a==par[a.ff][a.ss])return a;
    return par[a.ff][a.ss]=Find(par[a.ff][a.ss]);
}
void Union(pii a, pii b){
    //cout<<a.ff<<" "<<a.ss<<" "<<b.ff<<" "<<b.ss<<endl;
    a = Find(a);
    b = Find(b);
    if(a==b)return;
    if(under[a.ff][a.ss]>under[b.ff][b.ss]){
        under[a.ff][a.ss]+=under[b.ff][b.ss];
        par[b.ff][b.ss]=a;
    }
    else{
        under[b.ff][b.ss]+=under[a.ff][a.ss];
        par[a.ff][a.ss]=b;
    }
}
int main(){
    FIO;
    int n,m,i,j;
    cin>>n>>m;
    vvi grid(n,vi(m));
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin>>grid[i][j];
            par[i][j]={i,j};under[i][j]=1;
            if(j>0){
                int pre = grid[i][j-1];
                int East = pre&(1<<2), West = grid[i][j]&1;
                if((East|West)==false)
                    Union({i,j},{i,j-1});
            }
            if(i>0){
                int pre = grid[i-1][j];
                int South = pre&(1<<1), North = grid[i][j]&(1<<3);
                if((South|North)==false)
                    Union({i,j},{i-1,j});
            }
            //cout<<i<<" "<<j<<" par "<<par[i][j].ff<<" "<<par[i][j].ss<<endl;
        }
    }
    vi ans;
    map<pii,bool>vis;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            pii p = Find(mp(i,j));
            if(vis[p]==true)continue;
            vis[p]=true;
            ans.pb(under[p.ff][p.ss]);
        }
    }
    sort(allr(ans));
    print(ans);
}
```
