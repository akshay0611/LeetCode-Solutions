class Solution {
 public:
  long long putMarbles(vector<int>& weights, int k) {
   
    vector<int> arr;  
    long mn = 0;
    long mx = 0;

    for (int i = 0; i + 1 < weights.size(); ++i)
      arr.push_back(weights[i] + weights[i + 1]);

    ranges::sort(arr);

    for (int i = 0; i < k - 1; ++i) {
      mn += arr[i];
      mx += arr[arr.size() - 1 - i];
    }

    return mx - mn;
  }
};