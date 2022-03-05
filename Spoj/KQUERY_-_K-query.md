<h2> Algorithm: Divide and Conquer</h2>
<h2> Problem: <a href="https://www.spoj.com/problems/KQUERY/">KQUERY - K-query</a></h2>

```c++
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vct vector
#define vi vct<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vvi vct<vi>
#define vll vct<ll>
#define vvll vct<vll>
#define vpii vct<pii>
#define vpll vct<pll>
#define vb vct<bool>
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
#define ft cout << "for test" << endl;
#define read(v, a, n) for (int i = a; i < n; i++)cin >> v[i];
#define print(v) for (auto it : v)cout << it << ' ';cout << endl;
#define PI acos(-1.0)
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define t_c int test, cs = 1;cin >> test;while (test--)
#define casep cout << "Case " << cs++ << ":"<<endl;
///................function.....................///
#define D(a) (double)(a)
#define sqr(a) (a * a)
#define siz(s) (int)(s.size())
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define Min(a) *min_element(all(a))
#define Max(a) *max_element(all(a))
 
///.........Graph.........///
int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};
///........constant........///
const int N = 3e4 + 5;
const ll mod =  1e9+7;
vi v(N);
vvi tree(4*N);
void Merge(int nd){
    int l = nd*2,r=nd*2+1;
    int n1 = siz(tree[nd*2]);
    int n2 = siz(tree[nd*2+1]);
    int i=0,j=0;
    while(i<n1&&j<n2){
        if(tree[l][i]<tree[r][j]){
            tree[nd].pb(tree[l][i++]);
        }
        else{
            tree[nd].pb(tree[r][j++]);
        }
    }
    while(i<n1)tree[nd].pb(tree[l][i++]);
    while(j<n2)tree[nd].pb(tree[r][j++]);
}
void build(int nd, int b, int e){
    if(b>e)return;
    if(b==e){
        tree[nd].pb(v[b]);
        return ;
    }
    int m = (b+e)/2;
    build(nd*2,b,m);
    build(nd*2+1,m+1,e);
    Merge(nd);
}
int query(int nd, int b, int e, int l, int r, int k){
    if(b>r||e<l)return 0;
    if(l<=b&&e<=r){
        int pos = upper_bound(all(tree[nd]),k)-tree[nd].begin();
        return siz(tree[nd])-pos;
    }
    int m=(b+e)/2;
    int p1 = query(nd*2,b,m,l,r,k);
    int p2 = query(nd*2+1,m+1,e,l,r,k);
    return p1+p2;
}
int main()
{
    FIO;
    int n,i,j,k;
    cin>>n;
    for(i=1; i<=n; i++)cin>>v[i];
    build(1,1,n);
    int q;
    cin>>q;
    while(q--){
        cin>>i>>j>>k;
        cout<<query(1,1,n,i,j,k)<<endl;
    }
}

```
