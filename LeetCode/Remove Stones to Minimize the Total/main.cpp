class Solution {
   public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> heap(cbegin(piles), cend(piles));
        while (k--) {
            auto ele = heap.top();
            heap.pop();
            if (ele % 2 == 0)
                ele = ele / 2;
            else
                ele = (ele / 2) + 1;
            heap.push(ele);
        }
        int ans = 0;
        while (!heap.empty()) {
            ans += heap.top();
            heap.pop();
        }
        return ans;
    }
};