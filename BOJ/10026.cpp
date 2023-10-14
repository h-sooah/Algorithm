#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> picture;
vector<vector<bool>> visited;
int N;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool dfs(int row, int col, char color) {
    if (visited[row][col])
        return false;
        
    if (picture[row][col] != color)
        return false;
        
    visited[row][col] = true;
    for (int i=0; i<4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        
        if (nr >= 0 && nr < N && nc >= 0 && nc < N)
            dfs(nr, nc, picture[row][col]);
    }
    
    return true;
}

void greenToRed(int N, vector<vector<char>> &picture) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (picture[i][j] == 'G')
                picture[i][j] = 'R';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    cin >> N;
    
    picture.assign(N, vector<char>(N, ' '));
    visited.assign(N, vector<bool>(N, false));
    
    string input;
    for (int i=0; i<N; i++) {
        cin >> input;
        
        for (int j=0; j<N; j++)
            picture[i][j] = input[j];
    }
    
    // 출력
    int cnt = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (dfs(i, j, picture[i][j]))
                cnt++;
        }
    }
    
    cout << cnt << ' ';
    
    // green -> red 
    greenToRed(N, picture);
    
    cnt = 0;
    visited.assign(N, vector<bool>(N, false));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (dfs(i, j, picture[i][j]))
                cnt++;
        }
    }
    
    cout << cnt << ' ';

    return 0;
}
