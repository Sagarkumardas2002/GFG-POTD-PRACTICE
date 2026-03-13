class Solution {
public:

    bool isValid(string part) {
        if(part.size() > 1 && part[0] == '0') return false;
        int num = stoi(part);
        return num >= 0 && num <= 255;
    }

    vector<string> generateIp(string &s) {
        
        vector<string> result;
        int n = s.size();

        for(int i = 1; i <= 3 && i < n; i++) {
            for(int j = i+1; j <= i+3 && j < n; j++) {
                for(int k = j+1; k <= j+3 && k < n; k++) {

                    string A = s.substr(0, i);
                    string B = s.substr(i, j-i);
                    string C = s.substr(j, k-j);
                    string D = s.substr(k);

                    if(D.size() > 3) continue;

                    if(isValid(A) && isValid(B) && isValid(C) && isValid(D)) {
                        result.push_back(A + "." + B + "." + C + "." + D);
                    }
                }
            }
        }

        return result;
    }
};