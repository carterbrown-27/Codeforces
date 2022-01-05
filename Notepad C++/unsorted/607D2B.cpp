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
	string s,t;
	cin >> s >> t;
	
	int n = s.length();

	vector<char> sv(s.begin(), s.end());
	sort(sv.begin(), sv.end());
	
	for(int i = 0; i < n; i++){
		if(sv[i] != s[i]){
			for(int j = n; j-- > 0;){
				if(s[j] == sv[i]){
					swap(s[i], s[j]);
					break;
				}
			}
			break;
		}
	}

	cout << (lexicographical_compare(s.begin(), s.end(), t.begin(), t.end()) ? s : "---") << endl;
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