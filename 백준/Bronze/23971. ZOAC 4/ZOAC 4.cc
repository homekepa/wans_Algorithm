#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int H, W, N, M;



void input() {
	cin >> H >> W >> N >> M;
		
	return;
}


int main() {
	input();

	int result;

	int vertical = ceil(float(H) / (N + 1));
	int horizontal = ceil(float(W) / (M + 1));

	result = vertical * horizontal;

	cout << result;

	return 0;
}