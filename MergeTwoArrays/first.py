class Solution:
    # @param {integer[]} nums1
    # @param {integer} m
    # @param {integer[]} nums2
    # @param {integer} n
    # @return {void} Do not return anything, modify nums1 in-place instead.
    # 8:57
    def merge(self, nums1, m, nums2, n):
        indexM, indexN = m - 1, n - 1

        while indexM > -1 and indexN > -1:
            index = indexM + indexN + 1
            if nums1[indexM] > nums2[indexN]:
                nums1[index] = nums1[indexM]
                indexM -= 1
            else:
                nums1[index] = nums2[indexN]
                indexN -= 1

        if indexN > -1:
            nums1[:indexN + 1] = nums2[:indexN + 1]
