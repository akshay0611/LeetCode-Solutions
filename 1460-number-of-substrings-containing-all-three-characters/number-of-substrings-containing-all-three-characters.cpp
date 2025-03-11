class Solution {
 public:
 
  int numberOfSubstrings(string s) {
    int ans = 0;
    vector<int> count(3);

    int l = 0;
    for (const char c : s) {
      ++count[c - 'a'];
      while (count[0] > 0 && count[1] > 0 && count[2] > 0)
        --count[s[l++] - 'a'];
      
      ans += l;
    }

    return ans;
  }
};