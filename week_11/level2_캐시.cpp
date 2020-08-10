// 프로그래머스 level2_캐시

/*
덱을 이용해서 
1. 캐시에 없으면 캐시에 넣어준다. 넣었을 때 캐시사이즈를 넘어가면 맨 앞 삭제
2. 캐시에 있으면 지우고 다시 캐시에 넣어준다. 
*/

#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> cache;
    int miss = 5, hit =1;
    for(string city :cities){
        for(int i=0;i<city.length();i++){
            city[i] = toupper(city[i]);
        }
        auto it = find(cache.begin(),cache.end(),city);
        if(it==cache.end()){
            answer +=miss;
            cache.push_back(city);
            if(cache.size()>cacheSize){
                cache.pop_front();
            }
        }
        else{
            cache.erase(it);
            cache.push_back(city);
            answer +=hit;
        }
    }        
    return answer;
}