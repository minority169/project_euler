#include <iostream>
#include <vector>

using namespace std;

int evaluate_prod(vector<vector<int> >& grid, int x, int y) {
	int ans = 0;
	if (x <= grid.size() - 4 && y <= grid.size() - 4) {
		int cur_prod = 1;
		for (int i = 0; i < 4; i++) {
			cur_prod *= grid[x + i][y + i];
		}
		ans = max(ans, cur_prod);
	}
	if (x <= grid.size() - 4 && y >= 3) {
		int cur_prod = 1;
		for (int i = 0; i < 4; i++) {
			cur_prod *= grid[x + i][y - i];
		}
		ans = max(ans, cur_prod);
	}
	if (x <= grid.size() - 4) {
		int cur_prod = 1;
		for (int i = 0; i < 4; i++) {
			cur_prod *= grid[x + i][y];
		}
		ans = max(ans, cur_prod);
	}
	if (y <= grid.size() - 4) {
		int cur_prod = 1;
		for (int i = 0; i < 4; i++) {
			cur_prod *= grid[x][y + i];
		}
		ans = max(ans, cur_prod);
	}
	return ans;
}

int solve(vector<vector<int> >& grid) {
	int ans = 0;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid.size(); j++) {
			ans = max(ans, evaluate_prod(grid, i, j));
		}
	}
	return ans;
}

int main() {
	vector<vector<int> > grid(20, vector<int>(20));
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			cin >> grid[i][j];
		}
	}
	cout << solve(grid) << endl;
}
