#include <bits/stdc++.h>
using namespace std;


int main(){
    string input;
    getline(cin, input);

    stringstream st(input);

    vector<long long> arr;
    int k;

    long long number, maxN = INT_MAX, minN = 0;
    while (st >> number){
        arr.push_back(number);
        minN = max(number, minN);
        maxN += number;
    }

    cin >> k;

    long long ans = INT_MAX;

    while (minN <= maxN){
        long long mid = minN + (maxN - minN)/2;
        int count=1;
        long long tmp = 0;
        for (int num : arr){
            if (tmp + num > mid) {
                tmp = num;
                count++;
            } else {
                tmp += num;
            }
        }

        if (count <= k){
            ans = mid;
            maxN = mid-1;
        } else {
            minN = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     string input;
//     getline(cin, input);

//     stringstream st(input);

//     vector<int> arr;
//     int k;

//     // SỬA 1: Dùng long long để tránh tràn số khi tính tổng
//     int number;
//     long long sumVal = 0; // Tổng tất cả các trang (cho cận trên)
//     int maxElement = 0;   // Quyển sách dày nhất (cho cận dưới)

//     while (st >> number){
//         arr.push_back(number);
//         maxElement = max(maxElement, number);
//         sumVal += number;
//     }

//     cin >> k;

//     // Nếu số học sinh nhiều hơn số sách -> Không chia được (theo đề bài thường trả về -1)
//     if (k > arr.size()) {
//         cout << -1 << endl;
//         return 0;
//     }

//     // SỬA 2: Thiết lập khoảng tìm kiếm đúng logic bài chia sách
//     // minN: Ít nhất phải đọc quyển dày nhất (không thể xé sách)
//     // maxN: Nhiều nhất là đọc hết tất cả (tổng)
//     long long minN = maxElement; 
//     long long maxN = sumVal;     
//     long long ans = sumVal;      // Khởi tạo ans là trường hợp tệ nhất

//     // SỬA 3: Dùng <= để không bỏ sót trường hợp khi minN == maxN
//     while (minN <= maxN){
//         long long mid = minN + (maxN - minN)/2; // Tính mid an toàn

//         int count = 1;
//         long long tmp = 0;
        
//         // Logic kiểm tra (Greedy)
//         for (int num : arr){
//             // Nếu cộng thêm quyển này mà vượt quá mid thì qua người mới
//             if (tmp + num > mid) {
//                 count++;
//                 tmp = num; // Người mới bắt đầu với quyển hiện tại
//             } else {
//                 tmp += num;
//             }
//         }

//         // SỬA 4: Cập nhật kết quả
//         if (count <= k){
//             ans = mid;      // mid này thỏa mãn, lưu lại làm kết quả tạm
//             maxN = mid - 1; // Thử tìm đáp án nhỏ hơn (tối ưu hơn)
//         } else {
//             minN = mid + 1; // mid quá nhỏ, không đủ sức chứa, phải tăng lên
//         }
//     }

//     cout << ans << endl;
//     return 0;
// }