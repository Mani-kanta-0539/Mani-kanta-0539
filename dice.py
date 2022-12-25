import random

class Dice:
    def roll(self):
        frist = random.randint(1,6)
        second = random.randint(1,6)
        return frist,second

dice = Dice()
print(dice.roll())