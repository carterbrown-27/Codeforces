#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

template<typename T>
using uset = unordered_set<T>;

#define pb push_back

int d4[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
enum Tile {water, land, sea, visland};
int n, m;

void sea_dfs(vector<vector<int>>& a, int i, int j){
	if(i < 0 || i >= n || j < 0 || j >= m || a[i][j] != water)
		return;
	
	a[i][j] = sea;
	for(auto d: d4){
		sea_dfs(a, i+d[0], j+d[1]);
	}
}

void sea_dfs(vector<vector<int>>& a){
	for(int i = 0; i < n; i++){
		sea_dfs(a, i, 0);
		sea_dfs(a, i, m-1);
	}
	
	for(int j = 0; j < m; j++){
		sea_dfs(a, 0, j);
		sea_dfs(a, n-1, j);
	}
}

int land_dfs(vector<vector<int>>& a, int i, int j){
	if(i < 0 || i >= n || j < 0 || j >= m || a[i][j] == sea)
		return 1;
	
	if(a[i][j] != land)
		return 0;
	
	int ans = 0;
	a[i][j] = visland;
	for(auto d: d4){
		ans += land_dfs(a, i+d[0], j+d[1]);
	}
	
	return ans;
}

int land_dfs(vector<vector<int>>& a){
	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(a[i][j] == land) ans += land_dfs(a, i, j);
		
	return ans;
}

int main() {
	cin >> n >> m;
	
	// 0 = water, 1 = land, 2 = sea, 3 = visland
	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < m; j++){
			a[i][j] = s[j]-'0';
		}
	}
	
	sea_dfs(a);
	// lazy
	cout << land_dfs(a) << endl;
	
	/*
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cout << a[i][j];
		cout << "\n";
	}
	*/
	
	return 0;
}