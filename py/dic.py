
words = dict()

def check(word: str):
    if word.lower() in words:
        return True
    else:
        return False

def load(dic):
    file = open(dic, "r")
    for line in file:
        word = line.rstrip()
        words.add(word)
    file.close()
    return True

def size():
    return len(words)



