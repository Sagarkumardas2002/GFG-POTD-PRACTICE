class Solution {
public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        int n = men.size();

        vector<int> womanPartner(n, -1); // which man is assigned to woman
        vector<int> manPartner(n, -1);   // which woman is assigned to man
        vector<int> nextProposal(n, 0);  // next woman to propose for each man

        // ranking[w][m] = preference rank of man m for woman w
        vector<vector<int>> ranking(n, vector<int>(n));

        // Precompute ranking
        for (int w = 0; w < n; w++) {
            for (int i = 0; i < n; i++) {
                ranking[w][women[w][i]] = i;
            }
        }

        queue<int> freeMen;

        // Initially all men are free
        for (int i = 0; i < n; i++) {
            freeMen.push(i);
        }

        while (!freeMen.empty()) {
            int man = freeMen.front();
            freeMen.pop();

            int woman = men[man][nextProposal[man]];
            nextProposal[man]++;

            // If woman is free
            if (womanPartner[woman] == -1) {
                womanPartner[woman] = man;
                manPartner[man] = woman;
            }
            else {
                int currentMan = womanPartner[woman];

                // Check if woman prefers new man
                if (ranking[woman][man] < ranking[woman][currentMan]) {
                    // She prefers new man
                    womanPartner[woman] = man;
                    manPartner[man] = woman;

                    // old man becomes free
                    manPartner[currentMan] = -1;
                    freeMen.push(currentMan);
                }
                else {
                    // She rejects new man
                    freeMen.push(man);
                }
            }
        }

        return manPartner;
    }
};