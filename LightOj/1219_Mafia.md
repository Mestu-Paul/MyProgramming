<h2> Algorithm: Graph(BFS and DFS)</h2>
<h2> Problem: <a href="https://lightoj.com/problem/mafia">1219 Mafia</a></li></h2>

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
struct Type{
    ll cost,node_free,mafia_free;
    vector<int>adj;
    Type(){
        adj.clear();
        node_free=cost=mafia_free=0ll;
    }
};
vector<Type>Tree;
vb vis;
void Set_and_Reset(int n){
    Tree.clear();
    Tree.resize(n+1);
    //vis.clear();
    //vis.resize(n+1);
    for(int i=0; i<=n; i++)Tree[i]=Type();
}
void dfs(int par, int node){
    //cout<<"from "<<par<<" to "<<node<<endl;
    //vis[node]=1;
    for(auto to:Tree[node].adj){
        if(to==par)continue;
        dfs(node,to);
        Tree[node].cost+=Tree[to].mafia_free+Tree[to].node_free+Tree[to].cost;
        Tree[node].node_free+=Tree[to].node_free;
        Tree[node].mafia_free+=Tree[to].mafia_free;
        
    }
    if(Tree[node].mafia_free>=Tree[node].node_free){
        Tree[node].mafia_free-=Tree[node].node_free;
        Tree[node].node_free=0;
    }
    else{
        Tree[node].node_free-=Tree[node].mafia_free;
        Tree[node].mafia_free=0;
    }
    //cout<<"cost "<<Tree[node].cost<<" free node "<<Tree[node].node_free<<" mafia "<<Tree[node].mafia_free<<endl;
}
int main(){
    FIO;
    //freopen("output.txt","w",stdout);
    t_c{
        int n,i,j;
        cin>>n;
        Set_and_Reset(n);
        ll node,mafia,num,child;
        int root;
        for(i=1; i<=n; i++){
            cin>>node>>mafia>>num;
            Tree[node].mafia_free=mafia;
            Tree[node].node_free=1;
            if(num>0)root=node;
            for(j=0; j<num; j++){
                cin>>child;
                Tree[node].adj.pb(child);
                Tree[child].adj.pb(node);
            }
        }
        //cout<<endl<<endl;
        dfs(0,root);
        casep;
        cout<<Tree[root].cost<<endl;
    }
}
```
