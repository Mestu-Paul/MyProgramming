<h2> Algorithm: Geometry</h2>
<h2> Problem: <a href="https://lightoj.com/problem/expanding-rods">1137 Expanding Rods</a></h2>

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
const double eps = 1e-6;
int main(){
	FIO;
	t_c{
		double l,n,c;
		cin>>l>>n>>c;
		double l_new = (1.0+n*c)*l,a=l/2.0;
		double lo=0,hi=l/2.0,ans=0;
		while(hi-lo>eps){
			double h = (hi+lo)/2.0;
			double r = (h/2.0)+((l*l)/(8*h));
			double theta = 2*asin(a/r);
			double s = r*theta;
			if(s>=l_new){
				hi=h;
			}
			else{
				ans = h;
				lo=h;
			}
		}
		casep;
		cout<<fixed<<setprecision(6)<<ans<<endl;
	}
}
```
