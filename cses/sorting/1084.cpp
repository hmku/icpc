#include <bits/stdc++.h>
using namespace std;

// nice typedefs
typedef double db;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

// arrays
#define ar array

// pairs
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

// vectors
#define vt vector
#define len(x) (int) (x).size()
#define beg(x) (x).begin()
#define en(x) (x).end()
#define all(x) beg(x), en(x)
#define sor(x) sort(all(x)) 
#define sorr(x) sort(all(x), greater<>())
#define resz resize
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back 
#define pf push_front

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define EACH(x, a) for (auto& x: a)

// input/output/debug
template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
	cin >> x;
}
void read(double& d) {
	string t;
	read(t);
	d=stod(t);
}
void read(long double& d) {
	string t;
	read(t);
	d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}
template<class A> void read(vt<A>& x) {
	EACH(a, x)
		read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
	EACH(a, x)
		read(a);
}
 
string to_string(char c) {
	return string(1, c);
}
string to_string(bool b) {
	return b?"true":"false";
}
string to_string(const char* s) {
	return string(s);
}
string to_string(string s) {
	return s;
}
string to_string(vt<bool> v) {
	string res;
	F0R(i, len(v))
		res+=char('0'+v[i]);
	return res;
}
 
template<size_t S> string to_string(bitset<S> b) {
	string res;
	F0R(i, S)
		res+=char('0'+b[i]);
	return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
		if(!f)
			res+=' ';
		f=0;
		res+=to_string(x);
	}
    return res;
}
 
template<class A> void write(A x) {
	cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) { 
	write(h);
	write(t...);
}
void print() {
	write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
	write(h);
	if(sizeof...(t))
		write(' ');
	print(t...);
}
 
void DBG() {
	cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	DBG(t...);
}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

// constants
const unsigned int MOD = 1e9 + 7;
const ll INF = 1e18;

// grids
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char dd[4] = {'U', 'L', 'D', 'R'};

// ------------------------------------------------------

ll n, m, k;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
	read(n, m, k);
	vi p;
	vi a;	
	F0R(i, n) {
		int x;
		read(x);
		p.pb(x);
	}
	F0R(i, m) {
		int x;
		read(x);
		a.pb(x);
	}
	sor(p);
	sor(a);
	int i = 0;
	int j = 0;
	int ct = 0;
	while (i < n && j < m) {
		if (p[i] < a[j]-k) {
			i++;
		}
		else if (p[i] > a[j]+k) {
			j++;
		}
		else {
			ct++, i++, j++;
		}
	}
	print(ct);
}
