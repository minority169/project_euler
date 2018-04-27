#include <iostream>

using namespace std;

int solve(int n, int k, string num) {
	int ans = 0;
	for (int i = 0; i < n - k; i++) {
		int cur_prod = 1;
		for (int j = i; j < i + k; j++) {
			cur_prod *= (int) (num[j] - '0');
		}
		ans = max(ans, cur_prod);
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n, k;
		cin >> n >> k;
		string num;
		cin >> num;
		cout << solve(n, k, num) << endl;
	}
}
