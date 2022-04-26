try:
    x = int(input("x: "))
except:
    print("not int")
    exit()
try:
    y = int(input("y: "))
except:
    print("not int")
    exit()

print(f"res is {x / y}")
print(f"digit res is {x / y:.50f}")
print(f"c res is {x // y}")

if x % 2 == 0:
    print("even")
else:
    print("odd")
