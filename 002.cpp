#include <iostream>

using namespace std;

long long solve(long long n) {
	long long a = 1, b = 1, ans = 0;
	while (a + b <= n) {
		ans += a + b;
		a = a + 2 * b;
		b = 2 * a - b;
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		long long n;
		cin >> n;
		cout << solve(n) << endl;
	}
}
