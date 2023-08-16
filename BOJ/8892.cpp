#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int palinedrome(string str) {
	string a;
	a = str;
	reverse(str.begin(), str.end());
	if (a == str)
		return 1;
	else
		return 0;
}

int main() {

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {

		int k;
		cin >> k;
		string* words = new string[100];

		for (int j = 0; j < k; j++) {
			string word;
			cin >> word;
			words[j] = word;
		}

		int flag = 0;
		string pal;
		string str;
		for (int j = 0; j < k; j++) {

			for (int l = j + 1; l < k; l++) {
				str = words[j] + words[l];
				if (palinedrome(str)) {
					pal = str;
					flag++;
					break;
				}
			}

		}

		if (flag == 0) {
			for (int j = k - 1; j >= 0; j--) {

				for (int l = j - 1; l >= 0; l--) {
					str = words[j] + words[l];
					if (palinedrome(str)) {
						pal = str;
						flag++;
						break;
					}
				}
			}
		}

		if (flag != 0)
			cout << pal << "\n";
		else
			cout << "0" << "\n";
	}


}