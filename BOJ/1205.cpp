#include <iostream>
#include <vector>

using namespace std;

int findNewRank(vector<int> &v, int new_score, int N, int P) {
    
    int rank = 1;
    for (int i=0; i<N; i++) {
        
        if (new_score < v[i]) {
            rank++;
            continue;
        }
        
        if (new_score == v[i]) {
            continue;
        }
        
        if (new_score > v[i]) {
            return rank;
        }
            
    }
    
    if (N == P)
        return -1;
        
    return rank;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, new_score, P;
    cin >> N >> new_score >> P;
    
    // N이 0일 땐 더 연산할 필요 X
    if (N == 0) {
        cout << 1 << '\n';
        return 0;
    }
    
    vector<int> v(P, 0);
    for (int i=0; i<N; i++)
        cin >> v[i];
        
    
    cout << findNewRank(v, new_score, N, P);

    return 0;
}