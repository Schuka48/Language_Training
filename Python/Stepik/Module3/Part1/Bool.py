# объявление функции
def func(num1, num2):
    return bool(num1 % num2)

# считываем данные
num1, num2 = int(input()), int(input())

# вызываем функцию
if func(num1, num2):
    print('не делится')
else:
    print('делится')