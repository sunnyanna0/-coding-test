import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[][] board;
    static long[][][] dp; // 파이프 옮기기 2는 long 필수

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        board = new int[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dp = new long[n][n][3];

        if (board[0][1] == 0) dp[0][1][0] = 1;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 1) continue; // 벽

                if (c - 1 >= 0 && board[r][c - 1] == 0) {
                    dp[r][c][0] += dp[r][c - 1][0] + dp[r][c - 1][2];
                }

                if (r - 1 >= 0 && board[r - 1][c] == 0) {
                    dp[r][c][1] += dp[r - 1][c][1] + dp[r - 1][c][2];
                }

                if (r - 1 >= 0 && c - 1 >= 0) {
                    if (board[r - 1][c] == 0 && board[r][c - 1] == 0) {
                        dp[r][c][2] += dp[r - 1][c - 1][0]
                                    + dp[r - 1][c - 1][1]
                                    + dp[r - 1][c - 1][2];
                    }
                }
            }
        }

        long ans = dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
        System.out.println(ans);
    }
}
