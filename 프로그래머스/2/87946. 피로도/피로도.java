class Solution {
    int answer = 0;
    public int solution(int k, int[][] dungeons) { // 현재 피로도, [최소 필요 피로도][소모 피로도]
        // int array[][] = new int[k+1][dungeons.length + 1];
        // array[남은피로도][방문한던전수] = [들린 던전 id 들] 을 생각했으나, 이건 메모리 너무 많이 씀. -> 차라리 비트마스킹
        // 그리고 지금 방식은: 똑같은 피로도와 방문 횟수라도, 들린 던전의 조합은 여러 개가 될 수 있으므로 논리적으로 틀림 -> dfs 써야함

        int[] vis = new int[dungeons.length];

        dfs(k, dungeons, vis, 0);

        return answer;
    }

    void dfs(int k, int[][] dungeons, int[] vis, int count){
        answer = Math.max(count, answer);

        for(int i=0 ; i<dungeons.length ; i++){
            if(vis[i]==0 && k>= dungeons[i][0]){
                vis[i]=1;
                dfs(k-dungeons[i][1], dungeons, vis, count+1); // 재귀
                vis[i]=0; // 중요! 다른 경우의 수를 위해 방문 처리 취소 (백트래킹)... 이거시 백트래킹
            }
        }
    }
}