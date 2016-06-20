#!/usr/bin/env python
# coding: UTF-8

import sys

str = 'EBG KVVV vf n fvzcyr yrggre fhofgvghgvba pvcure gung ercynprf n yrggre jvgu gur yrggre KVVV yrggref nsgre vg va gur nycunorg. EBG KVVV vf na rknzcyr bs gur Pnrfne pvcure, qrirybcrq va napvrag Ebzr. Synt vf SYNTFjmtkOWFNZdjkkNH. Vafreg na haqrefpber vzzrqvngryl nsgre SYNT.'
for x in str:
	x = ord(x)	# xをASCIIコードに変換

	if 65 < x & x < 90:		# A~Zの場合
		x = x + 13
		if x > 90:
			x = x - 26

	elif 97 < x & x < 122:	# a~zの場合
		x = x + 13
		if x > 122:
			x = x - 26

	sys.stdout.write(chr(x))