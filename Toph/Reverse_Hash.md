<h2> Algorithm: DP</h2>
<h2> Problem: <a href="https://toph.co/p/reverse-hash">Reverse Hash</a></h2>

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
class C{
public:
	int n,m,b,h;
	vll Pow;
	vector<vvi>dp;
	bool change;
	string s;
	C(){
		cin>>n>>m>>b>>h;
		Pow.resize(n+1);int tmp=b;
		for(int i=0; i<n; i++){
			Pow[i]=tmp;tmp=(tmp*b)%m;
		}
		dp.resize(n+1,vvi(2,vi(m+1,-1)));
		s.resize(n,'0');
		change=1;
	}
	int fun(int pos, bool bit, int mod){
		if(pos>=n){
			if(mod==h){
				//cout<<" return "<<mod<<" "<<h<<" "<<pos<<endl;
				change=0;
				return 1;
			}
			return 0;
		}
		int &ret = dp[pos][bit][mod];
		if(ret!=-1){
			//cout<<"return var "<<ret<<endl;
			return ret;
		}
		ret=0;
		if(change){
			s[pos]='0';
			//cout<<pos<<" 0 "<<mod<<endl;
			ret	|= fun(pos+1,0,mod);
			if(ret)return ret;
			s[pos]='1';
			//cout<<pos<<" 1 "<<(mod+Pow[pos])%m<<endl;
			ret |= fun(pos+1,1,(mod+Pow[pos])%m);
			return ret;
		}
		else {
			//cout<<"return 1"<<endl;
			return 1;
		}
	}
	void p(){
		if(fun(0,0,0)){
			cout<<s<<endl;
		}
		else cout<<-1<<endl;
	}
};
int main(){
	FIO;
	t_c{
		C ob;
		ob.p();
	}
}
```
