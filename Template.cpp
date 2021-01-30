#include<bits/stdc++.h>

//--------------definitions-------------
#define endl '\n'
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define ALL(v) v.begin(), v.end()
#define ALLR(v) v.rbegin(), v.rend()
#define UNIQUE(v) (v).resize(unique(ALL(v))-(v).begin())
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i, a, b) for(int i=(int)a;i <= (int)b;i++)
#define forri(i, b, a) for(int i=(int)b; i >= (int)a;i--)
#define bse(v,f) binary_search(ALL(v),f)
#define lb(v,f) lower_bound(ALL(v),f)
#define ub(v,f) upper_bound(ALL(v),f)
#define SZ(x) (int)x.size()
#define pub push_back
#define MOD int(1e9+7)
//--------------definitions-------------

using namespace std;

//--------------DEBUG--------------
#define ts to_string
string ts(char c) { return string(1, c); }
string ts(bool b) { return b ? "true" : "false"; }
string ts(const char* s) { return (string)s; }
string ts(string s) { return s; }
template<class A> string ts(complex<A> c) { 
	stringstream ss; ss << c; return ss.str(); }
string ts(vector<bool> v) { 
	string res = "{"; for(int i = 0; i < (int)(v).size(); ++i) res += char('0' + v[i]);
	res += "}"; return res; }
template<size_t SZ> string ts(bitset<SZ> b) {
	string res = ""; for(int i = 0; i < SZ; ++i) res += char('0' + b[i]);
	return res; }
template<class A, class B> string ts(pair<A,B> p);
template<class T> string ts(T v) { // containers with begin(), end()
	bool fst = 1; string res = "{";
	for (const auto& x: v) {
		if (!fst) res += ", ";
		fst = 0; res += ts(x);
	}
	res += "}"; return res;
}
template<class A, class B> string ts(pair<A,B> p) {
	return "(" + ts(p.fi) + ", " + ts(p.se) + ")"; }

void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << ts(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
void EDBG(string names) { names = names; }
template<class H, class... T> void EDBG(string names, H h, T... t) {
	auto pos = names.find(',');
	auto first_name = names.substr(0, pos);
	auto rest = names.substr(pos + 1);
	while(rest.front() == ' '){
		rest = rest.substr(1);
	}
	cerr << "[" << first_name << "]: [" << ts(h) << "]" << "\n";
	EDBG(rest, t...);
}
#ifdef LOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define edbg(...) EDBG(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 0
#define edbg(...) 0
#endif
//--------------DEBUG--------------
//--------------DTypes-------------
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;
//--------------DTypes-------------
void solve(){
    ll n,m,x;
    cin>>n>>m;
    vi a(n);
    forn(i,n){
        cin>>a[i];
    }
}
int main(){
    fast
    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}