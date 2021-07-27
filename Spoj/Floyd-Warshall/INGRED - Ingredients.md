## Algorithm: Floyd Warshall
## Problem: [Ingredients](https://www.spoj.com/problems/INGRED/)
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
#define casep cout<<"Case #"<< cs++<<": ";
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
const ll inf = 1e8;
int main(){
    FIO;
    int n,m,i,j;
    cin>>n>>m;
    int dis[n][n];
    for(i=0; i<n; i++){
        for(j=0; j<n; j++)
            dis[i][j]=inf;
        dis[i][i]=0;
    }
    int a,b,c;
    for(i=0; i<m; i++){
        cin>>a>>b>>c;
        dis[a][b]=c;
        dis[b][a]=c;
    }
    int s;cin>>s;
    vi v(s);
    for(i=0; i<s; i++){
        cin>>v[i];
    }
    for(int k=0; k<n; k++){
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    int mn=inf;
    cin>>a>>b;
    int total = (1<<s);
    sort(all(v));
    do {
        //print(v);
        for(i=0; i<s; i++){
            int pre=a,c1=0,c2=0;
            for(j=0; j<i; j++){
                //cout<<"first "<<pre<<" "<<v[j]<<" "<<dis[pre][v[j]]<<endl;
                c1 += dis[pre][v[j]];
                pre = v[j];
            }
            pre = b;
            for(j=i; j<s; j++){
                //cout<<"second "<<pre<<" "<<v[j]<<" "<<dis[pre][v[j]]<<endl;
                c2 += dis[pre][v[j]];
                pre = v[j];
            }
            mn = min(mn,c1+c2);
        }
    }
    while(next_permutation(all(v)));
    cout<<mn<<endl;
}
```
