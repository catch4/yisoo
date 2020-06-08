#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#include <cstring>

//프로그래머스 level2_[1차]-프렌즈4블록

using namespace std;

// 1. 하나의 블록에서 오른,아래, 대각선 확인 => 2*2가 되는 지 확인
// 2. 된다면 오른,아래, 대각선 확인하면서 bfs
// 3. 참인 곳 없애고 블록 내리기.
// 1-4. 반복

int board[30][30];
bool visit[30][30];
int answer, col, row;

int dx[3] ={0,1,1};
int dy[3] ={1,0,1};

// 1.
bool isBlock(int x, int y){
    for(int i =0;i<3;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx > row || ny < 0 || ny > col || board[nx][ny] != board[x][y])
            return false;
    }
    return true;
}


// 2.
void bfs(int x,int y){
    if(!isBlock(x,y))
        return;
    
    queue<pair<int,int>> q;
    q.push({x,y});
    visit[x][y] = true;
    
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        if(isBlock(qx,qy)){
            for(int i =0;i<3;i++){
                int nx = qx + dx[i];
                int ny = qy + dy[i];
                if(nx >=0 && nx < row && ny >=0 && ny < col && !visit[nx][ny]){
                    q.push({nx,ny});
                    visit[nx][ny] = true;
                }
            }
        }
    }
}


// 3. 
int check(){
    int ret = 0;
    for(int i =0;i<row;i++){
        for(int j =0;j<col;j++){
            if(visit[i][j]){
                answer++;
                board[i][j] = -1;
                ret++;
            }
        }
    }
    memset(visit,0,sizeof(visit));
    return ret;
}

//3.
void fill(){
    for(int i=0; i<col;i++){
        for(int j = row-1 ; j>=0;j--){
            
            if(board[j][i] != -1)
                continue;
            int idx = j-1;
            while(board[idx][i] == -1 && idx>=0){idx--;}
            
            if(idx >=0){
                board[j][i] = board[idx][i];
                board[idx][i] = -1;
            }
            else
                break;
        }
        
    }
    return;
}


int solution(int m, int n, vector<string> b) {
    answer = 0;
    row = m, col =n;
    
    for(int i =0;i<b.size();i++){
        for(int j=0;j<b[i].length();j++){
            board[i][j] = b[i][j]-'A';
        }
    }
    
    // 반복
    while(true){
        for(int i=0;i<row-1;i++){
            for(int j= 0 ;j<col-1;j++){
                if(board[i][j]!=-1)
                    bfs(i,j);
            }
        }
        int ret = check();
        if(ret == 0)
            break;
        fill();
    }
    
    return answer;
}