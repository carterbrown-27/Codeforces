#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

map<int,int> genProb(int d, int f){
	map<int,int> m;
	m[0] = 1;
	for(int i = 0; i < d; i++){
		map<int,int> t;
		for(auto const &p: m){
			for(int n = 1; n <= f; n++){
				t[p.first + n] += p.second;
			}
		}
		m = t;
	}
	return m;
}

void solve() {
	map<int,int> a = genProb(6, 6);
	map<int,int> b = genProb(9, 4);
	
	vector<int> ap(37), as(37);
	ap[0] = 0, as[36] = b[36];
	
	for(int i = 1; i <= ap.size(); i++){
		ap[i] = ap[i-1] + a[i];
		as[ap.size()-i-1] = as[ap.size()-i] + a[ap.size()-i-1];
	}
	
	ll w = 0, nw = 0;
	for(auto const &p: b){
		cout << p.first << " " << p.second << " => \t";
		cout << ap[p.first-1] << " " << as[p.first] << endl;
		w += ap[p.first-1] * p.second;
		nw += as[p.first] * p.second;
	}
	
	cout << w << " " << nw << endl;
	cout << setprecision(7) <<  1.0 *  w / (nw+w) << endl;
}

int main() {
	solve();
	return 0;
}