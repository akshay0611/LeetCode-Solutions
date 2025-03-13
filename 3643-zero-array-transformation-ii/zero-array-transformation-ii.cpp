#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int minZeroArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        int n = nums.size();
        std::vector<int> current = nums; 
        auto zerolithx = nums; 

        
        if (std::all_of(current.begin(), current.end(), [](int x) { return x == 0; })) {
            return 0;
        }

        
        auto canMakeZero = [&](int k) {
            std::vector<int> diff(n + 1, 0); 
            for (int i = 0; i < k; ++i) {
                int l = queries[i][0], r = queries[i][1], val = queries[i][2];
                diff[l] += val;
                if (r + 1 < n) diff[r + 1] -= val;
            }

            int total = 0;
            for (int i = 0; i < n; ++i) {
                total += diff[i];
                if (total < current[i]) return false; 
            }
            return true;
        };

        
        int left = 1, right = queries.size(), ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canMakeZero(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
