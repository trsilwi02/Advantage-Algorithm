public class Task1 {

    private static string RemoveElement(string st)
    {
        int index = st.Length - 1;
        for (int i = 0; i < st.Length - 1; i++)
        {
            if (st[i] > st[i + 1] || i == st.Length - 1)
            {
                index = i;
                break;
            }
        }

        return st.Remove(index, 1);
    }
    public static void Main(string[] args)
    {
        string st = Console.ReadLine();
        Console.WriteLine(RemoveElement(st));
    }

    //public static int Solution(int[] nums)
    //{
    //    int n = nums.Length;
    //    int count = 0;
    //    Array.Sort(nums);
    //    for (int i = 1; i < n; i++)
    //    {
    //        while (nums[i - 1] == nums[i])
    //        {
    //            nums[i]++;
    //            count++;
    //        }
    //    }
    //    Console.WriteLine(count);
    //    return count;
    //}
    //public static void main(string[] args)
    //{
    //    int[] arr = { 1, 2, 1 };
    //    int a = Solution(arr);

    //}
}
