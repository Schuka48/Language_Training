class Dog:
    """Первый класс, описывающй поведение собаки"""

    def __init__(self, name, age):
        self.name = name
        self.age = age
        print(f"Created Dog-object with name: {self.name} and age: {self.age}")

    def sit(self):
        """Собака садится по команде."""
        print(f"{self.name} is now sitting!")

    def roll_over(self):
        """Собака перекатывается по команде."""
        print(f"{self.name} is rolling out!")
