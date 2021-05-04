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