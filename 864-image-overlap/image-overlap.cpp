class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> ones1, ones2;

        int n = img1.size();

        // Store coordinates of 1s in img1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1)
                    ones1.push_back({i, j});
            }
        }

        // Store coordinates of 1s in img2
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img2[i][j] == 1)
                    ones2.push_back({i, j});
            }
        }

        map<pair<int, int>, int> count;

        int answer = 0;

        // Try every possible translation
        for (auto p1 : ones1) {
            for (auto p2 : ones2) {

                int dx = p2.first - p1.first;
                int dy = p2.second - p1.second;

                count[{dx, dy}]++;

                answer = max(answer, count[{dx, dy}]);
            }
        }

        return answer;
    }
};