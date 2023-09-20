class Solution {
public:
    int minOperations(vector<int>& nums, int targetSum) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int target = totalSum - targetSum; // Calculate the target sum difference

        if (target < 0)
            return -1; // Return -1 if target sum is not achievable

        if (target == 0)
            return nums.size(); // Return the number of elements if target sum is 0

        int n = nums.size(); // Number of elements in the vector
        int minOperations = INT_MAX; // Minimum operations to achieve the target sum
        int currentSum = 0; // Current sum of elements
        int leftIndex = 0, rightIndex = 0; // Pointers for the sliding window

        while (rightIndex < n) {
            currentSum += nums[rightIndex];
            rightIndex++;

            while (currentSum > target && leftIndex < n) {
                currentSum -= nums[leftIndex];
                leftIndex++;
            }

            if (currentSum == target)
                minOperations = min(minOperations, n - (rightIndex - leftIndex));
        }

        return (minOperations == INT_MAX) ? -1 : minOperations; // Return the minimum operations or -1 if not possible
    }
};