## Algorithm : Floyd Warshall and chinese postman
## Problem link: <a href="https://lightoj.com/problem/jogging-trails">Jogging Trails</a>
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
const ll N = 2005;
const int inf = 10000000;
int n,m;
int dis[15][15];
void Floyd_Warshall(){
    int i,j,k;
    for(k=0; k<n; k++){
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}
int main(){
    FIO;
    t_c{
        cin>>n>>m;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                dis[i][j]=inf;
            dis[i][i]=0;
        }
        int a,b,c,total=0;
        int deg[n];memset(deg,0,sizeof deg);
        for(int i=0; i<m; i++){
            cin>>a>>b>>c;a--,b--;
            dis[a][b]=dis[b][a]=min(dis[a][b],c);
            total+=c;
            deg[a]++,deg[b]++;
        }
        Floyd_Warshall();
        ///chinese postman start
        c=0;
        int odda[n];
        for(int i=0; i<n; i++){
            if(deg[i]&1){
                odda[c++]=i;
            }
        }
        int dp[(1<<c)];
        for(int i=0; i<(1<<c); i++)dp[i]=inf;
        dp[0]=0;
        for(int i=0; i<c; i++){
            for(int j=0; j<c; j++){
                for(int bit=0; bit < (1<<c); bit++){
                    if(i==j or (bit&(1<<i)) or (bit&(1<<j)))continue;
                    dp[(bit | (1<<i)) | (1<<j)] = min( dp[(bit | (1<<i)) | (1<<j)],dp[bit]+dis[odda[i]][odda[j]]);
                }
            }
        }
        ///chinese postman finished
        total+=dp[(1<<c)-1];
        casep;
        cout<<total<<endl;
    }

}
```
