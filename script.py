from collections import defaultdict
import re


#   Code Globals

wordList = open("sample.txt", "r")

#   End of Globals



def getSorted(dict_, desc=True):
    return dict(sorted(dict_.items(), key=lambda item: item[1], reverse=desc))


def getCharFreq(offset=0, prevChars=[], words=[]):
    charFreq = defaultdict(int)

    prevChars = ''.join(prevChars)
    filter_ = re.compile(prevChars+".*")

    matchingList = list(filter(filter_.match, words))

    pos = offset+len(prevChars) if prevChars else offset

    for word in matchingList:
        char = word[pos]
        charFreq[char] += 1

    return getSorted(dict(charFreq))


def guess():
    prevChars = []

    for i in range(0, 5):
        highFreqChar = list(
            map(
                lambda item: item[0] if not item[0] in prevChars else None,
                getCharFreq(prevChars=prevChars, words=words)
            )
        )[0]

        prevChars.append(highFreqChar)
    
    return ''.join(prevChars)


if __name__=="__main__":

    words = list(map(lambda word: word.strip(), wordList))
    
    print("None", getCharFreq(offset=0, prevChars=[], words=words))