//approach - 1
//time complexity - O(n)
//space complexity - O(n)
// class Solution {
// public:
//     vector<int> getLeftMax(vector<int> &height, int &n) {
//         vector<int> leftMax(n);

//         leftMax[0] = height[0];
//         for(int i = 1; i < n; i++) {
//             leftMax[i] = max(leftMax[i - 1], height[i]);
//         }

//         return leftMax;
//     }
//     vector<int> getRightMax(vector<int> &height, int &n) {
//         vector<int> rightMax(n);

//         rightMax[n - 1] = height[n - 1];
//         for(int i = n - 2; i >= 0; i--) {
//             rightMax[i] = max(rightMax[i + 1], height[i]);
//         }

//         return rightMax;
//     }
//     int trap(vector<int>& height) {
//         int n = height.size();
//         int result = 0;

//         vector<int> leftMax = getLeftMax(height, n);
//         vector<int> rightMax = getRightMax(height, n);

//         for(int i = 0; i < n; i++) {
//             int h = min(leftMax[i], rightMax[i]) - height[i];

//             result += h;
//         }

//         return result;
//     }
// };





//approach - 2
//time complexity - O(n)
//space complexity - O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;

        int result = 0;
        while(left < right) {
            if(height[left] < height[right]) {
                if(height[left] >= leftMax) {
                    leftMax = height[left];
                }
                else {
                    result += leftMax - height[left];
                }
                left++;
            }
            else {
                if(height[right] >= rightMax) {
                    rightMax = height[right];
                }
                else {
                    result += rightMax - height[right];
                }
                right--;
            }
        }

        return result;
    }
};
