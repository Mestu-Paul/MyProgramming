<h2> Algorithm: BFS and DFS</h2>
<h2> Problem: <a href="https://lightoj.com/problem/gathering-food">1066 Gathering Food</a></h2>

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
    t_c{
        int n,i,j;
        cin>>n;
        string s[n];
        vpii v(26);
        int sz=0;
        for(i=0; i<n; i++){
            cin>>s[i];
            for(j=0; j<n; j++){
                if('A'<=s[i][j] and s[i][j]<='Z')
                    v[s[i][j]-'A']={i,j},sz++;
            }
        }
        vvi Final(n,vi(n,-1));
        Final[v[0].ff][v[0].ss]=0;
        bool Impossible=0;
        for(int l=0; l<sz; l++){
            pii letter=v[l];
            char Char = 'A'+l;
            //cout<<Char<<" == "<<letter.ff<<" "<<letter.ss<<" "<<Final[letter.ff][letter.ss]<<endl;
            if(Final[letter.ff][letter.ss]==-1){
                Impossible=1;break;
            }
            priority_queue<pair<int,pii>>pq;
            vvi Cur(n,vi(n,N));
            Cur[letter.ff][letter.ss]=Final[letter.ff][letter.ss];
            pq.push({-1*Cur[letter.ff][letter.ss],{letter.ff,letter.ss}});
            while(!pq.empty()){
                int val = -1*pq.top().ff;
                pii Letter = pq.top().ss;
                pq.pop();
                for(i=0; i<4; i++){
                    int x = Letter.ff+X[i];
                    int y = Letter.ss+Y[i];
                    if(0<=x and x<n and 0<=y and y<n and Cur[x][y]>val+1 and s[x][y]!='#'){
                        if('A'<=s[x][y] and s[x][y]<='Z'){
                            if(Char+1==s[x][y]){
                                Cur[x][y]=val+1;
                                Final[x][y]=val+1;
                            }
                        }
                        else{
                            Cur[x][y]=val+1;
                            pq.push({-1*Cur[x][y],{x,y}});
                        }
                    }
                }
            }
            s[letter.ff][letter.ss]='.';
        }
        casep;
        if(Impossible)cout<<"Impossible"<<endl;
        else cout<<Final[v[sz-1].ff][v[sz-1].ss]<<endl;
    }
}
```