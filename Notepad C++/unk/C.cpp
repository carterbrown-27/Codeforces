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
	
	vector<string> v(n);
	for(string& s: v){
		cin >> s;
	}
	
	const int K = 5;
	
	vector<vector<int>> cnts(n);
	for(int i = 0; i < n; i++){
		string s = v[i];
		
		vector<int> tmp(K+1);
		for(char c: s){
			tmp[c-'a']++;
		}
		tmp[K] = s.length();
		cnts[i] = tmp;
	}
	
	int mx = 0;
	for(int i = 0; i < K; i++){
		sort(cnts.begin(), cnts.end(), [&](vector<int> a, vector<int> b) {
			// best g-b
			return a[i] - (a[K] - a[i]) > b[i] - (b[K] - b[i]);
		});
		
		int g = 0, b = 0;
		for(int j = 0; j < n; j++){
			g += cnts[j][i];
			b += cnts[j][K] - cnts[j][i];
			
			// cout << g << " " << b << endl;
			if(g > b){
				mx = max(mx, j+1);
			}
		}
	}
	
	cout << mx << endl;
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