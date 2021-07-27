// problem link : https://www.spoj.com/problems/TRYCOMP/
// algorithm : trie

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
#define casep cout<<"Case"<< cs++<<": ";
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
const ll N = 1e6;
int val;
string s;
struct Trie{
    Trie* Next[26];
    int leaf,count;
    string store;
    Trie(){
        leaf=0,count=0;
        for(int i=0; i<26; i++)
            Next[i]=NULL;
    }
};
void build(int pos, int n, Trie* root){
    if(pos==n){
        root->leaf++;
        val=root->leaf;
        if(root->count < root->leaf){
            root->count = root->leaf;
            root->store = s;
        }
        else if(root->count == root->leaf){
            root->store = min(root->store,s);
        }
        return ;
    }
    int c = s[pos]-'a';
    if(root->Next[c]==NULL){
        root->Next[c] = new Trie;
    }
    build(pos+1,n,root->Next[c]);
    if(root->count < val){
        root->store = s;
        root->count = val;
    }
    else if(root->count == val){
        root->store = min(s,root->store);
    }
}
pair<int,string>query(Trie* root){

    for(int i=0; i<siz(s); i++){
        int c = s[i]-'a';
        if(root->Next[c]==NULL)return mp(0,"");
        root = root->Next[c];
    }
    return mp(root->count,root->store);
}
int main(){
    FIO;
    Trie* root = new Trie;
    int n,i,j;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>s;
        build(0,siz(s),root);
    }
    cin>>n;
    while(n--){
        cin>>s;
        pair<int,string>ress=query(root);
        if(ress.ff==0)cout<<-1<<endl;
        else cout<<ress.ss<<" "<<ress.ff<<endl;
    }
    return 0;
} 
