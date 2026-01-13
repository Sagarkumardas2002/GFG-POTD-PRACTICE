class Solution {
  public:
    bool canServe(vector<int> &arr) {
        int five = 0, ten = 0;

        for (int note : arr) {
            if (note == 5) {
                five++;
            }
            else if (note == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            }
            else { // note == 20
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }
                else if (five >= 3) {
                    five -= 3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
