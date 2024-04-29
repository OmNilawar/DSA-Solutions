https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int finalXOR = 0;
        for(int i = 0;i < n;i++)
        {
            finalXOR = finalXOR ^ nums[i];
        }
        int count = 0;
        while(k || finalXOR)
        {
            if(k == finalXOR)
                return count;
                
            if((k&1) != (finalXOR&1))
                count++;

            k = k>>1;
            finalXOR = finalXOR>>1;
        }

        return count;
    }
};