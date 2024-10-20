
class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        vector<int> res;
        int left = 0;
        int right = v.size() - 1;

        while (left < right) {
            int sum = v[left] + v[right];

            if (sum == target) {
                left++;
                right++;
                res.push_back(left);
                res.push_back(right);
                return res;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        
        return res;
    }
};
