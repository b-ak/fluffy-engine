'''
 There is a special way of receiving parameters to a function as a tuple or a dictionary using the * or ** prefix
 respectively. This is useful when taking variable number of arguments in the function.

  Due to the * prefix on the args variable, all extra arguments passed to the function are stored in args as a tuple.
  If a ** prefix had been used instead, the extra parameters would be considered to be key/value pairs of a dictionary.
'''
def powersum(power, *args):
	'''Return the sum of each argument raised to specified power.'''
	total = 0
	for i in args:
	        total += pow(i, power)
	return total

def fun(*args):
    for i in args:
        print("i = ", i)

def fun2(args):
	print(args)

print(powersum(2, 3, 4))
tup_1 = ("abc", 'g', 1234, 3.1415)
print(fun(*tup_1))
print(fun(tup_1))
print(fun("abc", 'g', 1234, 3.1415))
print(fun2(("abc", 'g', 1234, 3.1415)))

# Output
'''
25
i =  abc
i =  g
i =  1234
i =  3.1415
None
i =  ('abc', 'g', 1234, 3.1415)
None
i =  abc
i =  g
i =  1234
i =  3.1415
None
'''