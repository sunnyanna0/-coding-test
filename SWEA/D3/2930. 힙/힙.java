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

		for(int test_case = 1; test_case <= T; test_case++)
		{
			int N;
			N=Integer.parseInt(br.readLine());
			PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

			StringBuilder sb = new StringBuilder();
			sb.append("#").append(test_case).append(" ");

			for(int i = 0 ; i<N ; i++){
				// int calculation = Integer.parseInt(br.readLine());
				StringTokenizer st = new StringTokenizer(br.readLine());
    			int calculation = Integer.parseInt(st.nextToken());

				if(calculation == 1){
					int num = Integer.parseInt(st.nextToken());
					maxHeap.add(num);
				}
				else if(calculation == 2){
					if(maxHeap.isEmpty()){
						sb.append(-1).append(" ");
					} else {
						sb.append(maxHeap.poll()).append(" ");
					}
				}
			}
			System.out.println(sb);
		}
	}
}