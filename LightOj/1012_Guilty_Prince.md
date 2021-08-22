<h2> Algorithm: BFS_and_DFS</h2>
<h2> Problem: <a href="https://lightoj.com/problem/guilty-prince">1012 Guilty Prince</a></li></h2>

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
#define print(v) for (auto it : v)cout << it<<endl//' ';cout << endl;
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
#define mod 100000007
///.........Graph.........///
int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};
///........constant........///
const ll N = 1e5+5;
int main(){
	FIO;
	t_c{
		int n,m,i,j;
		cin>>m>>n;
		string S[n];
		queue<pii>q;
		vector<vb>vis(n,vb(m,false));
		for(i=0; i<n; i++){
			cin>>S[i];
			for(j=0; j<m; j++){
				if(S[i][j]=='@')
					q.push({i,j});
				if(S[i][j]=='#' or S[i][j]=='@')
					vis[i][j]=true;
			}
		}
		j=1;
		while(!q.empty()){
			pii u = q.front();
			q.pop();
			for(i=0; i<4; i++){
				int x = u.ff+X[i];
				int y = u.ss+Y[i];
				if(0<=x and x<n and 0<=y and y<m and vis[x][y]==false){
					vis[x][y]=true;
					j++;
					q.push({x,y});
				}
			}
		}
		casep;
		cout<<j<<endl;
	}
}
```
