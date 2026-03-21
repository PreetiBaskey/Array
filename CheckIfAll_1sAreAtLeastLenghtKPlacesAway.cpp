//approach - 1
//time complexity - O(n)
//space complexity - O(1)
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();

        // Initialize with a value that ensures the first '1' found 
        // doesn't trigger the "too close" condition.
        int lastIndexOf1 = -(k + 1);

        for(int i = 0; i < n; i++) {
            // Check only when we encounter a '1'
            if(nums[i] == 1) {
                // Calculate distance between current index and last '1' found.
                // (i - lastIndexOf1 - 1) gives the number of zeros between them.
                if(i - lastIndexOf1 - 1 < k) {
                    return false; // Found two 1's with fewer than k zeros between them
                }
                // Update the last seen position of '1'
                lastIndexOf1 = i;
            }
        }

        // All 1's satisfy the k-distance requirement
        return true;
    }
};
