/**
* __INFO__
* BOJ_12856_평법한 배낭.cpp
* Algorithm_
*
* Created by 조완기 on 24/09/30
* Copyright © 2024 wans. All rights reserved.
**/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

/** COMMENT
*
* 
* 
* 
* 
* 
* 
* 
* 
**/

/**
* DEFINE
**/
struct Article
{
	int W, V; // W = weight, V = value
};

void init(); // INITIAL
void input(); // INPUT
void solve(); // SOLUTION

int N, K;
int dp[101][100001];

vector<Article> bag;
/**
* FUNCTION
**/


void init() {
	memset(dp, 0, sizeof(dp));
}

void input() {
	cin >> N >> K;
	int weight, value;
	bag.push_back({ 0,0 });
	for (int i = 1; i <= N; i++)
	{
		cin >> weight >> value;
		bag.push_back({ weight, value });
	}
	
}

void solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j >= bag[i].W) {  // bag[i-1]로 수정
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - bag[i].W] + bag[i].V);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
}


/**
* MAIN
**/
int main() {
	//freopen("sample_input.txt", "r", stdin); // 파일 입출력

	init();
	input();
	
	solve();
	cout << dp[N][K];
	return 0; // Program End
}
