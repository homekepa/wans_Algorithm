#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int N;

void input() {
	cin >> N;

	return;
}

int solve() {
	int level = 1;
	int maxi = 1;
	while (1) {
		if (N == 1) {
			break;
		}
		maxi += (6 * level);
		level++;
		if (maxi >= N) {
			break;
		}
	}
	return level;
}


int main() {
	input();

	cout << solve();
	return 0;
}