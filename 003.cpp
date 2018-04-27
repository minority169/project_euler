#include <iostream>

using namespace std;

unsigned long long solve(unsigned long long n) {
	unsigned long long ans = 1;
	for (unsigned long long i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ans = i;
		}
		while (n % i == 0) {
			n /= i;
		}
	}
	return n == 1 ? ans : n;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		unsigned long long n;
		cin >> n;
		cout << solve(n) << endl;
	}
}
