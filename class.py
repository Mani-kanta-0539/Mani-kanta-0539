class Person:
    def __init__(self, name):
        self.name =name

    def talk(self):
        print(f"hello {self.name}")


person = Person("Mani")

person.talk()

