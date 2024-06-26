#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int change_time(string time){
    return stoi(time.substr(0,2)) * 60 + stoi(time.substr(3,2)); 
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int, int>> times; // 시작 시간과 끝 시간을 저장할 벡터
    
    for (auto time : book_time) {
        int start_time = change_time(time[0]);
        int end_time = change_time(time[1]) + 10; //종료 후 10분 청소시간 추가 
        times.push_back({start_time, end_time}); // 시작시간과 끝나는 시간을 pair에 삽입ㅁ
    }
    sort(times.begin(), times.end()); // start값에 따른 정렬
    
    vector<int> room_end_time;
    
     for (auto& time : times) {
        bool flag = false;
        for (auto& end_time : room_end_time) {
            if (end_time <= time.first) { // 방이 비었으면
                end_time = time.second; // 방 사용 후 종료 시간 갱신
                flag = true;
                break;
            }
        }
        if (!flag) { // 배정되지 않았다면 새로운 방 필요
            room_end_time.push_back(time.second);
        }
    }

    return room_end_time.size(); // 필요한 방의 수
}