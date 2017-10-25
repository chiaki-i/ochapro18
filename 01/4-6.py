# !/usr/bin/env python3
import collections
import unittest

####### 1.4 #######
def simplifyWord (string):
    lst1 = string.lower()
    lst2 = list(lst1)
    if ' ' in lst2:
        lst2.remove(' ')
    return lst2

def myCounter(lst):
    dic = {}
    for i in lst:
        if i in dic: # has_key (only in Python2.X)
            dic[i] += 1
        else:
            dic[i] = 1
    return dic

def isPalindrome(lst):
    # counter = collections.Counter(lst) 
    counter = myCounter(lst)
    result = 0
    for i in counter.values():
        if i % 2 == 0:
            result = result
        else:
            result += 1
    if result <= 1:
        return True
    else:
        return False

####### 1.5 #######
def isOneStep(word1, word2):
    len1 = len(word1)
    len2 = len(word2)
    if len1 == len2:
        return same(word1, word2)
    elif len1 == len2 + 1:
        return longer(word1, word2)
    elif len1 + 1 == len2:
        return longer(word2, word1)
    else:
        return False

def same (word1, word2):
    if word1 == word2:
        return True
    else:
        lst1 = list(word1)
        lst2 = list(word2)
        cnt = 0
        cnt_rev = 0
        for i in range(len(word1)):
            if lst1[i] != lst2[i]:
                cnt = i
                break
        for j in range(len(word1)):
            if (lst1[::-1])[j] != (lst2[::-1])[j]:
                cnt_rev = j
                break
        if cnt + cnt_rev + 1 == len(word1):
            return True
        else:
            return False

def longer(word1, word2):
    for i in range(len(word1)):
        lst2 = list(word2)
        lst2.insert(i, '.')
        newword = ''.join(lst2)
        if same(word1, newword):
            return True
    return False 

####### 1.6 #######
def condense(word):
    lst = list(word)
    bucket = []
    result = ''
    for i in lst:
        if len(bucket) == 0:
            bucket.append([i, 1])
        elif bucket[-1][0] == i:
            bucket[-1][1] += 1
        else:
            bucket.append([i, 1])
    for i in bucket:
        result += i[0]
        result += str(i[1])
    if len(result) <= len(word):
        return result
    else:
        return word
            
####### test #######    
def test4(arg, expected):
    lst = simplifyWord(arg)
    answer = isPalindrome(lst)
    if answer == expected:
        print('PASS. ' + arg + ': ' + str(expected))
    else:
        print('FAIL. ' + arg + ' should be ' + str(expected) + ' but was ' + str(answer))

def test5(arg1, arg2, expected):
    answer = isOneStep(arg1, arg2)
    if answer == expected:
        print('PASS. ' + arg1 + ' and ' + arg2 + ': ' + str(expected))
    else:
        print('FAIL. ' + arg1 + ' and ' +  arg2 + ' should be ' + str(expected) + ' but was ' + str(answer))

def test6(arg, expected):
    answer = condense(arg)
    if answer == expected:
        print('PASS. ' + arg + ': ' + str(expected))
    else:
        print('FAIL. ' + arg + ' should be ' + expected + ' but was ' + answer)
        
def runTest():
    print('=== 1.4 started ====')
    test4('1', True)
    test4('a', True)
    test4(' ', True)
    test4('aa', True)
    test4('abc', False)
    test4('madam', True)
    test4('madam1', False)
    test4('ootee ', True)
    test4('Tact Coa', True)
    test4('TactCoaPAPA', True)
    print('=== 1.4 finished ===')
    print('=== 1.5 started ====')
    test5('same', 'same', True)
    test5('same', 'samee', True)
    test5('apple', ' apple', True)
    test5('apple', 'aple', True)
    test5('bake', 'pale', False)
    test5('hippo', 'elephant', False)
    print('=== 1.5 finished ===')
    print('=== 1.6 started ====')
    test6('a', 'a')
    test6('abc', 'abc')
    test6('aabccccc', 'a2b1c5')
    test6('ABC', 'ABC')
    test6('BBBBB', 'B5')
    test6('aabcd', 'aabcd') # a2b1c1d1 is longer
    test6('aabcccccaaa', 'a2b1c5a3')
    print('=== 1.6 finished ===')

if __name__ == '__main__':
    runTest()
