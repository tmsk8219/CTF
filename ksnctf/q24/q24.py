#!/usr/bin/python

import sys


def htoa(string):
	for x in string:
		sys.stdout.write(chr(x))

def main():

	numArray = [1, 7, 0x10, 11, 14, 0x13, 20, 0x12]
	numArray2 = [0x55, 0x6f, 0x75, 0x2b, 0x68, 0x7f, 0x75, 0x75, 0x21, 110, 0x63, 0x2b, 0x48, 0x5f, 0x55, 0x55, 0x5e, 0x42, 120, 0x62, 0x4f, 0x75, 0x44, 0x53, 0x40, 0x5e, 0x27, 0x41, 0x49, 0x20, 0x41, 0x48, 0x33]
	string = []
	num2 = 0
	for x in numArray2:
		s = numArray2[num2] ^ numArray[num2%len(numArray)]
		string.append(s)
		num2 = num2 + 1

	htoa(string)

if __name__ == '__main__':
	main()