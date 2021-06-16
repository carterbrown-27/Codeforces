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
	int n;
	cin >> n;
	
	int a = 1;
	for(int x = 2; x*x <= n; x++){
		if(n%x == 0){
			a = n/x;
			break;
		}
	}
	
	cout << n-a << endl;
	return 0;
}