## Algorithm : Shortest Path
## Problem : <a href="https://www.spoj.com/problems/CHICAGO/">106 miles to Chicago</a>
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
#define casep cout<<"Case"<< cs++<<": ";
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
    int n,m,i,j;
    while(cin>>n and n){
        cin>>m;
        double ekso=100.0;
        vector<vector<pair<int,double>>>g(n+1);
        int a,b;double w;
        for(i=0; i<m; i++){
            cin>>a>>b>>w;
            g[a].pb(mp(b,w));
            g[b].pb(mp(a,w));
        }
        queue<int>q;q.push(1);
        double dis[n+1];
        for(i=0; i<=n; i++)dis[i]=-50000.0;
        dis[1]=100;
        while(!q.empty()){
            int u = q.front();q.pop();
            for(auto to:g[u]){
                double New = (dis[u]*to.ss)/ekso;
                if(dis[to.ff]<New){
                    dis[to.ff]=New;
                    q.push(to.ff);
                    //cout<<u<<" "<<to.ff<<" "<<dis[to.ff]<<endl;
                }
            }
        }
        cout<<fixed<<setprecision(6)<< dis[n]<<" percent"<<endl;

    }

}
```
