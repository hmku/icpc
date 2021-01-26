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

ll t, x, y, x2, y2, x3, y3;

string solve(ll x, ll y, ll x2, ll y2, ll x3, ll y3) {
	// // THIS OVERFLOWS
	// if (y == y2) {
	// 	if (y3 == y2) {
	// 		return "TOUCH";
	// 	}
	// 	else if ((y3 > y2 && x < x2) || (y3 < y2 && x > x2)) {
	// 		return "LEFT";
	// 	}
	// 	else {
	// 		return "RIGHT";
	// 	}
	// }
	// ll m = (x2 - x) / (y2 - y);
	// // cout << m << "\n";
	// ll xp = x + (y3 - y)*m;
	// // cout << xp << "\n";
	// if (xp == x3) {
	// 	return "TOUCH";
	// }
	// else if ((x3 < xp && y < y2) || (x3 > xp && y > y2)) {
	// 	return "LEFT";
	// }
	// else {
	// 	return "RIGHT";
	// }

	ll c = (x2 - x) * (y3 - y) - (y2 - y) * (x3 - x);
	if (c < 0) {
		return "RIGHT";
	}
	else if (c > 0) {
		return "LEFT";
	}
	else {
		return "TOUCH";
	}
}

int main(){
	cin >> t;
	for (int i = 0; i < t; i++){
		cin >> x >> y >> x2 >> y2 >> x3 >> y3;
		cout << solve(x, y, x2, y2, x3, y3) << "\n";
	}
}