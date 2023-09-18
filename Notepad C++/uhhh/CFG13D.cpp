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

void to_bin(int x, vector<bool>& b){
	while(x>0){
		b.pb(x%2);
		x/=2;
	}
	while(b.size() < 30)
		b.pb(0);
	
	reverse(b.begin(), b.end());
}

void get_ones(vector<bool>& b, vector<int>& v){
	for(int i = 0; i < b.size(); i++)
		if(b[i])
			v.pb(i);
}

bool solve(){
	int s, t;
	cin >> s >> t;
	
	if(s > t){
		return false;
	}
	
	vector<bool> sb, tb;
	to_bin(s,sb);
	to_bin(t,tb);
	
	vector<int> sv, tv;
	get_ones(sb,sv);
	get_ones(tb,tv);
	
	// we know that if we need to shift (have extra 1s), msb(s) < msb(t)... because s<=t
	auto sit = sv.begin();
	for(auto& x: tv){
		if(sit == sv.end())
			return false;
		
		while(x > *sit)
			if(++sit == sv.end())
				return false;
			
		++sit;
	}
	
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cout << (solve() ? "YES" : "NO") << endl;
	}
	return 0;
}