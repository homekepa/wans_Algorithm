#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, d;
vector<pair<int, int>> line;

void input() {
    int h, o;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h >> o;
        if (h > o) swap(h, o);
        line.push_back({ h, o });
    }
    cin >> d;
}

int main() {
    input();
    int result = 0;

    sort(line.begin(), line.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
      });

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        int start = line[i].first;
        int end = line[i].second;

        if ((end - start) <= d) {
            pq.push(start);
        }

        while (!pq.empty() && (end - pq.top() > d)) {
            pq.pop();
        }

        result = max(result, static_cast<int>(pq.size()));
    }

    cout << result << endl;

    return 0;
}
