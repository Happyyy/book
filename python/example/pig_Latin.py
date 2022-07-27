#!/usr/bin/python3
word = input("Please input a Pig Latin word in English: ")
if word.isalpha() & len(word)>0:
    Pig_Latin = word + word[0] + "ay"
    Pig_Latin = Pig_Latin[1:]
    print(Pig_Latin)
else:
    print("please input the letter 'a~zA~Z'")


