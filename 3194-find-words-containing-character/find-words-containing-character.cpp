class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int> ans;
        
        for(int i = 0;i < n;i++)
        {
            string temp = words[i];
            sort(temp.begin(),temp.end());
            int m = temp.length();

            for(int j = 0;j < m;j++)
            {
                if(temp[j] == x)
                {
                    ans.push_back(i);
                    break;
                }

                if(temp[j] > x)
                    break;
            }
        }

        return ans;
    }
};