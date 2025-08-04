class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0;
        int r = 0;
        unordered_map<int,int> mpp;
        int maxLen = 0;

        while(r < n)
        {
            mpp[fruits[r]]++;

            while(l < r && mpp.size() > 2)
            {
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0)
                    mpp.erase(fruits[l]);
                l++;
            }

            maxLen = max(maxLen,r-l+1);
            r++;
        }

        return maxLen;
    }
};