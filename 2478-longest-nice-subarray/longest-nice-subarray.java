class Solution {
    public int longestNiceSubarray(int[] nums) {
        int left=0;
        int used=0;
        int ans=0;
        for(int right=0;right<nums.length;right++){
            while((used & nums[right])!=0){
                used^=nums[left];
                left++;
            }
            used|=nums[right];
            ans=Math.max(ans,right-left+1);
        }
        return ans;
    }
}