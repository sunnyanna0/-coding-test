import java.util.*;

class Solution {
    // 중복된 숫자를 방지하기 위해 Set 사용
    Set<Integer> numberSet = new HashSet<>();

    public int solution(String numbers) {
        int answer = 0;
        
        // 1. 모든 숫자 조합 만들기 (재귀)
        recursive("", numbers);

        // 2. 소수 개수 세기
        for (int num : numberSet) {
            if (isPrime(num)) answer++;
        }

        return answer;
    }

    // 모든 조합을 만드는 재귀 함수
    public void recursive(String comb, String others) {
        // 현재 조합이 비어있지 않으면 숫자로 변환해 Set에 추가
        if (!comb.equals("")) {
            numberSet.add(Integer.parseInt(comb));
        }

        // 남은 숫자들 중에서 하나씩 골라 조합을 이어감
        for (int i = 0; i < others.length(); i++) {
            recursive(comb + others.charAt(i), 
                      others.substring(0, i) + others.substring(i + 1));
        }
    }

    // 소수인지 판별하는 함수
    public boolean isPrime(int num) {
        if (num < 2) return false;
        // 제곱근까지만 확인하면 효율적
        for (int i = 2; i <= (int) Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
}