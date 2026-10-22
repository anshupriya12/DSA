class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> heap;

        //push all the elements into heap
        for (int i = 0; i < piles.size(); i++) {
            heap.push(piles[i]);
        }

        //extract largest element
        for (int i = 0; i < k; i++) {
            int x = heap.top();
            heap.pop();

            int m = x/2;

            x = x - m;

            heap.push(x);           
        }

        int sum = 0;
        while (!heap.empty()) {
            sum = sum + heap.top();
            heap.pop();
        }

        return sum;
    }
};