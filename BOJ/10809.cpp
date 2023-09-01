#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s;
    vector<int> checked(26, -1);
    
    // 입력
    cin >> s;
    
    // 출력
    int size = s.size();
    
    for (int i=0; i<size; i++) {
        int index = s[i] - 'a';
        
        if (checked[index] == -1)
            checked[index] = i;
    }
    
    for (int i : checked) {
        cout << i << " ";
    }
    
    return 0;
    
}