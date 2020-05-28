#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

/* 
 * Given n strings of length m, determine if it is possible to create a string s such that
 * each of the n strings differs from s by at most 1 character, and if so, print s.
 */
// probably way more complicated than needed, but it works.
void solve() {
	int n,m;
	cin >> n >> m;
	string a[n];
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		a[i] = s;
	}
	
	string first = a[0];
	vector<pair<int,char>> rowdiffs[n];
	for(int i = 1; i < n; i++){
		int diffs = 0;
		for(int x = 0; x < m; x++){
			if(a[i][x] != first[x]){
				diffs++;
				rowdiffs[i].push_back(make_pair(x,a[i][x]));
				
				if(diffs>2){
					cout << -1 << endl;
					return;
				}
			}
		}
	}
	
	int onerows = 0;
	int tworows = 0;
	map<pair<int,char>,int> trCands;
	set<int> oneInds;
	for(int i = 1; i < n; i++){
		if(rowdiffs[i].size()==2){
			tworows++;
			for(auto p: rowdiffs[i]){
				trCands[p]++;
			}
		}else if(rowdiffs[i].size()==1){
			onerows++;
			oneInds.insert(rowdiffs[i][0].first);
		}
	}
	
	int oneInd = -1;
	if(!oneInds.empty()) oneInd = *oneInds.begin();
	
	bool exists = false;
	pair<int,char> switchP;
	for(auto const& p: trCands){
		if(p.second == tworows){
			if(!exists || p.first.first == oneInd) switchP = p.first;
			exists = true;
			if(oneInd == -1) break;
		}
	}
	
	// cout<< onerows << "|" << tworows << endl;
	//if(!oneInds.empty()) cout << oneInd << endl;
	
	if(!exists){
		//cout<<"dne"<<endl;
		if(tworows){
			cout << -1 << endl;
		}else{
			cout << first << endl;
		}
	}else if(oneInds.size() < 2 && (oneInds.empty() || oneInd==switchP.first)){
		for(int i = 0; i < m; i++){
			if(i==switchP.first){
				cout << switchP.second;
			}else{
				cout << first[i];
			}
		}
		cout << endl;
	}else{
		//cout << switchP.first << endl;
		cout << -1 << endl;
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}