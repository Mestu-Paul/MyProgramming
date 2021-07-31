## Algorithm: Fenwick Tree (Interval)
## Problem: [INTERVA2 - Interval Challenge](https://www.spoj.com/problems/INTERVA2/cstart=10)
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
const ll N = 1e9+5;
map<int,int>cast;
set<int>store;
vi table;
struct tp{
	int x,y,pos;
	bool operator<(const tp& other )const{
		if(other.x==x)return y>other.y;
		return x<other.x;
	}
};
void update(int pos, int n){
	while(pos<=n){
		table[pos]+=1;
		pos += pos&(-pos);
	}
}
int query(int pos, int n){
	int sum=0,idx=pos;
	while(idx>0){
		sum += table[idx];
		idx -= idx&(-idx);
	}
	idx=n;
	int total=0;
	while(idx>0){
		total += table[idx];
		idx -= idx&(-idx);
	}
	return total-sum;
}
int main(){
	FIO;
	int n;
	while(cin>>n){
		vector<tp>v(n);
		int i,j=0;
		for(i=0; i<n; i++){
			cin>>v[i].x>>v[i].y;
			v[i].pos=i;
			store.insert(v[i].y);
		}
		for(auto it:store)cast[it]=++j;
		table.resize(n+1);
		sort(all(v));
		//for(auto it:v)cout<<it.pos<<" "<<it.x<<" "<<it.y<<endl;
		for(i=0; i<n; i++){
			v[i].y = cast[v[i].y];
		}
		vi ans(n);
		map<pii,int>cnt;
		for(i=0; i<n; i++){
			if(i==0){
				cnt[{v[i].x,v[i].y}]=1;
				update(v[i].y,n);
				continue;
			}
			//cout<<v[i].x<<" >> "<<v[i].y<<endl;
			//print(table);
			ans[v[i].pos] = query(v[i].y-1,n)-cnt[{v[i].x,v[i].y}];
			cnt[{v[i].x,v[i].y}]++;
			update(v[i].y,n);
		}
		print(ans);
		cast.clear();
		store.clear();
		table.clear();
	}
}
```