
int missingNumber(const string& str) {
     int n = str.length();

        // Try first number length from 1 to 6
        for (int len = 1; len <= 6; len++) {

            if (len > n) break;

            long long first = stoll(str.substr(0, len));
            long long curr = first;

            int i = len;
            int missing = -1;
            bool valid = true;

            while (i < n) {
                curr++;

                string nextStr = to_string(curr);
                int nextLen = nextStr.length();

                // If the next expected number does not match
                if (i + nextLen <= n && str.substr(i, nextLen) == nextStr) {
                    i += nextLen;
                }
                else {
                    // Maybe this number is missing → check for curr+1
                    long long missCandidate = curr;  // this might be missing
                    curr++;

                    string nextNextStr = to_string(curr);
                    int nextNextLen = nextNextStr.length();

                    if (missing == -1 && i + nextNextLen <= n &&
                        str.substr(i, nextNextLen) == nextNextStr) {

                        missing = missCandidate;
                        i += nextNextLen;
                    }
                    else {
                        valid = false;
                        break;
                    }
                }
            }

            if (valid && missing != -1)
                return missing;
        }

        return -1; // No valid sequence found
}