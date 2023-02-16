from itertools import permutations

N = 5 # change this to the number of values you want to generate

values = range(1, N+1) # generate a list of values from 1 to N

possibilities = list(permutations(values, N)) # generate all possible permutations

for p in possibilities:
    print(''.join(str(num) for num in p)) # print each permutation as a string of digits
