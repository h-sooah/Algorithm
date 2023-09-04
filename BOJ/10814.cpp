#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct member {
    int seq;
    int age;
    string name;
};

bool comp (const member &a, const member &b) {
    if (a.age != b.age)
        return a.age < b.age;
    return a.seq < b.seq;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N;
    cin >> N;
    
    // 연산 및 출력
    vector<member> v;
    int age;
    string name;
    member m;
    for (int i=1; i<=N; i++) {
        cin >> age >> name;
        m.seq = i;
        m.age = age;
        m.name = name;
        v.push_back(m);
    }
    
    sort(v.begin(), v.end(), comp);
    
    for (member m : v) {
        cout << m.age << " " << m.name << "\n";
    }
    
    return 0;
}