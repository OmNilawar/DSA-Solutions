class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        long long ans = 0;
        if(x < 0)
            return 0;
        while(x)
        {
            int bit = x%10;
            ans = ans*10 + bit;
            x = x/10;
        }
        return (ans == temp);
    }
};