class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        int a, b;
        for(int i=yellow ; i>=1 ; i--){
            if(yellow%i==0){
                a=i;
                b=yellow/i;
                
                if(2*a + 2*b +4 ==brown){
                    answer[0] = a + 2;
                    answer[1] = b + 2;
                    return answer;
                }
            }
        }
        return answer;
    }
}