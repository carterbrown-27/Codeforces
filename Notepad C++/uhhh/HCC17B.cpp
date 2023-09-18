#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point {
	int x,y;
};

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

template<typename T>
using uset = unordered_set<T>;

#define pb push_back

void solve() {
	int n,k;
	cin >> n >> k;
	
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	// stores position of next occurence of num
	umap<int,queue<int>> mp;
	for(int i = 0; i < n; i++){
		mp[a[i]].push(i);
	}
	
	set<int, greater<int>> books;
	int cost = 0;
	
	for(int i = 0; i < n; i++){
		// If today's req book is not in
		if(books.find(i) == books.end()){
			cost++;
			if(books.size() == k){
				books.erase(books.begin());
			}
		}else{
			books.erase(i);
		}
		
		// Stock today's book
		auto& q = mp[a[i]];
		q.pop();
		if(!q.empty()){
			books.insert(q.front());	
		}
	}

	cout << cost << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}