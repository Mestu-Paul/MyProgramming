<h2> Algorithm: Greedy</h2>
<h2> Problem: <a href="https://www.codechef.com/LRNDSA02/problems/ZCO15004">ZCO15004 Rectangle</a></h2>

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
const ll N = 100000;
int main(){
    FIO;
    int n,i,j;
    cin>>n;
    vpll v(n);
    for(i=0; i<n; i++){
        cin>>v[i].ff>>v[i].ss;
    }
    sort(all(v));
    ll ans = max(v[0].ff*500ll,(N-v.back().ff)*500ll);
    for(i=0; i<n; i++){
        ll lft=0,rgt=N,height = v[i].ss;
        j = i;
        while(j>=0 and v[j].ss>=v[i].ss){
            lft=j;j--;
        }
        j=i;
        while(j<n and v[j].ss>=v[i].ss){
            rgt = j;j++;
        }
        if(lft!=0)lft=v[lft-1].ff;
        if(rgt+1<n)rgt=v[rgt+1].ff;
        else rgt = N;
        ans = max(ans,height*(rgt-lft));
        ll width = (i+1==n)?N-v[i].ff:v[i+1].ff-v[i].ff;
        ans = max(ans,width*500ll);
    }
    cout<<ans<<endl;
}
```
