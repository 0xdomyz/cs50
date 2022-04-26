scores = []
for i in range(3):
    score = int(input("score: "))
    # scores.append(score)
    scores += [score]

avg = sum(scores) / len(scores)

print(f"avg is {avg}")