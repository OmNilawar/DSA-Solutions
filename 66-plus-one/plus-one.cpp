class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        reverse(digits.begin(), digits.end());
        
        for(int i = 0;i < n;i++)
        {
            if(digits[i] < 9)
            {
                digits[i]++;
                break;
            }
            else
            {
                digits[i] = 0;
            }
        }
        if(digits[n-1] == 0)
            digits.push_back(1);

        reverse(digits.begin(),digits.end());

        return digits;
    }
};