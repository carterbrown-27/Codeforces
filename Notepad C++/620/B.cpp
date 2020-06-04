#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair

void solve() {
	int n,m;
	cin >> n >> m;
	
	string s[n];
	set<string> st;
	for(int i = 0; i < n; i++){
		cin >> s[i];
		st.insert(s[i]);
	}
	
	string mid = "";
	vector<string> fh;
	vector<string> sh;
	int len = 0;
	
	for(int i = 0; i < n; i++){
		string r = s[i];	
		reverse(r.begin(),r.end());
		
		if(s[i] == r){
			mid = r;
		}else if(find(st.begin(),st.end(),r) != st.end()){
			fh.pb(s[i]);
			sh.pb(r);
			st.erase(s[i]);
			st.erase(r);
		}
	}
	
	cout << fh.size()*m*2 + mid.length() << endl;
	
	for(string s: fh){
		cout << s;
	}
	
	cout << mid;
	
	reverse(sh.begin(),sh.end());
	for(string s: sh){
		cout << s;
	}
	
	cout << endl;
}

int main() {
	solve();
	return 0;
}