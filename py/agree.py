
while True:
    try:
        s = input("s: ").lower()
    except:
        next()
    if True:
        break


if s in ["yes", "y"]:
    print("Agreed")
elif s in ["no", "n"]:
    print("Not agree")
else:
    print("else")