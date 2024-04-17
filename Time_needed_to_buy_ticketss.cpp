//https://leetcode.com/problems/time-needed-to-buy-tickets/description/
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int sum = 0;
        for(int i = 0;i < n;i++)
        {
            if(i <= k)
            {
                if(tickets[i] < tickets[k])
                    sum = sum + tickets[i];
                else
                    sum = sum + tickets[k];
            }
            else
            {
                if(tickets[i] < tickets[k])
                    sum = sum + tickets[i];
                else
                    sum = sum + tickets[k] - 1;
            }
        }
        
        return sum;
    }
};