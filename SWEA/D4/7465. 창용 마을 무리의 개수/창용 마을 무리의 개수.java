// union find
// 루트가 같은 애들끼리가 그룹임.
// 일반 트리와 달리 이것도 트리긴 한데 부모 -> 자식이 아니라 자식 -> 부모로 찾음.
// 재귀로 부모 타고 올라가서 루트 같은 지 확인하면 됨
// 대신 순환구조랑 루트가 자기 자신인 거 생각해서 재귀로 타고 올라가다가 자기 자신이 루트면 멈추고 그 루트 값을 리턴하도록.

import java.util.*;
import java.io.*;

class Solution
{
	static int find(int[] tree, int a){
		if (tree[a] == a) return a;
		return tree[a] = find(tree, tree[a]); // 이게 경로 압축이라고 불림.
	}

	static void union(int[] tree, int a, int b){
		int rootA = find(tree, a);
		int rootB = find(tree, b);
		if (rootA != rootB){
			tree[rootB] = rootA; // b의 루트를 a의 루트에 연결
		}
	}

	public static void main(String args[]) throws Exception
	{
		// System.setIn(new FileInputStream("input.txt"));

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T;
		T=Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
			// 입력
			int answer = 0;
			int N;
			int M;
			String line = br.readLine();
			String[] parts = line.split(" ");
			N = Integer.parseInt(parts[0]);
			M = Integer.parseInt(parts[1]);
			int[] tree = new int[N + 1]; // 1-indexed이므로 N+1 크기
			// 초기화: 자기 자신이 루트
			for (int i = 1; i <= N; i++){
				tree[i] = i;
			}
			for (int i = 0 ; i<M ; i++){
				line = br.readLine();
				parts = line.split(" ");
				int a = Integer.parseInt(parts[0]);
				int b = Integer.parseInt(parts[1]);
				union(tree, a, b); // 왜 여기서 union을 하나? 그냥 tree[b] = a; 하면 안되나? -> 순환 해결. (1,2,5에서 2-5연결이 1을 통해서 이루어지므로 연결안해서 순환이 안생김)
			}

			// 루트가 자기 자신인 노드 수 = 그룹 수
			for (int i = 1 ; i <= N ; i++){
				if (find(tree, i) == i){
					answer ++;
				}
			}
			
			System.out.println("#" + test_case + " " + answer);
		}
	}
}