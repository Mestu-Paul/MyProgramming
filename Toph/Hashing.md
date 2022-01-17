<h2> Algorithm: Graph and Tree</h2>
<h2> Problem: <a href="https://toph.co/p/hashing">Hashing</a></h2>

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
class A{
public:
    ll n,XOR;
    vi par,sz;
    vll Xor;
    set<int>odd_times;
    A(ll _n){
        n=_n;
        par.resize(n+1);
        sz.resize(n+1);
        Xor.resize(n+1);
        for(int i=1; i<=n; i++){
            par[i]=i;
            sz[i]=1;
            Xor[i]=0;
        }
        odd_times.clear();
        for(int i=1; i<=n; i++)odd_times.insert(i);
    }
    void count_xor(){
        XOR=0;
        for(int i=1; i<=n; i++)cin>>Xor[i];
        for(int i=1; i<=n; i++)XOR^=Xor[i];
    }
    int Find(int a){
        if(a==par[a])return a;
        return par[a]=Find(par[a]);
    }
    int Union(int a, int b){
        if(sz[a]>=sz[b]){
            sz[a]+=sz[b];
            par[b]=a;
            Xor[a]^=Xor[b];return a;
        }
        else{
            sz[b]+=sz[a];
            par[a]=b;
            Xor[b]^=Xor[a]; return b;
        }
    }
    ll query(){
        int x,y;
        cin>>x>>y;
        int par_x = Find(x),par_y=Find(y);
        if(par_x!=par_y){
            if(sz[par_x]&1){
                odd_times.erase(par_x);
            }
            if(sz[par_y]&1){
                odd_times.erase(par_y);
            }
            par_x = Union(par_x,par_y);
            //cout<<"query "<<x<<" "<<y<<" "<<par_x<<endl;
            if(sz[par_x]&1)odd_times.insert(par_x);
        }
        //cout<<"set ";print(odd_times);
        if(odd_times.size()==0){
            return XOR;
        }
        else if(odd_times.size()==1){
            return Xor[*odd_times.begin()];
        }
        else{
            return 0;
        }
    }
};
int main(){
    FIO;
    t_c{
        ll n,q,i,j,a,b,c;
        cin>>n>>q;
        A ob(n);
        ob.count_xor();
        cout<<"Case "<<cs++<<":"<<endl;
        while(q--){
            cout<<ob.query()<<endl;
        }
    }
}
```
