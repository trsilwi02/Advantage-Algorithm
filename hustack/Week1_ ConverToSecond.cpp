#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int hour;
int minute;
int second;

bool isValidTimeFormat(string& s) {
    if (s.length() != 8 || s[2] != ':' || s[5] != ':') return false;
    for (int i = 0; i < 8; ++i) {
        if (i == 2 || i == 5) continue;
        if (!isdigit(s[i])) return false;
    }

    hour = stoi(s.substr(0, 2));
    minute = stoi(s.substr(3, 2));
    second = stoi(s.substr(6, 2));

    return (0 <= hour && hour <= 23) &&
           (0 <= minute && minute <= 59) &&
           (0 <= second && second <= 59);
}

int main() {
    string timeStr;
    cin >> timeStr;
    if (isValidTimeFormat(timeStr)) {
        cout << hour *3600 + minute * 60 + second << endl;
    } else {
        cout << "INCORRECT" << endl;
    }
    return 0;
}