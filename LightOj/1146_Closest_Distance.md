<h2> Algorithm: Ternery Search</h2>
<h2> Problem: <a href="https://lightoj.com/problem/closest-distance">1146 Closest Distance</a></h2>

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
#define print(v) for (auto it : v)cout << it<<'\n';
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
double const eps=1e-8;
double x[4],y[4];
double calc(double m){
    double x1 = x[0]+(x[1]-x[0])*m;
    double y1 = y[0]+(y[1]-y[0])*m;
    double x2 = x[2]+(x[3]-x[2])*m;
    double y2 = y[2]+(y[3]-y[2])*m;

    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int main(){
    FIO;
    t_c{
        for(int i=0; i<4; i++){
            cin>>x[i]>>y[i];
        }
        double lo=0,hi=1;
        while(hi-lo>eps){
            double m1 = (2*lo+hi)/3;
            double m2 = (lo+2*hi)/3;
            if(calc(m1)<calc(m2)){
                hi=m2;
            }
            else{
                lo=m1;
            }
        }
        casep;
        cout<<fixed<<setprecision(6)<<sqrt(calc(lo))<<endl;
    }
}
```
