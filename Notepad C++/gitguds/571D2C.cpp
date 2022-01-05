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
	
	string a, b;
	cin >> a >> b;
	
	int bc = 0;
	for(char c: b)
		bc += (c == '1');
	
	int ans = 0;
	int prf[a.length()+1];
	prf[0] = 0;
	
	for(int i = 1; i <= a.length(); i++){
		prf[i] = prf[i-1] + (a[i-1] == '1');
		if(i >= b.length())
			ans += ((prf[i] - prf[i-b.length()])%2 == bc%2);
	}
	
	cout << ans << endl;
	
	return 0;
}