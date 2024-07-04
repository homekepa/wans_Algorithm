#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int n, m;
string map[1000];
int dp_map[1000][1000];

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> map[i];
    }
}

int main() {
    int max_size = 0;
    input();

    // 첫 번째 행 초기화
    for (int i = 0; i < m; i++) {
        dp_map[0][i] = map[0][i] - '0';
        if (dp_map[0][i] == 1) {
            max_size = 1;
        }
    }
    // 첫 번째 열 초기화
    for (int i = 0; i < n; i++) {
        dp_map[i][0] = map[i][0] - '0';
        if (dp_map[i][0] == 1) {
            max_size = 1;
        }
    }

    // 나머지 행과 열 계산
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (map[i][j] == '1') {
                dp_map[i][j] = min({ dp_map[i - 1][j - 1], dp_map[i - 1][j], dp_map[i][j - 1] }) + 1;
                max_size = max(max_size, dp_map[i][j]);
            }
            else {
                dp_map[i][j] = 0;
            }
        }
    }
    cout << max_size * max_size; // 최대 크기의 정사각형 면적 출력

    return 0;
}
