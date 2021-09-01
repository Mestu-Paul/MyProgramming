<h2> Algorithm: Random</h2>
<h2> Problem: <a href="https://lightoj.com/problem/birthday-paradox">1104 Birthday Paradox</a></h2>

```c++
#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define t_c int test, cs = 1;cin>>test;while (test--)
#define casep cout<<"Case "<< cs++<<": ";
int main(){
    FIO;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    t_c{
        double n,a=1;
        cin>>n;
        int MinDay=0;
        double b=n;
        while((1.0-a)*100<50){
            a*=(b/n);
            b--;
            MinDay++;
        }
        casep;
        cout<<max(0,MinDay-1)<<endl;
    }
}
```
