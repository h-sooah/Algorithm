#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

map<string, int> dict;

bool compare (const string &a, const string &b) {
        if (dict[a] != dict[b])
            return dict[a] > dict[b];
        if (a.size() != b.size())
            return a.size() > b.size();
        return a < b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, M;
    vector<string> v;
    cin >> N >> M;

    string s;
    while (N--) {
        cin >> s;
        
        if (s.size() >= M) {
            if (dict.find(s) != dict.end())
                dict[s]++;
            else {
                dict.insert({s, 1});
                v.push_back(s);
            }
        }
        
    }

    // 연산 및 출력
    sort(v.begin(), v.end(), compare);
    
    for (string word : v)
        cout << word << "\n";
        
    return 0;
}
