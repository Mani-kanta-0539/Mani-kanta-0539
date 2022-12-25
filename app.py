from  max import find_max

from pack.ship import ship

from random import randint

from pathlib import Path

path = Path()
for file in path.glob('*'):
    print(file)

for i in range(3):
    print(randint(10 ,50))

numbers=[10,22,13,456]
print(find_max(numbers))

ship()

