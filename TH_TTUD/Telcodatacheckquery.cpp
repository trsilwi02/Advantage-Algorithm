#include <bits/stdc++.h>
using namespace std;

struct Time {
    int h,m,s;
};

Time praseTime (string str){
    Time t;
    t.h = stoi(str.substr(0, 2)); // 2 ký tự
    t.m = stoi(str.substr(3, 2)); // 2 ký tự
    t.s = stoi(str.substr(6, 2)); // 2 ký tự
    return t;
}

long long ToSecond(Time time){
    return time.h*3600 + time.m*60+ time.s;
}


int main(){
    vector<string> note_from_number;;
    vector<string> note_to_number;
    vector<string> note_date;
    vector<string> note_from_time;
    vector<string> note_end_time;

    while (true){
        string s;
        cin >> s;
        if (s == "#") break;
        
        if (s == "call"){
            string from_number;
            cin >> from_number;
            int count = 0;
            for (char c : from_number){
                count++;
                if (c < '0' || c > '9'){
                    from_number = "null";
                    break;
                }
            }
            if (count != 10) from_number = "null";
            count = 0;
            note_from_number.push_back(from_number);

            string to_number;
            cin >> to_number;
            for (char c : to_number){
                count++;
                if (c < '0' || c > '9'){
                    to_number = "null";
                    break;
                }
            }
            if (count != 10) to_number = "null";
            note_to_number.push_back(to_number);

            string date;
            cin >> date;
            note_date.push_back(date);

            string from_time;
            cin >> from_time;
            note_from_time.push_back(from_time);

            string end_time;
            cin >> end_time;
            note_end_time.push_back(end_time);
        }
    } 

    while (true){
        string cmd;
        cin >> cmd;
        if (cmd == "#"){
            break;
        }

        if (cmd == "?check_phone_number"){
            bool check = true;
            for (string s : note_from_number){
                if (s == "null"){
                    cout << 0 << endl;
                    check = false;
                    break;
                }
            }
            if (check){
                for (string s : note_to_number){
                    if (s == "null"){
                        cout << 0 << endl;
                        check = false;
                        break;
                    }
                }
            }

            if (check) cout << 1 << endl;
        }

        if (cmd == "?number_calls_from"){
            string number;
            cin >> number;
            int count = 0;
            for (string s : note_from_number){
                if (s == number) count++;
            }
            cout << count << endl;
        }

        if (cmd == "?number_total_calls"){
            cout << note_from_number.size() << endl;
        }

        if (cmd == "?count_time_calls_from"){
            string number;
            cin >> number;
            long long time = 0;
            for (int i = 0; i < note_from_number.size(); i++){
                if (number == note_from_number[i]){
                    time += ToSecond(praseTime(note_end_time[i])) - ToSecond(praseTime(note_from_time[i]));
                }
            }

            cout << time << endl;
        }
    }
}