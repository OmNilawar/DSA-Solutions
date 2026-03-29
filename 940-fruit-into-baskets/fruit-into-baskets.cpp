class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans = 0;
        unordered_map<int,int> mpp;

        int l = 0;
        int r = 0;

        while(r < n)
        {
            mpp[fruits[r]]++;

            while(mpp.size() > 2 && l < r)
            {
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0)
                    mpp.erase(fruits[l]);
                l++;
            }

            ans = max(r-l+1, ans);
            r++;
        }

        return ans;
    }
};