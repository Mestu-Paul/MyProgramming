<h2> Algorithm: Binary Search</h2>
<h2> Problem: <a href="https://lightoj.com/problem/counting-triangles">Counting Triangles</a></h2>

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
class solve{
    public:
    int n;
    vll v;
    solve(){
        cin>>n;
        v.resize(n);
        for(int i=0; i<n; i++)cin>>v[i];
        sort(all(v));
        //print(v);
        ll tot=0;
        for(int i=0; i+2<n; i++){
            for(int j=i+1; j+1<n; j++){
                ll tmp = BS(j+1,n-1,v[i]+v[j]-1);;
                //cout<<v[i]<<" "<<v[j]<<" >> "<<v[i]+v[j]-1<<" "<<tmp<<endl;
                tot+=tmp;
            }
        }
        cout<<tot<<endl;
    }
    int BS(int l, int hi, ll val){
        //cout<<"searching in "<<l<<" "<<hi<<" "<<val<<endl;
        if(l>hi)return 0;
        int pos=l-1;
        int lo=l;
        while(l<=hi){
            int mid = (l+hi)/2;
            if(v[mid]<=val){
                pos=mid;
                l=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        //cout<<"after searched "<<pos<<" "<<max(pos-lo+1,0)<<endl;
        return max(pos-lo+1,0);
    }

};
int main(){
    FIO;
    t_c{
        casep;
        solve s;
    }
}
```
