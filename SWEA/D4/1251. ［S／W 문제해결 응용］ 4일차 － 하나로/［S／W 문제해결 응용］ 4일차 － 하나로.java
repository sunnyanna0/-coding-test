import java.util.*;
import java.io.*;

public class Solution {
    static class Node implements Comparable<Node> {
        int id;
        long cost;

        Node(int id, long cost) {
            this.id = id;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node o) {
            return Long.compare(this.cost, o.cost);
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        for (int t = 1; t <= T; t++) {
            int N = sc.nextInt();
            long[] x = new long[N];
            long[] y = new long[N];

            for (int i = 0; i < N; i++) x[i] = sc.nextLong();
            for (int i = 0; i < N; i++) y[i] = sc.nextLong();
            double E = sc.nextDouble();

            long[] minEdge = new long[N];
            Arrays.fill(minEdge, Long.MAX_VALUE);
            boolean[] visited = new boolean[N];
            
            PriorityQueue<Node> pq = new PriorityQueue<>();
            pq.add(new Node(0, 0));
            minEdge[0] = 0;

            long totalLSquare = 0;
            int count = 0;

            while (!pq.isEmpty()) {
                Node current = pq.poll();

                if (visited[current.id]) continue;

                visited[current.id] = true;
                totalLSquare += current.cost;
                if (++count == N) break;

                for (int next = 0; next < N; next++) {
                    if (!visited[next]) {
                        long distSq = (x[current.id] - x[next]) * (x[current.id] - x[next]) +
                                      (y[current.id] - y[next]) * (y[current.id] - y[next]);
                        
                        if (distSq < minEdge[next]) {
                            minEdge[next] = distSq;
                            pq.add(new Node(next, distSq));
                        }
                    }
                }
            }

            long result = Math.round(totalLSquare * E);
            System.out.println("#" + t + " " + result);
        }
    }
}