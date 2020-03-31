
'''
1. caculate the volume
2.
'''


class Solution:
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        res, hei_len, peak = 0, len(height), 0
        if hei_len < 3:
            return 0
        max_val = height[0]
        for i in range(1, hei_len):
            if height[i] >= max_val:
                max_val = height[i]
                peak = i

        max_left, max_right = height[0], height[-1]
        for i in range(peak):
            if max_left < height[i]:
                max_left = height[i]
            else:
                res += max_left - height[i]

        for i in range(hei_len - 1, peak, -1):
            if max_right < height[i]:
                max_right = height[i]
            else:
                res += max_right - height[i]

        return res


class Solution2:
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left, right = 0, len(height) - 1
        left_max, right_max = 0, 0
        res = 0
        while left < right:
            if height[left] < height[right]:
                if height[left] >= left_max:
                    left_max = height[left]
                else:
                    res += left_max - height[left]
                left += 1
            else:
                if height[right] >= right_max:
                    right_max = height[right]
                else:
                    res += right_max - height[right]
                right -= 1

        return res


tick = Solution2()
inArr = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
print(tick.trap(inArr))
