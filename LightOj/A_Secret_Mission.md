## Algorithm: Lowest Common Ancestor(LCA), DFS, Sparse table
## Problem: <a href="https://lightoj.com/problem/a-secret-mission">A Secret Mission</a>

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
#define casep cout<<"Case "<< cs++<<":\n";
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
const ll N = 50005;
int n,m;
vector<pair<int,pii>>g_temp;
vector<vector<pii>>graph;
int depth[N],par[N],under[N],LOG=17;
int sparse[N][17],up[N][17];

int find(int a){
	if(a==par[a]){
		return a;
	}
	return par[a]=find(par[a]);
}
void Union(int a, int b){
	if(under[a]>=under[b]){
		under[a]+=under[b];
		under[b]=0;
		par[b]=a;
	}
	else{
		under[b]+=under[a];
		under[a]=0;
		par[a]=b;
	}
}
void dfs(int p, int node, int d){
	par[node]=p;
	depth[node]=d;
	for(auto it:graph[node]){
		if(p==it.ff)continue;
		sparse[it.ff][0]=it.ss;
		dfs(node,it.ff,d+1);
	}
}
void LCA_build(){
	for(int i=1; i<=n; i++)up[i][0]=par[i];
	for(int k=1; k<LOG; k++){
		for(int i=1; i<=n; i++){
			if(up[i][k-1]==-1)continue;
			up[i][k] = up[up[i][k-1]][k-1];
			sparse[i][k] = max(sparse[i][k-1],sparse[up[i][k-1]][k-1]);
		}
	}
}
int LCA_query(int a, int b){
	if(depth[a]<depth[b])swap(a,b);
	int Log = log2(depth[a]);
	int ans=0;
	for(int i=Log; i>=0; i--){
		if(depth[a]-(1<<i)>=depth[b]){
			ans = max(ans,sparse[a][i]);
			a = up[a][i];
		}
	}
	if(a==b)return ans;
	for(int i=Log; i>=0; i--){
		if(up[a][i]!=up[b][i]){
			ans = max3(sparse[a][i],sparse[b][i],ans);
			a = up[a][i];
			b = up[b][i];
		}
	}
	return max3(ans,sparse[a][0],sparse[b][0]);
}
void Set_and_reset(){
	graph.clear();
	g_temp.clear();
	graph.resize(n+1);
	for(int i=1; i<=n; i++)par[i]=i,under[i]=1;
	memset(sparse,-1,sizeof sparse);
	memset(up,-1,sizeof up);
}
int main(){
	FIO;
	t_c{
		cin>>n>>m;
		Set_and_reset();
		int a,b,c,i,j;
		for(i=0; i<m; i++){
			cin>>a>>b>>c;
			g_temp.pb({c,{a,b}});
		}
		sort(all(g_temp));
		int cnt=0;
		for(i=0; i<g_temp.size() and cnt<n-1; i++){
			c = g_temp[i].ff;
			a = g_temp[i].ss.ff;
			b = g_temp[i].ss.ss;
			int par_a = find(a);
			int par_b = find(b);
			if(par_a!=par_b){
				Union(par_a,par_b);
				cnt++;
				graph[a].pb({b,c});
				graph[b].pb({a,c});
			}
		}

		dfs(1,1,0);
		LCA_build();
		int q;
		cin>>q;
		casep;
		while(q--){
			cin>>a>>b;
			cout<<LCA_query(a,b)<<endl;
		}
	}
}
```