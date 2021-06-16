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

int main() {
	ios::sync_with_stdio(false);
	
	int n, h;
	cin >> n >> h;
	
	vector<int> a(h);
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		
		if(i%2 == 0){
			// up (stalagmite)
			a[0]++;
			a[x]--;
		}else{
			// down (stalactite)
			a[h-x]++;
		}
	}
	
	int mn = n;
	int c = 0;
	int sum = 0;
	
	for(int i = 0; i < h; i++){
		sum += a[i];
		if(sum < mn){
			mn = sum;
			c = 1;
		}else if(sum == mn){
			c++;
		}
	}
	
	cout << mn << " " << c << endl;
	
	return 0;
}