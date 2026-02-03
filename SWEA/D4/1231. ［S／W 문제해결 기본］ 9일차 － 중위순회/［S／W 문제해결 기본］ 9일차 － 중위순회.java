import java.util.*;
import java.io.*;

class Solution
{
    public static void main(String args[]) throws Exception
    {
        // System.setIn(new FileInputStream("input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for(int test_case = 1; test_case <= 10; test_case++)
        {
            String lineN = br.readLine();
            if (lineN == null) break;
            int N = Integer.parseInt(lineN.trim());

            // tree[node][0]은 왼쪽 자식, tree[node][1]은 오른쪽 자식 저장
            int[][] tree = new int[N + 1][2];
            char[] valueArr = new char[N + 1];

            // 초기화
            for(int i=0; i<=N; i++) {
                tree[i][0] = -1; 
                tree[i][1] = -1;
            }
            for (int i = 0; i < N; i++) {
                String line = br.readLine(); // 입력받아야 하는 거: 1 W 2 3(노드인덱스, 노드값, 왼쪽자식, 오른쪽자식)
                String[] parts = line.split(" ");

                int nodeIdx = Integer.parseInt(parts[0]);
                valueArr[nodeIdx] = parts[1].charAt(0);

                if (parts.length >= 3) {
                    tree[nodeIdx][0] = Integer.parseInt(parts[2]);
                }
                if (parts.length >= 4) {
                    tree[nodeIdx][1] = Integer.parseInt(parts[3]);
                }
            }

            // 중위순회. 1을 루트로.
            StringBuilder sb = new StringBuilder();
            inorder(1, tree, valueArr, sb);
            System.out.println("#" + test_case + " " + sb.toString());
        }
        // br은 별도로 close 하지 않아도 채점에 지장이 없습니다.
    }
    
    static void inorder(int node, int[][] tree, char[] valueArr, StringBuilder sb) {
        if (node == -1) return;
        
        inorder(tree[node][0], tree, valueArr, sb);
        sb.append(valueArr[node]);
        inorder(tree[node][1], tree, valueArr, sb);
    }
}