## Algorithm: Segment tree
## Problem: <a href="https://toph.co/p/singing-game">Singing Game</a>

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
const ll N = 1e5+5;
const ll inf = 1e5;
#define lft nd*2
#define rgt nd*2+1
#define mid (b+e)/2
int character=26;
struct tp{
	string s;
	vector<int>freq;
	tp():freq(26){}
};
string s;
vector<tp>tree(4*N);
void build(int nd ,int b, int e){
	if(b>e)return;
	if(b==e){
		tree[nd].s = s[b];
		tree[nd].freq[s[b]-'a']=1;
		//cout<<nd<<" "<<b<<" base "<<s[b]<<endl;
		return;
	}
	build(lft,b,mid);
	build(rgt,mid+1,e);
	for(auto it:tree[lft].s){
		if(tree[nd].freq[it-'a']==0)
			tree[nd].s += it;
		tree[nd].freq[it-'a']+=tree[lft].freq[it-'a'];
	}
	for(auto it:tree[rgt].s){
		if(tree[nd].freq[it-'a']==0)
			tree[nd].s += it;
		tree[nd].freq[it-'a']+=tree[rgt].freq[it-'a'];
	}
	//cout<<nd<<" "<<b<<" <> "<<e<<" merge "<<tree[nd].s<<endl;
}
tp query(int nd, int b, int e, int l, int r){
	if(b>e or e<l or r<b){
		vi tmp;
		tp tempo;
		tempo.s="";tempo.freq=tmp;
		return tempo;
	}
	if(l<=b and e<=r){
		return tree[nd];
	}
	tp p1 = query(lft,b,mid,l,r);
	tp p2 = query(rgt,mid+1,e,l,r);
	for(auto it:p2.s){
		if(p1.freq[it-'a']==0)
			p1.s += it;
		p1.freq[it-'a']+=p2.freq[it-'a'];
	}
	return p1;
}
int main(){
	ll n,m,i,j;
	cin>>n>>m;
	cin>>s;
	s = '_'+s;
	build(1,1,n);
	while(m--){
		cin>>i>>j;
		tp p = query(1,1,n,i,j);
		ll ans=0;
		//print(p.s);
		for(i=0; i<p.s.size(); i++){
			ans += (ll)(p.freq[p.s[i]-'a'])*(i+1);
		}
		cout<<ans<<endl;
	}
}
```