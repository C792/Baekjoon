n = int(input())

word = []
translate = []
word_sorted = []

for i in range(n):
    word.append(input())

eng =    "L A B C D E F G H I J K M N O P Q R S T"
eng = eng.split()
minsik = "ng a b k d e g h i l m n o p r s t u w y"
minsik = minsik.split()

for i in word:
    temp = i
    for j in range(len(minsik)):
        temp = temp.replace(minsik[j],eng[j])
    translate.append(temp)

trans_sorted = sorted(translate)

for i in trans_sorted:
    temp = i
    for j in range(len(eng)):
        temp = temp.replace(eng[j],minsik[j])
    word_sorted.append(temp)

for i in word_sorted:
    print(i)