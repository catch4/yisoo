// 프로그래머스 level3_입국심사

/*
이분탐색
시간을 심사시간으로 나눈 몫의 합이 n인 시간 중 가장 작은 시간 찾는다.
선형탐색으로 하기에는 시간이 부족하므로 이분탐색 활용

메인은 right가 1e14 ( 심사관 최대시간이 1e9 * 심사관의 수 1e5)부터;
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 1e14;
    
    long long left = 0, right = 1e14;
    
    while(left<right){
        long long mid =(left+right)/2;
        long long tmp = 0;
        
        for(int i=0;i<times.size();i++){
            tmp += mid/times[i];
        }
        
        if(tmp>=n){
            answer = min(answer,mid);
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return answer;
}