<h2> Algorithm: Grid (BFS and DFS)</h2>
<h2> Problem: <a href="https://lightoj.com/problem/power-puff-girls">1238 Power Puff Girls</a></h2>

```c++
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define t_c int test, cs = 1;cin>>test;while (test--)
#define casep cout<<"Case "<< cs++<<": ";
#define max3(a, b, c) max(a, max(b, c))
///.........Graph.........///
int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};
const ll N = 1e6+5;
int bfs(pii pos, pii dest, string s[],int n, int m){
    int dp[n][m];
    for(int i=0; i<n; i++)for(int j=0; j<m; j++)dp[i][j]=N;
    dp[pos.ff][pos.ss]=0;
    priority_queue<pair<int,pii>>q;q.push({0,pos});
    while(!q.empty()){
        pii node = q.top().ss;
        int val = -1*q.top().ff;q.pop();
        for(int i=0; i<4; i++){
            int x = node.ff+X[i];
            int y = node.ss+Y[i];
            if(0<=x and x<n and 0<=y and y<m and s[x][y]!='#' and s[x][y]!='m' and dp[x][y]>val+1){
                dp[x][y]=val+1;
                q.push({-1*dp[x][y],{x,y}});
            }
        }
    }
    return dp[dest.ff][dest.ss];
}
int main(){
    FIO;
    t_c{
        int n,m,i,j;
        cin>>n>>m;
        string s[n];
        pii pos[5];
        map<char,int>cast;cast['a']=1,cast['b']=2,cast['c']=3,cast['h']=4;
        for(i=0; i<n; i++){
            cin>>s[i];
            for(j=0; j<m; j++){
                pos[cast[s[i][j]]]={i,j};
            }
        }
        casep;
        cout<<max3(bfs(pos[1],pos[4],s,n,m),bfs(pos[2],pos[4],s,n,m),bfs(pos[3],pos[4],s,n,m))<<endl;
    }
}
```
