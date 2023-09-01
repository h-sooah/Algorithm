#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string info, tmp;
    
    // 입력 및 연산 및 출력
    double subject_score, sum_grade = 0, sum_score = 0;
    for (int i=0; i<20; i++) {
        getline(cin, info);
        
        istringstream ss (info);
        vector<string> v;
        
        while (getline(ss, tmp, ' ')) {
            v.push_back(tmp);
        }
        
        
        double score = stod(v[1]);
        string grade = v[2];
        
        if (grade == "P") {
            continue;
        }
        
        sum_score += score;
        
        if (grade == "A+") {
            subject_score = 4.5;
        }
        else if (grade == "A0") {
            subject_score = 4.0;
        }
        else if (grade == "B+") {
            subject_score = 3.5;
        }
        else if (grade == "B0") {
            subject_score = 3.0;
        }
        else if (grade == "C+") {
            subject_score = 2.5;
        }
        else if (grade == "C0") {
            subject_score = 2.0;
        }
        else if (grade == "D+") {
            subject_score = 1.5;
        }
        else if (grade == "D0") {
            subject_score = 1.0;
        }
        else if (grade == "F") {
            subject_score = 0.0;
        }
        
        sum_grade += (score * subject_score);
    
    }
    
    cout.precision(6);
    cout << fixed << sum_grade / sum_score << "\n";
    
    
    return 0;
}