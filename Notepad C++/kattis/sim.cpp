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

void solve() {
	string s;
	getline(cin, s);
	
	list<char> d;
	auto it = d.end();
	for(char c: s){
		switch(c)
		{
			case '<':
				if(it != d.begin()){
					--it;
					it = d.erase(it);
				}
				break;
			
			case '[':
				it = d.begin();
				break;
			
			case ']':
				it = d.end();
				break;
			
			default:
				d.insert(it, c);
		}
	}
	
	string res;
	for(char c: d){
		res += c;
	}
	
	cout << res << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	cin.ignore();
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}