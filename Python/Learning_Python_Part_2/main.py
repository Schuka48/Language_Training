from person import Person

bob = Person('Bob Smith')
print(bob.__class__.__name__)

for attr in bob.__dict__:
    print(attr, '=>', getattr(bob, attr))