# learning-python
A combination of code snippets and syntax from MOOCs and other online resources

Table of Contents
=================

   * [Print statement](#print-statement)
      * [Printing a List](#printing-a-list)
      * [Comma after print](#comma-after-print)
      * [Reading input](#reading-input)
   * [Boolean operators](#boolean-operators)
   * [Bitwise Operator](#bitwise-operator)
      * [Shift Operatons](#shift-operatons)
      * [NOT Operator](#not-operator)
      * [Flip Bit](#flip-bit)
   * [Conditional statements](#conditional-statements)
   * [type()](#type)
   * [String methods](#string-methods)
      * [Concatenation](#concatenation)
      * [Sub-String](#sub-string)
      * [String Looping](#string-looping)
      * [Reverse](#reverse)
   * [Loops](#loops)
      * [While](#while)
      * [While / else](#while--else)
         * [Example One](#example-one)
         * [Example Two](#example-two)
         * [Example Three](#example-three)
      * [For Loops](#for-loops)
      * [For / else](#for--else)
   * [Functions](#functions)
      * [Function Imports](#function-imports)
      * [List all functions in a module](#list-all-functions-in-a-module)
      * [Universal Import](#universal-import)
      * [Don't use Universal Imports](#dont-use-universal-imports)
      * [Passing multiple arguments](#passing-multiple-arguments)
         * [Example](#example)
      * [Anonymous Functions / lambda Operator](#anonymous-functions--lambda-operator)
         * [filter](#filter)
            * [Example One](#example-one-1)
            * [Example Two](#example-two-1)
            * [Example Three](#example-three-1)
            * [Example Four](#example-four)
            * [Example Five](#example-five)
            * [Example Six](#example-six)
            * [Example Seven](#example-seven)
   * [Lists](#lists)
      * [Building Lists / List Comprehension](#building-lists--list-comprehension)
      * [for/in &amp; if](#forin--if)
      * [List Append](#list-append)
      * [List remove](#list-remove)
      * [List pop](#list-pop)
      * [List remove](#list-remove-1)
      * [List delete](#list-delete)
      * [List concatenate](#list-concatenate)
      * [List Reverse](#list-reverse)
         * [Example One](#example-one-2)
         * [Example Two](#example-two-2)
      * [List Slicing](#list-slicing)
         * [Example One](#example-one-3)
         * [Example Two](#example-two-3)
         * [Example Three](#example-three-2)
         * [Example Four](#example-four-1)
         * [Example Five](#example-five-1)
      * [Omitting Indices](#omitting-indices)
      * [List Insertion &amp; Indexing](#list-insertion--indexing)
      * [Looping in lists](#looping-in-lists)
         * [Example](#example-1)
         * [Method 1 - for item in list](#method-1---for-item-in-list)
         * [Method 2 - iterate through indexes](#method-2---iterate-through-indexes)
      * [List of Lists](#list-of-lists)
         * [Example One](#example-one-4)
         * [Example Two](#example-two-4)
      * [Printing Pretty](#printing-pretty)
         * [Example](#example-2)
      * [Sorting the List](#sorting-the-list)
      * [Range in lists](#range-in-lists)
      * [Passing a range into a function](#passing-a-range-into-a-function)
         * [Example One](#example-one-5)
         * [Example Two](#example-two-5)
      * [Enumerate](#enumerate)
      * [Iterating Multiple Lists](#iterating-multiple-lists)
   * [Dictionary](#dictionary)
      * [Assigning a dictionary with three key-value pairs to residents](#assigning-a-dictionary-with-three-key-value-pairs-to-residents)
      * [Adding New entries](#adding-new-entries)
      * [Add &amp; Delete](#add--delete)
      * [Retrieve key and value](#retrieve-key-and-value)
         * [Method One](#method-one)
         * [Method Two](#method-two)
         * [Example](#example-3)
      * [Lists and Dictionaries](#lists-and-dictionaries)
         * [Looping in dictionaries](#looping-in-dictionaries)
      * [More Looping techniques](#more-looping-techniques)
      * [List of Dictionaries](#list-of-dictionaries)
   * [Classes](#classes)
      * [Example One](#example-one-6)
      * [Errors](#errors)

# Print statement

```python
  print "Turn", turn + 1
  print '%s/%s/%s' % (now.year, now.month, now.day)
  print "Let's not go to %s. 'Tis a silly %s." % (string_1, string_2)
  print 'This isn\'t flying, this is falling with style!'
```
## Printing a List
```python
  name = ["brave", "ice", "berg"]
  id = [1, 2, 3]
  for i in id:
    print "My name is {0}. ID {1}".format(name[i-1], id[i-1])
```

## Comma after print


String manipulation is useful in for loops if you want to modify
some content in a string.

```python
  word = "Marble"
  for char in word:
      print char,

  '''
  The example above iterates through each character in word and,
  in the end, prints out M a r b l e.

  The , character after our print statement means that our next print
  statement keeps printing on the same line.
  '''

  #Example
    phrase = "A bird in the hand..."

    # Add your for loop
    for i in phrase:
        if i == 'A' or i == 'a':
            print 'X',
        else:
            print i,

    #Don't delete this print statement!
    print
```

## Reading input

```python
  name = raw_input("What is your name?")
  var = input("Enter a number")
    OR
  var = int(input("Enter a number"))
```

There were two functions to get user input, called `input` and `raw_input`.
The difference between them is, `raw_input` doesn't evaluate the data and returns as it is,
in string form.
But, `input` will evaluate whatever you entered and the result of evaluation will be returned

```python
  name = raw_input("What is your name?")
  quest = raw_input("What is your quest?")
  color = raw_input("What is your favorite color?")

  print "Ah, so your name is %s, your quest is %s, " \
  "and your favorite color is %s." % (name, quest, color)

  # Example
  number = raw_input("Enter a number: ")
  if int(number) == 0:
      print "You entered 0"

  '''
  raw_input asks the user for input and returns it as a string. But we're going to
  want to use integers for our guesses! To do this, we'll wrap the raw_inputs with int()
  to convert the string to an integer.
  '''

  guess = int(raw_input("Your guess: "))
  '''
  Remember, raw_input turns user input into a string, so we use int()
  to make it a number again.
  '''
```

# Boolean operators

```python
  True or False
  (3 < 4) and (5 >= 5)
  this() and not that()
```

# Bitwise Operator

```python
  print 5 >> 4  # Right Shift
  print 5 << 1  # Left Shift
  print 8 & 5   # Bitwise AND
  print 9 | 4   # Bitwise OR
  print 12 ^ 42 # Bitwise XOR
  print ~88     # Bitwise NOT

  print bin(4)
  # => 0b100

  print int("0b11001001", 2)
  # => 201

  print int("111",2)
  # => 7

  print int(bin(5),2)
  # => 5
```

## Shift Operatons

```python
  shift_right = 0b1100
  shift_left = 0b1

  # Your code here!
  shift_right >>= 2
  shift_left <<= 2

  print bin(shift_right)
  print bin(shift_left)

  # => 0b11
  # => 0b100
```

## NOT Operator

```python
  print ~2
  # => -3
```

## Flip Bit
```python
  def flip_bit(number, n):
      result = 0b0
      result = number ^ (1 << (n-1))
      return bin(result)
```

# Conditional statements

```python
  if this_might_be_true():
    print "This really is true."
  elif that_might_be_true():
    print "That is true."
  else:
    print "None of the above."
```

Don't forget to include a : after your if statements!

```python
  if guess_row not in range(5) or guess_col not in range(5):
      print "Oops, that's not even in the ocean."
```

# type()
```python
  '''
  Finally, the type() function returns the type of the data it receives as an
  argument.
  '''

  print type(42)
  print type(4.2)
  print type('spam')

  #Python will output:

  <type 'int'>
  <type 'float'>
  <type 'str'>
```

# String methods
```python
  fifth_letter = "MONTY"[4]

  ministry = "The ministry of Defence"

  len()	- len(ministry)
  lower()	- "Ryan".lower()
  upper()	- ministry.upper()
  str()	- str(2), would turn 2 into "2".

  x = "J123"
  x.isalpha()  # False
```

In the first line, we create a string with letters and numbers.

The second line then runs the function isalpha() which returns
False since the string contains non-letter characters.

## Concatenation

Remember how to concatenate (i.e. add) strings together?

```python
  greeting = "Hello "
  name = "D. Y."
  welcome = greeting + name

  print "Spam" + " and" + " eggs"
    This will print I have 2 coconuts!


  print "I have " + str(2) + " coconuts!"
```

The `str()` method converts non-strings into strings. In the above example,
you convert the number 2 into a string and then you concatenate the strings
together just like in the previous exercise.


## Sub-String

```python
  s = "Charlie"

  print s[0]
  # will print "C"

  print s[1:4]
  # will print "har"
```

## String Looping

Strings are like lists with characters as elements.
You can loop through strings the same way you loop through lists
```python
  for letter in "Codecademy":
      print letter

  for x in S: print(x, end=' ') # Iterate over a string
  ...
  l u m b e r j a c k

  # Empty lines to make the output pretty
  print
  print

  word = "Programming is fun!"

  for letter in word:
      # Only print out the letter i
      if letter == "i":
    print letter
```

## Reverse

```python
  reverse("abcd") should return "dcba".

  or

  [::-1] to help you with this.
  S = "hello"
  S[::-1] will return "olleh"
```

# Loops

## While
```python
  loop_condition = True

  while loop_condition:
    print "I am a loop"
    loop_condition = False
```

## While / else


`while/else` is similar to `if/else`, but there is a difference: the `else`
block will execute anytime the loop condition is evaluated to `False`.

This means that it will execute if the loop is never entered or if the
loop exits normally. If the loop exits as the result of a `break`, the
`else` will not be executed.



### Example One
```python
  '''
  In this example, the loop will break if a 5 is generated, and the else
  will not execute. Otherwise, after 3 numbers are generated, the loop
  condition will become false and the else will execute.
  '''

  import random

  print "Lucky Numbers! 3 numbers will be generated."
  print "If one of them is a '5', you lose!"

  count = 0
  while count < 3:
      num = random.randint(1, 6)
      print num
      if num == 5:
          print "Sorry, you lose!"
          break
      count += 1
  else:
      print "You win!"
```

### Example Two
```python
  from random import randint

  # Generates a number from 1 through 10 inclusive
  random_number = randint(1, 10)

  guesses_left = 3
  # Start your game!
  while guesses_left > 0:
      guess = int(raw_input("Your Guess : " ))
      if guess == random_number:
          print "You Win"
          break
      else:
          guesses_left -= 1
  else:
      print "You lose."
```

### Example Three
```python
  # A nice use of while/else

  def is_prime(x):
      if x < 2:
          return False
  #    elif x == 2:
  #        return True
      else:
          n = 2
          while n <= x-1:
              if x % n == 0:
                  return False
                  break
              n += 1
          else:
              return True
```
## For Loops
```python
  print "Counting..."

  for i in range(20):
      print i
```

## For / else

Just like with while, for loops may have an else associated with them.

In this case, the else statement is executed after the for, but only
if the for ends normally—that is, not with a break. This code will break
when it hits 'tomato', so the else block won't be executed.

```python
  fruits = ['banana', 'apple', 'orange', 'tomato', 'pear', 'grape']

  print 'You have...'
  for f in fruits:
      if f == 'tomato':
          print 'A tomato is not a fruit!' # (It actually is.)
          break
      print 'A', f
  else:
      print 'A fine selection of fruits!'
```

# Functions
```python
  def shout(phrase):
    if phrase == phrase.upper():
      return "YOU'RE SHOUTING!"
    else:
      return "Can you speak up?"

  shout("I'M INTERESTED IN SHOUTING")

  def count_small(numbers):
      total = 0
      for n in numbers:
    if n < 10:
        total = total + 1
      return total

  lost = [4, 8, 15, 16, 23, 42]
  small = count_small(lost)
  print small
```

## Function Imports
```python
  import math
  print math.sqrt(25)
```

Nice work! Now Python knows how to take the square root of a number.

However, we only really needed the sqrt function, and it can be frustrating
to have to keep typing `math.sqrt()`.

It's possible to import only certain variables or functions from a given module.
Pulling in just a single function from a module is called a function import, and
it's done with the from keyword:

```python
  from module import function
```

Now you can just type `sqrt()` to get the square root of a number—no more `math.sqrt()`!


## List all functions in a module

```python
  import math            # Imports the math module
  everything = dir(math) # Sets everything to a list of things from math
  print everything       # Prints 'em all!
```

## Universal Import


What if we still want all of the variables and functions in a module but don't want to
have to constantly `type math.`?

Universal import can handle this for you. The syntax for this is:

```python
  from module import *

  Ex:

  from math import *
  print sqrt(25)
 ```

## Don't use Universal Imports


Here Be Dragons

Universal imports may look great on the surface, but they're not a
good idea for one very important reason:
they fill your program with a ton of variable and function names
without the safety of those names still being associated with the
module(s) they came from.

If you have a function of your very own named sqrt and you import math,
your function is safe: there is your `sqrt` and there is `math.sqrt`.

If you do from `math import *`, however, you have a problem: namely,
two different functions with the exact same name.

Even if your own definitions don't directly conflict with names from
imported modules, if you `import *` from several modules at once,
you won't be able to figure out which variable or function came
from where.

For these reasons, it's best to stick with either `import module` and
type `module.name` or just `import` specific variables and functions
from various modules as needed.


## Passing multiple arguments

```python
  def biggest_number(*args):
    print max(args)
    return max(args)

  def smallest_number(*args):
    print min(args)
    return min(args)

  def distance_from_zero(arg):
    print abs(arg)
    return abs(arg)


  biggest_number(-10, -5, 5, 10)
  smallest_number(-10, -5, 5, 10)
  distance_from_zero(-10)
```
### Example
```python
  def shut_down(s):
    if s.lower() == "yes":
      return "Shutting Down"
    elif s.lower() == "no":
      return "Shutdown aborted"
    else:
      return "Sorry"

  print shut_down("yEs")
  print shut_down("nO")
  print shut_down("bleh")
```

## Anonymous Functions / lambda Operator

One of the more powerful aspects of Python is that it allows for a style
of programming called functional programming, which means that you're
allowed to pass functions around just as if they were variables or values.

The lambda operator or lambda function is a way to create small anonymous
functions, i.e. functions without a name. These functions are throw-away
functions, i.e. they are just needed where they have been created.

Lambda functions are mainly used in combination with the functions
filter(), map() and reduce().

```python
  # lambda
  # lambda argument_list: expression

  lambda x: x % 3 == 0

  # Is the same as

  def by_three(x):
      return x % 3 == 0
```

Only we don't need to actually give the function a name; it does its work
and returns a value without one. That's why the function the lambda
creates is an anonymous function.


### filter

The function `filter(function, list)` offers an elegant way to filter out
all the elements of a list, for which the function function returns True.

The function `filter(f,l)` needs a function `f` as its first argument.
`f` returns a Boolean value, i.e. either `True` or `False`.
This function will be applied to every element of the list `l`.
Only if `f` returns `True` will the element of the list be included in
the result list

#### Example One
```python
  fib = [0,1,1,2,3,5,8,13,21,34,55]
  result = filter(lambda x: x % 2, fib)
  print result
  # => [1, 1, 3, 5, 13, 21, 55]
```

#### Example Two
```python
  my_list = range(16)
  print filter(lambda x: x % 3 == 0, my_list)
  # => [0, 3, 6, 9, 12, 15]
```

#### Example Three
```python
  languages = ["HTML", "JavaScript", "Python", "Ruby"]
  print filter(lambda x: 'Python' in x, languages)
  # => ['Python']
``` 

#### Example Four
```python
  lst = ['a', 'ab', 'abc', 'bac']
  filter(lambda k: 'ab' in k, lst)
  # => ['ab', 'abc']
```

#### Example Five
```python
  cubes = [x**3 for x in range(1, 11)]    # List Comprehension
  filter(lambda x: x % 3 == 0, cubes)
  # => [27, 216, 729]
```

#### Example Six
```python
  squares = [x**2 for x in range(1,11)]
  print filter(lambda x: x > 30 and x < 70, squares)
  # => [36, 49, 64]
```

#### Example Seven
```python
  garbled = "IXXX aXXmX aXXXnXoXXXXXtXhXeXXXXrX sXXXXeXcXXXrXeXt mXXeXsXXXsXaXXXXXXgXeX!XX"
  message = filter(lambda x: 'X' not in x, garbled)
  print message
  # => "I am another secret message!"
```

# Lists


Lists are a datatype you can use to store a collection of different pieces of information as a
sequence under a single variable name. (Datatypes you've already learned about include strings,
numbers, and booleans.)

```python
  zoo_animals = ["pangolin", "cassowary", "sloth", "Optimus"];
  if len(zoo_animals) > 3:
    print "The first animal at the zoo is the " + zoo_animals[0]
    print "The second animal at the zoo is the " + zoo_animals[1]
    print "The third animal at the zoo is the " + zoo_animals[2]
    print "The fourth animal at the zoo is the " + zoo_animals[3]
```

## Building Lists / List Comprehension

Let's say you wanted to build a list of the numbers from 0 to 50
(inclusive). We could do this pretty easily:

```python
  my_list = range(51)
```

But what if we wanted to generate a list according to some logic—for
example, a list of all the even numbers from 0 to 50?


Python's answer to this is the list comprehension. List comprehensions
are a powerful way to generate lists using the keywords


## for/in & if
```python
  evens_to_50 = [i for i in range(51) if i % 2 == 0]
  print evens_to_50

  # This will create a new_list populated by the numbers one to five.
  new_list = [x for x in range(1,6)]
  # => [1, 2, 3, 4, 5]

  # If you want those numbers doubled, you could use:
  doubles = [x*2 for x in range(1,6)]
  # => [2, 4, 6, 8, 10]

  # And if you only wanted the doubled numbers that are evenly divisible by three:
  doubles_by_3 = [x*2 for x in range(1,6) if (x*2)%3 == 0]
  # => [6]

  # Even Squares
  even_squares = [i*i for i in range(1,12) if i*i % 2 == 0]

  c = ['C' for x in range(5) if x < 3]
  print c
  # => ['C', 'C', 'C'].

  cubes_by_four = [x ** 3 for x in range(1, 11) if x ** 3 % 4 == 0]
  print cubes_by_four
  # => [8, 64, 216, 512, 1000]

    threes_and_fives = [x for x in range(1,16) if x % 3 == 0 or x % 5 == 0]
    print threes_and_fives
    # => [3, 5, 6, 9, 10, 12, 15]
```
## List Append

	A list doesn't have to have a fixed length. You can add items to the end of a
	list any time you like!

```python
  letters = ['a', 'b', 'c']
  letters.append('d')
  print len(letters)
  print letters
```

## List remove

We can remove an item from the list.

```python
  letters.remove('a')
```

## List pop

`n.pop(index)` will remove the item at index from the list and return it to you:

```python
  n = [1, 3, 5]
  n.pop(1)
  # Returns 3 (the item at index 1)
  print n
  # prints [1, 5]
```

## List remove

`n.remove(item)` will remove the actual item if it finds it:

```python
  n.remove(1)
  # Removes 1 from the list,
  # NOT the item at index 1
  print n
  # prints [3, 5]
```

## List delete

`del(n[1])` is like `.pop` in that it will remove the item at the given
index, but it won't return it:

```python
  del(n[1])
  # Doesn't return anything
  print n
  # prints [1, 5]
```

## List concatenate
```python
  a = [1, 2, 3]
  b = [4, 5, 6]
  print a + b
  # prints [1, 2, 3, 4, 5, 6]
```

The example above is just a reminder of how to concatenate two lists.

```python
  m = [1, 2, 3]
  n = [4, 5, 6]

  # Add your code here!
  def join_lists(x, y):
      return x + y

  print join_lists(m, n)
  # You want this to print [1, 2, 3, 4, 5, 6]
```

## List Reverse

A negative stride progresses through the list from right to left.

### Example One
```python
  letters = ['A', 'B', 'C', 'D', 'E']
  print letters[::-1]
  # => ['E', 'D', 'C', 'B', 'A']
```

### Example Two
```python
  my_list = range(1, 11)
  backwards = my_list[::-1]
  print backwards
  # => [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
```

## List Slicing

Access a portion of a list.

List slicing allows us to access elements of a list in a concise manner.
The syntax looks like this:

```python
  [start:end:stride]
```

Where start describes where the slice starts (inclusive), end is where
it ends (exclusive), and stride describes the space between items in
the sliced list. For example, a stride of 2 would select every other
item from the original list to place in the sliced list.

Stride Length

A positive stride length traverses the list from left to right,
and a negative one traverses the list from right to left.

Further, a stride length of 1 traverses the list "by ones," a stride
length of 2 traverses the list "by twos," and so on.


### Example One
```python
  l = [i ** 2 for i in range(1, 11)]
  # Should be [1, 4, 9, 16, 25, 36, 49, 64, 81, 100]

  print l[2:9:2]
  # => [9, 25, 49, 81]
```

### Example Two
```python
  letters = ['a', 'b', 'c', 'd', 'e']
  slice = letters[1:3]
  print slice
  print letters
```

### Example Three
```python
  to_21 = range(1,22)
  odds = to_21[::2]
  middle_third = to_21[7:14:1]

  print odds
  print middle_third

  # => [1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21]
  # => [8, 9, 10, 11, 12, 13, 14]
```

### Example Four
```python
  suitcase = ["sunglasses", "hat", "passport", "laptop", "suit", "shoes"]

  first  = suitcase[0:2]  # The first and second items (index zero and one)
  middle = suitcase[2:4]  # Third and fourth items (index two and three)
  last   = suitcase[4:6]  # The last two items (index four and five)
```

### Example Five
```python
  animals = "catdogfrog"
  cat  = animals[:3]   # The first three characters of animals
  dog  = animals[3:6]  # The fourth through sixth characters
  frog = animals[6:]   # From the seventh character to the end
```

## Omitting Indices

If you don't pass a particular index to the list slice,
Python will pick a default.

```python
  to_five = ['A', 'B', 'C', 'D', 'E']

  print to_five[3:]
  # prints ['D', 'E']

  print to_five[:2]
  # prints ['A', 'B']

  print to_five[::2]
  # print ['A', 'C', 'E']

  to_one_hundred = range(101)
  backwards_by_tens = to_one_hundred[::-10]
  print backwards_by_tens
  # => [100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0]

  garbled = "!XeXgXaXsXsXeXmX XtXeXrXcXeXsX XeXhXtX XmXaX XI"
  message = garbled[::-2]
  print message
  # => 'I am the secret message!'
```

## List Insertion & Indexing


Search for an item in a list

```python
  animals = ["ant", "bat", "cat"]
  print animals.index("bat")
```

We can also insert items into a list.

```python
  animals.insert(1, "dog")
  print animals
```

We insert `dog` at `index 1`, which moves everything down by `1`
animals will be `["ant", "dog", "bat", "cat"]`

## Looping in lists
```python
  for variable in list_name:
  # Do stuff!
```

A variable name follows the for keyword; it will be assigned the value
of each list item in turn.

Then in list_name designates list_name as the list the loop will work on.


### Example
```python
  my_list = [1,9,3,8,5,7]

  for number in my_list:
    # Your code here
    print 2 * number

  names = ["Adam","Alex","Mariah","Martine","Columbus"]

  for i in names:
    print i
```

### Method 1 - for item in list
```python
  for item in list:
      print item
```
### Method 2 - iterate through indexes
```python
  for i in range(len(list)):
      print list[i]
```

Method 1 is useful to loop through the list, but it's not possible
to modify the list this way.

Method 2 uses indexes to loop through the list, making it possible
to also modify the list if needed.


## List of Lists

Single list that contains multiple lists and how to use them in a function


### Example One
```python
  list_of_lists = [[1,2,3], [4,5,6]]

  for lst in list_of_lists:
      for item in lst:
    print item
```
### Example Two
```python
  n = [[1, 2, 3], [4, 5, 6, 7, 8, 9]]
  # Add your function here
  def flatten(lists):
    results = []
    for numbers in lists:
  for i in numbers:
    results.append(i)
    return results

  print flatten(n)

  # Creates a list containing 5 lists, each of 8 items, all set to 0
  w, h = 8, 5
  Matrix = [[0 for x in range(w)] for y in range(h)]
```

## Printing Pretty

We're getting pretty close to a playable board, but wouldn't it be nice to get
rid of those quote marks and commas?

```python
  letters = ['a', 'b', 'c', 'd']
  print " ".join(letters)
  print "---".join(letters)
```

In the example above, we create a list called letters.
Then, we print `a b c d`.

The `.join` method uses the string to combine the items in the list.

Finally, we print `a---b---c---d`.
We are calling the `.join` function on the `---` string.


### Example
```python
  board = []
  # Creates a list containing 5 lists, each of 5 items, all set to 0
  w, h = 5, 5
  board = [['O' for x in range(w)] for y in range(h)]

  def print_board(board):
      for lst in board:
    print " ".join(lst)

  print_board(board)
```

## Sorting the List


Sorting can happen on numbers and strings. Others I do not know yet.

```python
  start_list = [5, 3, 1, 2, 4]
  square_list = []

  # Your code here!

  for i in start_list:
    square_list.append(i ** 2)

  square_list.sort()
  print square_list
```

## Range in lists

```python
  n = [3, 5, 7]

  def double_list(x):
      for i in range(0, len(x)):
    x[i] = x[i] * 2
      # Don't forget to return your new list!
      return x

  print double_list(n)
```

## Passing a range into a function

Okay! Range time. The Python `range()` function is just a shortcut for generating a
list, so you can use ranges in all the same places you can use lists.

```python
  range(6) # => [0,1,2,3,4,5]
  range(1,6) # => [1,2,3,4,5]
  range(1,6,3) # => [1,4]
```

The range function has three different versions:
```python
  range(stop)
  range(start, stop)
  range(start, stop, step)
```

In all cases, the `range()` function returns a list of numbers from start up to
(but not including) stop. Each item increases by step.

If omitted, start defaults to zero and step defaults to one.


### Example One

```python
  def my_function(x):
  for i in range(0, len(x)):
  x[i] = x[i] * 2
  return x

  print my_function(range(2)) # Add your range between the parentheses!
```

### Example Two

```python
  n = ["Michael", "Lieberman"]
  # Add your function here

  def join_strings(words):
      result = ""
      for i in range(0, len(words)):
    result = result + words[i]
      return result

  print join_strings(n)
```
## Enumerate

`enumerate` works by supplying a corresponding index to each element in the list
that you pass it. Each time you go through the loop, index will be one greater,
and item will be the next item in the sequence. It's very similar to using a
normal for loop with a list, except this gives us an easy way to count how many
items we've seen so far.

`enumerate` is a built-in function of Python. It’s usefulness can not be summarized
in a single line. Yet most of the newcomers and even some advanced programmers are
unaware of it. It allows us to loop over something and have an automatic counter.

```python
  choices = ['pizza', 'pasta', 'salad', 'nachos']

  print 'Your choices are:'
  for index, item in enumerate(choices):
      print index, item

  for counter, value in enumerate(some_list):
    print(counter, value)

  my_list = ['apple', 'banana', 'grapes', 'pear']
  for c, value in enumerate(my_list, 1):
      print(c, value)

  # Output:
  # 1 apple
  # 2 banana
  # 3 grapes
  # 4 pear
```
## Iterating Multiple Lists


Multiple lists

It's also common to need to iterate over two lists at once. This is where
the built-in `zip` function comes in handy.

`zip` will create pairs of elements when passed two lists, and will stop at
the end of the shorter list.

`zip` can handle three or more lists as well!

```python
  list_a = [3, 9, 17, 15, 19]
  list_b = [2, 4, 8, 10, 30, 40, 50, 60, 70, 80, 90]

  for a, b in zip(list_a, list_b):
      # Add your code here!
      if a > b:
          print a
      else:
          print b
```

# Dictionary


A `dictionary` is similar to a `list`, but you access values by looking up a key instead
of an index. A key can be any string or number. Dictionaries are enclosed in
*curly braces*, like so:

```python
	d = {'key1' : 1, 'key2' : 2, 'key3' : 3}
```

This is a dictionary called d with three key-value pairs. The key `key1` points to the
`value 1`, `key2` to `2`, and so on.

Dictionaries are great for things like phone books (pairing a name with a phone number),
login pages (pairing an e-mail address with a username), and more!


## Assigning a dictionary with three key-value pairs to residents

```python
  residents = {'Puffin' : 104, 'Sloth' : 105, 'Burmese Python' : 106}

  print residents['Puffin'] # Prints Puffin's room number

  # Your code here!
  print residents['Sloth']
  print residents['Burmese Python']
```

## Adding New entries

An empty pair of curly braces `{}` is an empty dictionary, just like an empty pair of `[]`
is an empty list.

```python
  menu = {} # Empty dictionary
  menu['Chicken Alfredo'] = 14.50 # Adding new key-value pair
  print menu['Chicken Alfredo']

  # Your code here: Add some dish-price pairs to menu!
  menu['Letuce Sandwich'] = 3.50
  menu['Mango Juice'] = 12.70
  menu['Sweet Corn + Chat Masala'] = 1.80

  print "There are " + str(len(menu)) + " items on the menu."
  print menu
```

## Add & Delete

Because dictionaries are mutable, they can be changed in many ways. Items can be removed
from a dictionary with the del command:

```python
  del dict_name[key_name]
```


will remove the key `key_name` and its associated value from the dictionary.
A new value can be associated with a key by assigning a value to the key, like so:

```python
  dict_name[key] = new_value
```
## Retrieve key and value

### Method One
```python
  d = {'a': 'apple', 'b': 'berry', 'c': 'cherry'}

  for key in d:
      # Your code here!
      print key, d[key]
```

### Method Two
```python
  knights = {'gallahad': 'the pure', 'robin': 'the brave'}
  for k, v in knights.iteritems():
    print k, v

  ''' Prints the key and the value '''
  gallahad the pure
  robin the brave
```

### Example
```python
  >>> D = {'a': 1, 'b': 2, 'c': 3}
  >>> for key in D:
    print(key, '=>', D[key]) # Use dict keys iterator and index

  a => 1
  c => 3
  b => 2

  >>> list(D.items())
  [('a', 1), ('c', 3), ('b', 2)]
    >>> for (key, value) in D.items():
    print(key, '=>', value)		# Iterate over both keys and values

  a => 1
  c => 3
  b => 2
```

## Lists and Dictionaries
```python
  inventory = {
  'gold' : 500,
  'pouch' : ['flint', 'twine', 'gemstone'], # Assigned a new list to 'pouch' key
  'backpack' : ['xylophone','dagger', 'bedroll','bread loaf']
  }

  # Adding a key 'burlap bag' and assigning a list to it
  inventory['burlap bag'] = ['apple', 'small ruby', 'three-toed sloth']

  # Sorting the list found under the key 'pouch'
  inventory['pouch'].sort()

  # Your code here
  inventory['pocket'] = ['seashell', 'strange berry', 'lint']
  inventory['backpack'].sort()

  inventory['backpack'].remove('dagger')
  inventory['gold'] = inventory['gold'] + 50

  print inventory['gold']
  print inventory['pocket']
  print inventory['pouch']
  print inventory['backpack']
```

### Looping in dictionaries
```python
  prices = {
      "banana" : 4,
      "apple"  : 2,
      "orange" : 1.5,
      "pear"   : 3,
  }
  stock = {
      "banana" : 6,
      "apple"  : 0,
      "orange" : 32,
      "pear"   : 15,
  }

  for key in prices:
      print key
      print "price: %s" % prices[key]
      print "stock: %s" % stock[key]

  total = 0
  for i in prices:
      total = total + prices[i] * stock[i]
    print total
```

## More Looping techniques


To loop over two or more sequences at the same time, the
entries can be paired with the `zip()` function.

```python
  questions = ['name', 'quest', 'favorite color']
  answers = ['lancelot', 'the holy grail', 'blue']
  for q, a in zip(questions, answers):
    print 'What is your {0}?  It is {1}.'.format(q, a)
```

## List of Dictionaries

Iterating over a list of dictionaries

```python
  lloyd = {
      "name": "Lloyd",
      "homework": [90.0,97.0, 75.0, 92.0],
      "quizzes": [88.0, 40.0, 94.0],
      "tests": [75.0, 90.0]
  }
  alice = {
      "name": "Alice",
      "homework": [100.0, 92.0, 98.0, 100.0],
      "quizzes": [82.0, 83.0, 91.0],
      "tests": [89.0, 97.0]
  }
  tyler = {
      "name": "Tyler",
      "homework": [0.0, 87.0, 75.0, 22.0],
      "quizzes": [0.0, 75.0, 78.0],
      "tests": [100.0, 100.0]
  }

  students = [lloyd, alice, tyler]

  for n in [0,1,2]:
      for k, v in students[n].iteritems():
    print k, v

    #OR

  for n in range(len(students)):
      for k, v in students[n].iteritems():
    print k, v
```

# Classes

You can think of an object as a single data structure that contains data as
well as functions; functions of objects are called methods

Python is an object-oriented programming language, which means it
manipulates programming constructs called objects.

```python
  len("Eric")
```

Python is checking to see whether the string object you passed it has a
length, and if it does, it returns the value associated with that attribute

```python
  my_dict.items()
```
Python checks to see if `my_dict` has an `items()` method (which all dictionaries
have) and executes that method if it finds it.

But what makes `Eric` a string and `my_dict` a dictionary? The fact that
they're instances of the `str` and `dict` classes, respectively. A `class` is
just a way of organizing and producing objects with similar attributes
and methods


## Example One


Check out the code in the editor to the right. We've defined our own
class, Fruit, and created a lemon instance

```python
  class Fruit(object):
      """A class that makes various tasty fruits."""
      def __init__(self, name, color, flavor, poisonous):
          self.name = name
          self.color = color
          self.flavor = flavor
          self.poisonous = poisonous

      def description(self):
          print "I'm a %s %s and I taste %s." % (self.color, self.name, self.flavor)

      def is_edible(self):
          if not self.poisonous:
              print "Yep! I'm edible."
          else:
              print "Don't eat me! I am super poisonous."

  lemon = Fruit("lemon", "yellow", "sour", False)

  lemon.description()
  lemon.is_edible()
```

## Errors

```python
  # local variable 's' referenced before assignment

  def digit_sum(n):
    #s = 0
    while(n != 0):
        d = n % 10
        n = n / 10
        s = s + d
    return s
```
