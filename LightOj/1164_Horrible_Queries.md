<h2> Algorithm: Segment Tree</h2>
<h2> Problem: <a href="https://lightoj.com/problem/horrible-queries">1164 Horrible Queries</a></h2>

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
#define casep cout<<"Case "<< cs++<<":\n";
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
const int N=1e5+5;
#define lft nd*2
#define rgt nd*2+1
#define mid (b+e)/2
ll tree[4*N],lazy[4*N];
void Push_Down(int nd, int b, int e){
    tree[nd]+=(e-b+1)*lazy[nd];
    if(b!=e){
        lazy[lft]+=lazy[nd];
        lazy[rgt]+=lazy[nd];
    }
    lazy[nd]=0;
}
void update(int nd, int b, int e, int l, int r, ll val){
    //cout<<b<<">> "<<e<<" "<<l<<" "<<r<<endl;
    if(lazy[nd]){
        Push_Down(nd,b,e);
    }
    if(b>e or e<l or r<b){
        return ;
    }
    if(l<=b and e<=r){
        lazy[nd]+=val;
        Push_Down(nd,b,e);
        return;
    }
    update(lft,b,mid,l,r,val);
    update(rgt,mid+1,e,l,r,val);
    tree[nd]=tree[lft]+tree[rgt];
}
ll query(int nd, int b, int e, int l, int r){
    //cout<<b<<" qq "<<e<<" "<<l<<" "<<r<<endl;
    if(lazy[nd]){
        Push_Down(nd,b,e);
    }
    if(b>e or e<l or r<b){
        return 0ll;
    }
    if(l<=b and e<=r){
        return tree[nd];
    }
    ll p1 = query(lft,b,mid,l,r);
    ll p2 = query(rgt,mid+1,e,l,r);
    return p1+p2;
}
int main(){
    FIO;
    t_c{
        int n,m,i,j;
        cin>>n>>m;
        memset(tree,0,sizeof tree);
        memset(lazy,0,sizeof lazy);
        int tp,x,y;
        ll val;
        casep;
        while(m--){
            cin>>tp;
            if(tp){
                cin>>x>>y;
                cout<<query(1,1,n,x+1,y+1)<<endl;
            }
            else{
                cin>>x>>y>>val;
                update(1,1,n,x+1,y+1,val);
            }
        }
    }
}
```
