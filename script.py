from collections import defaultdict
import re


#   Code Globals

wordList = open("sample.txt", "r")

#   End of Globals



def getCharFreq(prevChars=[], words=[]):
    charFreq = defaultdict(int)

    prevChars = ''.join(prevChars)
    filter_ = re.compile(prevChars+".*")

    matchingList = list(filter(filter_.match, words))

    pos = len(prevChars)+1 if prevChars else 0

    for word in matchingList:
        char = word[pos]
        charFreq[char] += 1

    return dict(charFreq)



if __name__=="__main__":

    words = list(map(lambda word: word.strip(), wordList))

    print(getCharFreq(words=words))

    print(words)