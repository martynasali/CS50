from cs50 import get_string

text = get_string("Text: ")
text = text.lower()
words = text.count(" ")+1
sentences = text.count(".") + text.count("!") + text.count("?")
# Taken from https://thispointer.com/python-count-uppercase-characters-in-a-string/
letters = len([lett for lett in text if lett.islower()])

# calculate
L = (letters / words) * 100
S = (sentences / words) * 100
index = 0.0588 * L - 0.296 * S - 15.8
result = round(index)
# print
if result >= 16:
    print("Grade 16+")
elif result < 1:
    print("Before Grade 1")
else:
    print(f"Grade {result}")