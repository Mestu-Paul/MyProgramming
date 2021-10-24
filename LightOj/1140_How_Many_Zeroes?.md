<h2> Algorithm: DP</h2>
<h2> Problem: <a href="https://lightoj.com/problem/how-many-zeroes">1140 How Many Zeroes?</a></h2>

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
ll dp[11][2][2][11];
vi bit;
ll n,_size;
void NumberToDigit(ll a){
    bit.clear();
    _size=0;
    while(a){
        bit.pb(a%10);
        a/=10;
        _size++;
    }
    reverse(all(bit));
}
ll fun(ll pos, bool isSmall, bool start, int zeros){
    //cout<<pos<<" "<<isSmall<<" "<<start<<endl;
    if(pos>=_size){
        return zeros;
    }
    ll &ret = dp[pos][isSmall][start][zeros];
    if(ret!=-1)return ret;
    ret=0;
    int hi = (isSmall)?9:bit[pos];
    if(start){
        ret += fun(pos+1,isSmall|(0<hi),1,zeros+1);
        for(int i=1; i<=hi; i++)
            ret += fun(pos+1,isSmall|(i<hi),1,zeros);
    }
    else{
        for(int i=0; i<=hi; i++){
            ret += fun(pos+1,isSmall|(i<hi),i>0,0);
        }
    }
    return ret;
}
int main(){
    FIO;/**
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE**/
    t_c{
        ll a,b;
        cin>>a>>b;
        NumberToDigit(a-1);
        memset(dp,-1,sizeof dp);
        ll a1 = fun(0,0,0,0)-(a==0);
        NumberToDigit(b);
        memset(dp,-1,sizeof dp);
        ll a2 = fun(0,0,0,0);
        casep;
        //cout<<a2<<" "<<a1<<endl;
        cout<<a2-a1<<endl;
        
    }
}
```
