//https://leetcode.com/problems/subsets/description/

class Solution {
public:
void solve(vector<int> arr,int n,vector<int> temp,vector<vector<int>>& ans)
{
    if(n >= arr.size())
    {
        ans.push_back(temp);
        return ;
    }
    // exclude a element
    solve(arr,n+1,temp,ans);

    //include a element

    int element = arr[n];
    temp.push_back(element);
    solve(arr,n+1,temp,ans);

}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = 0;

        solve(nums,n,temp,ans);

        return ans;
    }
};