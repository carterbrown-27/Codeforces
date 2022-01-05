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

bool solve(int fg) {
	int guess = fg;
	uset<int> tl, th;
	string rsp;
	getline(cin, rsp);
	
	while(true){
		if(rsp == "too high"){
			th.pb(guess);
		}else if(rsp == "too low"){
			tl.pb(guess);
		}else{
			break;
		}
		cin >> guess;
		cin.ignore();
		getline(cin, rsp);
	}
	
	// last guess value is answer
	for(int i: tl)
		if(i >= guess)
			return false;
		
	for(int i: th)
		if(i <= guess)
			return false;
		
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	
	while(true){
		int fg;
		cin >> fg;
		cin.ignore();
		if(fg == 0)
			break;
		cout << (solve(fg) ? "Stan may be honest" : "Stan is dishonest") << endl;
	}
	return 0;
}