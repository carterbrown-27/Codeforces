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
	
	const int K = 3;
	
	string s;
	cin >> s;
	
	ll sum = 0;
	vector<int> a(K);
	
	for(char c: s){
		int x = c-'0';
		for(int i = K; --i > x;){
			sum += a[i];
		}
		a[x]++;
	}
	
	cout << sum << endl;
	
	return 0;
}