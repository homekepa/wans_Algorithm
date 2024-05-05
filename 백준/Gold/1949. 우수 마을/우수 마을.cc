// 백준 1949번 : 우수 마을
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v[10001];
int resident[10001];
int dp[10001][2];
bool visited[10001];

void dfs(int node) {
    visited[node] = true;
    dp[node][0] = 0; // 해당 노드가 우수 마을이 아닐 경우
    dp[node][1] = resident[node]; // 해당 노드가 우수 마을일 경우

    for (int next : v[node]) {
        if (visited[next]) {
            continue;
        }
        dfs(next);
        dp[node][0] += max(dp[next][0], dp[next][1]);
        dp[node][1] += dp[next][0];
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> resident[i];
    }
    for (int i = 0, a, b; i < N - 1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);

    cout << max(dp[1][0], dp[1][1]);
    return 0;
}