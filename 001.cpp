#include <iostream>

using namespace std;

long long solve(int n) {
	n--;
	long long ans = (long long) 3 * (n / 3 + 1) / 2 * (n / 3);
	if ((n / 3) % 2 == 0) {
		ans += (n / 3) / 2;
	}
	ans += (long long) 5 * (n / 5 + 1) / 2 * (n / 5);
	if ((n / 5) % 2 == 0) {
		ans += (n / 5) / 2;
	}
	ans -= (long long) 15 * (n / 15 + 1) / 2 * (n / 15);
	if ((n / 15) % 2 == 0) {
		ans -= (n / 15) / 2;
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
