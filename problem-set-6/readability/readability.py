import re

# Input prompt
text = input("Text: ")


# Implement ReGex and len() to determine the count for letters, words, and sentences
letter_count = len(re.findall("[a-zA-Z]", text))
word_count = len(re.findall("\s", text)) + 1
sentence_count = len(re.findall("[.!?]", text))


# Coleman-Liau index calculation
argl = letter_count / word_count * 100
args = sentence_count / word_count * 100
clindex = round(0.0588 * argl - 0.296 * args - 15.8)


# Print out the results
if clindex < 1:
    print("Before Grade 1\n")
elif clindex > 16:
    print("Grade 16+\n")
else:
    print("Grade " + str(clindex) + "\n")
