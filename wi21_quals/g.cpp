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
const int mxN = 1e7 + 5;


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char dd[4] = {'U', 'L', 'D', 'R'};

int n, t, a[mxN], pf[mxN], notPrime[mxN], ans[mxN];


void calcPrimes(){
	for (int i = 2; i < mxN; i+=2){
		pf[i] = 2;
		notPrime[i] = 1;
	}
	notPrime[2] = 0;

	for (int i = 3; i < mxN; i+=2){
		if (!notPrime[i]){
			pf[i] = i;
			for (int j = i; (ll) i * j < mxN; j+=2){
				if(!notPrime[i * j]){
					pf[i*j] = i;
					notPrime[i*j] = 1;
				}
			}
		}
	}
}

int main(){
	calcPrimes();
    cin >> t;
    while(t--){
		cin >> n;
		memset(ans, 0, sizeof(ans));
		F0R(i, n){
			cin >> a[i];
		}
		F0R(i, n){
			int j = a[i];
			while (j > 1){
				ans[pf[j]] = 1;
				j = j/pf[j];
			}
		}
		
		for (int i = 2; i <= 1e7; i++){
			if (!ans[i] && !notPrime[i]){
				cout << i << endl;
				break;
			}
		}
	}
}