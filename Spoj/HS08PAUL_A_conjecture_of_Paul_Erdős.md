<h2>Algorithm: Number Theory</h2>
<h2>Problem: <a href="https://www.spoj.com/problems/HS08PAUL/">HS08PAUL - A conjecture of Paul Erdős</a>

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
#define print(v) for (auto it : v)cout << it<<" ";cout << endl;
#define PI acos(-1.0)
#define yes cout <<"Yes"<< endl
#define no cout<<"No"<<endl
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define t_c int test, cs = 1;cin>>test;while (test--)
#define casep cout<<"Case "<< cs++<<": ";
///................function.....................///

#define D(a) (double)(a)
#define siz(s) (int)(s.size())
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define Min(a) *min_element(all(a))
///#define mod 1000000007
///.........Graph.........///
int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};
///........constant........///
const ll N = 1e7+5;
int main(){
    FIO;
    vi primes;
    vb mark(N);
    for(ll i=3; i*i<N; i+=2){
        if(!mark[i]){
            for(ll j=i*i; j<N; j+=i*2)mark[j]=1;
        }
    }
    primes.pb(2);
    for(int i=3; i<N; i+=2)
        if(!mark[i])
            primes.pb(i);
    vi pre_sum(N);
    for(auto p:primes){
        for(ll i=1; i*i*i*i<N; i++){
            ll x = i*i*i*i;
            if(x>=p)break;
            ll y = p-x;
            ll a = sqrt(y*1.0);
            if(a*a==y){
                pre_sum[p]=1;
            }
        }
    }
    for(int i=2; i<N; i++)
        pre_sum[i]+=pre_sum[i-1];
    t_c{
        int n;
        cin>>n;
        cout<<pre_sum[n]<<endl;
    }
}
```