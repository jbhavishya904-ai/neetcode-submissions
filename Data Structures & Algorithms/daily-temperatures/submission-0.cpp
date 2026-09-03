class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st;   // stores indices

        for (int i = 0; i < n; i++) {

            // Current temperature is warmer
            // than the temperature at stack top
            while (!st.empty() &&
                   temperatures[i] > temperatures[st.top()]) {

                int prev = st.top();
                st.pop();

                result[prev] = i - prev;
            }

            st.push(i);
        }

        return result;
    }
};