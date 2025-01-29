class Solution {
public:
int first(vector<int> arr,int target)
    {
        int n = arr.size();
        int start = 0;
        int end = n-1;
        int ans = -1;
        int mid = start + (end - start)/2;
        while(start <= end)
        {
            if(arr[mid] == target)
            {
                ans =mid;
                end = mid - 1;
            }
            else if(arr[mid] < target)
            {
                start = mid + 1;
            }
            else if(arr[mid] > target)
            {
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return ans;
    }
    int last(vector<int> arr,int target)
    {
        int n = arr.size();
        int start = 0;
        int end = n-1;
        int ans = -1;
        int mid = start + (end - start)/2;
        while(start <= end)
        {
            if(arr[mid] == target)
            {
                ans = mid;
                start = mid + 1;
            }
            else if(arr[mid] < target)
            {
                start = mid + 1;
            }
            else if(arr[mid] > target)
            {
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int f = first(nums,target);
        int l = last(nums,target);
        ans.push_back(f);
        ans.push_back(l);
        return ans;
    }

    
};