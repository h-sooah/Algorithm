#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int h, m, s;

void queryTwo (int c) {
    
    int hour, min, sec;
    hour = c / 3600;
    min = (c % 3600) / 60;
    sec = (c % 3600) % 60;
    
    s -= sec;
    while (s < 0) {
        s += 60;
        m--; 
    }
    
    m -= min;
    while (m < 0) {
        m += 60;
        h--;
    }
    
    h -= hour;
    while (h < 0) {
        h += 24;
    }
        
    
}

void queryOne (int c) {
    int hour, min, sec;
    hour = c / 3600;
    min = (c % 3600) / 60;
    sec = (c % 3600) % 60;
    
    s += sec;
    while (s >= 60) {
        s -= 60;
        m++; 
    }
    
    m += min;
    while (m >= 60) {
        m -= 60;
        h++;
    }
    
    h += hour;
    while (h >= 24)
        h -= 24;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    int q, T, c;
    cin >> h >> m >> s >> q;
    
    // 연산 및 출력
    while (q--) {
        cin >> T;
        
        if (T == 1) {
            cin >> c;
            queryOne(c);
        }
        else if (T == 2) {
            cin >> c;
            queryTwo(c);
        }
        else
            cout << h << " " << m << " " << s << "\n";
    }
    
    return 0;
}