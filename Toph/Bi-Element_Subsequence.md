<h2> Algorithm: Number Theory</h2>
<h2> Problem: <a href="https://toph.co/p/bi-element-subsequence">Bi-Element Subsequence</a></h2>

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
#define mod 1000000007
///.........Graph.........///
int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};
///........constant........///
const ll N = 1e5+5;
int main(){
    FIO;
    vll Power_two(N);
    Power_two[0]=1;
    for(int i=1; i<N; i++){
        Power_two[i]=(Power_two[i-1]*2ll)%mod;
    }
    t_c{
        int n,i,j;
        cin>>n;
        map<int,int>cnt;
        for(i=0; i<n; i++){
            cin>>j;
            cnt[j]++;
        }
        n = cnt.size();
        vll v(n);//,pre_sum(n);
        i=0;
        ll total=0;
        for(auto to:cnt){
            v[i]=Power_two[to.ss]-1;
            //pre_sum[i]=v[i];
            total = (total+v[i++])%mod;
        }

        for(i=n-2; i>=0; i--){
            //pre_sum[i]=(pre_sum[i]+pre_sum[i+1])%mod;
            total = (total + v[i]*v[i+1]%mod)%mod;
            v[i]+=v[i+1];
        }
        cout<<total<<endl;
    }
}
```
