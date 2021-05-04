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
	
	for(int i = 1; i <= n; i++){
		ll sum = 0;
		for(int x = 1; x <= i; x++)
			for(int y = 1; y <= i; y++)
				sum += abs(x-y);
			
		cout << sum << "/" << i*i << " || " << i*i - 1 << "/" << 3*i << " -> ";
		bool good = (((float) sum / (i*i)) == ((float) (i*i - 1) / (3*i)));
		cout << good << endl;
		
		if(!good) break;
	}
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}