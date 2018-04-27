#include <iostream>
#include <vector>

using namespace std;

void sieve_of_eratosthenes(vector<bool>& is_prime, vector<int>& primes, int k) {
	for (int i = 2; i < k; i++) {
		if (!is_prime[i]) {
			continue;
		}
		primes.push_back(i);
		int cur = 2 * i;
		while (cur < k) {
			is_prime[cur] = 0;
			cur += i;
		}
	}
}

int main() {
	vector<bool> is_prime(1000000, 1);
	vector<int> primes;
	sieve_of_eratosthenes(is_prime, primes, 1000000);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		cout << primes[n - 1] << endl;
	}
}
