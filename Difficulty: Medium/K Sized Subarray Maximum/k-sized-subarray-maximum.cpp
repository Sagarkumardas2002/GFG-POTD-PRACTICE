class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> result;
        
        priority_queue<pair<int,int>> pq; // {value, index}

        for (int i = 0; i < n; i++) {
            // Push current element
            pq.push({arr[i], i});

            // Remove elements outside window
            while (!pq.empty() && pq.top().second <= i - k) {
                pq.pop();
            }

            // Window formed
            if (i >= k - 1) {
                result.push_back(pq.top().first);
            }
        }

        return result;
    }
};
