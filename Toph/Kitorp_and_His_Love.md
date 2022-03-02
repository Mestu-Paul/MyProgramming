<h2> Algorithm: Number Theory</h2>
<h2> Problem: <a href="https://toph.co/p/kitorp-and-his-love">Kitorp and His Love</a></h2>

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
ll f(ll a){
    ll lo=1,hi=400000020,ans=-1;
    while(lo<=hi){
        ll mid = (hi+lo)/2;
        ll tmp = mid,c=0;
        while(tmp>0){
            c+=(tmp/5ll);
            tmp/=5ll;
        }
        if(c>a){
            hi=mid-1;
        }
        else if(c<a){
            lo=mid+1;
        }
        else{
            ans=mid;break;
        }
    }
    if(ans==-1)return ans;
    return (ans/5)*5;
}
int main(){
    FIO;
    t_c{
        ll n;
        cin>>n;
        ll ans = f(n);
        casep;
        if(ans==-1)cout<<"Go Home! You are drunk!"<<endl;
        else cout<<ans<<endl;
    }
}
```
