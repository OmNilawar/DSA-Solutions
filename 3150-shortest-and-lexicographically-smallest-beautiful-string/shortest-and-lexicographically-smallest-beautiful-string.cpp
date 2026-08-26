class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int i = 0;
        int j = 0;
        int count = 0;
        string ans = "";

        while(j < n)
        {
            if(s[j] == '1')
                count++;
            
            j++;

            while(count > k && i <= j)
            {
                if(s[i] == '1')
                    count--;
                i++;
            }

            if(count == k)
            {
                while(i <= j && s[i] == '0')
                    i++;

                string temp = s.substr(i, j-i);

                if(ans.empty() || temp.size() < ans.size() || (temp.size() == ans.size() && temp < ans))
                    ans = temp;
            }
        }

        return ans;
    }
};