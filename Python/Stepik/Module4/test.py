n = int(input())
matrix = [list(map(int, input().split())) for i in range(n)]


for i in range(n):
    for j in range(n):
        if i != j:
            if matrix[i][j] != matrix[j][i]:
                print('NO')
                exit(1)
else:
    print('YES')
