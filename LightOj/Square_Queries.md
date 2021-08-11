## Algorithm: Sparse table, Range minimum query(RMQ)
## Problem: <a href="https://lightoj.com/problem/square-queries">Sqaure Queries</a>

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
const ll N = 1e5+5;
int main(){
	FIO;
	t_c{
		int n,m,i,j;
		cin>>n>>m;
		int LOG = log2(n)+1;
		vvi v(n+1,vi(n+1));
		int sparse[n+1][n+1][LOG];
		memset(sparse,0,sizeof sparse);
		for(i=1; i<=n; i++){
			for(j=1; j<=n; j++){
				cin>>v[i][j];
				sparse[i][j][0]=v[i][j];
			}
		}
		for(int bit=1; bit<LOG; bit++){
			for(i=1; i+(1<<bit)-1<=n; i++){
				for(j=1; j+(1<<bit)-1<=n; j++){
					int p = 1<<(bit-1);
					sparse[i][j][bit] = max({sparse[i][j][bit-1],sparse[i][j+p][bit-1],sparse[i+p][j][bit-1],sparse[i+p][j+p][bit-1]});
					/**
					cout<<"root "<<i<<" "<<j<<" bit "<<bit<<" val "<<(1<<bit)<<" p "<<p<<endl;
					cout<<"first "<<i<<" "<<j<<" "<<bit-1<<" "<<sparse[i][j][bit-1]<<endl;
					cout<<"2nd   "<<i<<" "<<j+p<<" "<<bit-1<<" "<<sparse[i][j+p][bit-1]<<endl;
					cout<<"3rd   "<<i+p<<" "<<j<<" "<<bit-1<<" "<<sparse[i+p][j][bit-1]<<endl;
					cout<<"4th   "<<i+p<<" "<<j+p<<" "<<bit-1<<" "<<sparse[i+p][j+p][bit-1]<<endl;
					cout<<"update "<<i<<" "<<j<<" "<<bit<<" "<<sparse[i][j][bit]<<endl<<endl;
					**/
				}
			}
		}
		casep;
		while(m--){
			int a,b,c;
			cin>>a>>b>>c;
			int Log = log2(c);
			int p = (1<<Log);
			/**
			cout<<a<<" "<<b<<" "<<c<<" "<<Log<<" "<<(1<<Log)<<" "<<p<<endl;
			cout<<a<<" "<<b<<" "<<sparse[a][b][Log]<<endl;
			cout<<a<<" "<<b+c-p<<" "<<sparse[a][b+c-p][Log]<<endl;
			cout<<a+c-p<<" "<<b<<" "<<sparse[a+c-p][b][Log]<<endl;
			cout<<a+c-p<<" "<<b+c-p<<" "<<sparse[a+c-p][b+c-p][Log]<<endl;
			**/
			int ans = max({sparse[a][b][Log],sparse[a][b+c-p][Log],sparse[a+c-p][b][Log],sparse[a+c-p][b+c-p][Log]});
			cout<<ans<<endl;
		}

	}
}
```