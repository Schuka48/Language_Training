import defmodules as dm
import dog


def main():
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
        persons.append(dm.create_person(first_name, second_name))

    dm.greet_users(persons)

    unprinted_designs = ['phone case', 'robot pendant', 'dodecahedron']
    completed_designs = []
    dm.print_models(unprinted_designs[:], completed_designs)

    dm.make_pizza(12, 'mushrooms', 'green peppers', 'extra cheese')

    print(dm.create_person('Artem', 'Schukin', location='Lipetsk', age=21))
    my_dog = dog.Dog(name='keisy', age=3)
    my_dog.roll_over()

    health = 100
    finished = False
    while not finished:
        print('My health', health, 'Hit me!')
        damage = int(input())
        health -= damage
        if health <= 0:
            finished = True
    print("You kill me!")


if __name__ == '__main__':
    main()
