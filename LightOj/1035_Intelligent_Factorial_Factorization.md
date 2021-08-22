<h2> Algorithm: Number Theory(Prime Factorization)</h2>
<h2> Problem: <a href="https://lightoj.com/problem/intel-factor-factorization">1035 Intelligent Factorial Factorization</a></li></h2>

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
const ll N = 105;
vi mark(N);
void sieve(){
	int i,j;
	for(i=1; i<N; i++)mark[i]=i;
	for(i=2; i<N; i+=2)mark[i]=2;
	for(i=3; i<N; i+=2){
		if(mark[i]==i){
			for(j=i*i; j<N; j+=i*2)if(mark[j]==j)mark[j]=i;
		}
	}
}
int main(){
	FIO;
	sieve();
	t_c{
		int n;
		cin>>n;
		map<int,int>cnt;
		for(int i=2; i<=n; i++){
			int m = i;
			while(m>1){
				cnt[mark[m]]++;
				m/=mark[m];
			}
		}
		cout<<"Case "<<cs++<<": "<<n<<" =";
		int cross=0;
		for(auto it:cnt){
			if(cross)
				cout<<" *";
			else cross=1;
				cout<<" "<<it.ff<<" ("<<it.ss<<")";
		}
		cout<<endl;
	}
}
```
