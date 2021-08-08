## Algorithm: Lowest Common Ancestor (LCA)
## Problem: <a href="https://lightoj.com/problem/greatest-parent">Greatest Parent</a>

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
const int N = 1e5+5;
int LOG=18;
vi depth(N),cost(N);
vvi up(N,vi(LOG));
int main(){
	t_c{
		int i,j,n,q;
		for(i=0; i<N; i++)
			for(j=0; j<LOG; j++)
				up[i][j]=-1;
		cin>>n>>q;
		int a,b;
		vvi g(n);
		cost[0]=1;
		for(i=1; i<n; i++){
			cin>>a>>b;
			g[a].pb(i);
			cost[i]=b;
			up[i][0]=a;
			//cout<<"done "<<i<<" "<<0<<" "<<a<<endl;
		}
		queue<int>Q;Q.push(0);
		while(!Q.empty()){
			int u = Q.front();Q.pop();
			for(auto it:g[u]){
				depth[it]=depth[u]+1;
				Q.push(it);
			}
		}
		///LCA build
		for(i=1; i<LOG; i++){
			for(j=1; j<n; j++){
				//cout<<"pre "<<j<<" "<<i-1<<" "<<up[j][i-1]<<endl;
				if(up[j][i-1]==-1)continue;
				up[j][i] = up[ up[j][i-1] ][i-1];
				//cout<<j<<" "<<i<<" "<<up[j][i]<<endl;
			}
		}
		///query
		casep;
		while(q--){
			cin>>a>>b;
			for(i=LOG-1; i>=0; i--){
				if(up[a][i]!=-1 and cost[up[a][i]]>=b){
					//cout<<a<<" = "<<up[a][i];
					a = up[a][i];
				}
			}
			if(up[a][0]!=-1 and cost[up[a][0]]>=b)a=up[a][0];
			cout<<a<<endl;
		}
	}
}
```