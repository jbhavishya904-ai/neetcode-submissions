class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<int> price(n, INT_MAX);
        price[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> temp = price;

            for (auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int cost = flight[2];

                if (price[u] != INT_MAX &&
                    price[u] + cost < temp[v]) {
                    temp[v] = price[u] + cost;
                }
            }

            price = temp;
        }

        return price[dst] == INT_MAX ? -1 : price[dst];
    }
};