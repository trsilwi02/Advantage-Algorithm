#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> note_from_number;;
    vector<string> note_to_number;
    vector<string> note_date;
    vector<string> note_from_time;
    vector<string> note_end_time;

    while (true){
        string s;
        cin >> s;
        if (c == "#") break;
        
        if (s == "call"){
            string from_number;
            cin >> from_number;
            int count;
            for (char c : from_number){
                count++;
                if (c <= 0 || c >= 9){
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
                if (c <= 0 || c >= 9){
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
        if (cmd == "#"){
            break;
        }

        if (cmd == "?check_phone_number"){
            bool check = true;
            for (string s : note_from_number){
                if (s == "null"){
                    cout << 0 << endl;
                    !check;
                    break;
                }
            }
            if (check){
                for (string s : note_to_number){
                    if (s == "null"){
                        cout << 0 << endl;
                        break;
                    }
                }
            }
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
            cout << note_from_number << end;
        }

        if (cmd == "?count_time_calls_from"){
            string number;
            cin >> number;
            long long time;
            for (int i = 0; i < note_from_number.length; i++){
                if (number == note_from_number[i]){
                    time = note_end_time[i] - note_from_time[i];
                }
            }
        }
    }
}