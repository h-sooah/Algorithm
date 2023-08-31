#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> vector;
    int num;
    
    // 입력 및 출력
    for (int i=0; i<9; i++) {
        cin >> num;
        vector.push_back(num);
    }

    int max_num = -1, index = -1;
    for (int i=0; i<9; i++) {
        if (vector[i] > max_num) {
            max_num = vector[i];
            index = (i + 1);
        }
    }
    
    cout << max_num << "\n";
    cout << index << "\n";
    
    return 0;
    
}