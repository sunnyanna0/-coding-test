#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int n = (int)sequence.size();
    int left = 0;
    long long sum = 0;
    int bestL = 0, bestR = n - 1;
    int bestLen = n + 1;

    for (int right = 0; right < n; ++right) {
        sum += sequence[right];

        while (left <= right && sum > k) { // right=left에서부터 다시 해봤자 이미 sum보다 작은데 더 작아지게 할 필요 없음.
            sum -= sequence[left++];
        }

        if (sum == k) {
            int curLen = right - left + 1;
            if (curLen < bestLen || (curLen == bestLen && left < bestL)) {
                bestLen = curLen;
                bestL = left;
                bestR = right;
            }
        }
    }
    return {bestL, bestR};
}