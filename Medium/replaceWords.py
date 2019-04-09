#Date: 4/9/2019
# Program: Replace Words
#Description: Given a dictionary consisting of many roots and a sentence. 
# You need to replace all the successor in the sentence with the root forming it. 
# If a successor has many roots can form it, replace it with the root with the 
# shortest length.
'''
Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
'''

def isIn(x,dictionary):
    for i in dictionary:
        if i in x:
            return i
    return ""


def replace(dictionary, sentence):
    newsentence=''
    arr=sentence.split()
    for x in arr:
        word= isIn(x,dictionary)
        if word != "":
            newsentence+=word
        else:
            newsentence+=x
        newsentence+=" "
    return newsentence

sentence="the cattle was rattled by the battery"
dictionary=["cat", "bat", "rat"]
replace(dictionary,sentence)