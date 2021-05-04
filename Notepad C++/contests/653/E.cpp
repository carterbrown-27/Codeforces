#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n,k,m;
	cin >> n >> m >> k;
	vector<int> a;
	vector<int> b;
	vector<int> ab;
	vector<int> ne;
	for(int i = 0; i < n ; i++){
		int t, x, y;
		cin >> t >> x >> y;
		if(x && y){
			ab.push_back(t);
		}else if(x){
			a.push_back(t);
		}else if(y){
			b.push_back(t);
		}else{
			ne.push_back(t);
		}
	}
	
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	sort(ab.begin(),ab.end());
	sort(ne.begin(),ne.end());
	
	int ap = 0, bp = 0, abp = 0;
	int at = 0, bt = 0;
	int ans = 0;
	int books = 0;
	while(at < k || bt < k){
		if(abp < ab.size() && (ap >= a.size() || bp >= b.size() || ab[abp] <= (at < k ? a[ap] : 0) + (bt < k ? b[bp] : 0))){
			at++;
			bt++;
			ans += ab[abp++];
			books++;
		}else{
			if((at < k && ap >= a.size()) || (bt < k && bp >= b.size())){
				cout << -1 << endl;
				return;
			}
			
			if(at < k && ap < a.size()){
				at++;
				ans += a[ap++];
				books++;
			}
			
			if(bt < k && bp < b.size()){
				bt++;
				ans += b[bp++];
				books++;
			}	
		}
	}
	
	// E-hard:
	cout << books << endl;
	
	while(books > m && !(ap <= 0 || bp <= 0 || abp >= ab.size())){
		ans -= a[--ap] + b[--bp];
		ans += ab[abp++];
		books--;
	}
	
	while(books < m && !(abp <= 0 || ap >= a.size() || bp >= b.size())){
		ans -= ab[--abp];
		ans += a[ap++] + b[bp++];
		books++;
	}
	
	int nep = 0;
	int INF = 1e5;
	while(books < m && (ap < a.size() || bp < b.size() || nep < ne.size())){
		int mn = min(min(ap < a.size() ? a[ap] : INF, bp < b.size() ? b[bp] : INF ), nep < ne.size() ? ne[nep] : INF);
		
		if(ap < a.size() && a[ap] == mn){
			ans+=a[ap++];
		}else if(bp < b.size() && b[bp] == mn){
			ans+=b[bp++];
		}else{
			ans+=ne[nep++];
		}
		books++;
	}
	
	cout << (books==m ? ans : -1) << endl;
}

int main() {
	solve();
	return 0;
}