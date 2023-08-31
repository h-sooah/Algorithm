#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> scores;
    int N, input;
    
    // 입력 및 출력
    cin >> N;
    
    for (int i=0; i<N; i++) {
        cin >> input;
        scores.push_back(input);
    }
    
    sort(scores.begin(), scores.end());
    
    int MAX = scores[N-1];
    double sum = 0, tmp;
    for (int i=0; i<N; i++) {
        tmp = scores[i] * 100;
        tmp /= MAX;
        sum += tmp;
    }
    
    double avg = sum / N;
    
    cout << avg;
    
    return 0;
    
}