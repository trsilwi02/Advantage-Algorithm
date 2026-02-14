class Task1
{
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
}