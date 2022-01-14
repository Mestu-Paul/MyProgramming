<h2> Algorithm: BFS</h2>
<h2> Problem: <a href="https://atcoder.jp/contests/abc126/tasks/abc126_d">Even Relation</a></h2>

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
const ll N = 1e5+5;
int main(){
    FIO;
    int n,i,j,a,b,c;
    cin>>n;
    vector<vpii> g(n+1);
    for(i=1; i<n; i++){
        cin>>a>>b>>c;
        c%=2;
        g[a].pb({b,c});
        g[b].pb({a,c});
    }
    queue<int>q;
    q.push(1);
    vi dis(n+1,3);
    dis[1]=0;
    while(!q.empty()){
        a = q.front();q.pop();
        for(pii to:g[a]){
            if(dis[to.ff]==3){
                dis[to.ff]=(dis[a]+to.ss)%2;
                q.push(to.ff);
            }
        }
    }
    for(i=1; i<=n; i++)cout<<dis[i]<<endl;

}
```
