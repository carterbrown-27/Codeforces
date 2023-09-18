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
	
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	auto f = [&] (int k) -> bool {
		deque<int> q;
		uset<int> st;
		// monotonic queue
		for(int i = 0; i < n; i++){
			while(!q.empty() && a[q.back()] > a[i]){
				q.pop_back();
			}
			
			q.push_back(i);
			
			while(!q.empty() && i-q.front() >= k){
				q.pop_front();
			}
			
			if(i >= k-1){
				if(a[q.front()] > n-k+1){
					// cout << k << "= Too big" << endl;
					return false;
				}
				// cout << "Insert " << q.front() << endl;
				st.insert(a[q.front()]);
			}
		}
		
		return st.size() == n-k+1;
	};
	
	int l = 2, r = n;
	while(l <= r){
		// cout << l << " " << r << endl;
		int mid = (l+r)/2;
		if(f(mid)){
			r = mid-1;
		}else{
			l = mid+1;
		}
	}
	
	cout << f(1);
	for(int i = 2; i <= n; i++){
		cout << (i >= r+1);
	}
	cout << endl;
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