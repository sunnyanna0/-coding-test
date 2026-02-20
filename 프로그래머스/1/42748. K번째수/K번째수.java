import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        for(int i =0 ; i<commands.length ; i++){
            // array의 2번째부터 5번째까지 자르면 [5, 2, 6, 3]입니다.
            int[] tempArray = Arrays.copyOfRange(array, commands[i][0]-1, commands[i][1]);

            // 1에서 나온 배열을 정렬하면 [2, 3, 5, 6]입니다.
            Arrays.sort(tempArray);

            // 2에서 나온 배열의 3번째 숫자는 5입니다.
            answer[i] = tempArray[commands[i][2] - 1];

        }
        return answer;
    }
}