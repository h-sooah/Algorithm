#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	string sent;
	getline(cin, sent);
	
	int len;
	len = sent.length();

	vector<char> v;
	int flag = 0;

	for (int i = 0; i < len; i++) {
		if (flag == 0 && sent[i] == 'U') {
			v.push_back('U');
			flag++;
		}
		else if ( (flag == 1 || flag == 3) && sent[i] == 'C') {
			v.push_back('C');
			flag++;
		}
		else if (flag == 2 && sent[i] == 'P') {
			v.push_back('P');
			flag++;
		}
	}
	
	if (flag == 4 && v[0] == 'U' && v[1] == 'C' && v[2] == 'P' && v[3] == 'C')
		cout << "I love UCPC";
	else
		cout << "I hate UCPC";
}