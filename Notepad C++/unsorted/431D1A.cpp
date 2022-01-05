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
	
	int n;
	cin >> n;
	
	const int mxr = sqrt(1e5)/2;
	
	string ans = "";
	for(char c = 'a'; c <= 'z'; c++){
		int l = 0, r = mxr;
		while(l < r){
			int m = (l+r)/2;
			// sum from 1 to m-1
			int v = (m-1)*m/2;
			if(v > n){
				r = m;
			}else{
				l = m+1;
			}
		}
		r--;
		n -= (r-1)*r/2;
		for(int i = 0; i < r; i++)
			ans += c;
		
		if(n == 0)
			break;
	}
	
	cout << ans << endl;
	
	return 0;
}