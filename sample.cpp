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

int n, m, a, b, visited[100001];
vector<int> road[100001];

int main(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> a >> b;
		road[a].pb(b);
		road[b].pb(a);
	}	

	// (city, dist)
	queue<pi> q;
	q.push(mp(1, 0));
	visited[1] = 1;
	while (!q.empty()){
		pi u = q.front(); q.pop();

		cout << u.f << " " << u.s << endl;

		if (u.f == 1 && u.s >= 3){
			cout << u.s + 1 << endl;
			vector<int> path;
			path.pb(1);
			int curr = visited[1];
			while (curr != 1){
				path.pb(visited[curr]);
				curr = visited[curr];
			}

			reverse(path.begin(), path.end());
			for (int i = 0; i < path.size(); i++){
				cout << path[i] << " ";
			}
			cout << endl;
			return 0;
		}

		for (auto e : road[u.f]){
			if (u.s >= 2){
				if (e == 1){
					q.push(mp(e, u.s + 1));
				}
				else if (!visited[e]){
					q.push(mp(e, u.s + 1));
					visited[e] = u.f;
				}
			}
			else if (!visited[e] && e != 1){
				q.push(mp(e, u.s + 1));
				visited[e] = u.f;
			}
		}
	}

	cout << "IMPOSSIBLE" << endl;
}