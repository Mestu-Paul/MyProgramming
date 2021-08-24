<h2> Algorithm: Graph</h2>
<h2> Problem: <a href="https://lightoj.com/problem/one-way-roads">1049 One Way Roads</a></h2>

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
int Fun(int n, vector<vpii>v, int pos){
    vb vis(n+1,false);
    queue<int>q;
    q.push(1);vis[1]=1;
    int total1=0;
    int u;
    while(!q.empty()){
        u = q.front();
        q.pop();
        if(u==1){
            vis[v[1][pos].ff]=1;
            q.push(v[1][pos].ff);
            total1+=v[1][pos].ss;
            continue;
        }
        for(auto it:v[u]){
            if(vis[it.ff])continue;
            vis[it.ff]=1;
            q.push(it.ff);
            total1+=it.ss;
        }
    }
    pos = (v[u][0].ff==1)?0:1;
    total1 += v[u][pos].ss;
    return total1;
}
int main(){
    FIO;
    t_c{
        int n,i,j;
        cin>>n;
        vector<vpii> v(n+1);
        int a,b,c;
        for(i=0; i<n; i++){
            cin>>a>>b>>c;
            v[a].pb({b,0});
            v[b].pb({a,c});
        }
        int ans1=Fun(n,v,0);
        ans1 = min(ans1,Fun(n,v,1));
        casep;
        cout<<ans1<<endl;
    }
}
```