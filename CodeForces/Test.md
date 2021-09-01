<h2> Algorithm: LPS,KMP</h2>
<h2> Problem: <a href="https://codeforces.com/contest/25/problem/E">Test</a></h2>

```c++
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int LPS(string s1, string s2){
    string s = s2+"$"+s1;
    int i,index=0,n=s.size();
    vi lps(n);
    int tmp=0;
    for(i=1; i<s.size();){
        if(s[i]==s[index]){
            lps[i]=++index;
            if(index==s2.size()){
                tmp=index;break;
            }
            i++;
        }
        else{
            if(index!=0)index = lps[index-1];
            else i++;
        }
    }
    if(tmp)return tmp;
    return lps[n-1];
}
int main(){
    FIO;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    string s[3];
    cin>>s[0]>>s[1]>>s[2];
    int ans = s[0].size()+s[1].size()+s[2].size();
    int mn = ans;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i==j)continue;
            int compress1 = LPS(s[i],s[j]);
            int k = 3-i-j;
            string tmp = s[i];
            if(compress1!=s[j].size()){
                tmp = s[i]+s[j].substr(compress1,s[j].size()-compress1);
            }
            compress1 += LPS(tmp,s[k]);
            mn = min(mn,ans-compress1);
        }
    }
    cout<<mn<<endl;
}

```
