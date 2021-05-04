#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

/* Source: Codeforces EDU */

void countSort(vector<int> &p, vector<int> &c){
	int n = p.size();
	vector<int> cnt(n);
	for(auto x: c){
		cnt[x]++;
	}
		
	vector<int> p_new(n);
	vector<int> pos(n);
	pos[0] = 0;
	for(int i = 1; i < n; i++){
		pos[i] = pos[i-1] + cnt[i-1];
	}
		
	for(auto x: p){
		int i = c[x];
		p_new[pos[i]] = x;
		pos[i]++;
	}
		
	p = p_new;
}

vector<int> sufArr(string s){
	s += '$';
	int n = s.size();
	
	vector<int> p(n), c(n);
	
	// k = 0
	{
		vector<pair<char, int>> a;
		for(int i = 0; i < n; i++) a.pb({s[i], i});
		
		sort(a.begin(), a.end());
		
		int ec = 0;
		p[0] = a[0].second;
		c[p[0]] = 0;
		for(int i = 1; i < a.size(); i++){
			p[i] = a[i].second;
			if(a[i-1].first != a[i].first){
				ec++;
			}
			c[p[i]] = ec;
		}
	}
	
	// k -> k+1
	int k = 1;
	while(k < n){
		// shift strings
		for(int i = 0; i < n; i++){
			p[i] = (p[i] - k + n) % n;
		}
		countSort(p,c);
		
		int ec = 0;
		vector<int> c_new(n);
		c_new[p[0]] = 0;
		pair<int,int> prev = {c[p[0]], c[(p[0]+k)%n]};
		
		for(int i = 1; i < n; i++){
			pair<int,int> cur = {c[p[i]], c[(p[i]+k)%n]};
			
			if(cur != prev){
				ec++;
			}
			c_new[p[i]] = ec;
			
			prev = cur;
		}
		
		c = c_new;
		k *= 2;
	}
	
	return p;
}

bool contains(vector<int>& suf, string s, string t){
	if(t.length() > s.length()) return false;
	
	int l = 0, r = suf.size()-1;
	while(l <= r){
		int m = (l+r)/2;
		
		bool eq = true;
		for(int i = 0; i < t.length(); i++){
			int dif = (suf[m]+i < s.length() ? s[suf[m]+i] : 0) - t[i];
			if(dif != 0){
				if(dif > 0){
					// s > t
					r = m-1;
				}else{
					l = m+1;
				}
				eq = false;
				break;
			}
		}
		
		if(eq) return true;
	}
	
	return false;
}

/* END OF SUFFIX ARRAY */

void solve() {
	string s;
	cin >> s;
	
	vector<int> suf = sufArr(s);
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		string t;
		cin >> t;
		cout << (contains(suf,s,t) ? "Yes" : "No") << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}