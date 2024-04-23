#include<iostream>

using namespace std;

int N;
int block[30];

int main() {
	cin >> N;

	block[0] = 1;
	block[1] = 0;
	block[2] = 3;

    for (int n = 3; n <= N; n++)
    {
        if (n % 2 != 0) block[n] = 0;
        else
        {
            for (int i = 2; i <= N; i += 2)
            {
                if (i == 2) block[n] = block[n - i] * block[2];
                else if ((n - i) >= 0) block[n] += block[n - i] * 2;
            }
        }
    }
    cout << block[N];

	return 0;
}