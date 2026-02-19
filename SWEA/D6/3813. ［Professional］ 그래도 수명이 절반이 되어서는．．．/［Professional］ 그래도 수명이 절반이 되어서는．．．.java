import java.util.*;
import java.io.*;

class Solution {
    static int N, K;
    static int[] W;
    static int[] S;

    public static void main(String args[]) throws Exception {
        // System.setIn(new FileInputStream("sample_input.txt"));

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());

        for (int test_case = 1; test_case <= T; test_case++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());

            W = new int[N];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                W[i] = Integer.parseInt(st.nextToken());
            }

            S = new int[K];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < K; i++) {
                S[i] = Integer.parseInt(st.nextToken());
            }

            int low = 1;
            int high = 200000;
            int answer = high;

            while (low <= high) {
                int mid = (low + high) / 2;
                if (canPlace(mid)) {
                    answer = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            System.out.println("#" + test_case + " " + answer);
        }
    }

    // 최대 Wear Level이 limit 이하일 때 모든 덩어리를 배치할 수 있는지 확인
    static boolean canPlace(int limit) {
        int currentIdx = 0;

        for (int size : S) {
            int count = 0;
            boolean found = false;

            while (currentIdx < N) {
                if (W[currentIdx] <= limit) {
                    count++;
                } else {
                    count = 0;
                }

                if (count == size) {
                    currentIdx++;
                    found = true;
                    break;
                }
                currentIdx++;
            }

            if (!found) return false;
        }
        return true;
    }
}