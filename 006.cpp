#include <iostream>
#include <vector>

using namespace std;

void count_square_sum(vector<long long>& squares_sum, long long k) {
	for (int i = 1; i <= k; i++) {
		squares_sum[i] = squares_sum[i - 1] + i * i;
	}
}

long long evaluate(vector<long long>& squares_sum, long long n) {
	return n * n * (n + 1) * (n + 1) / 4 - squares_sum[n];
}

int main() {
	vector<long long> squares_sum(10001);
	count_square_sum(squares_sum, 10000);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		cout << evaluate(squares_sum, n) << endl;
	}
}
