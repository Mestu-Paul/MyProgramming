## Algorithm: Floyd Warshall
## Problem: [Arbitrage](https://www.spoj.com/problems/ARBITRAG/)

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
#define casep cout<<"Case #"<< cs++<<": ";
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
const ll inf = 1e16;
int main(){
    FIO;
    int n;
    int cs=1;
    while(cin>>n and n){
        int m,i,j,k;
        string s,p;
        map<string,int>numbering;
        for(i=0; i<n; i++){
            cin>>s;numbering[s]=i;
        }
        double rate[n][n],a;
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                rate[i][j]=0.0;
                rate[i][i]=1.0;
            }
        }
        cin>>m;
        for(i=0; i<m; i++){
            cin>>s>>a>>p;
            rate[numbering[s]][numbering[p]]=a;
        }
        for(k=0; k<n; k++){
            for(i=0; i<n; i++){
                for(j=0; j<n; j++){
                    rate[i][j] = max(rate[i][j],rate[i][k]*rate[k][j]);
                }
            }
        }
        bool hobe=0;
        for(i=0; i<n; i++){
            if(rate[i][i]>1.0){
                hobe=1;break;
            }
        }
        cout<<"Case "<<cs++<<": "<<((hobe)?"Yes":"No")<<endl;
    }

}
```
