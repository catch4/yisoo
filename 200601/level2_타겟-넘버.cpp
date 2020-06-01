#include <string>
#include <vector>

//프로그래머스 level2_타겟-넘버

using namespace std;

int answer;

// dfs 재귀 이용
// vector, target
// idx : 현재 인덱스 val: 현재 값
void dfs(vector<int> num, int target, int idx, int val){
    //만약 모든 경우 확인
    if(idx == num.size()){
        if(val == target) answer++;	// 현재 값이 target과 같다면
        return;
    }
    dfs(num, target, idx+1, val + num[idx]);	// + 경우
    dfs(num, target, idx+1, val - num[idx]);	// - 경우
    return;    
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    dfs(numbers,target,0,0);
    return answer;
}