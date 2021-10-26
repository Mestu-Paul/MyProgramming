<h2> Algorithm: graph</h2>
<h2> Problem: <a href="https://vjudge.net/problem/UVA-336">336 A Node Too Far </a></h2>

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
const ll N = 1e6+5;vvi g;
map<int,int>rev_cast;
int bfs(int node, int tlt, int n){
    queue<pii>q;
    q.push({node,tlt});
    vb vis(n+1);
    vis[node]=1;
    int cnt=0;
    while(!q.empty()){
        pii u = q.front();q.pop();
        cnt++;
        if(u.ss==0)continue;
        for(auto to:g[u.ff]){
            if(vis[to])continue;
            vis[to]=1;
            q.push({to,u.ss-1});
        }
    }
    return n-cnt;
}
int main(){
    FIO;
    int edge,cs=1;while(cin>>edge and edge){
        g.clear();
        rev_cast.clear();
        set<int>st;
        vpii temp_input;
        int i,j,a,b;
        for(i=0; i<edge; i++){
            cin>>a>>b;
            temp_input.pb({a,b});
            st.insert(a),st.insert(b);
        }
        int node = st.size();
        g.resize(node+1);
        map<int,int>cast;
        j=1;
        for(auto to:st){
            cast[to]=j;
            rev_cast[j]=to;
            j++;
        }
        for(auto to:temp_input){
            g[cast[to.ff]].pb(cast[to.ss]);
            g[cast[to.ss]].pb(cast[to.ff]);
        }
        while((cin>>a>>b)){
            if(a==0 and b==0)break;
            cout<<"Case "<<cs++<<": "<<bfs(cast[a],b,node)<<" nodes not reachable from node "<<a<<" with TTL = "<<b<<"."<<endl;
        }
    }
}
```
