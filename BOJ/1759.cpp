#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> answer;
int L, C;

// n: 모음 선택 개수
void findPassword(vector<char> &arr) {
    
    vector<bool> check_arr(arr.size(), true);
    for (int i=0; i<L; i++)
        check_arr[i] = false;
    
    // 일단 모음 선택
    do {
        string s = "";
        for (int i=0; i<arr.size(); i++)  {
            if (!check_arr[i])
                s += arr[i];
        }
        
        int count1 = 0, count2 = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                count1++;
            else
                count2++;
        }
        
        if (count1 >= 1 && count2 >= 2)
            answer.push_back(s);
        
    } while(next_permutation(check_arr.begin(), check_arr.end()));
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    cin >> L >> C;
    
    vector<char> arr;
    while (C--) {
        char c;
        cin >> c;
        arr.push_back(c);
    }
    
    sort(arr.begin(), arr.end());
    
    findPassword(arr);
    
    sort(answer.begin(), answer.end());
    
    for (string s: answer)
        cout << s << "\n";
    
    return 0;
}
