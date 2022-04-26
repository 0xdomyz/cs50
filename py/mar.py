
def get_height():
    while True:
        try:
            s = int(input("int: "))
            if s > 0:
                break
        except ValueError:
            print("wrong input")
    return s

def draw(n):
    # for i in range(n):
    #     print("#", end="")
    print("#"*n, end="")


draw(get_height())