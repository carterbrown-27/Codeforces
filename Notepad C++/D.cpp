#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point {
	int x,y;
};

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

template<typename T>
using uset = unordered_set<T>;

#define pb push_back

void solve() {
	int n;
	cin >> n;
	
	int N = 2*n;
	
	int c[N][N];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> c[i][j];
		}
	}
	
	ll ans = 0;
	for(int i = n; i < N; i++){
		for(int j = n; j < N; j++){
			ans += c[i][j];
			c[i][j] = 0; // jic
		}
	}
	
	// djikstra from top left to find best path to bottom right
	ll INF = 1e18;
	vector<vector<ll>> d(N, vector<ll>(N, INF));
	vector<vector<point>> prev(N, vector<point>(N, {-1,-1}));
	d[0][0] = 0;
	
	using edge = tuple<ll,int,int>;
	minpq<edge> q;
	q.push({0,0,0});
	
	point d4[4] = {{-1,0},{0,-1},{1,0},{0,1}};
	while(!q.empty()){
		auto t = q.top();
		ll d_v = get<0>(t);
		point p {get<1>(t), get<2>(t)};
		q.pop();
		
		// outdated
		if(d[p.x][p.y] != d_v)
			continue;
	
		for(int i = 0; i < 4; i++){
			int nx = ((p.x + d4[i].x) % N + N) % N;
			int ny = ((p.y + d4[i].y) % N + N) % N;
			int cost = c[nx][ny];
			
			if(d_v + cost < d[nx][ny]){
				d[nx][ny] = d_v + cost;
				prev[nx][ny] = p;
				q.push({d[nx][ny], nx, ny});
			}
		}
	}
	
	ans += d[N-1][N-1];
	
	point cur = {N-1, N-1};
	while(prev[cur.x][cur.y].x != -1){
		cur = prev[cur.x][cur.y];
		c[cur.x][cur.y] = 0;
		//cout << cur.x << " " << cur.y << endl;
	}
	
	vector<int> adj_costs;
	for(int i = n; i < 2*n; i++){
		adj_costs.pb(c[i][n-1]);
		adj_costs.pb(c[i][0]);
		adj_costs.pb(c[n-1][i]);
		adj_costs.pb(c[0][i]);
	}
	
	sort(adj_costs.begin(), adj_costs.end());
	for(int i = 0; i < n-1; i++){
		ans += adj_costs[i];
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}