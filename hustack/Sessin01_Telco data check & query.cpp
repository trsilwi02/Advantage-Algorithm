// #include <bits/stdc++.h>
// using namespace std;

// struct Call {
//     string from_number;
//     string to_number;
//     string date;
//     string from_time;
//     string end_time;
//     int duration; // thời lượng cuộc gọi (giây)
// };

// // Chuyển "hh:mm:ss" -> giây
// int convertTimeToSeconds(const string &t) {
//     int h, m, s;
//     sscanf(t.c_str(), "%d:%d:%d", &h, &m, &s);
//     return h * 3600 + m * 60 + s;
// }

// // Kiểm tra số điện thoại hợp lệ
// bool isValidPhone(const string &p) {
//     if (p.size() != 10) return false;
//     for (char c : p) {
//         if (!isdigit(c)) return false;
//     }
//     return true;
// }

// int main() {
//     vector<Call> calls;
//     unordered_map<string, int> countCalls; // đếm số lần gọi từ số
//     unordered_map<string, long long> timeCalls; // tổng thời gian gọi
//     bool allValid = true;
//     int totalCalls = 0;

//     // Đọc block 1 (danh sách cuộc gọi)
//     string line;
//     while (true) {
//         getline(cin, line);
//         if (line == "#") break;
//         if (line.empty()) continue;

//         stringstream ss(line);
//         string cmd, from, to, date, t1, t2;
//         ss >> cmd >> from >> to >> date >> t1 >> t2;
//         if (cmd != "call") continue;

//         Call c;
//         c.from_number = from;
//         c.to_number = to;
//         c.date = date;
//         c.from_time = t1;
//         c.end_time = t2;

//         int start = convertTimeToSeconds(t1);
//         int end = convertTimeToSeconds(t2);
//         c.duration = end - start;

//         // kiểm tra số điện thoại
//         if (!isValidPhone(from) || !isValidPhone(to)) {
//             allValid = false;
//         }

//         calls.push_back(c);
//         totalCalls++;
//         countCalls[from]++;
//         timeCalls[from] += c.duration;
//     }

//     // Đọc block 2 (các truy vấn)
//     while (true) {
//         getline(cin, line);
//         if (line == "#") break;
//         if (line.empty()) continue;

//         stringstream ss(line);
//         string query;
//         ss >> query;

//         if (query == "?check_phone_number") {
//             cout << (allValid ? 1 : 0) << "\n";
//         } else if (query == "?number_calls_from") {
//             string num; 
//             ss >> num;
//             cout << countCalls[num] << "\n";
//         } else if (query == "?number_total_calls") {
//             cout << totalCalls << "\n";
//         } else if (query == "?count_time_calls_from") {
//             string num; 
//             ss >> num;
//             cout << timeCalls[num] << "\n";
//         }
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

struct Call {
    string numberFrom;
    string numberTo;
    string date;
    string timeFrom;
    string timeEnd;
    int duration;
};

int TimeToSecond(string t){
    int h, m, s;
    char sep;
    stringstream iss(t);
    iss >> h >> sep >> m >> sep >> s;
    return h*3600 + m*60 + s;
}

bool GoodPhoneNumber(string p){
    if (p.size() != 10) return false;
    for (char c:p){
        if (!isdigit(c)){
            return false;
        }
    }
    return true;
}

int main() {
    vector<Call> calls;
    map<string, int> countCalls;
    map<string, long long> timeCalls;
    bool allGoodNumber = true;
    int totalCalls = 0;

    string line;
    while (true) {
        getline(cin, line);
        if (line == "#") break;
        if (line.empty()) continue;

        stringstream ss(line);
        string cmd, from, to, date, t1, t2;
        ss >> cmd >> from >> to >> date >> t1 >> t2;
        if (cmd != "call") continue;

        Call c;
        c.numberFrom = from;
        c.numberTo = to;
        c.date = date;
        c.timeFrom = t1;
        c.timeEnd = t2;

        int start = TimeToSecond(t1);
        int end = TimeToSecond(t2);
        c.duration = end - start;

        if (!GoodPhoneNumber(from) || !GoodPhoneNumber(to)) {
            allGoodNumber = false;
        }

        calls.push_back(c);
        totalCalls++;
        countCalls[from]++;
        timeCalls[from] += c.duration;
    }

    while (true) {
        getline(cin, line);
        if (line == "#") break;
        if (line.empty()) continue;

        stringstream ss(line);
        string query;
        ss >> query;

        if (query == "?check_phone_number") {
            if (allGoodNumber) cout << 1 << endl;
            else cout << 0 << endl;
        } else if (query == "?number_calls_from") {
            string num; 
            ss >> num;
            cout << countCalls[num] << "\n";
        } else if (query == "?number_total_calls") {
            cout << totalCalls << "\n";
        } else if (query == "?count_time_calls_from") {
            string num; 
            ss >> num;
            cout << timeCalls[num] << "\n";
        }
    }

    return 0;
}