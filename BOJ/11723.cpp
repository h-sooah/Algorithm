#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    int M;
    cin >> M;
    
    string cmd;
    int num;
    bool check[21] = { false };
    
    while (M--) {
        cin >> cmd;
        
        if (cmd == "add") {
            cin >> num;
            check[num] = true;
        }
        else if (cmd == "remove") {
            cin >> num;
            check[num] = false;
        }
        else if (cmd == "check") {
            cin >> num;
            if (check[num])
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (cmd == "toggle") {
            cin >> num;
            if (check[num])
                check[num] = false;
            else
                check[num] = true;
        }
        else if (cmd == "all") {
            for (int i=1; i<=20; i++)
                check[i] = true;
        }
        else if (cmd == "empty") {
            for (int i=1; i<=20; i++)
                check[i] = false;
        }
    }
    
    return 0;
}