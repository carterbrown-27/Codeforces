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

// solution from editorial
int main() {
	ios::sync_with_stdio(false);
	
	string a,b;
	cin >> a >> b;
	
	const int n = a.length();
	
	// only have to consider best ceil(n/2) from a, and n/2 from b
	
	sort(a.begin(), a.end());
	deque<char> av;
	for(int i = 0; i < (n+1)/2; i++){
		av.pb(a[i]);
	}
	
	sort(b.rbegin(), b.rend());
	deque<char> bv;
	for(int i = 0; i < n/2; i++){
		bv.pb(b[i]);
	}
	
	string front, back;
	bool alt_strat = false;
	for(int i = 0; i < n; i++){
		if(i%2 == 0){
			if(!bv.empty() && av[0] >= bv[0])
				alt_strat = true;
			
			if(alt_strat){
				back.pb(av.back());
				av.pop_back();
			}else{
				front.pb(av.front());
				av.pop_front();
			}
		}else{
			if(!av.empty() && av[0] >= bv[0])
				alt_strat = true;
			
			if(alt_strat){
				back.pb(bv.back());
				bv.pop_back();
			}else{
				front.pb(bv.front());
				bv.pop_front();
			}
		}
	}
	
	reverse(back.begin(), back.end());
	cout << front << back << endl;
	
	return 0;
}