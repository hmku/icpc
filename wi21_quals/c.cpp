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
const int mxN = 2e5 + 1;


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char dd[4] = {'U', 'L', 'D', 'R'};


int n, w, d, c, u, ans;
int dp[mxN], curr[mxN], capacity[mxN];
vi adj[mxN];

void dfs(int u){
	for (auto& a : adj[u]){
		dp[a] = capacity[a] - curr[a] + max(0, dp[u] - capacity[a]);
		ans = min(ans, dp[a]);
		dfs(a);
	}
}

int main(){
	cin >> n >> w;
	F0R(i, n){
		cin >> d >> c >> u;
		adj[d].pb(i+1);	
		curr[i+1] = u;
		capacity[i+1] = c;
	}
	capacity[0] = w;
	ans = w;
	dp[0] = w;
	dfs(0);

	cout << ans << endl;
}