<h2> Algorithm: Inclusion-exclusion</h2>
<h2> Problem: <a href="https://lightoj.com/problem/helping-cicada">1117 Helping Cicada</a></h2>

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
ll lcm(ll a, ll b){
    ll tmp = __gcd(a,b);
    return (a*b)/tmp;
}
int main(){
    FIO;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    t_c{
        ll n,m,i,j,total=0;
        cin>>n>>m;
        vll tmp(m),v;
        for(auto &i:tmp)cin>>i;
        sort(all(tmp));
        v.pb(tmp[0]);
        for(i=1; i<m; i++){
            bool ok=1;
            for(j=0; j<i; j++){
                if(tmp[i]%tmp[j]==0){ok=0;break;}
            }
            if(ok)v.pb(tmp[i]);
        }
        m=v.size();
        for(i=1; i<(1<<m); i++){
            bool odd = (__builtin_popcountll(i)&1);
            ll tmp=1ll;
            for(j=0; j<m; j++){
                if(i&(1<<j)){
                    ll tmp1 = lcm(tmp,v[j]);;
                    if(tmp1<=n)tmp = tmp1;
                    else {tmp=n+1;break;}
                }
            }
            if(odd)total=total-(n/tmp);
            else total=total+(n/tmp);
        }
        casep;
        cout<<n+total<<endl;
    }
}
```
