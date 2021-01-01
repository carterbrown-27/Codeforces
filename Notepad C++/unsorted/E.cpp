#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n,k;
	cin >> n >> k;
	
	map<int, int> t;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		t[x]++;
	}
	
	for(int i = 0; i < n; i++){
		int y;
		cin >> y;
		// don't need yet? or ever?
	}
	
	map<int,int> prefix;
	vector<int> sortedx;
	sortedx.push_back(0);
	int sum = 0;
	prefix[0] = 0;
	for(auto const &p: t){
		sortedx.push_back(p.first);
		sum += p.second;
		prefix[p.first] = sum;
		//cout << sum << " ";
	}
	//cout << endl;
	
	// first window
	int l = 0, r = 0;
	int best = 0, bl = 0, br = 0;
	for(int j = 0; j < sortedx.size() && sortedx[j] <= k; j++){
		r = j;
	}
	
	best = prefix[sortedx[r]];
	bl = 0;
	br = r;
	
	for(; r < sortedx.size(); r++){
		while(sortedx[r] - sortedx[l] > k && l < r){
			l++;
		}
		int v = prefix[sortedx[r]]-prefix[sortedx[l-1]];
		if(v > best){
			best = v;
			bl = l;
			br = r;
		}
	}
	
	int ans = best;
	int z = prefix[sortedx[bl-1]];
	for(int i = bl; i < br; i++){
		prefix[sortedx[i]] = z;
	}
	
	prefix[sortedx[br]] = z + t[sortedx[br]];
	
	for(int i = br+1; i < sortedx.size(); i++){
		sum += t[sortedx[i]];
		prefix[sortedx[i]] = sum;
	}
	
	l = 0;
	r = 0;
	best = 0;
	for(int j = 0; j < sortedx.size() && sortedx[j] <= k; j++){
		r = j;
	}
	
	best = prefix[sortedx[r]];
	for(; r < sortedx.size(); r++){
		while(sortedx[r] - sortedx[l] > k && l < r){
			l++;
		}
		int v = prefix[sortedx[r]]-prefix[sortedx[l-1]];
		if(v > best){
			best = v;
		}
	}
	
	ans += best;
	
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}