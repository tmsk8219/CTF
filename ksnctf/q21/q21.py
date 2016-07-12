#!/bin/usr/python

def xor_right(x, n):
	return x ^ (x >> n)




def xor_left(x, n):
	return x ^ (x << n)


def main():
	x = 42
	x = xor_right(x, 11)
	x = xor_left(x, 7)
	x = xor_left(x, 15)
	x = xor_right(x, 18)

	print x



if __name__ == '__main__':
	main()