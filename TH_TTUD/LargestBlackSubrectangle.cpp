#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int, int> adj;

vector<int> build(){
    vector<int> maxArr;
    vector<int,int> H;
    for (int i = 0; i < m; i++){ //Lot truoc nen
        H.push_back(adj[0][i]);
        maxArr.push_back(adj[0][i]);
    }

    for (int i = 1; i < n; i++){
        for (int j = 0; j < m; j++){
            if (adj[i][j] == 1){
                int temp = H[i-1][j] + 1;
                H.push_back(temp);
                maxArr[j] = max(maxArr[j], temp);
            } else { // == 0
                H.push_back(0);
            }
        }
    }

    return maxArr;
}

int LargestArea(vector<int> arr){
    arr.push_back(0);
    stack<int> st;
    int maxArea = -1;
    for (int i = 0; i < arr.size(); i++){
        if (st.empty() || arr[st.top()] <= arr[i]){
            st.push(i);
        } else {
            while (!st.empty() || arr[st.top()] > arr[i]){
                int index = st.top();
                st.pop();
                int area = 0;
                if (st.empty()){
                    area = arr[index] * i;
                } else {
                    area = arr[index] * (i-st.top()-1);
                }
                maxArea = max(area, maxArea);
            }
            st.push(i);
        }
    }
}


int main(){

}