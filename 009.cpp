#include <iostream>
#include <vector>

using namespace std;

int find_pythagorean_triplet(int a, int b) {
	int t = a * a + b * b;
	int l = 0, r = a + b;
	while (l < r) {
		int m = (l + r) / 2;
		if (m * m < t) {
			l = m + 1;
		} else {
			r = m;
		}
	}
	if (l * l == t) {
		return l;
	}
	return -1;
}

void find_ans(vector<int>& ans, int k) {
	for (int a = 1; a <= k; a++) {
		for (int b = a; b <= k; b++) {
			int c = find_pythagorean_triplet(a, b);
			if (c != -1) {
				ans[a + b + c] = max(ans[a + b + c], a * b * c);
			}
		}
	}
}

int main() {
	vector<int> ans(10000, -1);
	find_ans(ans, 3000);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		cout << ans[n] << endl;
	}
}
