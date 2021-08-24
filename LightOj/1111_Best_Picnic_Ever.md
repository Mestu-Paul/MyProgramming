<h2> Algorithm:  Graph (BFS and DFS)</h2>
<h2> Problem: <a href="https://lightoj.com/problem/best-picnic-ever">1111 Best Picnic Ever</a></h2>

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
///#define mod 1000000007
///.........Graph.........///
int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};
///........constant........///
const ll N = 1e6+5;
int main(){
    FIO;
    t_c{
        int k,n,m,i,j,a,b;
        cin>>k>>n>>m;
        vi pos(k);
        for(i=0; i<k; i++)cin>>pos[i];
        vvi g(n+1);
        for(i=0; i<m; i++){
            cin>>a>>b;
            g[a].pb(b);
        }
        vi total_visit(n+1,0);
        int ans=0;
        for(auto it:pos){
            queue<int>q;
            vb vis(n+1,false);
            q.push(it);vis[it]=1;
            while(!q.empty()){
                int u = q.front();q.pop();
                total_visit[u]++;
                ans += (total_visit[u]==k);
                for(auto it:g[u]){
                    if(!vis[it]){
                        vis[it]=true;
                        q.push(it);
                    }
                }
            }
        }
        casep;
        cout<<ans<<endl;
    }
}
```