class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        // Put all stones into max heap
        for (int stone : stones) {
            pq.push(stone);
        }

        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();

            int b = pq.top();
            pq.pop();

            // If weights are different, add the remaining stone
            if (a != b) {
                pq.push(a - b);
            }
        }

        // If no stones remain, return 0
        if (pq.empty()) {
            return 0;
        }

        return pq.top();
    }
};