class Solution {

    public int maxSubarraySumCircular(int[] nums) {

        int total = 0;

        int currentMax = 0;
        int maxSum = Integer.MIN_VALUE;

        int currentMin = 0;
        int minSum = Integer.MAX_VALUE;

        for (int num : nums) {

            total += num;

            currentMax += num;
            maxSum = Math.max(maxSum, currentMax);

            if (currentMax < 0)
                currentMax = 0;


            currentMin += num;
            minSum = Math.min(minSum, currentMin);

            if (currentMin > 0)
                currentMin = 0;
        }

        if (maxSum < 0)
            return maxSum;

      
        return Math.max(maxSum, total - minSum);
    }
}