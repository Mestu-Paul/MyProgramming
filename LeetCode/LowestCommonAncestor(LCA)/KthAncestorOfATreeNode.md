## Algortigm : LCA
## Problem: <a href="https://leetcode.com/problems/kth-ancestor-of-a-tree-node/">Kth Ancestor of a Tree Node</a>
```c++
/**
#include<bits/stdc++.h>
using namespace std;
**/
class TreeAncestor {
    vector<vector<int>> up;
    int LOG;
public:
    TreeAncestor(int n, vector<int>& parent) {
        LOG=18;
        up = vector<vector<int>>(n,vector<int>(LOG,-1));
        for(int i=0; i<n; i++)
            up[i][0]=parent[i];
        for(int i=1; i<LOG; i++){
            for(int v=0; v<n; v++){
                if(up[v][i-1]==-1)continue;
                up[v][i] = up[ up[v][i-1] ][i-1];
            }
        }
    }
    int getKthAncestor(int node, int k) {
        for(int i=LOG-1; i>=0; i--){
            if(k&(1<<i)){
                node = up[node][i];
                if(node==-1)break;
            }
        }
        return node;
    }
};
/**
int main(){
    vector<int>v = {-1,0,0,1,1,2,2};
    TreeAncestor obj(7,v);
    while(true){
        int a,b;
        cin>>a>>b;
        cout<<obj.getKthAncestor(a,b)<<endl;
    }
}
**/
```