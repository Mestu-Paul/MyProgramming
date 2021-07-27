///problem link : https://www.spoj.com/problems/CPCRC1C/
///algorithm : digitDP
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
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define t_c int test, cs = 1;cin >> test;while (test--)
#define casep cout << "Case " << cs++ << ": ";
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
ll n;
vll v;
ll dp[11][2];
vll makeDigit(int a){
    vll tmp;
    while(a){
        tmp.pb(a%10);
        a/=10;
    }
    reverse(all(tmp));
    return tmp;
}
ll lensum(int l){
    ll ans=0;
    while(l<n){
        ans=ans*10+v[l++];
    }
    return ans;
}
ll f(int pos, int issmall){
    ///cout<<"call "<<pos<<" "<<issmall<<endl;
    if(pos>=n)return 0;
    if(dp[pos][issmall]!=-1)
        return dp[pos][issmall];
    int lo=0,hi=v[pos];
    if(issmall)hi=9;
    dp[pos][issmall]=0;
    for(int i=lo; i<=hi; i++){
        if(i<hi||issmall){
            dp[pos][issmall] += (f(pos+1,1)+i*(ll)(pow(10,n-pos-1)));
        }
        else{
            dp[pos][issmall] += f(pos+1,0) + i*(lensum(pos+1)+1);
        }
    }
    return dp[pos][issmall];
}
int main()
{
    FIO;
    ll a,b;
    while(cin>>a>>b){
        if(a==-1&&b==-1)return 0;
        if(a<=1)a=0;
        else {
            memset(dp,-1,sizeof dp);
            v = makeDigit(a-1);
            n = siz(v);
            a = f(0,0);
        }
        v.clear();
        memset(dp,-1,sizeof dp);
        v = makeDigit(b);
        n = siz(v);
        b = f(0,0);
        cout<<b-a<<endl;
        v.clear();
    }
}
