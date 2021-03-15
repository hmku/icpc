#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define f first
#define s second
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
const ll INF = 1e18;
const int mxN = 2e5;


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char dd[4] = {'U', 'L', 'D', 'R'};

int n, x[mxN], dp[mxN];

int main(){
	cin >> n;
	F0R(i, n){
		cin >> x[i];
		dp[i] = i-1;
		while (dp[i] != -1  && x[dp[i]] >= x[i]){
			dp[i] = dp[dp[i]];
		}
		cout << dp[i] + 1 << " ";
	}
}


















