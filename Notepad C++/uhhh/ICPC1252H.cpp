#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

template<typename T>
using uset = unordered_set<T>;

#define pb push_back

struct rect {
	int l,w;
};

int main() {
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	vector<rect> v;
	ll ans1 = 0;
	for(int i = 0; i < n; i++){
		int l,w;
		cin >> l >> w;
		if(l > w)
			swap(l, w);
		
		ans1 = max(ans1, 1LL*l*w);
		v.pb({l,w});
	}
	
	sort(v.begin(), v.end(), [](rect& a, rect& b){
		return a.l > b.l;
	});
	
	ll ans2 = 0;
	int mxw = 0;
	for(rect& r: v){
		ans2 = max(ans2, 1LL * r.l * min(r.w, mxw));
		mxw = max(mxw, r.w);
	}
	
	if(ans1/2 >= ans2){
		cout << ans1/2 << "." << (ans1%2 ? 5 : 0) << endl;
	}else{
		cout << ans2 << ".0" << endl;
	}
	return 0;
}