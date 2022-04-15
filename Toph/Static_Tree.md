<h2> Algorithm: Graph and Tree</h2>
<h2> Problem: <a href="https://toph.co/p/static-tree">Static Tree</a></h2>

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
#define print(v) for (auto it : v)cout << it<<" ";cout << endl;
#define PI acos(-1.0)
#define yes cout <<"Yes"<< endl
#define no cout<<"No"<<endl
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define t_c int test, cs = 1;cin>>test;while (test--)
#define casep cout<<"Case "<< cs++<<": ";
///................function.....................///

#define D(a) (double)(a)
#define siz(s) (int)(s.size())
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define Min(a) *min_element(all(a))
///#define mod 1000000007
///.........Graph.........///
int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};
///........constant........///
const ll N = 200000+5;
vvi up(N,vi(19,-1)),nxt(N,vi(27));
vvi g(N);
vi depth(N);
string s,qs;
void dfs(int nd, int par, int d){
   depth[nd]=d,up[nd][0]=par;
   for(auto to:g[nd]){
      if(to==par)continue;
      for(int i=0; i<26; i++){
         nxt[to][i]=nxt[nd][i];
      }
      nxt[to][s[nd]-'a']=nd;
      dfs(to,nd,d+1);
   }
}
int lca(int u, int v){
   if(depth[u] < depth[v]) swap(u,v);
   ll diff = depth[u] - depth[v];
   for(ll i = 0; i < 19; i++) if( (diff>>i)&1 ) u = up[u][i];
   if(u == v) return u;
   for(ll i = 19-1; i >= 0; i--) {
      if(up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
      }
   }
   return up[u][0];
}
int qry1(int len, int u, int p){
   int ptr=1,cur=u;
   while(ptr<len and cur!=0 and depth[cur]>=depth[p]){
      if(qs[ptr]!=s[cur]){
         cur = nxt[cur][qs[ptr]-'a'];
         continue;
      }
      ptr++;
      if(ptr<len)cur = nxt[cur][qs[ptr]-'a'];
   }
   return ptr;
}
int qry2(int len, int u, int p){
   int ptr=len-1,cur=u;
   while(ptr>0 and cur!=0 and depth[cur]>depth[p]){
      if(qs[ptr]!=s[cur]){
         cur = nxt[cur][qs[ptr]-'a'];
         continue;
      }
      ptr--;
      if(ptr>0)cur = nxt[cur][qs[ptr]-'a'];
   }
   return ptr;
}
int main(){
   FIO;
   int n,q,i,j;
   cin>>n>>q;
   int a,b;
   cin>>s;s = "_"+s;
   for(i=1; i<n; i++){
      cin>>a>>b;
      g[a].pb(b);
      g[b].pb(a);
   }
   dfs(1,-1,0);
   for(i=1; i<19; i++){
      for(j=1; j<=n; j++){
         if(up[j][i-1]!=-1)
            up[j][i] = up[up[j][i-1]][i-1];
      }
   }
   while(q--){
      cin>>a>>b>>qs;
      qs = "_"+qs;
      int p = lca(a,b);
      int p1 = qry1(qs.size(),a,p);
      int p2 = qry2(qs.size(),b,p);
      int len = qs.size();
      if(p1>=len or p2<1 or p1>p2 )
         cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
   }

}
```