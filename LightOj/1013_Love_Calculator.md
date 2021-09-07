<h2> Algorithm: DP (Longest Common Subsequence)</h2>
<h2> Problem: <a href="https://lightoj.com/problem/love-calculator">1013 Love Calculator</a></h2>

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
struct type{
    ll len,unique;
};
type dp[32][32];
int main(){
    FIO;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    memset(dp,-1,sizeof dp);
    t_c{
        string s1,s2;
        cin>>s1>>s2;
        s1.insert(0,"+");
        s2.insert(0,"-");
        int n=s1.size(),m=s2.size(),i,j;
        for(i=0; i<31; i++){
            dp[i][0].len=dp[0][i].len=i;
            dp[i][0].unique=dp[0][i].unique=1ll;
        }
        for(i=1; i<n; i++){
            for(j=1; j<m; j++){
                if(s1[i]==s2[j]){
                    dp[i][j].len=1+dp[i-1][j-1].len;
                    dp[i][j].unique=dp[i-1][j-1].unique;
                }
                else{
                    dp[i][j].len = 1+min(dp[i-1][j].len,dp[i][j-1].len);
                    if(dp[i-1][j].len<dp[i][j-1].len)
                        dp[i][j].unique=dp[i-1][j].unique;
                    else if(dp[i-1][j].len>dp[i][j-1].len)
                        dp[i][j].unique=dp[i][j-1].unique;
                    else dp[i][j].unique = dp[i-1][j].unique+dp[i][j-1].unique;
                }
            }
        }
        casep;
        cout<<dp[n-1][m-1].len<<" "<<dp[n-1][m-1].unique<<endl;
    }
}
```
