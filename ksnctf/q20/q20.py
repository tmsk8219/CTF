#!/usr/bin/env python
# coding: UTF-8

import math

def is_prime(q):
    q = abs(q)
    if q == 2: return True
    if q < 2 or q&1 == 0: return False
    return pow(2, q-1, q) == 1

def main():
	for i in xrange(9, 100):
		a, b = math.modf(math.pi * 10**i)
		num = int(b) % 10**10
		if(is_prime(num)):
			print 'True!'
			print num
			break

if __name__ == '__main__':
	main()

