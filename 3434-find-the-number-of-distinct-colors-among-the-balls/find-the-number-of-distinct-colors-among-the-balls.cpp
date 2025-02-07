class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball, color;
        vector<int> ans;
        ans.reserve(queries.size());
        int distinct = 0;

        for (const auto& q : queries) {
            int pos = q[0], c = q[1];

            if (ball.find(pos) != ball.end()) {
                int old_color = ball[pos];
                color[old_color]--;
                if (color[old_color] == 0) {
                    distinct--;
                }
            }

            ball[pos] = c;

            if (color[c] == 0) {
                distinct++;
            }
            color[c]++;

            ans.push_back(distinct);
        }

        return ans;
    }
};
