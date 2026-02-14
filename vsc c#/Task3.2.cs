class Solution
{
    public int Solution2(int[] nums)
    {
        int n = nums.Length;
        int count = 0;
        Array.Sort(nums);
        for (int i = 0; i < n; i++)
        {
            while (nums[i] < i + 1)
            {
                nums[i]++;
                count++;
            }
            while (nums[i] > i + 1)
            {
                nums[i]--;
                count++;
            }
        }
        return count;
    }
}