<h2> Algorithm: DP Bitmask</h2>
<h2> Problem: <a href="https://lightoj.com/problem/marriage-ceremonies">1011 Marriage Ceremonies</a></h2>

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
const ll N = (1<<16);
vvi v;
int dp[16][N],n;
void Set_and_Reset(){
    v.resize(16,vi(16));
    memset(dp,-1,sizeof dp);
}
int fun(int pos, int female){
    if(__builtin_popcount(female)==n)
        return 0;
    int &ret=dp[pos][female];
    if(~ret)return ret;
    ret=0;
    for(int i=0; i<n; i++){
        if(female&(1<<i))continue;
        ret=max(ret,fun(pos+1,female|(1<<i))+v[pos][i]);
    }
    return ret;
    
}
int main(){
    FIO;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    t_c{
        int i,j;
        cin>>n; Set_and_Reset();
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                cin>>v[i][j];
            }
        }
        
        casep;
        cout<<fun(0,0)<<endl;
    }
}
```
