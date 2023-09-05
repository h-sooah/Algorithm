#include <iostream>
#include <set>

using namespace std;

struct compare {
    bool operator() (const string &a, const string &b) const {
        return a > b;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N;
    string name, status;
    set<string, compare> s;
    
    cin >> N;
    while (N--) {
        cin >> name >> status;
        if (status == "enter")
            s.insert(name);
        else
            s.erase(name);
    }
    
    // 연산 및 출력
    for (auto iter : s)
        cout << iter << "\n";
    
    return 0;
}


