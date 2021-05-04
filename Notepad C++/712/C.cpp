#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	string a;
	for(int i = 0; i < n/2; i++){
		a+="()";
	}
	
	int d = 0;
	string b;
	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			b += a[i];
		}else{
			b += (a[i] == '(' ? ')' : '(');
		}
		d += (b[i] == '(' ? 1 : -1);
		if(d < 0){
			cout << "NO" << endl;
			return;
		}
	}
	
	if(d == 0 && a != b){
		cout << "YES\n";
		cout << a << "\n" << b << endl;
	}else{
		cout << "NO" << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}