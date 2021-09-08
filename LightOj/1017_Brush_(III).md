<h2> Algorithm: DP</h2>
<h2> Problem: <a href="https://lightoj.com/problem/brush-3">1017 Brush (III)</a></h2>

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
int dp[101][101],v[101],n,w,k;
int cnt[101];
int fun(int pos, int K){
    if(pos>n or K==0)return 0;
    int &ret=dp[pos][K];
    if(ret!=-1)return ret;
    ret=0;
    for(int i=pos; i<=n; i++){
        if(v[i]-v[pos]<=w){
            ret = max(ret,i-pos+1+fun(i+1,K-1));
        }
        ret = max(ret,fun(i+1,K));
    }
    return ret;
}
int main(){
    FIO;
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    t_c{
        int i,j;
        cin>>n>>w>>k;
        memset(dp,-1,sizeof dp);
        for(i=1; i<=n; i++)cin>>j>>v[i];
        sort(v+1,v+n+1);
        casep;
        cout<<fun(1,k)<<endl;
    }
}
```
