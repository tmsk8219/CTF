# predict_mt.py
import random

def untemper(x):
    x = unBitshiftRightXor(x, 18)
    x = unBitshiftLeftXor(x, 15, 0xefc60000)
    x = unBitshiftLeftXor(x, 7, 0x9d2c5680)
    x = unBitshiftRightXor(x, 11)
    return x

def unBitshiftRightXor(x, shift):
    i = 1
    y = x
    while i * shift < 32:
        z = y >> shift
        y = x ^ z
        i += 1
    return y

def unBitshiftLeftXor(x, shift, mask):
    i = 1
    y = x
    while i * shift < 32:
        z = y << shift
        y = x ^ (z & mask)
        i += 1
    return y

def main():
    # values1 = [random.getrandbits(32) for i in xrange(624)]
    # values2 = [random.getrandbits(32) for i in xrange(624)]

    # mt_state = tuple([untemper(x) for x in values1] + [624])
    # random.setstate((3, mt_state, None))

    # predicted = [random.getrandbits(32) for i in xrange(624)]
    # print predicted == values2
    y = 100
    y ^= (y >> 11)
    y ^= (y << 7) & 0x9d2c5680
    y ^= (y << 15) & 0xefc60000
    y ^= (y >> 18)

    print y

    print untemper(y)

if __name__ == '__main__':
    main()