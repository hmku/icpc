#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define f first
// #define s second
#define lb lower_bound
#define ub upper_bound

// #define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

const unsigned int MOD = 1e9 + 7;
const ll INF = 1e9;
const int mxN = 1e7 + 5;


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char dd[4] = {'U', 'L', 'D', 'R'};

int n;
vector<set<string>> a;
map<string, ll> pd, d;

int rep(){
	trav(s, a){
		if (s == a[a.size() - 1]){
			return 1;
		}
	}
	return 0;
}

set<string> rp(set<string> s1, set<string> s2, int flag){
	set<string> s;
	trav(c1, s1){
		trav(c2, s2){
			ll n1 = c1.length(); ll n2 = c2.length();
			if (n1 > n2 && c1 == c2.substr(0, n1)){
				s.insert(c2.substr(n1));
				if (!flag){
					if (d.find(c2.substr(n1)) != d.end()){
						if (pd.find(c2) != pd.end()){
							d[c2.substr(n1)] = min(d[c2.substr(n1)], pd[c2] + n1);
						}
						else {
							d[c2.substr(n1)] = min(d[c2.substr(n1)], n1);
						}
					}
					else {
						if (pd.find(c2) != pd.end()){
							d[c2.substr(n1)] = min(INF, pd[c2] + n1);
						}
						else {
							d[c2.substr(n1)] = min(INF, n1);
						}						
					}
				}
				else {
					if (d.find(c2.substr(n1)) != d.end()){
						if (pd.find(c2) != pd.end()){
							d[c2.substr(n1)] = min(d[c2.substr(n1)], pd[c1] + n1);
						}
						else {
							d[c2.substr(n1)] = min(d[c2.substr(n1)], n1);
						}
					}
					else {
						if (pd.find(c2) != pd.end()){
							d[c2.substr(n1)] = min(INF, pd[c1] + n1);
						}
						else {
							d[c2.substr(n1)] = min(INF, n1);
						}
					}
				}
			}
		}
	}
	return s;
}

int main(){
	cin >> n;
	set<string> s;
	F0R(i, n){
		string c; cin >> c;
		s.insert(c);
	}
	a.pb(s);

	int i = 1;
	while(1){
		set<string> s;
		if (i == 1){
			s = rp(a[0], a[i-1], 0); 
		}
		else {
			set<string> temp1 = rp(a[0], a[i-1], 0);
			set<string> temp2 = rp(a[i-1], a[0], 1);
			
			trav(c, temp1){
				s.insert(c);
			}
			trav(c, temp2){
				s.insert(c);
			}
		}

		set<string> intersect; 
		trav(e, s){
			if (a[0].find(e) != a[0].end()){
				intersect.insert(e);
			}
		}


		if (intersect.size()) {
			ll mc = 1e9;
			trav(c, intersect) {
				mc = min(mc, d[c] + (ll)c.length());
			}
			cout << mc << endl;
			return 0;
		}
		for (int j = 1; j < i; j++) {
			if (s == a[j]) {
				cout << 0;
				return 0;
			}
		}
		a.pb(s);
		i++;
		pd = d;
	}



}