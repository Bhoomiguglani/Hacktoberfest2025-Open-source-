#include <iostream>
#include <vector>
using namespace std;

int maxSumSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1;

    int max_sum = 0, window_sum = 0;
    for (int i = 0; i < k; i++) window_sum += arr[i];
    max_sum = window_sum;

    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];
        if (window_sum > max_sum) max_sum = window_sum;
    }

    return max_sum;
}

int main() {
    int n, k;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter window size k: ";
    cin >> k;

    int result = maxSumSubarray(arr, k);
    if (result != -1)
        cout << "Maximum sum of subarray of size " << k << " is: " << result << endl;
    else
        cout << "Window size is larger than array size!" << endl;

    return 0;
}
