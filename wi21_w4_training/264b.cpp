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
int a[100000];

bool rp (int a, int b) { // Assumes a, b > 0
   return (a<b) ? rp(b,a) : !(a%b) ? (b==1) : rp(b, a%b);
}

vi pf(int n) { 
    vi res;
    if (n % 2 == 0) {
        res.push_back(2);
        while (n % 2 == 0) {
            n /= 2;
        }
    }
    for (int i = 3; i <= sqrt(n); i = i+2) {  
        if (n % i == 0) {
            res.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 2) {
        res.push_back(n);
    }
    return res;
}

int solve() {
    int r = 1;
    int dp[100000] = {0};
    for (int i = 0; i < n; i++) {
        vi f = pf(a[i]);
        int m = 0;
        for (int p: f) {
            m = max(dp[p], m);
        }
        for (int p: f) {
            dp[p] = m+1;
        }
        r = max(r, m+1);
        // cout << a[i] << " " << r << "\n";
    }
    return r;
}

int main(){
	cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
	cout << solve();
}