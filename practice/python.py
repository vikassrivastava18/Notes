def is_anagram(w1, w2):
    return sorted(w1) == sorted(w2)

# print(is_anagram("pots", "spot"))
# print(is_anagram("hello", "world"))

def all_anagrams(word, word_list):
    result = set()
    for w in word_list:
        if is_anagram(word, w):
            result.add(w)
    result.remove(word)
    return {word: list(result)}

# word_list = ['stop', 'pots', 'test', 'tops', 'trop', 'wall', 'malayalam', 'noon', 'rotator']
# print(all_anagrams(word='stop', word_list=word_list))


def is_palindrome(word):
    return list(word) == list(reversed(word))
    # return word == ''.join(word[::-1])

# print(is_palindrome("malayalam"))
# print(is_palindrome("malaya"))

def reverse_sentence(sentence: str):
    rever_list = list(reversed(sentence.split(' ')))
    reversed_sent = [rever_list[0].capitalize()] + [word.lower() for word in rever_list[1:]]
    return ' '.join(reversed_sent)

print(reverse_sentence('Kaise ho bhai'))
print(reverse_sentence('ek kam karo'))

def total_length(sentence):
    # Only return the length of characters
    return len(sentence)

# print(total_length("kaise ho bhai"))


def convert_to_binary(num: int) -> str:
    """
    :param num: an integer
    :return: binary equivalent (eg. 9 -> 1001, 7 -> 111)
    """
    result = ''
    i = 0
    remaining = num

    while True:
        while 2 ** i < remaining:
            i += 1
        r = remaining % (2 ** i)
        result = str(1 - r) + result
        remaining -= result
        if remaining >= num:
            break
        i = 0
    return result

# Lambda functions

upper = lambda x: x.upper()

name = "vikas srivasteva"
print(upper(name))


odd_even = lambda x: "even" if x % 2 == 0 else "odd"

check_number = lambda x: "Positive" if x > 0 else "Negative" if x < 0 else "Zero"

print(check_number(0))

print(odd_even(23))

sum_product = lambda x, y: (x + y, x * y)

print(sum_product(3, 4))


# Map
a = [1,2,3,4,5]
square = map(lambda x: x ** 2, a)

# print(list(square))

from functools import reduce

reduce_mult = reduce(lambda x, y: x * y, a)
# print(reduce_mult)

# Itertools
import operator
import time

a = list(range(1, 1000001))
b = list(range(1, 1000001))

iter_out = []
# for i in range(5):
#     t1 = time.time()
#     result = list(map(operator.mul, a, b))
#     t2 = time.time()
#     iter_out.append(t2 - t1)
#
# print(sum(iter_out) / len(iter_out))

for_out = []
# for i in range(5):
#     t1 = time.time()
#     result = [a[i] * b[i] for i in range(len(a))]
#     t2 = time.time()
#     for_out.append(t2 - t1)
#
# print(sum(for_out) / len(for_out))

import itertools

l = ['Geeks', 'for', 'Geeks']

iterators = itertools.cycle(l)

# for i in range(100):
#     print(next(iterators), end=" ")
#
#
# def infinite_sequence():
#     n = 0
#     while True:
#         yield n
#         n += 1
#
# g = infinite_sequence()
# for _ in range(10):
#     print(next(g), end="\n")

# REGEX
import re

email = input("What's your email?").strip()

if re.search(r"^\w+@.+\.com$", email):
    print("Valid")

else:
    print("Invalid")








