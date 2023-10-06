#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void convert3x3(vector<vector<int>> &A, int x, int y) {
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            
            if (A[i][j] == 0)
                A[i][j] = 1;
            else
                A[i][j] = 0;
            
        }
    }
}

bool isSame(vector<vector<int>> &A, vector<vector<int>> &B, int n, int m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (A[i][j] != B[i][j])
                return false;
        }
    }
    return true;
}

int convertAToB(int n, int m, vector<vector<int>> &A, vector<vector<int>> &B) {
    
    int cnt = 0;
    for (int i=0; i<=n-3; i++) {
        for (int j=0; j<=m-3; j++) {
            if (A[i][j] == B[i][j])
                continue;
            
            // 두 원소가 다르면 3x3 변환 (A를)
            convert3x3(A, i, j);
            cnt++;
        }
    }
    
    // 두 행렬이 같은지
    if (isSame(A, B, n, m))
        return cnt;
    else
        return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    //입력
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> mtrx_a(N, vector<int>(M, 0));
    vector<vector<int>> mtrx_b(N, vector<int>(M, 0));
    
    string input;
    for (int i=0; i<N; i++) {
        cin >> input;
        for (int j=0; j<M; j++) {
            int n = input[j] - '0';
            mtrx_a[i][j] = n;
        }
    }
    
    for (int i=0; i<N; i++) {
        cin >> input;
        for (int j=0; j<M; j++) {
            int n = input[j] - '0';
            mtrx_b[i][j] = n;
        }
    }
    
    cout << convertAToB(N, M, mtrx_a, mtrx_b);
    
    return 0;
}