#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map> // abs() 함수를 사용하기 위해 필요한 헤더 추가

using namespace std;

int main()
{
    unordered_map<long long, int>mp;
    vector<int> answer;

    int N, M;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        mp[num]++;
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        
        if (mp[num]) { //값이 존재하면 1
            answer.push_back(1);
        }
        else { //값이 존재하지 않으면 0
            answer.push_back(0);
        }
    }
    for (auto i : answer)
        cout << i << "\n";

    return 0;
}
