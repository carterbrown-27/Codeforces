#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using uset = unordered_set<T>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

int main() {
	while(true){
		int n;
		double t;
		cin >> n >> t;
		
		if(n == 0) break;
		
		double cont = 1<<n;
		double walk = prize;
		
		for(int i = n-1; i >= 0; i--){
			walk /= 2;
			double half = max(walk/cont, t);
			
			double h = (1-half)/(1-t);
			double p = (1+half)/2;
			
			cont = p*h*cont + (1-h)*walk;
		}
		
		printf("%.3f\n", cont);
	}
	return 0;
}