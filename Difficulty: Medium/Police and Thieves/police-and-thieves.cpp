class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        vector<int> police, thieves;

        // Store positions
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 'P') police.push_back(i);
            else thieves.push_back(i);
        }

        int i = 0, j = 0, caught = 0;

        // Two pointer matching
        while (i < police.size() && j < thieves.size()) {
            if (abs(police[i] - thieves[j]) <= k) {
                caught++;   // Match found
                i++;
                j++;
            } 
            else if (police[i] < thieves[j]) {
                i++;        // Police too far left
            } 
            else {
                j++;        // Thief too far left
            }
        }

        return caught;
    }
};
