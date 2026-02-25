import java.util.*;
import java.io.*;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		
		// System.setIn(new FileInputStream("input.txt"));

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T;
		T=Integer.parseInt(br.readLine());

		String answer = null;


		for(int test_case = 1; test_case <= T; test_case++)
		{
			int k = Integer.parseInt(br.readLine());
			String s = br.readLine();

			List<String> suffixes = new ArrayList<>();
            for (int i = 0; i < s.length(); i++) {
                suffixes.add(s.substring(i));
            }

            Collections.sort(suffixes);

            if (k <= suffixes.size()) {
                answer = suffixes.get(k - 1);
            }

			System.out.println("#"+test_case+" "+answer);
		}
	}
}