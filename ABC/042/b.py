num_strings, length_strings = map(int, input().split())

strings = [input() for _ in range(num_strings)]

strings.sort()

print(''.join(strings))
