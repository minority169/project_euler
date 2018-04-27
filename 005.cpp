#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
	return a / gcd(a, b) * b;
}

long long solve(int n) {
	long long ans = 1;
	for (int i = 2; i <= n; i++) {
		ans = lcm(ans, i);
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		cout << solve(n) << endl;
	}
}
