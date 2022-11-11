n = int(input())
k = int(input())


lst = list(range(1, n + 1))

i = 0
while len(lst) > 1:
    i = (i+(k)-1) % (len(lst))
    lst.pop(i)

print(*lst)
