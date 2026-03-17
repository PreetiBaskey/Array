//approach - 1
//time complexity - O(m * nlong)
//space complexity - O(n)
// class Solution {
// public:
//     int largestSubmatrix(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();

//         int maxArea = 0;

//         for(int row = 0; row < m; row++) {
//             for(int col = 0; col < n; col++) {
//                 if(matrix[row][col] == 1 && row > 0) {
//                     matrix[row][col] += matrix[row - 1][col];
//                 }
//             }

//             vector<int> heights = matrix[row];
//             sort(begin(heights), end(heights), greater<int>());

//             for(int i = 0; i < n; i++) {
//                 int base = (i + 1);
//                 int height = heights[i];

//                 maxArea = max(maxArea, base * height);
//             }
//         }

//         return maxArea;
//     }
// };





//approach - 2
//time complexity - O(m * nlogn)
//space complexity - O(n)
// class Solution {
// public:
//     int largestSubmatrix(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();

//         int maxArea = 0;
    
//         vector<int> prevRow(n, 0);
//         for(int row = 0; row < m; row++) {
//             vector<int> currRow = matrix[row];
//             for(int col = 0; col < n; col++) {
//                 if(currRow[col] == 1) {
//                     currRow[col] += prevRow[col];
//                 }
//             }

//             vector<int> heights = currRow;
//             sort(begin(heights), end(heights), greater<int>());

//             for(int i = 0; i < n; i++) {
//                 int base = (i + 1);
//                 int height = heights[i];

//                 maxArea = max(maxArea, base * height);
//             }

//             prevRow = currRow;
//         }

//         return maxArea;
//     }
// };




//approach - 3
//time complexity - O(m * n)
//space complexity - O(n)
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxArea = 0;

        vector<pair<int, int>> prevHeights; //height, col

        for(int row = 0; row < m; row++) {
            vector<pair<int, int>> currHeights;
            vector<bool> seen(n, false);

            for(auto [height, col] : prevHeights) {
                if(matrix[row][col] == 1) {
                    currHeights.push_back({height + 1, col});
                    seen[col] = true;
                }
            }

            for(int col = 0; col < n; col++) {
                if(seen[col] == false && matrix[row][col] == 1) {
                    currHeights.push_back({1, col});
                } 
            }

            for(int i = 0; i < currHeights.size(); i++) {
                int height = currHeights[i].first;
                int base = (i + 1); //width

                maxArea = max(maxArea, height * base);
            }

            prevHeights = currHeights;
        }

        return maxArea;
    }
};
