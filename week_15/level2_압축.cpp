// 프로그래머스 level2_압축
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> dict;

vector<int> solution(string msg) {
    vector<int> answer;
    for(int i=0;i<26;i++){
        string s = string(1,'A'+i);
        dict[s] = i+1;
    }    
    int idx = 27;
    int now = 0;
    string tmp;
    
    while(now<msg.size()){
        tmp += msg[now];
        while(dict[tmp]){
            now++;
            tmp += msg[now];
        }
        tmp.pop_back();
        answer.push_back(dict[tmp]);
        dict[tmp+ msg[now]] = idx++;
        tmp.clear();
        
    }
    
    return answer;
}