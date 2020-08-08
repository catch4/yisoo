// 프로그래머스 level3_베스트앨범

/*
장르의 총 재생 횟수를 담은 map : genre
장르별 재생 횟수, 고유번호를 담은 map : play
genres 확인하며 genre, play에 재생횟수 추가
재생횟수 많은 장르부터 play확인하면서 최대 2개씩 answer에 추가.
*/

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int,int> pi;
typedef pair<int,string> pp;

map<string, int> genre;
map<string, vector<pi>> play;
vector<pp> ans; 

bool cmpp(pp a, pp b){
    return a.first>b.first;
}

bool cmpi(pi a, pi b){
    return a.first>b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for(int i=0;i<genres.size();i++){
        genre[genres[i]] +=plays[i];
        play[genres[i]].push_back({plays[i],i});
    }
    
    for(auto it = genre.begin();it!=genre.end();it++){
        ans.push_back({it->second, it->first});
    }
    sort(ans.begin(),ans.end(),cmpp);
    
    for(int i=0;i<ans.size();i++){
        string s = ans[i].second;
        sort(play[s].begin(),play[s].end(),cmpi);
        answer.push_back(play[s][0].second);
        if(play[s].size()>1)
            answer.push_back(play[s][1].second);
    }
    
    return answer;
}