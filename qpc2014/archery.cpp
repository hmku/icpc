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


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char dd[4] = {'U', 'L', 'D', 'R'};



ll n, m, x, x2, y, y2, r;
const int N = 10e6;
int a[N];
int cs[N+1];


int main(){
	cin >> n;
    int k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        a[k] += 1;
    }
    cs[0] = 0;
    for (int i = 1; i < N+1; i++) {
        cs[i] = cs[i-1] + a[i-1];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> x2 >> y2;
        double d1 = sqrt(x*x + y*y);
        double d2 = sqrt(x2*x2 + y2*y2);
        r += (cs[int(ceil(max(d1, d2)))] - cs[int(ceil(min(d1, d2)))]);
    }
    cout << r;
}
