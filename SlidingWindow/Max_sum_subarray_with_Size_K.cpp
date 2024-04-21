//https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        long long sum = 0;
        for(int i = 0;i < K;i++)
        {
            sum = sum + Arr[i];
        }
        long long ans = sum;
        for(int j = 1;j <= N-K;j++)
        {
            sum = sum - Arr[j-1] + Arr[j+K-1];
            ans = max(ans,sum);
        }
        
        return ans;
    }
};