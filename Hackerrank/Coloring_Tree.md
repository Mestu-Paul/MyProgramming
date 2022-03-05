<h2> Algorithm: Divide and conquer</h2>
<h2> Problem: <a href="https://www.hackerrank.com/challenges/coloring-tree/problem">Coloring Tree</a></h2>

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
#define print(v) for (auto it : v)cout << it<<'\n';//cout << endl;
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
#define lft nd*2
#define rgt nd*2+1
#define mid (b+e)/2
vvi g;
vi col,tree,in,out,mapping;
int n,m,r,Time=0;
void Set(int n){
    g.resize(n+1);
    tree.resize(4*n);
    col.resize(n+1);
    in.resize(n+1);
    out.resize(n+1);
    mapping.resize(n+1);
}
class c{
    public:
    int l,r,pos;
    c(int L, int R, int p){
        l=L;r=R;pos=p;
    }
    bool operator<(const c other)const{
        //if(this->r==other.r)
            //return this->l<=other.l;
        return this->r<other.r;
    }
};
void dfs(int nd=r, int p=r){
    Time++;
    in[nd]=Time;
    for(auto to:g[nd]){
        if(to!=p){
            dfs(to,nd);
        }
    }
    out[nd]=Time;
}
void update(int nd, int b, int e, int l, int up){
    if(b>e or e<l or l<b)return;
    if(b==e and b==l){
        tree[nd]=up;
        return;
    }
    update(lft,b,mid,l,up);
    update(rgt,mid+1,e,l,up);
    tree[nd]=tree[lft]+tree[rgt];
}
int query(int nd, int b, int e, int l, int r){
    if(b>e or e<l or r<b)return 0;
    if(l<=b and e<=r){
        return tree[nd];
    }
    int p1 = query(lft,b,mid,l,r);
    int p2 = query(rgt,mid+1,e,l,r);
    return p1+p2;
}
int main(){
    FIO;
    cin>>n>>m>>r;
    Set(n);
    int a,b;
    for(int i=1; i<n; i++){
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs();
    vi tmp_col(n+1);
    set<int>st;
    for(int i=1 ;i<=n; i++){
        cin>>tmp_col[i];
        st.insert(tmp_col[i]);
    }
    map<int,int>casting;a=1;
    for(auto to:st){
        casting[to]=a++;
    }
    for(int i=1; i<=n; i++){
        col[i]=casting[tmp_col[i]];
    }
    vector<c>q;
    for(int i=0; i<m; i++){
        cin>>a;
        q.pb(c(in[a],out[a],i));
    }
    for(int i=1; i<=n; i++){
        mapping[in[i]]=i;
    }
    vi prev_pos(n+1);
    sort(all(q));
    vi ans(m);
    for(int i=1,qq=0; i<=n and qq<m; i++){
        int color = col[mapping[i]];
        if(prev_pos[color]!=0){
            update(1,1,Time,prev_pos[color],0);
        }
        prev_pos[color]=i;
        update(1,1,Time,i,1);
        while(qq<m and q[qq].r==i){
            ans[q[qq].pos]=query(1,1,Time,q[qq].l,q[qq].r);
            qq++;
        }
    }
    print(ans);
}

```
