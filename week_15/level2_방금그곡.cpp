// 프로그래머스 level2_방금그곡

/*
#은 소문자로 대체 
나머지는 구현.

*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, vector<string>> pi;
typedef pair<vector<int>, string> pp;

string change(string m){
    string tmp;
    for(int i=0;i<m.size();i++){
        if(m[i] == '#') continue;
        if(i!=m.size()-1 && m[i+1]=='#'){
            tmp += tolower(m[i]);
        }else{
            tmp += m[i];
        }
    }
    return tmp;
}

int getTime(string start, string end){
    int hourStart = stoi(start.substr(0,2));
    int hourEnd = stoi(end.substr(0,2));
    
    int minStart = stoi(start.substr(3,2));
    int minEnd = stoi(end.substr(3,2));
    
    return (hourEnd-hourStart)*60 + minEnd-minStart;
}

pi split(string info){
    vector<string> ret;
    string tmp;
    for(int i=0;i<info.size();i++){
        if(info[i]==','){
            ret.push_back(tmp);
            tmp.clear();
        }else{
            tmp +=info[i];
        }
    }
    ret.push_back(tmp);
    vector<string> ans;
    ans.push_back(ret[2]);
    ans.push_back(change(ret[3]));
    
    int time = getTime(ret[0],ret[1]);
    return {time,ans};
}

string make(int time, string info){
    int size = info.size();
    string tmp;
    for(int i=0;i<time/size;i++){
        tmp +=info;
    }
    for(int i=0;i<time%size;i++){
        tmp +=info[i];
    }
    
    return tmp;
    
}

bool contain(string m, string code){
    int ms = m.size();
    int cs = code.size();
    bool flag = false;
    for(int i=0;i<=cs-ms;i++){
        flag = false;
        for(int j = 0;j<ms;j++){
            if(m[j] != code[i+j]){
                flag = true;
                break;
            }
        }
        if(!flag)
            return true;
    }
    return false;
    
}

bool cmp(pp a, pp b){
    if(a.first[0] == b.first[0])
        return a.first[1]<b.first[1];
    return a.first[0]>b.first[0];
}

string solution(string m, vector<string> musicinfos) {
    string answer;
    vector<pp> ans;
    
    for(int i=0;i<musicinfos.size();i++){
        string info = musicinfos[i];
        pi p = split(info);
        string code = make(p.first, p.second[1]);
        if(contain(change(m),code)){
            ans.push_back({{p.first,i},p.second[0]});
        }
    }
    
    if(ans.size()==0)
        return "(None)";
    if(ans.size()==1)
        return ans[0].second;
    
    sort(ans.begin(),ans.end(),cmp);
    return ans[0].second;
}