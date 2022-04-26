<h2> Algorithm: Trie , XOR</h2>
<h2> Problem: <a href="https://www.spoj.com/problems/SUBXOR/">SubXor</a></h2>

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
class Trie{
    public:
        Trie* child[2];
        int childCount[2];
        Trie(){
            child[0]=child[1]=NULL;
            childCount[0]=childCount[1]=0;
        }
        void Insert(int a){
            Trie* cur = this;
            for(int i=20; i>=0; i--){
                int d = (a>>i)&1;
                cur->childCount[d]++;
                if(cur->child[d]==NULL)
                    cur->child[d]=new Trie();
                cur = cur->child[d];
            }
        }
        ll query(int a, int k){
            Trie* cur = this;
            ll ans=0;
            for(int i=20; i>=0; i--){
                if(cur==NULL)break;
                int d = (a>>i)&1;
                int b = (k>>i)&1;
                if(b){
                    ans += cur->childCount[d];
                    cur = cur->child[d^1];
                }
                else{
                    cur = cur->child[d];
                }
            }
            return ans;
        }
};
int main(){
    FIO;
    t_c{
        int n,k;
        cin>>n>>k;
        Trie* head = new Trie();
        head->Insert(0);
        ll ans=0,XOR=0,a;
        for(int i=0; i<n; i++){
            cin>>a;
            XOR ^= a;
            ans += head->query(XOR,k);
            head->Insert(XOR);
        }
        cout<<ans<<endl;
    }
}
```