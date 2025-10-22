#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pi;
typedef map<int, int> mi;
typedef vector<long long> vl;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl "\n"
#define nl cout << "\n"
#define loopf(i,a,b) for(int i=a;i<b;i++)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define metaprint cout << "Case #" << ts << ": ";
#define read(v) for(int i=0;i<(int)v.size();++i) cin>>v[i]
#define read1(v) for(int i=1;i<(int)v.size();++i) cin>>v[i]
#define print(v) {for(int i=0;i<(int)v.size();++i)cout<<v[i]<<" ";nl;}
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define bits(x) __builtin_popcountll(x)
#define minvec(a) *min_element(a.begin(), a.end())
#define maxvec(a) *max_element(a.begin(), a.end())
const ll mod = 1e9+7;
const ll mod1 = 998244353;
const ld pie = 3.141592653589793238;
using i128 = __int128_t;

void solve(int ts) {
    int n;  cin>>n;
    vl a(n);    read(a);

    vl pref;    ll cur = 0;
    pref.PB(cur);

    for(int i=0; i<n; i++){
        cur ^= a[i];
        pref.PB(cur);
    }

    i128 stotal = ((i128)n*((i128)n+1)*((i128)n+2))/6;
    ll total = (ll)stotal;
    sort(all(pref));
    i128 cnt = 0;     int i = 0;

    while(i <= n){
        int j = i+1;
        while(j <= n and pref[j] == pref[i])  j++;

        i128 c = (j-i);
        if(c >= 2){
            i128 c2 = (c*(c-1))/2;
            i128 c3 = (c >= 3) ? (c*(c-1)*(c-2)/6) : 0;
            cnt += c2 + c3;
        }
        i = j;
    }

    i128 ans = total - cnt;
    metaprint
    cout<<(ll)ans<<endl;
}


int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int tests; cin>>tests;
    for(int t=1; t<=tests; t++){
        solve(t);
    }
    return 0;
}