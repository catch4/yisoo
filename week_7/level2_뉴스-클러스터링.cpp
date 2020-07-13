#include <string>
#include <vector>
#include <algorithm>
#include <map>

//프로그래머스 level2_뉴스-클러스터링

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    const int num = 65536;
    map<string,int> m;
    double intersection=0, union_size =0;

    for(int i=0;i<str1.length();i++){
        str1[i] = toupper(str1[i]);
    }
    for(int i=0;i<str2.length();i++){
        str2[i] = toupper(str2[i]);
    }
    string ret="";
    for(int i=0;i<str1.length()-1;i++){
        ret.clear();

        if(str1[i]<'A'||str1[i]>'Z'||str1[i+1]<'A'||str1[i+1]>'Z')
            continue;
        ret +=str1[i];
        ret +=str1[i+1];
        union_size++;
        if(m[ret])
            m[ret]++;
        else
            m[ret]=1;
    }

    for(int i=0;i<str2.length()-1;i++){
        ret.clear();

        if(str2[i]<'A'||str2[i]>'Z'||str2[i+1]<'A'||str2[i+1]>'Z')
            continue;
        ret +=str2[i];
        ret +=str2[i+1];
        if(m[ret]){
            m[ret]--;
            intersection++;
        }else
            union_size++;
    }

    if(union_size==0)
        return num;
    answer = (int)((double)num*intersection/union_size);


    return answer;
}