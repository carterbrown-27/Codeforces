#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n;
	cin >> n;
	
	int segs = 0;
	int a = -1, b = -1;
	
	int arr[n];
	vector<set<int>> p(n+1);
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		arr[i] = v;
		p[v].insert(i);
	}
	
	for(int i = 0; i < n; i++){
		int v = arr[i];
		if(v == a || v == b){
			continue;
		}else if(i == n){
			segs++;
		}else if(b == -1 || arr[i+1] == a){
			b = v;
			segs++;
		}else if(a == -1 || arr[i+1] == b){
			a = v;
			segs++;
		}else{
			// next is neither a nor b.
			// "recursive" case?
			// choose save a, save b, save neither
			set<int> seen;
			int last = -1;
			for(; i < n; i++){
				v = arr[i];
				if(v == a){
					b = last;
					break;
				}else if(v == b){
					a = last;
					break;
				}else if(seen.find(v) != seen.end()){
					// choose neither?
					auto ap = p[a].upper_bound(i);
					auto bp = p[b].upper_bound(i);
					
					if(ap == p[a].end() && bp == p[b].end()){
						a = v;
					}else if(bp == p[b].end() || (ap != p[a].end() && *ap < *bp)){
						// cout << i << " " << *ap << " " << *bp << endl;
						// cout << "B" << endl;
						b = v;
					}else{
						// cout << "A" << endl;
						a = v;
					}
				}else{
					segs++;
				}
				
				seen.insert(v);
				last = v;
			}
		}
	}
	
	cout << segs << endl;
}

int main() {
	solve();
	return 0;
}