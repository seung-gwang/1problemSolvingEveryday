#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int as = -1;
    int ae = -1; 
    
    int s = 0;
    int e = 0;
    
    int sum = sequence[0];
    while(s <= e && s < sequence.size() && e < sequence.size()) {
        if(sum < k) {
            sum += sequence[++e];
        }
        else if (sum > k) {
            sum -= sequence[s++];
        }
        else { //sum == k
            if(as == -1 && ae == -1) {
                as = s;
                ae = e;
            }
            else if(ae - as > e - s) { //길이가 짧은 것
                ae = e;
                as = s;
            }
            else if(ae - as == e - s && s < as) {//같은 길이면 앞쪽 인덱스가 앞서는것
                ae = e;
                as = s;
            } 
            sum -= sequence[s++];
            sum += sequence[++e];
        }
    }
    
    
    return {as, ae};
}