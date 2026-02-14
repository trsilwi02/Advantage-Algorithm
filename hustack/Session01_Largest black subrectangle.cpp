// #include <bits/stdc++.h>
// using namespace std;

// int MaxRectangle (vector<int> arr){
//     stack<int> st;
//     int maxRec = 0;

//     for (int i = 0; i < arr.size(); i++){
//         while (!st.empty() && arr[i] <= arr[st.top()]){
//             int tmp = st.top();
//             st.pop();
//             int width;
//             if (st.empty()){
//                 width = i;
//             } else {
//                 width = i - st.top() - 1;
//             }

//             int area = arr[tmp] * width;
//             maxRec = max(maxRec, area);
//         }

//         st.push(i);
//     }

//     // Xử lý các phần tử còn lại trong stack
//     while (!st.empty()) {
//         int heightIndex = st.top();
//         st.pop();
        
//         int width;
//         if (st.empty()) {
//             width = arr.size();
//         } else {
//             width = arr.size() - st.top() - 1;
//         }
        
//         int area = arr[heightIndex] * width;
//         maxRec = max(maxRec, area);
//     }

//     return maxRec;

// }

// int main(){
//     int n, m;
//     cin >> n >> m;

//     vector<vector<int>> matrix(n, vector<int>(m));
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cin >> matrix[i][j];
//         }
//     }

//     int maxArea = 0;
//     vector<int> heights(m, 0);

//     // Xử lý từng hàng
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (matrix[i][j] == 1) {
//                 heights[j]++; // Tăng chiều cao nếu gặp 1
//             } else {
//                 heights[j] = 0; // Reset về 0 nếu gặp 0
//             }
//         }
        
//         int currentArea = MaxRectangle(heights);
//         maxArea = max(maxArea, currentArea);
//     }

//     cout << maxArea;
    
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int MaxRectangle(vector<int> const &arr){
    stack<int> st;
    int maxRec = 0;

    for (int i = 0; i < arr.size(); i++){
        while (!st.empty() && arr[i] <= arr[st.top()]){
            int tmp = st.top();
            st.pop();
            int width;
            if (st.empty()){
                width = i;
            } else {
                width = i - st.top() - 1;
            }

            int area = arr[tmp] * width;
            maxRec = max(maxRec, area);
        }

        st.push(i);
    }

    while (!st.empty()) {
        int heightIndex = st.top();
        st.pop();
        
        int width;
        if (st.empty()) {
            width = arr.size();
        } else {
            width = arr.size() - st.top() - 1;
        }
        
        int area = arr[heightIndex] * width;
        maxRec = max(maxRec, area);
    }

    return maxRec;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    vector<int> arr(m, 0);
    int maxArea = MaxRectangle(arr);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                arr[j]++;
            } else {
                arr[j] = 0;
            }
        }
        
        int currentArea = MaxRectangle(arr);
        maxArea = max(maxArea, currentArea);
    }

    cout << maxArea;

    return 0;
}