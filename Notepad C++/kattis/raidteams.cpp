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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	const int SC = 3;
	
	vector<minpq<pair<int,string>>> skills(SC);
	uset<string> used;
	
	for(int i = 0; i < n; i++){
		string name;
		cin >> name;
		for(int j = 0; j < SC; j++){
			int s;
			cin >> s;
			// sort desc by val, asc by name (lazy)
			skills[j].push({-s, name});
		}
	}
	
	for(int t = 0; t < n/3; t++){
		vector<string> names(3);
		for(int s = 0; s < SC; s++){
			auto p = skills[s].top();
			
			while(used.find(p.second) != used.end()){
				skills[s].pop();
				p = skills[s].top();
			}
			
			names[s] = p.second;
			used.insert(p.second);
		}
		
		sort(names.begin(), names.end());
		for(string s: names){
			cout << s << " ";
		}
		cout << "\n";
	}
	
	return 0;
}