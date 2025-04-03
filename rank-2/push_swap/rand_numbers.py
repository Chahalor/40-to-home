import random
import argparse

parser = argparse.ArgumentParser(description="Generate random numbers in a given range.")
parser.add_argument("count", type=int)

args = parser.parse_args()

random_numbers = random.sample(range(-500, 1000 + args.count), args.count)
# random_numbers = random.sample(range(0, args.count), args.count)


for n in random_numbers:
	print(n, end=" ")
