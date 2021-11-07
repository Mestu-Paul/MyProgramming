<h2> Algorithm: DP</h2>
<h2> Problem: <a href="https://lightoj.com/problem/fast-bit-calculations">1032 Fast Bit Calculations</a></h2>

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
///........constant........///a
const ll N = 1e6+5;
ll dp[32][2][2],n;
vi bit,pre_cal;
ll cal(int pos, int isSmall){
  if(isSmall)
    return (1ll<<(n-pos));
  else
    return pre_cal[pos]+1;
}
ll fun(int pos, int pre_bit, int isSmall){
  if(pos>=n){
    return 0;
  }
  ll &ret = dp[pos][pre_bit][isSmall];
  if(ret!=-1){
    return ret;
  }
  ret=0;
  int hi = (isSmall)?1:bit[pos];
  for(int i=0; i<=hi; i++){
    ret =ret+fun(pos+1,i,isSmall|(i<hi));
    if(i==1 and pre_bit==1)ret+=cal(pos+1,isSmall);
  }
  return ret;
}
void NumberToDigit(ll a){
  bit.clear();
  pre_cal.clear();
  n=0;
  while(a){
    bit.pb(a&1);
    a/=2;
    n++;
  }
  reverse(all(bit));
  pre_cal.resize(n+1);
  ll two=1;
  for(int i=n-1; i>=0; i--){
    pre_cal[i] = pre_cal[i+1]+bit[i]*two;
    two*=2;
  }
}
int main(){
    FIO;
    t_c{
      ll a;
      cin>>a;
      NumberToDigit(a);
      memset(dp,-1,sizeof dp);
      casep;
      cout<<fun(0,0,0)<<endl;
    }
}
```
