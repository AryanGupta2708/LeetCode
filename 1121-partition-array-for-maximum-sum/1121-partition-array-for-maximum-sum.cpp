class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int m = 0;
        std::array<int, 501> arrMaxSum{0};
        for (int i = 0; i < k; ++i)
        {
            m = (arr[i] > m) ? arr[i] : m;
            arrMaxSum[i] = m * (i + 1);
        }
        int n = arr.size();
        int maxSub = 0;
        int maxTempSum = 0;
        for (int i = k; i < n; ++i)
        {
            maxSub = arr[i];
            maxTempSum = 0;
            for (int j = 0; j < k; ++j)
            {
                maxSub = (arr[i - j] > maxSub) ? arr[i - j] : maxSub;
                maxTempSum = arrMaxSum[i - j - 1] + maxSub * (j + 1);
                arrMaxSum[i] = (maxTempSum > arrMaxSum[i]) ? maxTempSum : arrMaxSum[i];
            }
        }
        return arrMaxSum[n - 1];
    }
}; 