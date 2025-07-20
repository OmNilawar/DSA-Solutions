class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        unordered_map<int,int> mpp;

        for(int i = 0;i < n;i++)
        {
            mpp[numbers[i]] = i;
        }

        for(int i = 0;i < n;i++)
        {
            int diff = target - numbers[i];
            if(mpp.find(diff) != mpp.end() && mpp[diff] != i)
                return {i+1,mpp[diff]+1};
        }

        return {-1,-1};
    }
};