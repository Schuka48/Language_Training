from classtools import AttrDisplay

class Person(AttrDisplay):
    def __init__(self, name: str, job: str|None = None, pay: int = 0):
        self.name = name
        self.job = job
        self.pay = pay
    
    def lastName(self) -> str:
        return self.name.split()[-1]

    def giveRaise(self, persent: float):
        self.pay = int(self.pay* (1 + persent))
    
    # def __repr__(self) -> str:
    #     return '[Person: %s, %s]' % (self.name, self.pay)

class Manager(Person):
    def __init__(self, name:str, pay:int = 0):
        Person.__init__(self, name, 'mgr', pay)

    def giveRaise(self, persent: float, bonus: float = 0.1):
        Person.giveRaise(self, persent + bonus)


if __name__ == '__main__':
    bob = Person('Bob Smith', 'dev', 100000)
    sue = Manager('Sue Vesson', 100000)
    print(bob, sue)
    bob.giveRaise(0.1)
    sue.giveRaise(0.1)
    print(bob, sue)
     