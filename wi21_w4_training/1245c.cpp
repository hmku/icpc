#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef vector<int> vi;
typedef vector<int, int> vii;
typedef pair<int, int> pi;

const unsigned int M = 1000000007;

// bool sortSec(const pair<pi, int> &a, const pair<pi, int> &b){
// 	return (a.f.s < b.f.s);
// }

// struct Grid{
// 	int r;
// 	int c;
// 	int d;
// 	string ans;

// 	Grid(int r, int c, int d, string ans) 
// 		: r(r), c(c), d(d), ans(ans)
// 	{
// 	}
// };

// struct compareGrid {
// 	bool operator()(Grid const& g1, Grid const& g2){
// 		return g1.d > g2.d; // min heap
// 	}
// };

// int dx[4] = {-1, 0, 1, 0};
// int dy[4] = {0, -1, 0, 1};
// char dd[4] = {'U', 'L', 'D', 'R'};

int n;
string s;

int solve(string s) {
	int dp[s.length()+1] = {0};
    dp[0] = 1;
    dp[1] = 1;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'w' || s[i] == 'm') {
			return 0;
		}
		else if (i > 0) {
			if ((s[i] == 'n' && s[i-1] == 'n') || (s[i] == 'u' && s[i-1] == 'u')) {
				dp[i+1] = (dp[i] + dp[i-1]) % M;
			}
			else {
				dp[i+1] = dp[i];
			}
		}
	}
	return dp[s.length()];
}

int main(){
	cin >> s;
	cout << solve(s);
}