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
	
	string s;
	cin >> s;
	
	list<char> d;
	auto it = d.end();
	for(char c: s){
		switch(c)
		{
			case '<':
				if(it != d.begin()){
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
				if(it != d.end()){
					++it;
				}
				it = d.insert(it, c);
		}
	}
	
	string res;
	for(char c: d){
		res += c;
	}
	
	cout << res << endl;
	
	return 0;
}