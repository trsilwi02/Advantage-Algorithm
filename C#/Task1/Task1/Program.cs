public class Program
{

    //public static int Solution(int[] nums)
    //{
    //    int n = nums.Length;
    //    int count = 0;
    //    Array.Sort(nums);
    //    for (int i= 1; i < n; i++)
    //    {
    //        while (nums[i-1] == nums[i])
    //        {
    //            nums[i]++;
    //            count++;
    //        }
    //    }
        //for (int i = 0; i<n; i++)
        //{
        //    Console.Write(nums[i] + " ");
        //}
//    return count;
//}

public static int Solution2(int[] nums)
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
        for (int i = 0; i < n; i++)
        {
            Console.Write(nums[i] + " ");
        }
        Console.WriteLine(count);
        return count;
    }
    public static void Main(string[] args)
    {
        int[] arr = { 6, 2 ,3, 5 ,6, 3};
        int a = Solution2(arr);

    }
}
