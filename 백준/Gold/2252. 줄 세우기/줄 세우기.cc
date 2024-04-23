#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> in_degree;
vector<vector<int>> graph;

vector<int> topological_sort() {
    vector<int> result;
    queue<int> q;

    for (int i = 1; i <= N; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        result.push_back(current);

        for (int next : graph[current]) {
            if (--in_degree[next] == 0) {
                q.push(next);
            }
        }
    }

    return result;
}

int main() {
    cin >> N >> M;

    in_degree.resize(N + 1, 0);
    graph.resize(N + 1);

    for (int i = 0; i < M; ++i) {
        int front_num, back_num;
        cin >> front_num >> back_num;
        graph[front_num].push_back(back_num);
        ++in_degree[back_num];
    }

    vector<int> result = topological_sort();

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }

    return 0;
}
