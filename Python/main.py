def create_person(f_name, s_name, **user_info) -> dict:
    user_info['first_name'] = f_name
    user_info['second_name'] = s_name
    return user_info


def greet_users(names):
    [print(f'Welcome, {name.get("second_name").title()} {name.get("first_name").title()}!') for name in names]


def print_models(unprinted_designs: list, completed_designs: list) -> None:
    """
    :type completed_designs: list
    :type unprinted_designs: list
    """
    while unprinted_designs:
        detail = unprinted_designs.pop()
        print(f'Print model {detail}')
        completed_designs.append(detail)


def make_pizza(size, *toppings):
    print(f"\nMaking a {size}-inch pizza with the following toppings:")
    for top in toppings:
        print(f'- {top}')


if __name__ == '__main__':
    persons = []
    while True:
        print("\nPlease input your name:")
        print("You may quit at any time, please input 'q'")
        first_name = input("First name: ")
        if first_name == 'q':
            break
        second_name = input("Second name: ")
        if second_name == 'q':
            break
        persons.append(create_person(first_name, second_name))

    greet_users(persons)

    unprinted_designs = ['phone case', 'robot pendant', 'dodecahedron']
    completed_designs = []
    print_models(unprinted_designs[:], completed_designs)

    make_pizza(12, 'mushrooms', 'green peppers', 'extra cheese')

    print(create_person('Artem', 'Schukin', location='Lipetsk', age=21))
