'''
collections 可以直接取 and or 
'''

def intersect(self, nums1, nums2):
    a, b = map(collections.Counter, (nums1, nums2))
    return list((a & b).elements())
