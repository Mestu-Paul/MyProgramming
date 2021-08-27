<h2> Algorithm: Grid (BFS and DFS)</h2>
<h2> Problem: <a href="https://lightoj.com/problem/the-crystal-maze">1337 The Crystal Maze</a></h2>

```c++
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pair<int,int>>
#define vb vector<bool>
#define mp make_pair
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define t_c int test, cs = 1;cin>>test;while (test--)
#define casep cout<<"Case "<< cs++<<":\n";
///................function.....................///

///.........Graph.........///
int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};
class Try{
    public:
        int n,m;
        vector<vb>vis;
        vector<vpii>par;
        vector<string>s;
        map<pii,int>result;
        void Set(int _n, int _m){
            n=_n;m=_m;
            result.clear();
            s.resize(n);
            vis.resize(n,vb(m,false));
            par.resize(n,vpii(m));
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    par[i][j]={i,j};
                }
            }
        }
        void bfs(pii root){
            queue<pii>q;
            q.push(root);
            vis[root.ff][root.ss]=true;
            int total=0;
            while(!q.empty()){
                pii u=q.front();
                total += (s[u.ff][u.ss]=='C');
                q.pop();
                for(int i=0; i<4; i++){
                    int x = u.ff+X[i];
                    int y = u.ss+Y[i];
                    if(0<=x and x<n and 0<=y and y<m and vis[x][y]==false){
                        vis[x][y]=true;
                        par[x][y]=root;
                        q.push({x,y});
                    }
                }
            }
            result[root]=total;
        }
};
int main(){
    FIO;
    t_c{
        Try obj;
        int n,m,i,j,q;
        cin>>n>>m>>q;
        obj.Set(n,m);
        for(i=0; i<n; i++){
            cin>>obj.s[i];
            for(j=0; j<m; j++){
                if(obj.s[i][j]=='#')obj.vis[i][j]=true;
            }
        }
        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                if(obj.vis[i][j])continue;
                obj.bfs(mp(i,j));
            }
        }
        casep;
        while(q--){
            cin>>i>>j;
            i--;j--;
            pii root = obj.par[i][j];
            cout<<obj.result[root]<<endl;
        }

    }
}
```
