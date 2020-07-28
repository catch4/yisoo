// 프로그래머스 level1_키패드-누르기

// 키패드의 위치와 왼손, 오른손 위치를 정하여 거리 계산.

#include <string>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int,int> pi;

pi left, right;

char getNum(string hand, int num){
    if(num %3 ==1){
        left = {num/3,0};
        return 'L';
    }else if(num%3 == 0 && num!=0){ // 0은 제외해야 한다.
        right = {num/3-1,2};
        return 'R';
    }else{
        int x = num == 0? 3:num/3;  // 0일 때를 고려
        int y = 1;
        pi now ={x,y};
        int distL = abs(left.first -x) + abs(left.second - y);
        int distR = abs(right.first - x) + abs(right.second -y);
       
        if(distL > distR){
            right = now;
            return 'R';
        }else if(distL<distR){
            left = now;
            return 'L';
        }else{
            if(hand == "left"){
                left = now;
                return 'L';
            }else{
                right = now;
                return 'R';
            }
        }
        
    }    
}



string solution(vector<int> numbers, string hand) {
    string answer = "";
    left = {3,0}, right = {3,2};
    
    for(int num : numbers){
        answer += getNum(hand,num);
    }
    
    return answer;
}