// 프로그래머스 level3_가장-긴-팰린드롬

/*
manacher 알고리즘 이용.

*/

#include <string>
#include <iostream>


using namespace std;

int val[5001];

int solution(string str)
{
    string s;
    
    int answer=0;
    int n = str.length();
    for (int i = 0; i < n; i++) {
		s += '#';
		s +=str[i];
	}
	s += '#';
	int r = 0, p = 0;
	for (int i = 0; i < s.length(); i++) {
		if (i <= r)
			val[i] = min(val[2 * p - i], r - i);
		else
			val[i] = 0;

		while (i - val[i] - 1 >= 0 && i + val[i] + 1 < s.length() && s[i - val[i] - 1] == s[i + val[i] + 1])
			val[i]++;

		if (r < i + val[i]) {
			r = i + val[i];
			p = i;
		}
	}
    int ans = -1;
	for (int i = 0; i < s.length(); i++) {
		answer = max(answer, val[i]);
	}
    return answer;
}