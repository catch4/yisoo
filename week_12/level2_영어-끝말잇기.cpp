// 프로그래머스 level2_영어-끝말잇기

/*
만약 말했으면 탈락, 앞 글자 끝에랑 현재 글자 맨 앞이랑 달라도 탈락
아니면 진행.
*/
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string,bool> m;
    char last = words[0][0];
    for(int i=0;i<words.size();i++){
        string word = words[i];
        if(m[word] || last != words[i][0]) return {(i%n)+1,(i/n)+1};
        else
            m[word]= true;
        last = words[i][word.length()-1];
    }
    

    return {0,0};
}