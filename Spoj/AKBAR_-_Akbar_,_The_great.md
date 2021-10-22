<h2> Algorithm: GRAPH and TREE</h2>
<h2> Problem: <a href="https://www.spoj.com/problems/AKBAR/">AKBAR - Akbar , The great</a></h2>

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
#define read(v, a, n)           \
    for (int i = a; i < n; i++) \
        cin >> v[i];
#define print(v)           \
    for (auto it : v)      \
        cout << it << ' '; \
    cout << endl;
#define PI acos(-1.0)
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define t_c           \
    int test, cs = 1; \
    cin >> test;      \
    while (test--)
#define casep cout << "Case " << cs++ << ": ";
///#define endl '\n'
///................function.....................///
#define D(a) (double)(a)
#define sqr(a) (a * a)
#define siz(s) (int)(s.size())
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define Min(a) *min_element(all(a))
#define Max(a) *max_element(all(a))
#define mod 1000000007
 
///.........Graph.........///
int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};
 
///........constant........///
const int N = 2e5 + 5;
 
///........temporary.........///
#define mid (b + e) / 2
#define lft nd * 2
#define rgt nd * 2 + 1
vvi g;
vi vis;
struct  tp
{
    int now, dis,prev;
};
 
bool bfs(int a, int b)
{
    queue<tp>q;
    tp temp = {a, b, 0};
    q.push(temp);
    if(vis[a]!=0)return true;
    vis[a]=a;
    while(!q.empty())
    {
        tp t1 = q.front();
        q.pop();
        if(vis[t1.now]!=0&&vis[t1.now]!=a)
            return true;
        if(t1.dis==0)continue;
        for(auto to:g[t1.now])
        {
            q.push({to,t1.dis-1,t1.now});
            vis[to]=a;
        }
    }
    return false;
}
int main()
{
    FIO;
    ///freopen("output.txt","r",stdin);
    ///freopen("in.txt","w",stdout);
    t_c
    {
        int n, r, m, i, j;
        cin >> n >> r >> m;
        g.resize(n+1);
        vis.resize(n + 1);
        int a, b;
        for (i = 0; i < r; i++)
        {
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        bool ans = true;
        for (i = 0; i < m; i++)
        {
            cin >> a >> b;
            if (ans)
            {
                if (bfs(a, b))
                {
                    ans = false;
                }
            }
        }
        for(i=1; i<=n; i++)if(vis[i]==0)ans=false;
        if(ans)yes;
        else no;
        vis.clear();
        g.clear();
    }
}
```
