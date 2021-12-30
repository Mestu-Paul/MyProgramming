<h2> Algorithm: Segment tree</h2>
<h2> Problem: <a href="https://lightoj.com/problem/fast-queries">1188 Fast Queries</a></h2>

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
#define print(v) for (auto it : v)cout << it<<'\n';
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
const ll N = 1e6+5;
#define lft nd*2
#define rgt nd*2+1
#define mid (b+e)/2

class segment_tree{
    public:
        int sz,i,j;
        vi tree;
        segment_tree(int n){
            sz=n;
            tree.resize(4*n);
        }
        void build(int nd, int b, int e, int l,int val){
            if(b>e or l<b or e<l)return;
            if(b==e and b==l){
                tree[nd]=val;
                return;
            }
            build(lft,b,mid,l,val);
            build(rgt,mid+1,e,l,val);
            tree[nd]=tree[lft]+tree[rgt];
        }
        int query(int nd, int b, int e, int l, int r){
            if(b>e or e<l or r<b)
                return 0;
            if(l<=b and e<=r){
                return tree[nd];
            }
            int p1 = query(lft,b,mid,l,r);
            int p2 = query(rgt,mid+1,e,l,r);
            return p1+p2;
        }
};
struct tp{
    int l,r,pos;
};
bool cmp(tp a, tp b){
    if(a.r==b.r)
        return a.l<=b.l;
    return a.r<b.r;
}
int main(){
    FIO;
    t_c{
        int n,q,i,j=0;
        cin>>n>>q;
        vi v(n+1);
        for(i=1; i<=n; i++){
            cin>>v[i];
            j = max(j,v[i]);
        }
        vector<tp> qry(q);
        segment_tree seg(n);
        vi pos(j+1);
        for(i=0; i<q; i++){
            cin>>qry[i].l>>qry[i].r;
            qry[i].pos=i;
        }
        sort(all(qry),cmp);
        int cur=0;
        casep;
        vi result(q);
        for(i=1; i<=n and cur<q; i++){
            if(pos[v[i]]!=0){
                seg.build(1,1,n,pos[v[i]],0);
            }
            pos[v[i]]=i;
            seg.build(1,1,n,i,1);
            while(cur<q and qry[cur].r==i){
                result[qry[cur].pos]=seg.query(1,1,n,qry[cur].l,qry[cur].r);
                cur++;
            }
        }
        print(result);
    }
}
```
