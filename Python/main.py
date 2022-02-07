def create_person(first_name, second_name, age=None) -> dict:
    person = {}
    person['first_name'] = first_name
    person['second_name'] = second_name
    if age:
        person['age'] = age
    return person


if __name__ == '__main__':
    print(create_person("Artem", "Schukin", age=21))

