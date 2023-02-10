import random
import sys

if (sys.argv):
    qtd_values: int = int(sys.argv[1])
else:
    qtd_values: int = 5

max_note: int = 1000
with open('input', 'w') as file:

    file.write(f"{qtd_values}\n")
    for x in range(0, qtd_values):
        file.write(f"{random.randint(0, 10)}\n")
