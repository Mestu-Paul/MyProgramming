<h2> Algorithm: Segment tree</h2>
<h2> Problem: <a href="https://toph.co/p/nothing-is-absolute-everything-is-relative">Nothing Is Absolute, Everything Is Relative!</a></h2>

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
#define lft nd*2
#define rgt nd*2+1
#define mid (b+e)/2

class A{
public:
    vll tree,dif;
    A(int n){
        dif.resize(n+1);
        tree.resize(4*n);
    }
    void update(int nd, int b, int e, int l){
        if(e<l or l<b)return;
        if(b==e and e==l){
            tree[nd]=abs(dif[l]);
            return;
        }
        update(lft,b,mid,l);
        update(rgt,mid+1,e,l);
        tree[nd]=tree[lft]+tree[rgt];
    }
    ll query1(int nd, int b, int e, int l, int r){
        if(e<l or r<b){
            return 0;
        }
        if(l<=b and e<=r){
            return tree[nd];
        }
        ll p1 = query1(lft,b,mid,l,r);
        ll p2 = query1(rgt,mid+1,e,l,r);
        return p1+p2;
    }
};
int main(){
    FIO;
    int n,m,i,j;
    cin>>n>>m;
    A ob(n);
    vi v(n+1);
    for(i=1; i<=n; i++){
        cin>>v[i];
    }
    for(i=1; i<n; i++){
        ob.dif[i]=v[i+1]-v[i];
        ob.update(1,1,n,i);
    }
    //print(ob.dif);
    while(m--){
        int a,b,c;
        cin>>c;
        if(c==1){
            cin>>a>>b>>c;
            if(a-1>=1){
                ob.dif[a-1]+=c;
                ob.update(1,1,n,a-1);
                //cout<<"updat1 l ";print(ob.dif);
            }
            if(b<n){
                ob.dif[b]-=c;
                ob.update(1,1,n,b);
                //cout<<"update r ";print(ob.dif);
            }
        }
        else{
            cin>>a>>b;
            cout<<ob.query1(1,1,n,a,b-1)<<endl;
        }
    }

}
```
