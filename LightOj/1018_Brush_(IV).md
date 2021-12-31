<h2> Algorithm: Dynamic Programming</h2>
<h2> Problem: <a href="https://lightoj.com/problem/brush-4">1018 Brush (IV)</a></h2>

First method :

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
double const eps=1e-8;
class Class{
    public:
    int n;
    vector<double> ax,ay;
    vvi same;
    vi dp;
    Class(int a){
        n=a;
        ax.resize(a);
        ay.resize(a);
        same.resize(a+1,vector<int>(a+1));
        dp.resize((1<<(a+1)),-1);
    }
    double dist(int p1, int p2){
        double temp = (ax[p1]-ax[p2])*(ax[p1]-ax[p2])+(ay[p1]-ay[p2])*(ay[p1]-ay[p2]);
        return sqrt(temp);
    }
    bool isSame(int p1, int p2, int p3){
        double d=(ay[p2]-ay[p1])*(ax[p3]-ax[p2]);
        double o=(ay[p3]-ay[p2])*(ax[p2]-ax[p1]);
        return d==o;
    }
    void set_same(){
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int temp = (1<<i);
                temp|=(1<<j);
                for(int k=0; k<n; k++){
                    if(isSame(i,j,k))temp|=(1<<k);
                }
                same[i][j]=temp;
            }
        }
    }
    int Final(int mask){
        if(dp[mask]!=-1)
            return dp[mask];
        if(mask==(1<<n)-1)
            return dp[mask]=0;
        int one = __builtin_popcount(mask);
        if(one==n-1 or one==n-2)return dp[mask]=1;
        dp[mask]=8;
        for(int i=0; i<n; i++){
            if(mask&(1<<i))continue;
            for(int j=i+1; j<n; j++){
                if(mask&(1<<j))continue;
                dp[mask] = min(dp[mask],Final(mask|same[i][j])+1);
            }
            break;
        }
        return dp[mask];
    }
};
int main(){
    FIO;
    t_c{
        int n,i,j;
        cin>>n;
        Class obj(n);
        for(i=0; i<n; i++){
            cin>>obj.ax[i]>>obj.ay[i];
        }
        obj.set_same();
        casep;
        cout<<obj.Final(0)<<endl;
    }
}
```

Second method:

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
double const eps=1e-8;
class Class{
    public:
    int n;
    vector<double> ax,ay;
    vvi same;
    vi dp;
    Class(int a){
        n=a;
        ax.resize(a);
        ay.resize(a);
        same.resize(a+1,vector<int>(a+1));
        dp.resize((1<<(a+1)),-1);
    }
    double dist(int p1, int p2){
        double temp = (ax[p1]-ax[p2])*(ax[p1]-ax[p2])+(ay[p1]-ay[p2])*(ay[p1]-ay[p2]);
        return sqrt(temp);
    }
    bool isSame(int p1, int p2, int p3){
        double d=(ay[p2]-ay[p1])*(ax[p3]-ax[p2]);
        double o=(ay[p3]-ay[p2])*(ax[p2]-ax[p1]);
        return d==o;
    }
    int Final(int mask){
        if(dp[mask]!=-1)
            return dp[mask];
        if(mask==(1<<n)-1)
            return dp[mask]=0;
        int one = __builtin_popcount(mask);
        if(one==n-1 or one==n-2)return dp[mask]=1;
        dp[mask]=8;
        for(int i=0; i<n; i++){
            if(mask&(1<<i))continue;
            for(int j=i+1; j<n; j++){
                if(mask&(1<<j))continue;
                int temp = (1<<i);
                temp|=(1<<j);
                for(int k=0; k<n; k++){
                    if(isSame(i,j,k))temp|=(1<<k);
                }
                dp[mask] = min(dp[mask],Final(mask|temp)+1);
            }
            break;
        }
        return dp[mask];
    }
};
int main(){
    FIO;
    t_c{
        int n,i,j;
        cin>>n;
        Class obj(n);
        for(i=0; i<n; i++){
            cin>>obj.ax[i]>>obj.ay[i];
        }
        //obj.set_same();
        casep;
        cout<<obj.Final(0)<<endl;
    }
}
```