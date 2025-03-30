class Solution {
 public:
  vector<int> partitionLabels(string s) {
    vector<int> ans;
    vector<int> rightmost(26);

    for (int i = 0; i < s.length(); ++i)
      rightmost[s[i] - 'a'] = i;

    int l = 0;  
    int r = 0;  

    for (int i = 0; i < s.length(); ++i) {
      r = max(r, rightmost[s[i] - 'a']);
      if (r == i) {
        ans.push_back(i - l + 1);
        l = i + 1;
      }
    }

    return ans;
  }
};