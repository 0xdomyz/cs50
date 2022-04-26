from sys import exit, argv

if len(argv) != 2:
    print("miss")
    exit(1)
else:
    for i in argv:
        print(i)
    exit(0)