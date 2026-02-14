#include <iostream>
#include <string>
#include <vector>
#include <sstream> // Để xử lý chuỗi thời gian
#include <map>     // Để lưu trữ doanh thu theo shop và khách hàng
#include <algorithm> // Để sắp xếp và tìm kiếm nhị phân
#include <utility>   // Cho std::pair và std::make_pair

// Sử dụng long long để đảm bảo không bị tràn số khi tính tổng doanh thu
using namespace std;

/**
 * @brief Chuyển đổi chuỗi thời gian "HH:MM:SS" thành tổng số giây.
 * @param timeStr Chuỗi thời gian đầu vào.
 *V @return Tổng số giây.
 */
int timeToSeconds(string timeStr) {
    // Thay thế dấu ':' bằng dấu cách để stringstream có thể đọc
    replace(timeStr.begin(), timeStr.end(), ':', ' ');
    stringstream ss(timeStr);
    int h, m, s;
    ss >> h >> m >> s;
    return h * 3600 + m * 60 + s;
}

int main() {
    // Tối ưu hóa tốc độ nhập/xuất của C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // === 1. Lưu trữ và Tính toán trước ===

    long long totalOrders = 0;
    long long totalRevenue = 0;
    
    // map lưu doanh thu của mỗi shop: <ShopID, totalRevenue>
    map<string, long long> shopRevenue;
    
    // map lưu doanh thu của khách hàng tại shop: <{CustomerID, ShopID}, totalRevenue>
    map<pair<string, string>, long long> customerShopRevenue;
    
    // vector để lưu <thời gian (giây), giá> cho truy vấn theo giai đoạn
    vector<pair<int, int>> timeSortedRevenue;

    string customerID, productID, shopID, timeStr;
    int price;

    // === 2. Đọc khối dữ liệu ===
    while (cin >> customerID && customerID != "#") {
        cin >> productID >> price >> shopID >> timeStr;

        // Tính toán trước các giá trị tổng
        totalOrders++;
        totalRevenue += price;
        shopRevenue[shopID] += price;
        customerShopRevenue[{customerID, shopID}] += price;

        // Chuyển đổi thời gian và lưu lại để xử lý sau
        int timeInSeconds = timeToSeconds(timeStr);
        timeSortedRevenue.push_back({timeInSeconds, price});
    }

    // === 3. Xử lý hậu kỳ cho truy vấn thời gian ===

    // Sắp xếp vector theo thời gian O(N log N)
    sort(timeSortedRevenue.begin(), timeSortedRevenue.end());

    // Xây dựng mảng tổng tiền tố (prefix sum)
    // prefixRevenueSum[i] sẽ lưu tổng doanh thu của các đơn hàng từ 0 đến i-1
    vector<long long> prefixRevenueSum(totalOrders + 1, 0);
    for (int i = 0; i < totalOrders; ++i) {
        prefixRevenueSum[i + 1] = prefixRevenueSum[i] + timeSortedRevenue[i].second;
    }

    // === 4. Đọc khối truy vấn ===
    string queryType;
    while (cin >> queryType && queryType != "#") {
        if (queryType == "?total_number_orders") {
            cout << totalOrders << "\n";
        } 
        else if (queryType == "?total_revenue") {
            cout << totalRevenue << "\n";
        } 
        else if (queryType == "?revenue_of_shop") {
            cin >> shopID;
            // Nếu shopID không tồn tại, map[key] sẽ tự động trả về 0
            cout << shopRevenue[shopID] << "\n";
        } 
        else if (queryType == "?total_consume_of_customer_shop") {
            cin >> customerID >> shopID;
            cout << customerShopRevenue[{customerID, shopID}] << "\n";
        } 
        else if (queryType == "?total_revenue_in_period") {
            string from_time_str, to_time_str;
            cin >> from_time_str >> to_time_str;

            int from_seconds = timeToSeconds(from_time_str);
            int to_seconds = timeToSeconds(to_time_str);

            // Tìm vị trí bắt đầu (đơn hàng đầu tiên >= from_seconds)
            // Cặp {from_seconds, 0} đảm bảo nó tìm đúng
            auto it_lower = lower_bound(timeSortedRevenue.begin(), 
                                        timeSortedRevenue.end(), 
                                        make_pair(from_seconds, 0));

            // Tìm vị trí kết thúc (đơn hàng đầu tiên > to_seconds)
            // Cặp {to_seconds, 1001} (vì giá max là 1000) đảm bảo nó
            // lấy tất cả các đơn hàng có thời gian = to_seconds
            auto it_upper = upper_bound(timeSortedRevenue.begin(), 
                                        timeSortedRevenue.end(), 
                                        make_pair(to_seconds, 1001));

            // Lấy chỉ số từ các iterator
            int idx_lower = it_lower - timeSortedRevenue.begin();
            int idx_upper = it_upper - timeSortedRevenue.begin();

            // Tính tổng doanh thu bằng cách lấy hiệu của hai tổng tiền tố
            // prefixRevenueSum[idx_upper] = tổng từ 0 -> idx_upper-1
            // prefixRevenueSum[idx_lower] = tổng từ 0 -> idx_lower-1
            cout << (prefixRevenueSum[idx_upper] - prefixRevenueSum[idx_lower]) << "\n";
        }
    }

    return 0;
}