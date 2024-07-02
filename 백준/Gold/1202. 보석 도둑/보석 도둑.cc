#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int N, K;
vector<pair<int, int>> minarals;
vector<int> bag;

void input() {
    int m, v, c;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> m >> v;
        minarals.push_back({ m,v });
    }
    for (int i = 0; i < K; i++)
    {
        cin >> c;
        bag.push_back(c);
    }
}

int main() {
    long long result = 0;
    input();
    sort(minarals.begin(), minarals.end());
    sort(bag.begin(), bag.end());
    priority_queue<int> pq;
    int idx = 0;
    for (int i = 0; i < K; i++)
    {
        while (idx < N && bag[i] >= minarals[idx].first) {
            pq.push(minarals[idx].second);
            idx++;
        }
        if (!pq.empty()) {
            result += pq.top();
            pq.pop();
        }
    }

    cout << result;
    return 0;
}
