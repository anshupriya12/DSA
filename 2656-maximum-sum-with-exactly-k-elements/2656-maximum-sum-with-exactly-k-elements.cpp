class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        //i will use max-heap

        priority_queue<int> heap;

        //push all the elements into heap
        for (int x: nums) {
            heap.push(x);
        }

        int sum = 0;
        for (int i = 0; i < k; i++) {
            int m = heap.top();
            heap.pop();

            sum += m;

            heap.push(m+1);
        }

        return sum;
    }
};