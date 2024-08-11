#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int num[3];

void input() {
	memset(num, 0, sizeof(num));
	cin >> num[0] >> num[1] >> num[2];
	sort(num, num + 3, std::greater<int>());
	return;
}


int main() {

	while (1) {
		input();
		if (num[0] + num[1] + num[2] == 0) {
			break;
		}
		else if (num[0] == num[1] && num[0] == num[2]) {
			cout << "Equilateral" << endl;
		}
		else if (num[0] >= num[1] + num[2]) {
			cout << "Invalid" << endl;
		}
		else if (num[1] == num[0] || num[1] == num[2]) {
			cout << "Isosceles" << endl;
		}
		else {
			cout << "Scalene" << endl;
		}

	}

	return 0;
}