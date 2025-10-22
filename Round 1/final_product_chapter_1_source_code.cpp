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

void solve(int ts) {
    int n,a,b;  cin>>n>>a>>b;
    metaprint

    // first n days
    for(int i=1; i<=n; i++)
        cout<<1<<" ";

    // at day n+1
    cout<<b<<" ";

    // remaining days
    for(int i=n+2; i<=2*n; i++)
        cout<<1<<" ";

    cout<<endl;
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