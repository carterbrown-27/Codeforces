#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

void solve() {
	int n;
	cin >> n;
	string a,b;
	cin >> a >> b;
	
	vector<bool> opPts(n+1);
	opPts[0] = true;
	int d = 0;
	for(int i = 1; i <= n; i++){
		d += (a[i-1] == '1' ? 1 : -1);
		opPts[i] = (d==0);
		// cout << opPts[i] << " ";
	}
	// cout << endl;
	
	vector<bool> signs(n);
	for(int i = 0; i < n; i++){
		signs[i] = (a[i] != b[i]);
		// cout << signs[i] << " ";
	}
	// cout << endl;
	
	
	bool works = true;
	
	bool cur = 0;
	for(int i = n; i-- > 0;){
		if(signs[i] != cur){
			if(opPts[i+1]){
				cur = !cur;
			}else{
				works = false;
				break;
			}
		}
	}
	
	cout << (works ? "YES" : "NO") << endl;
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