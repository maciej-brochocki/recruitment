using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Codility
{
    class Program
    {
        // you can write to stdout for debugging purposes, e.g.
        // Console.WriteLine("this is a debug message");

/*        public int solution(int[] A) {
            long sum=0;
            long[] sums;
            sums = new long[A.Length];
            // write your code in C# 6.0 with .NET 4.5 (Mono)
            for (int i = 0; i < A.Length; i++)
            {
                sum += A[i];
                sums[i] = sum;
            }
            if (sum == 0)
            {
                return 0;
            }
            for (int i = 0; i < A.Length; i++)
            {
                if (sums[i] == sum - sums[i])
                {
                    return i + 1;
                }
            }

            return -1;
        }*/

/*        public int solution(int A, int B)
        {
            // write your code in C# 6.0 with .NET 4.5 (Mono)
            string s1 = B.ToString();
            string s2 = A.ToString();
            return s1.IndexOf(s2);
        }*/

        public int solution(int[] A, int[] B, int M, int X, int Y)
        {
            // write your code in C# 6.0 with .NET 4.5 (Mono)
            int N = A.Length;
            int stops = 0;
            int personNum = 0;
            int weightSum = 0;
            Dictionary<int, int> floors = new Dictionary<int,int>();

            for (int i = 0; i < N; i++)
            {
                if ((personNum + 1 <= X) && (weightSum + A[i] <= Y))
                {
                }
                else
                {
                    //need to go
                    stops = stops + floors.Count + 1 /*back to ground */;
                    personNum = 0;
                    weightSum = 0;
                    floors.Clear();
                }

                //hop in
                personNum++;
                weightSum += A[i];
                int value;
                if (floors.TryGetValue(B[i], out value))
                {
                    floors[B[i]] = value + 1;
                }
                else
                {
                    floors[B[i]] = 1;
                }

                if (i == N - 1)
                {
                    //force last go
                    stops = stops + floors.Count + 1 /*back to ground */;
                    personNum = 0;
                    weightSum = 0;
                    floors.Clear();
                }
            }

            return stops;
        }

        static void Main(string[] args)
        {
            Program p = new Program();
/*            int[] test;
            test = new int[4];
            test[0]=9;test[1]=1;test[2]=1;test[3]=3;
            int res = p.solution(test);*/
//            int res = p.solution(53, 1953786);
            int[] A = new int[3]; A[0]=60; A[1]=80; A[2]=40;
            int[] B = new int[3]; B[0]=2; B[1]=3; B[2]=5;
            int res = p.solution(A, B, 5, 2, 200);
            Console.WriteLine(res);
        }
    }
}
