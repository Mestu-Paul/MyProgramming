<h2>Algorithm: Segment tree</h2>
<h2>Problem: <a href="https://www.spoj.com/problems/GSS3/">GSS3 - Can you answer these queries III</a>

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
#define print(v) for (auto it : v)cout << it<<" ";cout << endl;
#define PI acos(-1.0)
#define yes cout <<"Yes"<< endl
#define no cout<<"No"<<endl
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define t_c int test, cs = 1;cin>>test;while (test--)
#define casep cout<<"Case "<< cs++<<": ";
///................function.....................///
 
#define D(a) (double)(a)
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
class Segtree{
    public:
    vi v;
    class Type{
        public:
        ll sum,max_sum,pref,suff;
        Type(){
            sum=max_sum=pref=suff=0;
        }
        Type(int a){
            sum=max_sum=pref=suff=a;
        }
    };
    vector<Type>tree;
    int n;
    Segtree(int _n){
        n=_n;
        v.resize(n);
        tree.resize(n*4);
    }
    void Merge(Type& ans,Type a, Type b){
        ans.sum=a.sum+b.sum;
        ans.max_sum = max3(a.suff+b.pref,a.max_sum,b.max_sum);
        ans.pref = max(a.pref,a.sum+b.pref);
        ans.suff = max(a.suff+b.sum,b.suff);
    }
    void build(int nd, int b, int e){
        if(b>e)return;
        if(b==e){
            tree[nd]=Type(v[b]);
            return;
        }
        build(lft,b,mid);
        build(rgt,mid+1,e);
        Merge(tree[nd],tree[lft],tree[rgt]);
    }
    void update(int nd, int b, int e, int l){
        if(b>e or l<b or e<l)return;
        if(b==e and e==l){
            tree[nd]=Type(v[l]);
            return ;
        }
        update(lft,b,mid,l);
        update(rgt,mid+1,e,l);
        Merge(tree[nd],tree[lft],tree[rgt]);
    }
    Type query(int nd, int b, int e, int l, int r){
        Type ret(INT_MIN);
        if(b>e or e<l or r<b)
            return ret;
        if(l<=b and e<=r){
            return tree[nd];
        }
        Type p1 = query(lft,b,mid,l,r);
        Type p2 = query(rgt,mid+1,e,l,r);
        Merge(ret,p1,p2);
        //cout<<b<<" - "<<mid<<" = "<<p1.max_sum<<" "<<mid+1<<" - "<<e<<" = "<<p2.max_sum<<endl;
        //cout<<b<<" - "<<e<<" = "<<ret.max_sum<<endl;
        return ret;
    }
};
int main(){
    FIO;
    int n;
    cin>>n;
    Segtree obj(n+1);
    for(int i=1; i<=n; i++){
        cin>>obj.v[i];
    }
    obj.build(1,1,n);
    int m;cin>>m;
    while(m--){
        int tp,x,y;
        cin>>tp>>x>>y;
        if(tp){
            cout<<obj.query(1,1,n,x,y).max_sum<<endl;
        }
        else{
            obj.v[x]=y;
            obj.update(1,1,n,x);
        }
    }
} 
```