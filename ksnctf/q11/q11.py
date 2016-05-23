#!/usr/bin/env python
# coding: UTF-8

import sys

def main():
	flag = ['BF', 'FF', '1B', '0D', '47', 'A7', '18', '4F', 'CB', 'D6', '5C', '59', '95', '61', '73', '57', 'B3', 'D1', '94', '9F', 'AC']
	dkey = ['F9', 'B3', '5A', '4A', '18', 'EA', '5D', '36', '99', 'E2', '06', '3F', 'A1', '20', '47', '1F', 'F5', '86', 'A3', 'AC', 'C7']

	for i in range(0, len(flag)):
		sys.stdout.write(chr(int(flag[i], 16) ^ int(dkey[i], 16)))

if __name__ == '__main__':
	main()