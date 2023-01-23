import sys

sys.path.append("/home/adam/github_repos/CTCI/helpers")
from CTCI_helpers import run_tests
# Q: determine if a string contains all unique character
# Clarification:
#   -What character set are we using? If we have a fixed character set we can use 
#    an array instead of a dict/hashmap to store our already seen characters
#   -Should uppercase and lowercase be considered different characters?
#   -What about non-alphanumeric characters?

# Test Cases:
tests = {
    True : 
    [
        "abcdefgh",
        "oen luf"
    ],
    
    False : 
    [
        "repeat",
        "random letters"
    ]
}

# A1: Brute force solution
# Description: for each char in string, iterate through the rest of the string checking if they match 
# Time:  O(n^2)
# Space: O(1)

def isUnique(s):
    for i in range(len(s)):
        for j in range(i+1  , len(s)):
            if s[i] == s[j]:
                return False
    return True

run_tests(tests, isUnique, "brute force")
# A2: Fastest solution
# Description: Use a dict to store seen characters as we iterate through the array
# Time: O(n)
# Space: O(n)

def isUnique(s):
    seenChars = {}
    for char in s:
        if char in seenChars:
            return False
        seenChars[char] = True
    return True
run_tests(tests, isUnique, "fastest solution")

# A3: fastest solution using no additional space
# Description: If we sort the string first, then we only need to iterate through the string once afterward
# Time: O(nlog(n))
# Space: O(1)

def isUnique(s):
    s = sorted(s)
    i, j = 0, 1
    while j < len(s):
        if s[j] == s[i]:
            return False
        i += 1
        j += 1
    return True

run_tests(tests, isUnique, "O(1) space (sorted)")