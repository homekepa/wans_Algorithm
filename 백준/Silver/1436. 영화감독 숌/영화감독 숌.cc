/**
* __INFO__
* codetree_색깔 트리.cpp
* Algorithm_
* https://www.codetree.ai/training-field/frequent-problems/problems/color-tree/description?page=1&pageSize=5
* Created by 조완기 on 24/10/1
* Copyright © 2024 wans. All rights reserved.
**/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

/** COMMENT
*
* 
**/

/**
* DEFINE
**/



/**
* FUNCTION
**/



/**
* MAIN
**/
int main() {
	//freopen("sample_input.txt", "r", stdin); // 파일 입출력


    int n;
    cin >> n;

    int cnt = 1;
    int num = 666;

    while (cnt <= n) {
        // 숫자를 문자열로 변환하여 "666"이 포함되어 있는지 확인
        if (to_string(num).find("666") != string::npos) {
            cnt++;
        }
        num++;
    }

    cout << num - 1 << endl;

	return 0; // Program End
}
