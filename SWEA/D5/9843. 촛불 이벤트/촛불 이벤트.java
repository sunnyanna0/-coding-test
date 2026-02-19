import java.util.*;
import java.io.*;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		// System.setIn(new FileInputStream("sample_input.txt"));

		BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
		int T;
		T=Integer.parseInt(sc.readLine());

		for(int test_case = 1; test_case <= T; test_case++)
		{
			// 이 양초를 모두 사용하면 몇 단 크기의 촛불 삼각형을 만들 수 있는지 구하여라.
			long N;
			N=Long.parseLong(sc.readLine());

			long k = N/2;

			long left = 0, right = 2000000000L;
			long answer = -1;
			while(left <= right) {
				k = (right + left) / 2;
				if(k*(k+1)/2 == N){
					answer = k;
					break;
				}

				else if (k*(k+1)/2 < N) {
					left = k+1;
				}
				else if (k*(k+1)/2 > N) {
					right = k-1;
				}
			}
			System.out.println("#" + test_case + " " + answer);
		}
	}
}