## Algorithm: Lowest Common Ancestor (LCA) + BFS
## Problem: [Lowest Common Ancestor](https://www.spoj.com/problems/ADAVISIT/)

```c++
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
///........constant........///
const ll N = 4e5+5;
vvi up(N,vi(20,-1)),g(N);
vi depth(N),preSum(N),vis(N);
int n,Log;
void bfs(){
    queue<int>q;
    q.push(0);
    depth[0]=0;up[0][0]=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto to:g[u]){
            if(up[to][0]==-1){
                up[to][0]=u;//cout<<u<<" >> "<<to<<endl;
                depth[to]=depth[u]+1;
                q.push(to);
            }
        }
    }
}
void build(){
    for(int bit=1; bit<20; bit++){
        for(int i=0; i<n; i++){
            if(up[i][bit-1]==-1)continue;
            up[i][bit] = up[ up[i][bit-1] ][bit-1];
            //cout<<i<<" "<<bit<<" << "<<up[i][bit-1]<<" "<< up[ up[i][bit-1]][bit-1]<<endl;
        }
    }
}
int lcaQuery(int a, int b){
    if(depth[a]<depth[b])swap(a,b);
    int k = depth[a]-depth[b];
    for(int i=19; i>=0; i--){
        if(k&(1<<i)){
            //cout<<k<<" "<<i<<" "<<a<<" "<<up[a][i]<<endl;
            a = up[a][i];
        }
    }
    //cout<<k<<" dis "<<a<<" "<<b<<endl;
    if(a==b)return a;
    for(int i=Log; i>=0; i--){
        if(up[a][i]!=up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}
void dfs(int node){
    for(auto to:g[node]){
        if(depth[to]>depth[node]){
            dfs(to);
            preSum[node]+=preSum[to];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int i,j;
    cin>>n;
    Log = log2(n);
    int a,b;
    for(i=1; i<n; i++){
        cin>>a>>b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs();
    build();
    up[0][0]=-1;
    for(i=0; i<n-1; i++){
        int lca = lcaQuery(i,i+1);
        preSum[i]++;preSum[i+1]++;
        preSum[lca]--;
        //cout<<i<<" "<<i+1<<" "<<lca<<endl;
        //cout<<up[lca][0]<<" <<<<<< rooot"<<endl;
        if(up[lca][0]!=-1)preSum[up[lca][0]]--;
    }
    //for(i=0; i<n; i++)cout<<i<<" "<<preSum[i]<<endl;
    dfs(0);
    for(i=0; i<n; i++)cout<<preSum[i]<<endl;

}
```