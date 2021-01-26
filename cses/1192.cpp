#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define f first
// #define s second

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

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char dd[4] = {'U', 'L', 'D', 'R'};

int n, m;
string s[1000];

void dfs(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || s[i][j] == '#') {
        return;
    }
    // cout << i << j << "\n";
    s[i][j] = '#';
    for (int d = 0; d < 4; d++) {
        dfs(i+dx[d], j+dy[d]);
    }
}

int main(){
    int c = 0;
	cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                dfs(i, j);
                c += 1;
            }
        }
    }
    cout << c << "\n";
}