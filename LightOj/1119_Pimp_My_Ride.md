<h2> Algorithm: Dynamic Programming</h2>
<h2> Problem: <a href="https://lightoj.com/problem/pimp-my-ride">1119 Pimp My Ride</a></h2>

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
ll dp[15][(1<<15)];
int n;
vvi grid(15);
ll fun(int pos, int bit){
    if(dp[pos][bit]!=-1)return dp[pos][bit];
    ll tmp=0,minimum=LONG_MAX;
    for(int i=0; i<n; i++){
        if(bit&(1<<i))tmp+=grid[pos][i];
    }
    if(__builtin_popcount(bit)==n)return tmp;
    for(int i=0; i<n; i++){
        if(bit&(1<<i))continue;
        minimum = min(minimum,fun(i,bit|(1<<i)));
    }
    return dp[pos][bit]=minimum+tmp;
}
int main(){
    FIO;
    t_c{
        cin>>n;
        int i,j;
        for(i=0; i<n; i++){grid[i].clear();grid[i].resize(n+1);}
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                cin>>grid[i][j];
            }
        }
        memset(dp,-1,sizeof dp);
        casep;
        cout<<fun(0,0)<<endl;
    }
}
```
