import java.util.*;
import java.io.*;

class Solution {
    private static final int INF = 1_000_000_000;
    private static final int[] dx = {-1, 1, 0, 0};
    private static final int[] dy = {0, 0, -1, 1};

    public static void main(String args[]) throws Exception {
        
        // System.setIn(new FileInputStream("input.txt"));

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for (int test_case = 1; test_case <= T; test_case++) {
            int N = Integer.parseInt(br.readLine());
            int[][] board = new int[N][N];

            for (int i = 0; i < N; i++) {
                String line = br.readLine();
                for (int j = 0; j < N; j++) {
                    board[i][j] = line.charAt(j) - '0';
                }
            }

            int[][] dist = new int[N][N];
            for (int i = 0; i < N; i++) Arrays.fill(dist[i], INF);
            dist[0][0] = 0;

            // [x, y, 누적비용] 비용 오름차순으로  우선순위 큐
            PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[2]));
            pq.add(new int[]{0, 0, 0});

            while (!pq.isEmpty()) {
                int[] cur = pq.poll();
                int x = cur[0];
                int y = cur[1];
                int cost = cur[2];

                // 이미 더 좋은 경로가 확정된 상태면 무시
                if (cost != dist[x][y]) continue;

                if (x == N - 1 && y == N - 1) break;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    int ncost = cost + board[nx][ny];
                    if (ncost < dist[nx][ny]) {
                        dist[nx][ny] = ncost;
                        pq.add(new int[]{nx, ny, ncost});
                    }
                }
            }

            System.out.println("#" + test_case + " " + dist[N - 1][N - 1]);
        }
    }
}
