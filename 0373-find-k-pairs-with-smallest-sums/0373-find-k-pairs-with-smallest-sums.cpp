
class Solution {
public:
    vector<vector<int>> kSmallestPairs(
        vector<int>& nums1,
        vector<int>& nums2,
        int k
    ) {
        vector<vector<int>> ans;

        if (nums1.empty() || nums2.empty() || k == 0) {
            return ans;
        }

        // Store: {sum, index in nums1, index in nums2}
        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;

        // Insert the first pair from each eligible row
        int m = nums1.size();
        int n = nums2.size();

        for (int i = 0; i < min(k, m); i++) {
            pq.push({(long long)nums1[i] + nums2[0], i, 0});
        }

        // Extract the k smallest pairs
        while (k > 0 && !pq.empty()) {
            auto [sum, i, j] = pq.top();
            pq.pop();

            ans.push_back({nums1[i], nums2[j]});

            // Add the next pair from the same row
            if (j + 1 < n) {
                pq.push({
                    (long long)nums1[i] + nums2[j + 1],
                    i,
                    j + 1
                });
            }

            k--;
        }

        return ans;
    }
};





// class Solution {
// public:
//     vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//         vector<vector<int>> ans;

//         vector<pair<int, pair<int, int>>> allPairs;

//         for (int i = 0; i < nums1.size(); i++) {
//             for (int j = 0; j < nums2.size(); j++) {

//                 int sum = nums1[i] + nums2[j];

//                 allPairs.push_back({
//                     sum, 
//                     {nums1[i], nums2[j]}
//                 });
//             }
//         }

//         //sort the allPairs
//         sort(allPairs.begin(), allPairs.end());

//         for (int i = 0; i < k && i < allPairs.size(); i++) {
//             int a = allPairs[i].second.first;
//             int b = allPairs[i].second.second;

//             ans.push_back({a,b});
//         }

//         return ans;

        
//     }
// };