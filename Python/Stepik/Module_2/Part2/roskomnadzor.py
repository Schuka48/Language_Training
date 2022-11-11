chars = ['а', 'б', 'в', 'г', 'д', 'е', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я']

input_str = input() + ' запретил букву '

in_chars = [char for char in chars if char in input_str]

for char in in_chars:
    test = (input_str + char).strip(' ')
    print(test)
    input_str = input_str.replace(char, '').replace('  ', ' ')
