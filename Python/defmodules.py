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
