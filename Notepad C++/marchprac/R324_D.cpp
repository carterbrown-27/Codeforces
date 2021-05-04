#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

bool isPrime(int n){
	for(int i = 2; i*i <= n; i++){
		if(n%i==0) return false;
	}
	return (n>=2);
}

// Sieve of Eratosthenes
set<int> primes;
void genPrimes(int B) {
	vector<bool> a(B+1, true);
	for(int i = 2; i*i <= B; i++){
		if(a[i]){
			for(int j = i*i; j <= B; j += i){
				a[j] = false;
			}
		}
	}
	
	for(int i = 2; i <= B; i++){
		if(a[i]) primes.insert(i);
	}
}

void solve() {
	int n;
	cin >> n;
	
	if(n==3){
		cout << "1\n3" << endl;
	}else if(n<=5){
		cout << "2\n2 "<< n-2 << endl;
	}else{
		genPrimes(1e5);
		n-=3;
		cout << "3\n3 ";
		for(int p: primes){
			if(isPrime(n-p)){
				cout << p << " " << n-p << endl;
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}