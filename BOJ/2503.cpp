#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct game {
    string num;
    int strike, ball;
};

int countStrike(string s1, string s2) {
    int cnt = 0;
    for (int i=0; i<3; i++) {
        if (s1[i] == s2[i])
            cnt++;
    }
    return cnt;
}

int countBall(string s1, string s2) {
    int cnt = 0;
    if (s1[0] == s2[1] || s1[0] == s2[2])
        cnt++;
    if (s1[1] == s2[0] || s1[1] == s2[2])
        cnt++;
    if (s1[2] == s2[0] || s1[2] == s2[1])
        cnt++;
    return cnt;
}

int countPossibles(vector<game> &arr) {
    
    int count = 0;
    bool flag = true;
    
    for (int i=123; i<=987; i++) {
        string s = to_string(i);
        flag = true;
        
        // 숫자에 0 들어가면 pass
        if (s[0] == '0' || s[1] == '0' || s[2] == '0')
            continue;
        
        // 숫자 같으면 pass
        if (s[0] == s[1] || s[1] == s[2] || s[2] == s[0])
            continue;
        
        for (int j=0; j<arr.size(); j++) {
            if (countStrike(s, arr[j].num) != arr[j].strike) {
                flag = false;
                break;
            }
            
            if (countBall(s, arr[j].num) != arr[j].ball) {
                flag = false;
                break;
            }
        }
        
        if (flag) {
            count++;
            //cout << "i: " << i << '\n';
        }
        
    }
    
    return count;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, strike, ball;
    string num;
    cin >> N;
    
    vector<game> arr;
    while (N--) {
        cin >> num >> strike >> ball;
        arr.push_back({num, strike, ball});
    }
    
    cout << countPossibles(arr);
    
    return 0;
}
