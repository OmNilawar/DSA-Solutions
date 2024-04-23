 int longestSubarrayWithSumK(vector<int> arr, long long k) {
    // Write your code here
    int n = arr.size();
   int ans = 0;
   int i = 0;
   int j = 0;
   int sum = 0;

   while(j < n)
   {
       sum = sum + arr[j];

       if(i <= j && sum > k)
       {
           sum = sum - arr[i];
           i++;
       }

        if(sum == k)
        {
            ans = max(ans,j-i+1);
        }
        j++;
   }
   
   return ans;
}