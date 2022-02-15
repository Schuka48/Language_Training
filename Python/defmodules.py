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


#  Here we go to train decorators

def get_bold(func):
    def wrapped():
        return "<b>" + func() + "</b>"

    return wrapped


def get_italic(func):
    def wrapped():
        return "<i>" + func() + "</i>"

    return wrapped


@get_italic
@get_bold
def get_hello():
    return "Hello, Artem!"


def my_decorator(func):
    print("Default function")

    def wrapper():
        print("I'm function that has been returned by decorator")
        func()

    return wrapper


@my_decorator
def lazy_function():
    print("zzzzzz ...")


def simple_decorator(func):
    def wrapper(*args, **kwargs):
        print("My args:", args)
        print("My kwargs:", kwargs)
        return func(*args, **kwargs)

    return wrapper

@simple_decorator
def summ(*args, **kwargs):
    summa: int = 0
    for arg in args:
        summa += arg
    for key in kwargs:
        print(key)

    return summa
