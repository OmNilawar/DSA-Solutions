//https://leetcode.com/problems/reveal-cards-in-increasing-order/description/
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n = deck.size();
        
        vector<int> ans(n);
        queue<int> indices;
        
        
        for (int i = 0; i < n; ++i)
            indices.push(i);
        
        for (int card : deck) {
            ans[indices.front()] = card;
            indices.pop();
            if (!indices.empty()) {
                indices.push(indices.front());
                indices.pop();
            }
        }
        
        return ans;
    }
};
