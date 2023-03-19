from leetcode_helpers import run_test_scenarios
# Q: Given two strings, write a function to determine if one is a permutation of the other 
# Clarification Questions:

# Test Cases:
tests = {
    True : 
    [
        ["abcdefgh", "hgfabcde"],
        ["abcdefgh"*10000, "hgfabcde"*10000],
        ["adam", "maad"],
        ["adam", "aamd"],
        ["python12", "2pythno1"],
    ],
    
    False : 
    [
        ["abcdefgh", "hgrfabcde"], # should stop immediately since len is not the same
        ["abcdefgh", "hgfarcde"], # should stop at "r"
        ["adam", "adbm"],
        ["p1ython2"*10000, "python23"*10000],
    ]
}

# A1: sort and iterate
# Description: Sort each string, then loop through each string and check if each element is the same
# Time:  O(nlog(n))
# Space: O(1)

def isPerm(s1, s2):
    if len(s1) != len(s2):
        return False
    s1 = sorted(s1)
    s2 = sorted(s2)
    for i in range(len(s1)):
        if s1[i] != s2[i]:
            return False
    return True


run_test_scenarios(isPerm, tests, "sort and iterate")

# A2: array (assumes ascii char set)
# Description: iterate through string 1, adding char counts to array, then iterate through string 2 subtracting char counts from array
#   return true if sum of array is 0, else false
# Time: O(n) 
# Space: O(1)

def isPerm(s1, s2):
    if len(s1) != len(s2):
        return False
    char_counts = [0 for _ in range(256)]
    for c in s1:
        char_counts[ord(c)] += 1
    for c in s2:
        if(char_counts[ord(c)] == 0):
            return False
        char_counts[ord(c)] -= 1
    for cnt in char_counts:
        if cnt != 0:
            return False
    return True

run_test_scenarios(isPerm, tests, "array of char counts")

# A3: 
# Description: 
# Time: 
# Space: 
