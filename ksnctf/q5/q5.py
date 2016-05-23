#!/usr/bin/env python
# coding: UTF-8

import base64

def main():
	f = open('onion')
	data = f.read()

	for i in range(0, 100):
		print data
		data = base64.b64decode(data)
		raw_input()

	# for d in data:
	# 	for i in  range(0, ):
	# 		d = d.encode('base64')
	# 	print d

if __name__ == '__main__':
	main()