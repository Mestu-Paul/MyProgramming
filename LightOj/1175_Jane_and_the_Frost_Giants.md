<h2> Algorithm: Grid(BFS</h2>
<h2> Problem: <a href="https://lightoj.com/problem/jane-and-the-frost-giants">1175 Jane and the Frost Giants</a></h2>

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
int main(){
    FIO;
    freopen("output.txt","w",stdout);
    t_c{
        int n,m,i,j;
        cin>>n>>m;
        string s[n];
        pii J,F;
        priority_queue<pair<int,pii>>q;
        int disf[n][m],disj[n][m];
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
                disf[i][j] = disj[i][j] = N;
        for(i=0; i<n; i++){
            cin>>s[i];
            for(j=0; j<m; j++){
                if(s[i][j]=='F'){
                    q.push({0,{i,j}});
                    disf[i][j]=0;
                }
                if(s[i][j]=='J')J={i,j};
            }
        }
        while(!q.empty()){
            pii node=q.top().ss;
            int val = -1*q.top().ff;
            q.pop();
            for(i=0; i<4; i++){
                int x = node.ff+X[i];
                int y = node.ss+Y[i];
                if(0<=x and x<n and 0<=y and y<m and s[x][y]!='#' and disf[x][y]>val+1){
                    disf[x][y]=val+1;
                    q.push({-1*disf[x][y],{x,y}});
                }
            }
        }
        disj[J.ff][J.ss]=0;
        q.push({0,J});
        int escape=-1;
        while(q.empty()==false and escape==-1){
            pii node=q.top().ss;
            int val = -1*q.top().ff;
            q.pop();
            for(i=0; i<4; i++){
                int x = node.ff+X[i];
                int y = node.ss+Y[i];
                if(0<=x and x<n and 0<=y and y<m){
                    if(s[x][y]!='#' and val+1<disf[x][y] and disj[x][y]>val+1){
                        disj[x][y]=val+1;
                        q.push({-1*disj[x][y],{x,y}});
                    }
                }
                else{
                    escape=val+1;break;
                }
            }
        }
        casep;
        if(escape!=-1)cout<<escape<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
    }
}
```
