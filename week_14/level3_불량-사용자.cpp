// 프로그래머스 level3_불량-사용자

/*
사용자, 제재 최대 크기 8이므로 가능한 경우는 8^8이므로 완전 탐색
다만 중복 제거해야 하므로 set이용
*/

#include <string>
#include <vector>
#include <set>

using namespace std;


set<set<string>> ss;
vector<string> user;
vector<string> ban;

// 아이디에 속했는지 확인
bool contain(string a, string b){
    if(a.size()!=b.size()){
        return false;
    }
    int len = a.size();
    
    for(int i=0;i<len;i++){
        if(a[i]=='*')
            continue;
        if(a[i]!=b[i])
            return false;
    }
    return true;
}

// 완전 탐색
void solve(vector<string> arr, int b){
    if(b == ban.size()){
        set<string> s;
        for(string str: arr)
            s.insert(str);
        // 아이디 개수가 중복이 없을 경우
        if(s.size()==ban.size())
            ss.insert(s);
        return;
    }
    
    for(int i=0;i<user.size();i++){
        if(contain(ban[b],user[i])){
            arr.push_back(user[i]);
            solve(arr,b+1);
            arr.pop_back();
        }
    }
    return;
}



int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    user =user_id, ban = banned_id;
    
    solve({},0);
    
    return ss.size();
}