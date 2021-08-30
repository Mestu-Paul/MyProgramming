<h2> Algorithm: Interactive</h2>
<h2> Problem: <a href="https://codeforces.com/contest/1556/problem/D">Take a Guess</a></h2>

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
int main(){
    FIO;
    int n,k,i,j;
    cin>>n>>k;
    vi v;
    ll x,y,z,a,b,c;
    string s;
    cout<<"and 1 2"<<endl;cin>>i;
    cout<<"or 1 2"<<endl;cin>>j;
    x = i+j;
    cout<<"and 2 3"<<endl;cin>>i;
    cout<<"or 2 3"<<endl;cin>>j;
    y=i+j;
    cout<<"and 1 3"<<endl;cin>>i;
    cout<<"or 1 3"<<endl;cin>>j;
    z=i+j;
    c = (y+z-x)/2;
    b = y-c;
    a = x-b;
    v.pb(a);v.pb(b);v.pb(c);
    for(i=4; i<=n; i++){
        cout<<"and "<<i-1<<" "<<i<<endl;cin>>a;
        cout<<"or "<<i-1<<" "<<i<<endl;cin>>b;
        v.pb(a+b-c);
        c=v.back();
    }
    sort(all(v));
    //UNIQUE(v);
    cout<<"finish "<<v[k-1]<<endl;
}

```
