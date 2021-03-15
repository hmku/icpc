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
	bool c[s.length()] = {false};
	int res = 0;
	if (s.length() == 1) {
		return 0;
	}
	for (int i = 1; i < s.length(); i++) {
		if ((s[i] == s[i-1] && !c[i-1]) || (i-2>=0 && s[i] == s[i-2] && !c[i-2])) {
			c[i] = true;
			res++;
		}
	}
	return res;
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		cout << solve(s) << "\n";
	}
}