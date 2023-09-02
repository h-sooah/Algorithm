#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<string> inputs;
    string input;
    vector<vector<char>> words(5, vector<char>(15, '#'));

    // 입력, 연산 및 출력
    for (int i=0; i<5; i++) {
        cin >> input;
        inputs.push_back(input);
    }
    
    for (int i=0; i<5; i++) {
        string s = inputs[i];
        int size = s.size();
        
        for (int j=0; j<size; j++) {
            words[i][j] = s[j];
        }
    }
    
    for (int i=0; i<15; i++) {
        for (int j=0; j<5; j++) {
            if (words[j][i] != '#')
                cout << words[j][i];
        }
    }
    
    
    
    
    return 0;
}