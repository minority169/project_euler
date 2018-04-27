#include <iostream>

using namespace std;

int make_palindrom(int k) {
	return k * 1000 + (k % 10) * 100 + ((k % 100) / 10) * 10 + k / 100;
}

int solve(int n) {
	int ans = 101101;
	for (int i = 100; i < 1000; i++) {
		int m = make_palindrom(i);
		if (m >= n) {
			break;
		}
		for (int j = 100; j < 1000; j++) {
			if (m % j == 0 && m / j < 1000 && m / j >= 100) {
				ans = max(ans, m);
			}
		}
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
