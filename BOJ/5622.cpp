#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string word;
    
    // 입력
    cin >> word;
    
    // 출력
    int sum = 0;
    for (int i=0; i<word.size(); i++) {
        char w = word[i];
        
        if (w == 'A' || w == 'B' || w == 'C')
            sum += 3;
        else if (w == 'D' || w == 'E' || w == 'F')
            sum += 4;
        else if (w == 'G' || w == 'H' || w == 'I')
            sum += 5;
        else if (w == 'J' || w == 'K' || w == 'L')
            sum += 6;
        else if (w == 'M' || w == 'N' || w == 'O')
            sum += 7;
        else if (w == 'P' || w == 'Q' || w == 'R' || w == 'S')
            sum += 8;
        else if (w == 'T' || w == 'U'|| w == 'V')
            sum += 9;
        else
            sum += 10;
    }
    
    cout << sum << "\n";
    
    return 0;
    
}