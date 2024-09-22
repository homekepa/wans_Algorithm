#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/* COMMENT
도시의 수 N(1 <= N <= 1,000)
버스의 수 M(1 <= M <= 1,000,000)
input
N
M
bus start num, end num, cost(0 <= cost <= 100,000)
start point, end point
*/

/*******************************************/
// DEFINE
struct info {
	int to_bus;
	long long cost;
};

struct cmp {
	bool operator() (info a, info b) {
		return a.cost > b.cost; // 최소 비용 기준으로 정렬
	}
};

void init(); // INITIAL
void input(); // INPUT
long long solve(); // SOLUTION

const long long INF = 1e15;  // 매우 큰 값으로 설정 (무한대)
int N, M, start_Point, end_Point;
vector<info> city[1001]; // 도시 인덱스가 1부터 시작
priority_queue<info, vector<info>, cmp> pq;
vector<long long> dist(1001, INF); // 각 도시까지의 최소 비용 관리

/*******************************************/
// FUNCTION

void init() {
	// 초기화 함수
	fill(dist.begin(), dist.end(), INF); // dist 배열 초기화
}

void input() {
	int from, to, cost;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> from >> to >> cost;
		city[from].push_back({ to, cost }); // from -> to로 가는 경로와 비용 저장
	}

	cin >> start_Point >> end_Point;
}

long long solve() {
	// 시작점 설정
	pq.push({ start_Point, 0 });
	dist[start_Point] = 0; // 시작점 비용은 0으로 설정

	while (!pq.empty()) {
		auto node = pq.top();
		pq.pop();

		int curr_city = node.to_bus;
		long long curr_cost = node.cost;

		// 이미 처리된 경로면 무시
		if (dist[curr_city] < curr_cost) continue;

		// 현재 도시에서 갈 수 있는 다른 도시 탐색
		for (auto next : city[curr_city]) {
			long long new_cost = curr_cost + next.cost;
			if (new_cost < dist[next.to_bus]) {
				dist[next.to_bus] = new_cost;
				pq.push({ next.to_bus, new_cost });
			}
		}
	}

	// 목적지까지의 최소 비용 반환
	return dist[end_Point] == INF ? -1 : dist[end_Point];
}

/*******************************************/
// MAIN
int main() {
	// freopen("sample_input.txt", "r", stdin); // 파일 입출력

	input();
	init();

	long long result = solve();

	cout << result;

	return 0; // Program End
}
