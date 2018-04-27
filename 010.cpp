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

void count_prefix_sum(vector<long long>& prefix_sum, vector<int>& primes) {
	for (int i = 1; i <= primes.size(); i++) {
		prefix_sum[i] = prefix_sum[i - 1] + primes[i - 1];
	}
}

int find_ind(vector<int>& primes, int n) {
	int l = 0, r = primes.size();
	while (l < r) {
		int m = (l + r + 1) / 2;
		if (primes[m] <= n) {
			l = m;
		} else {
			r = m - 1;
		}
	}
	return l + 1;
}

int main() {
	vector<bool> is_prime(1000000, 1);
	vector<int> primes;
	sieve_of_eratosthenes(is_prime, primes, 1000000);
	vector<long long> prefix_sum(primes.size() + 1);
	count_prefix_sum(prefix_sum, primes);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		cout << prefix_sum[find_ind(primes, n)] << endl;
	}
}
