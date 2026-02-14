class Solution
{
    public int solution(int[][] A)
    {
        int max = 0;
        for (int i1 = 0; i1 < A.Length; i1++)
        {
            for (int j1 = 0; j1 < A[i1].Length; j1++)
            {
                for (int i2 = 0; i2 < A.Length; i2++)
                {
                    for (int j2 = 0; j2 < A[i2].Length; j2++)
                    {
                        if (i1 != i2 && j1 != j2 && max < A[i1][j1] + A[i2][j2])
                        {
                            max = A[i1][j1] + A[i2][j2];
                        }
                    }
                }
            }
        }
        return max;
    }
}