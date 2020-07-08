#include <iostream>
#include <vector>
#include <map>
#include <string>
// ���� 15898�� �Ǿ��� ��Ʋ����

using namespace std;

// 0. �ùķ��̼� ����
// 1. n�� �� 3�� �̱� => ���.
// 2. 3�� ���� 6
// 3. 4���� 
// 4. 5*5�� �� �� �ִ� 4���� Ȯ�� => (0,0), (0,1), (1,0),(1,1)

// 5. ������ Ȯ��.

int dx[4] = { 0,0,1,1 };
int dy[4] = { 0,1,0,1 };

int n;
int matNum[10][4][4][4]; // ����ȣ, ����, ��ǥ
char matColor[10][4][4][4];
vector<vector<int>> hubo;

// 1+2. 3�������鼭 �������� ���ϱ�.
void choice(int cnt, bool check[10], string val) {
	if (cnt == 3) {
		vector<int> temp;
		for (int i = 0; i < 3; i++) {
			temp.push_back(val[i] - '0');
		}
		hubo.push_back(temp);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			check[i] = true;
			choice(cnt + 1, check, val + to_string(i));
			check[i] = false;
		}
	}
}

// 3. ȸ��
void rotate() { 
	for (int i = 0; i < n; i++) {					// ��� ��ȣ
		for (int j = 1; j < 4; j++) {				// ����
			for (int x = 0; x < 4; x++) {		// x��ǥ
				for (int y = 0; y < 4; y++) {	// y��ǥ
					matNum[i][j][3 - y][x] = matNum[i][j-1][x][y];
					matColor[i][j][3 - y][x] = matColor[i][j-1][x][y];
				}
			}
		}
	}
	return;
}
// �� �������� ������ �� Ȯ�� 
// @num : ��� ����, @num_x,y: ���� ��ǥ. ,@num_d : ����
int count(vector<int> num, vector<int> num_x, vector<int> num_y, vector<int> num_d) {
	int mapNum[5][5];
	char mapColor[5][5];
	// �ʱ�ȭ
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			mapNum[i][j] = 0;
			mapColor[i][j] = 'W';
		}
	}
	// ��� �� �� �ֱ�.
	for (int k = 0; k < 3; k++) {
		int now = num[k], now_x = num_x[k], now_y = num_y[k], now_d = num_d[k];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				mapNum[i + now_x][j + now_y] += matNum[now][now_d][i][j];	// ǰ�� �߰�
				// 0�̸� 9�ʰ� ó��
				if (mapNum[i + now_x][j + now_y] < 0) mapNum[i + now_x][j + now_y] = 0;	
				else if (mapNum[i + now_x][j + now_y] > 9) mapNum[i + now_x][j + now_y] = 9;
				// �� �ֱ�.
				mapColor[i + now_x][j + now_y] = matColor[now][now_d][i][j] == 'W' ? mapColor[i + now_x][j + now_y] : matColor[now][now_d][i][j];
			}
		}
		
	}
	// ���� ���
	map<char, int> color;
	color['R'] = 0, color['G'] = 0, color['B'] = 0, color['Y'] = 0 ;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			color[mapColor[i][j]] += mapNum[i][j];
		}
	}
	
	return 7 * color['R']+3* color['G']+ 5* color['B'] +2*color['Y'];
}


int main() {
	cin >> n;
	// 0. �Է¹ޱ�
	for (int i = 0; i < n; i++) {
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				cin >> matNum[i][0][x][y];
			}
		}
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				cin >> matColor[i][0][x][y];
			}
		}
	}
	// 3.
	rotate();

	//1.
	bool check[10] = { 0, };
	choice(0, check,"");
	
	int ret = 0;
	for (vector<int> v : hubo) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					for (int l = 0; l < 4; l++) {
						for (int m = 0; m < 4; m++) {
							for (int n = 0; n < 4; n++) {
								int temp = count(v, { dx[i],dx[j],dx[k] }, { dy[i],dy[j],dy[k] }, { l,m,n });
								ret = ret > temp ? ret : temp;
							}
						}
					}
				}
			}
		}
	}
	cout << ret;

	return 0;
}