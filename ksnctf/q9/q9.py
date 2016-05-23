#!/usr/bin/env python
# coding: UTF-8

import urllib
import urllib2
import md5

url = 'http://ksnctf.sweetduet.info:10080/~q9/flag.html'


username = "q9"
realm = "secret"
nonce = ""
uri = "/~q9/flag.html"
algorithm = "MD5"
response = ""
qop = "auth"
nc = "00000001"
cnonce = "9691c249745d94fc"
md5a1 = "c627e19450db746b739f41b64097d449"
a2 = 'GET:' + uri

def getNonce():
	try:
		data = urllib2.urlopen(url)
		html = data.read()
	except urllib2.HTTPError, e:
		nonce = e.info()['WWW-Authenticate'].split('"')[3]
		return nonce	

def genMD5(str):
	return md5.new(str).hexdigest()

def genResponse(nonce):
	response = genMD5(md5a1 + ':' + nonce + ':' + nc + ':' + cnonce + ':' + qop + ':' + genMD5(a2))
	return response


def genAuthorized(nonce, response):
	authorized = 'Digest username="' + username + '", realm="' + realm + '", nonce="' + nonce + '",uri="' + uri + '", algorithm=' + algorithm + ', response="' + response + '", qop=' + qop + ', nc=' + nc + ', cnonce="' + cnonce + '"'
	return authorized



def main():
	nonce = getNonce()
	response = genResponse(nonce)
	auth = genAuthorized(nonce, response)
	header = {'Authorization' : auth}
	req = urllib2.Request(url, None, header)
	try:
		data = urllib2.urlopen(req)
		html = data.read()
		print html
	except urllib2.HTTPError, e:
		print e.code
		print e.info()
		
if __name__ == '__main__':
	main()