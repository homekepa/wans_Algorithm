#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    float term = common[1] - common[0];
    if(term + common[1] == common[2]){
        return common[common.size() - 1] + term;  
    }
    term = common[1] / common[0];
    return common[common.size() - 1] * term; 
}