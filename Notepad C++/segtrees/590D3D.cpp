#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

vector<int> merge(vector<int> a, vector<int> b){
    vector<int> c(26);
    for(int i = 0; i < c.size(); i++){
        c[i] = a[i] + b[i];
    }
    return c;
}

struct segtree {
	int size;
	vector<vector<int>> sums;
    string s;
	
	void init(int n){
		size = 1;
		while(size < n) size*=2;
		sums.assign(2*size, vector<int>(26));
	}
	
	void init(string &a){
		init(a.size());
        s = a;
		build(a);
	}
	
	void build(string& a, int x, int lx, int rx){
		// if in bottom layer, check if within "actual" elems (not added 0s)
		if(rx-lx == 1){
			if(lx < a.size()){
                ++sums[x][a[lx]-'a'];
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2*x + 1, lx, m);
		build(a, 2*x + 2, m, rx);
		
		sums[x] = merge(sums[2*x+1],sums[2*x+2]);
	}
	
	void build(string& a){
		build(a, 0, 0, size);
	}
	
	void set(int i, char v){
		if(i < 0 || i >= size) return;
		set(i, v, 0, 0, size);
	}
	
	void set(int i, char v, int x, int lx, int rx){
		// if x is a leaf, set it directly
		if(rx-lx == 1){
			--sums[x][s[i]-'a'];
			++sums[x][v-'a'];
            s[i] = v;
            return;
		}
		
		int m = (lx+rx)/2;
		// i is in left
		if(i < m){
			// goto left node
			set(i, v, 2*x + 1, lx, m);
		}else{
			// goto right node
			set(i, v, 2*x + 2, m, rx);
		}
		
		// doesn't go o.o.b as x is not a leaf
		sums[x] = merge(sums[2*x+1], sums[2*x+2]);
	}
	
	vector<int> sum(int l, int r){
		return sum(l, r, 0, 0, size);
	}
	
	vector<int> sum(int l, int r, int x, int lx, int rx){
		// segment is completely outside
		if(rx <= l || lx >= r) return vector<int>(26);
		
		// segment is completely contained
		if(l <= lx && rx <= r) return sums[x];
		
		// segment is partially contained (recursive case)
		int m = (lx+rx)/2;
		
		return merge(sum(l, r, 2*x + 1, lx, m), sum(l, r, 2*x + 2, m, rx));
	}
};

void solve() {
    string s;
    cin >> s;
    
    int m;
    cin >> m;
    
	segtree sgt;
	sgt.init(s);
	
	for(int i = 0; i < m; i++){
		int o, a;
		cin >> o >> a;
		if(o == 1){
            a--;
            char b;
            cin >> b;
			sgt.set(a, b);
		}else if(o == 2){
            int b;
            cin >> b;
            a--;
            vector<int> v = sgt.sum(a,b);
            int ans = 0;
            for(int i = 0; i < 26; i++){
                if(v[i] > 0){
                    // cout << (char) (i+'a') << " ";
                    ans++;
                }
            }
            cout << ans << endl;
		}
	}
}

int main() {
	solve();
	return 0;
}