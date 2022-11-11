choice = ['камень', 'ящерица', 'Спок', 'ножницы', 'бумага']
tim, rus = choice.index(input()), choice.index(input())

res = tim - rus


if not res:
    print('ничья')
elif res % 2:
    # победа меньшего индекса
    if tim > rus:
        print('руслан'.title())
    else:
        print('тимур'.title())
else:
    if tim > rus:
        print('тимур'.title())
    else:
        print('руслан'.title())
