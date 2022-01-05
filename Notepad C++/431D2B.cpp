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

bool solve(){
	int n;
	cin >> n;
	
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	for(int i = 0; i < 3; i++){
		for(int j = i+1; j < 3; j++){
			// first line from a[i] to a[j]
			double m = ((double) a[j]-a[i])/(j-i);
			int b2 = -1, b2x = -1;
			bool works = true;
			
			for(int k = 0; k < n; k++){
				if(k == i || ((double) a[k]-a[i])/(k-i) == m)
					continue;
				if(b2 == -1){
					b2 = a[k];
					b2x = k;
				} else if (((double) a[k]-b2)/(k-b2x) != m) {
					works = false;
					break;
				}
			}
			
			if(works && b2 != -1){
				return true;
			}
		}
	}
	
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	
	cout << (solve() ? "Yes" : "No") << endl;
	
	return 0;
}