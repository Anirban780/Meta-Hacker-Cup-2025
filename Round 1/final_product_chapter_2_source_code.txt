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
const int inf = INT_MAX;
using i128 = __int128_t;

const int K = 50;
ll fact[K+1], invfact[K+1];

ll modpow(ll a, ll b, ll m = mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = ((i128)res * a) % m;
        a = ((i128)a * a) % m;
        b >>= 1;
    }
    return res;
}

void precmp() {
    fact[0] = 1;
    for(int i=1; i<=K; i++)
        fact[i] = (i128)fact[i-1] * i % mod;

    invfact[K] = modpow(fact[K], mod-2, mod);
    for(int i=K-1; i>=0; i--)
        invfact[i] = (i128)invfact[i+1] * (i+1) % mod;
}

ll comb(ll n, ll k){
    if(k < 0 || k > K) return 0;
    if(k == 0) return 1;

    ll num = 1;
    for(ll i=0; i<k; i++)
        num = (i128)num * ((n+i) % mod) % mod;

    return (i128)num * invfact[k] % mod;
}

// Deterministic Miller-Rabin for n <= 10^14
bool prime(ll n){
    if(n < 2) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;

    ll d = n-1, r = 0;
    while(d % 2 == 0){ d /= 2; r++; }

    // Deterministic witnesses for n <= 10^14
    vl witnesses;
    if(n < 4759123141LL) witnesses = {2, 3, 5, 7, 11, 13, 23};
    else witnesses = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    for(auto a : witnesses){
        if(a >= n) break;
        ll x = modpow(a, d, n);
        if(x == 1 || x == n-1) continue;

        bool comp = true;
        for(int i=1; i<r; i++){
            x = (i128)x * x % n;
            if(x == n-1){ comp = false; break; }
        }
        if(comp) return false;
    }
    return true;
}

ll find_factor(ll n){
    if(n % 2 == 0) return 2;
    for(ll i=3; i*i <= n; i+=2){
        if(n % i == 0) return i;
    }
    return n;
}

map<ll, int> factorise(ll n){
    map<ll, int> factors;
    while(n % 2 == 0){ factors[2]++; n /= 2; }
    
    while(n > 1){
        if(prime(n)){ factors[n]++; break; }
        
        ll d = find_factor(n);
        while(n % d == 0){ 
            factors[d]++; 
            n /= d; 
        }
    }
    return factors;
}

ll dfs(int i, ll cur_d, ll curp, vector<pair<ll, int>>& pf, vector<vl>& ls, vector<vl>& rs, ll A){
    if(i == (int)pf.size()) return curp;

    ll p = pf[i].F; int e = pf[i].S;
    ll res = 0; 
    ll ppow = 1;

    for(int f=0; f<=e; f++){
        if((i128)cur_d * ppow > A) break;
        ll nd = cur_d * ppow;
        ll npro = (i128)curp * ls[i][f] % mod * rs[i][f] % mod;

        res = (res + dfs(i+1, nd, npro, pf, ls, rs, A)) % mod;
        
        if(ppow > (ll)1e18 / p) break;
        ppow *= p;
    }
    return res;
}

void solve(int ts) {
    ll n, a, b; cin >> n >> a >> b;
    auto factors = factorise(b);
    
    vector<pair<ll, int>> pf;
    for(auto& pr : factors) pf.push_back(pr);

    int np = pf.size();
    vector<vl> ls(np), rs(np);

    for(int i=0; i<np; i++){
        int e = pf[i].S;
        ls[i].resize(e+1);
        rs[i].resize(e+1);

        for(int f=0; f<=e; f++){
            ls[i][f] = comb(n, f);
            rs[i][f] = comb(n, e-f);
        }
    }

    ll ans = dfs(0, 1, 1, pf, ls, rs, a);
    metaprint
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    precmp();
    int tests; cin >> tests;
    for(int t=1; t<=tests; t++){
        solve(t);
    }
    return 0;
}