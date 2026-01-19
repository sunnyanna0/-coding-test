import java.util.*;
import java.io.*;

class Main {
    static int answerCount = 0; // 경로의 수를 저장할 전역 변수
    static int n;
    static int[][] board;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        board = new int[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // 초기 상태: (0,0)과 (0,1)에서 시작
        dfs(0, 0, 0, 1);

        System.out.println(answerCount);
    }

    public static void dfs(int xS, int yS, int xE, int yE) {
        // 머리가 목적지(n-1, n-1)에 도달하면 카운트 증가 후 종료
        if (xE == n - 1 && yE == n - 1) {
            answerCount++;
            return;
        }

        // 1. 가로 상태 (xStart == xEnd)
        if (xS == xE) {
            // 오른쪽 이동
            if (yE + 1 < n && board[xE][yE + 1] == 0) {
                dfs(xE, yE, xE, yE + 1);
            }
            // 대각선 이동
            if (xE + 1 < n && yE + 1 < n && 
                board[xE + 1][yE + 1] == 0 && board[xE][yE + 1] == 0 && board[xE + 1][yE] == 0) {
                dfs(xE, yE, xE + 1, yE + 1);
            }
        } 
        // 2. 세로 상태 (yStart == yEnd)
        else if (yS == yE) {
            // 아래쪽 이동
            if (xE + 1 < n && board[xE + 1][yE] == 0) {
                dfs(xE, yE, xE + 1, yE);
            }
            // 대각선 이동
            if (xE + 1 < n && yE + 1 < n && 
                board[xE + 1][yE + 1] == 0 && board[xE][yE + 1] == 0 && board[xE + 1][yE] == 0) {
                dfs(xE, yE, xE + 1, yE + 1);
            }
        } 
        // 3. 대각선 상태
        else {
            // 오른쪽 이동
            if (yE + 1 < n && board[xE][yE + 1] == 0) {
                dfs(xE, yE, xE, yE + 1);
            }
            // 아래쪽 이동
            if (xE + 1 < n && board[xE + 1][yE] == 0) {
                dfs(xE, yE, xE + 1, yE);
            }
            // 대각선 이동
            if (xE + 1 < n && yE + 1 < n && 
                board[xE + 1][yE + 1] == 0 && board[xE][yE + 1] == 0 && board[xE + 1][yE] == 0) {
                dfs(xE, yE, xE + 1, yE + 1);
            }
        }
    }
}