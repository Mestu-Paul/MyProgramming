## Algorithm: Lowest Common Ancestor (LCA) + BFS
## Problem: [Lowest Common Ancestor](https://www.spoj.com/problems/LCASQ/)

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
#define casep cout<<"Case"<< cs++<<": ";
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
const ll N = 1e4+5;
vvi up(N,vi(15,-1)),g(N);
vi depth(N);
int n;
void bfs(){
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto to:g[u]){
            depth[to]=depth[u]+1;
            q.push(to);
        }
    }
}
void build(){
    for(int bit=1; bit<15; bit++){
        for(int i=0; i<n; i++){
            if(up[i][bit-1]==-1)continue;
            up[i][bit] = up[ up[i][bit-1] ][bit-1];
        }
    }
}
int lcaQuery(int a, int b){
    if(depth[a]<depth[b])swap(a,b);
    int k = depth[a]-depth[b];
    for(int i=14; i>=0; i--){
        if(k&(1<<i)){
            a = up[a][i];
        }
    }
    if(a==b)return a;
    for(int i=14; i>=0; i--){
        if(up[a][i]!=up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}
int main(){
    FIO;
    int i,j;
    cin>>n;
    int a,b;
    for(i=0; i<n; i++){
        cin>>a;
        for(j=0; j<a; j++){
            cin>>b;
            up[b][0]=i;
            g[i].pb(b);
        }
    }
    bfs();
    build();
    int q;
    cin>>q;
    while(q--){
        cin>>a>>b;
        cout<<lcaQuery(a,b)<<endl;
    }

}
```