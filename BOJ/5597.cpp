#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<bool> students(31, false);
    int num;
    
    // 입력 및 출력
    for (int i=0; i<28; i++) {
        cin >> num;
        students[num] = true;
    }
    
    for (int i=1; i<31; i++) {
        if (students[i] == false)
            cout << i << "\n";
    }
        
    return 0;
    
}