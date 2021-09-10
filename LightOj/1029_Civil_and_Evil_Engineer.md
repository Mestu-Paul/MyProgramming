<h2> Algorithm: Graph and Tree</h2>
<h2> Problem: <a href="https://lightoj.com/problem/civil-and-evil-engineer">1029 Civil and Evil Engineer</a></h2>

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
vi par(101),under(101);
int Find(int a){
    if(a==par[a])return a;
    else return par[a]=Find(par[a]);
}
int main(){
    FIO;
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    t_c{
        int n,i,j;
        cin>>n;
        vector<pair<int,pii>>v;
        int a,b,c;
        while(true){
            cin>>a>>b>>c;
            if(a==0 and b==0 and c==0)break;
            v.pb({c,{a,b}});
        }
        sort(all(v));
        for(i=0; i<=n; i++)par[i]=i,under[i]=1;
        int Min=0,Max=0;
        for(auto it:v){
            a = Find(it.ss.ff);
            b = Find(it.ss.ss);
            if(a==b)continue;
            par[b]=a;
            Min+=it.ff;
        }
        reverse(all(v));
        for(i=0; i<=n; i++)par[i]=i,under[i]=1;
        for(auto it:v){
            a = Find(it.ss.ff);
            b = Find(it.ss.ss);
            if(a==b)continue;
            par[b]=a;
            Min+=it.ff;
        }
        Max+=Min;
        casep;
        if(Max&1){
            cout<<Max<<"/2"<<endl;
        }
        else{
            cout<<Max/2<<endl;
        }
    }
}
```
