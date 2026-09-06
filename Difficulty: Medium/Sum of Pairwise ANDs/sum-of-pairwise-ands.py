
class Solution:
    def pairAndSum(self, arr):
        ans = 0

        # arr[i] <= 10^8, so we need at most 30 bits
        for bit in range(30):
            count = 0

            # Count numbers having this bit set
            for num in arr:
                if num & (1 << bit):
                    count += 1

            # Number of pairs having this bit set in both numbers
            pairs = count * (count - 1) // 2

            # Add contribution of this bit
            ans += pairs * (1 << bit)

        return ans

