class Solution {
public:
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n && nums[left] > nums[largest]) {
            largest = left;
        }

        if (right < n && nums[right] > nums[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        //build a max-heap 
        for (int i = n/2-1; i >= 0; i--) {
            heapify(nums, n, i);
        }

        //move the maximum to the end
        for (int i = n-1; i > 0; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }

        return nums;

        // priority_queue<int, vector<int>, greater<int>> min_heap;

        // //insert all the elements
        // for (int x : nums) {
        //     min_heap.push(x);
        // }

        // //extract elements in ascending order
        // for (int i = 0; i < nums.size(); i++) {
        //     nums[i] = min_heap.top();
        //     min_heap.pop();
        // } //specify the comparator when using min-heap

        // return nums;

    }
};