#include <iostream>
#include <vector>
#include <string>

using namespace std;

string isPerfect(int num) {
    string result = to_string(num);
    vector<int> v;
    
    for (int i=1; i<num; i++) {
        if (num % i == 0)
            v.push_back(i);
    }
    
    int sum = 0;
    
    for (int i : v) {
        sum += i;
    }
    
    if (sum != num) {
        result += " is NOT perfect.";
    }
    else {
        result += " = ";
        for (int i=0; i<v.size(); i++) {
            result += to_string(v[i]);
            if (i != v.size() -1)
                result += " + ";
        }
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int num;
    
    // 입력 및 출력
    while (true) {
        cin >> num;
        
        if (num == -1)
            return 0;
        
        cout << isPerfect(num) << "\n";
    }
    
    
    return 0;
}