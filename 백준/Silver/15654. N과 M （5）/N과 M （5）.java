import java.util.*;
import java.io.*;

class Main {
    static int[] visited;
    static int[] num;
    static int[] result;
    static int N, M;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        visited = new int[N];
        num = new int[N];
        result = new int[M];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            num[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(num);

        pick(0);
        System.out.print(sb);
    }

    static void pick(int count) {
        if (count == M) {
            printer();
            return;
        }

        for (int i = 0; i < N; i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                result[count] = num[i];
                pick(count + 1);
                visited[i] = 0;
            }
        }
    }

    static void printer() {
        for (int i = 0; i < M; i++) {
            System.out.print(result[i] + " ");
        }
        System.out.println();
    }
}