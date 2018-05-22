#include <iostream>
#include <vector>

using namespace std;

int get_divisors(long long n) {
	int ans = 1;
	for (long long i = 2; i * i <= n; i++) {
		int cur_power = 0;
		while (n % i == 0) {
			cur_power++;
			n /= i;
		}
		ans *= (cur_power + 1);
	}
	if (n != 1) {
		ans *= 2;
	}
	return ans;
}

void evaluate_ans(vector<int>& div_num) {
	long long cur = 0;
	for (int i = 1; i <= 45000; i++) {
		cur += i;
		div_num[i] = get_divisors(cur);
	}
}

int get_triangular_number(int n) {
	return n * (n + 1) / 2;
}

int solve(vector<int>& div_num, int n) {
	for (int i = 1; i <= 45000; i++) {
		if (n < div_num[i]) {
			return get_triangular_number(i);
		}
	}
	return get_triangular_number(45000);
}

int main() {
	int T;
	cin >> T;
	vector<int> div_num(45001);
	evaluate_ans(div_num);
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		cout << solve(div_num, n) << endl;
	}
}
