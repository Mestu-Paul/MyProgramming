<h2> Algorithm: Graph and Tree</h2>
<h2> Problem: <a href="https://lightoj.com/problem/escape">1185 Escape</a></h2>

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
const ll N =  20000+5;
bool isPrime(int a){
    for(int i=2; i*i<=a; i++){
        if(a%i==0)return 0;
    }
    return 1;
}
int main(){
    FIO;
    t_c{
        int n,m,i,j,a,b;
        cin>>n>>m;
        vvi g(n+1);
        for(i=0; i<m; i++){
            cin>>a>>b;
            g[a].pb(b);
            g[b].pb(a);
        }
        vector<vb> vis(n+1,vb(2,false));
        int cnt=0;
        
        queue<pii>q;
        q.push({1,1});
        while(!q.empty()){
            pii tmp = q.front();q.pop();
            b = tmp.ss, a=tmp.ff;
            //vis[b][a]=1;
            for(auto to:g[b]){
                if(vis[to][1^a]==false){
                    vis[to][1^a]=1;
                    q.push({a^1,to});
                }
            }
        }
        casep;
        for(i=1; i<=n; i++){
            if(vis[i][1])cnt++;
        }
        cout<<cnt<<endl;
    }
}

```
