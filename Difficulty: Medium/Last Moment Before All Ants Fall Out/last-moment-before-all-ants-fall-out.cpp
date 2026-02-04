class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int lastTime = 0;

        // Ants moving left: time = position
        for (int pos : left) {
            lastTime = max(lastTime, pos);
        }

        // Ants moving right: time = n - position
        for (int pos : right) {
            lastTime = max(lastTime, n - pos);
        }

        return lastTime;
    }
};
