
import java.util.*;
import java.io.*;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		// System.setIn(new FileInputStream("sample_input.txt"));

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T;
		T=Integer.parseInt(br.readLine());

		for(int test_case = 1; test_case <= T; test_case++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());

			// HashMap<Integer, Integer> graph = new HashMap<>();
			HashSet<String> set = new HashSet<>();

			st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                set.add(st.nextToken());
            }
			int answer = 0;
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < M; i++) {
				if (set.contains(st.nextToken())) {
					answer++;
				}
			}
			System.out.println("#" + test_case + " " + answer);
		}
	}
}