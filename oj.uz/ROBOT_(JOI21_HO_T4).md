## Algorithm: Graph (almost MST)
## Problem: <a href = "https://oj.uz/problem/view/JOI21_ho_t4">ROBOT (JOI21_HO_T4)</a>

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
///#define mod 1000000007
///.........Graph.........///
int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};
///........constant........///
const ll N = 2e6+5;
const ll inf = 4e18;
 
int main(){
	FIO;
	int n,m,i,j;
	cin>>n>>m;
	vector<vector<pair<int,pii>>>v(n+1);
	vector<vpll>g(N);
	int a,b,c,p;
	for(i=0; i<m; i++){
		cin>>a>>b>>c>>p;
		v[a].pb(mp(c,mp(p,b)));
		v[b].pb(mp(c,mp(p,a)));
	}
	int extra=n;
	for(i=1; i<n; i++){
		int tmp_sz = siz(v[i]);
		if(tmp_sz==0)continue;
		sort(all(v[i]));
		for(int l=0,r=0; r<tmp_sz ; l=r){
 
			ll sum=0;
			while(r<tmp_sz and v[i][l].ff == v[i][r].ff)sum +=(ll)(v[i][r++].ss.ff);
 
			if(r-l==1)g[i].pb({0,v[i][l].ss.ss});
			else{
				g[i].pb({0,++extra});
				for(j=l; j<r; j++){
					int node = v[i][j].ss.ss,cost = v[i][j].ss.ff;
 
					g[i].pb({cost,node});
					g[node].pb({0,extra});
					g[extra].pb({sum-(ll)(cost),node});
				}
			}
		}
	}
	vll dis(N,inf);
	priority_queue<pll>pq;
	pq.push({0ll,1ll});
	while(!pq.empty()){
		pll u = pq.top();
		pq.pop();
		if(dis[u.ss] != inf)continue;
		dis[u.ss] = (ll)(-u.ff);
		for(auto to:g[u.ss]){
			pq.push({(ll)(u.ff-to.ff),(ll)(to.ss)});
		}
	}
	cout<<((dis[n]==inf)?-1:dis[n])<<endl;
 
}
```