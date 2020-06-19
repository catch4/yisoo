#include<cstdio>

/*            U
          0  1  2
          3  4  5
          6  7  8
L        __________    R            B
36 37 38|F18 19 20 | 45 46 47 | 27 28 29
39 40 41| 21 22 23 | 48 49 50 | 30 31 32
42 43 44| 24 25 26 | 51 52 53 | 33 34 35
        -----------
          9  10 11
          12 13 14
          15 16 17
          D
*/

// 백준 풀이 참고 https://sangdo913.tistory.com/185

enum FACE { U, D, F, B, L, R, SIZE };
char init[7] = "wyrogb";
char arr[55];
int cube[SIZE][3][3];
char temp[3][3];

int rot[6][12] = {
    {36,37,38,18,19,20,45,46,47,27,28,29},        //U
    {33,34,35,51,52,53,24,25,26,42,43,44},        //D
    {6,7,8,44,41,38,11,10,9,45,48,51},            //F
    {2,1,0,53,50,47,15,16,17,36,39,42},            //B
    {0,3,6,35,32,29,9,12,15,18,21,24},            //L
    {8,5,2,26,23,20,17,14,11,27,30,33}            //R
};

void rotate(FACE f, int cnt) {
    char que[12];

    while (cnt--) {
        for (int i = 0; i < 12; i++) {
            que[i] = arr[rot[f][i]];
        }
        for (int i = 0; i < 12; i++) {
            arr[rot[f][i]] = que[(i + 3) % 12];
        }
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
            temp[j][2 - i] = arr[cube[f][i][j]];
        }
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) arr[cube[f][i][j]] = temp[i][j];
    }
}

int conv[256];

int main() {
    conv['-'] = 3;
    conv['+'] = 1;
    conv['U'] = U;
    conv['D'] = D;
    conv['F'] = F;
    conv['B'] = B;
    conv['L'] = L;
    conv['R'] = R;

    //큐브 인덱스 부여하기
    for (int i = 0; i < SIZE; i++) for (int j = 0; j < 3; j++) for (int k = 0; k < 3; k++) cube[i][j][k] = i * 9 + j * 3 + k;
    int n, m;
    char comm[3];

    scanf("%d\n", &n);

    while (n--) {
        //큐브 초기화
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 9; j++) {
                arr[i * 9 + j] = init[i];
            }
        }

        scanf("\n%d\n", &m);

        while (m--) {
            scanf("%s \n", comm);

            int f = conv[comm[0]], cnt = conv[comm[1]];
            rotate((FACE)f, cnt);
        }

        //출력
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%c", arr[cube[U][i][j]]);
            }
            printf("\n");
        }
    }

    return 0;
}
//// 내풀이
//#include <iostream>
//#include <string>
//#include <map>
//#include <vector>
//
//using namespace std;
//
//map<char, vector<string>> cube;
//string face = "UDFBLR";
//string color = "wyrogb";
//
//void init() {
//	for (int i = 0; i < 6; i++) {
//		string temp;
//		vector<string> str;
//		for (int j = 0; j < 3; j++)
//			temp += color[i];
//		for (int j = 0; j < 3; j++) 
//			str.push_back(temp);
//		cube[face[i]] = str;
//	}
//	return;
//}
//
//string getR(string str) {
//	int len = str.length() - 1;
//	string ret;
//	for (int i = len; i >= 0; i--) {
//		ret += str[i];
//	}
//	return ret;
//}
//void swap(string& a, string& b) {
//	string temp = a;
//	a = b;
//	b = temp;
//	return;
//}
//
//
//string getString(char c, int x, int y) {
//	if (y == -1)
//		return cube[c][x];
//	string ret;
//	for (int i = 0; i < 3; i++)
//		ret += cube[c][i][y];
//	return ret;
//}
//void rotate(int cnt, char c) {
//	
//	for (int k = 0; k < cnt; k++) {
//		vector<string> str;
//		for (int i = 0; i < 3; i++) {
//			string temp;
//			for (int j = 2; j >=0; j--)
//				temp += cube[c][j][i];
//			str.push_back(temp);
//		}
//		cube[c] = str;
//	}
//	
//	return;
//
//}
//void U(int cnt) {
//	string order = "FRBL";
//	for (int i = 0; i < cnt; i++) {
//
//		for (int j = 0; j < 3; j++) {
//			swap(cube[order[j]][0], cube[order[j + 1]][0]);
//		}
//	}
//	return;
//}
//
//void D(int cnt) {
//	string order = "LBRF";
//	for (int i = 0; i < cnt; i++) {
//		for (int j = 0; j < 3; j++) {
//			swap(cube[order[j]][2], cube[order[j + 1]][2]);
//		}
//	}
//	return;
//}
//
//void L(int cnt) {
//	for (int i = 0; i < cnt; i++) {
//		string u = getString('U', -1, 0);
//		string f = getString('F', -1, 0);
//		string d = getString('D', -1, 0);
//		string b = getString('B', -1, 2);
//		d = getR(d);
//		b = getR(b);
//
//		for (int j = 0; j < 3; j++) {
//			cube['F'][j][0] = u[j];
//			cube['D'][j][0] = f[j];
//			cube['B'][j][2] = d[j];
//			cube['U'][j][0] = b[j];
//		}
//	}
//	return;
//}
//
//void R(int cnt) {
//	for (int i = 0; i < cnt; i++) {
//		string u = getString('U', -1, 2);
//		string f = getString('F', -1, 2);
//		string d = getString('D', -1, 2);
//		string b = getString('B', -1, 0);
//		u = getR(u);
//		b = getR(b);
//
//		for (int j = 0; j < 3; j++) {
//			cube['F'][j][2] = d[j];
//			cube['D'][j][2] = b[j];
//			cube['B'][j][0] = u[j];
//			cube['U'][j][2] = f[j];
//		}
//	}
//	return;
//}
//
//void F(int cnt) {
//	for (int i = 0; i < cnt; i++) {
//		string u = getString('U', 2, -1);
//		string r = getString('R', -1, 0);
//		string d = getString('D', 0, -1);
//		string l = getString('L', -1, 2);
//		l = getR(l); 
//		r = getR(r); 
//
//		for (int j = 0; j < 3; j++) {
//			cube['R'][j][0] = u[j];
//			cube['D'][0][j] = r[j];
//			cube['L'][j][2] = d[j];
//			cube['U'][2][j] = l[j];
//		}
//	}
//	return;
//}
//
//void B(int cnt) {
//	for (int i = 0; i < cnt; i++) {
//		string u = getString('U', 0, -1);
//		string r = getString('R', -1, 2);
//		string d = getString('D', 2, -1);
//		string l = getString('L', -1, 0);
//		u = getR(u); 
//		d = getR(d);
//
//		for (int j = 0; j < 3; j++) {
//			cube['R'][j][2] = d[j];
//			cube['D'][2][j] = l[j];
//			cube['L'][j][0] = u[j];
//			cube['U'][0][j] = r[j];
//		}
//	}
//	return;
//}
//void printCube() {
//	cout << endl;
//	for (int i = 0; i < 3; i++) {
//		cout << cube['U'][i] << " ";
//		cout << cube['D'][i] << " ";
//		cout << cube['F'][i] << " ";
//		cout << cube['B'][i] << " ";
//		cout << cube['L'][i] << " ";
//		cout << cube['R'][i] << " ";
//		cout << endl;
//	}
//	cout << endl;
//}
//void count(vector<string> cmd) {
//	for (string str : cmd) {
//		int cnt = str[1] == '-' ? 3 : 1;
//		if (str[0] == 'U')
//			U(cnt);
//		else if (str[0] == 'D')
//			D(cnt);
//		else if (str[0] == 'F')
//			F(cnt);
//		else if (str[0] == 'B')
//			B(cnt);
//		else if (str[0] == 'L')
//			L(cnt);
//		else
//			R(cnt);
//		rotate(cnt, str[0]);
//	}
//}
//
//int main() {
//	int tc;
//	cin >> tc;
//	while (tc--) {
//		int n;
//		cin >> n;
//		vector<string> cmd(n);
//		for (int i = 0; i < n; i++)
//			cin >> cmd[i];
//		init();
//		count(cmd);
//		for (int i = 0; i < 3; i++) {
//			cout << cube['U'][i] << endl;
//		}
//		
//	}
//	return 0;
//}

