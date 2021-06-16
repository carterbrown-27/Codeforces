#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using uset = unordered_set<T>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

int query(int t, int i, int j, int x){
	printf("? %d %d %d %d\n", t, i, j, x);
	fflush(stdout);
		
	int ans;
	scanf("%d", &ans);
	assert(ans != -1);
	return ans;
}

void solve() {
	int n;
	cin >> n;
	
	int a = -1;

	for(int i = 0; i+1 < n; i += 2){
		int ans = query(1, i+1, i+2, n-1);
		
		if(ans == n){
			// found biggest (at i or j)
			int arb = (i == 0 ? 2 : 0);
			
			if(query(1, i+1, arb+1, n-1) == n) {
				a = i;
			}else{
				a = i+1;
			}
			break;
			
		}else if(ans == n-1){
			if(query(1, i+2, i+1, n-1) == n){
				a = i;
				break;
			}
		}
	}
	
	if(a==-1){
		assert(n%2 != 0);
		a = n-1;
	}
	
	vector<int> res(n);
	res[a] = n;
	
	for(int i = 0; i < n; i++){
		if(i == a){
			continue;
		}
		
		res[i] = query(2, i+1, a+1, 1);
	}
	
	cout << "! ";
	for(int i = 0; i < n; i++){
		cout << res[i] << " ";
	}
	cout << endl;
}

int main() {
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}