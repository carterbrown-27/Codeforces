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

const char digs[] = {'0','1','2','5','9','8','6'};

string solve(int n) {
	string ans = "";
	while(n > 0){
		ans += digs[n%7];
		n/=7;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	string s;
	while(true){
		getline(cin, s);
		if(s == "")
			break;
		
		cout << solve(stoi(s)) << endl;
	}
	
	return 0;
}