### Variables
A variable is a name that refer to a value. To create a variable, we can write a assignment satement like this
```
n = 17
```
An assignment statement has three parts: the name of the variable on the left, the equals operator, =, and an expression on the right. In this example, the expression is an integer. In the following example, the expression is a floating-point number.
```
pi = 3.141592653589793
```
And in the following example, the expression is a string

```
message = 'And now for something completely different'
```
When you run an assignment statement, there is no output. Python creates the variable and gives it a value, but the assignment statement has no visible effect. However, after creating a variable, you can use it as an expression. So we can display the value of message like this:
```
message

'Some message ..'
```

You can also use a variable as part of an expression with arithmetic operators.

```
n + 25
42  # n=17
```

```
2 * pi
6.283185307179586
```

And you can use a variable when you call a function
```
round(pi)
3
len(message)
42
```

### State diagrams
A common way to representvariables on paper 
<img src="../assets/state_diagram.png" width=400>

### Variable names
Variable name can be as long as you like. They can contain both letters and numbers, but they can't begin with a number. It is legal to use uppercase letters, but it is conventional to use only lower case for variable names.
The only punctuation that can appear in a variable name is the underscore character, _. It is often used in names with multiple words, such as your_name or airspeed_of_unladen_swallow.

If you give a variable an illegal name, you get a syntax error. The name million! is illegal because it contains punctuation.
```
million! = 1000000
```

```
  Cell In[12], line 1
    million! = 1000000
           ^
SyntaxError: invalid syntax
```
76trombones is illegal because it starts with a number.
```
  Cell In[13], line 1
    76trombones = 'big parade'
     ^
SyntaxError: invalid decimal literal
```
class is also illegal, but it may not be obvious why.
```
class = 'Self-Defence Against Fresh Fruit'
  Cell In[14], line 1
    class = 'Self-Defence Against Fresh Fruit'
          ^
SyntaxError: invalid syntax
```
It turns out that class is a keyword, which is a special word used to specify the structure of a program. Keywords can’t be used as variable names.

Here’s a complete list of Python’s keywords:
```
False      await      else       import     pass
None       break      except     in         raise
True       class      finally    is         return
and        continue   for        lambda     try
as         def        from       nonlocal   while
assert     del        global     not        with
async      elif       if         or         yield
```

### The import statement
In order to use some Python features, you have to import them. For example, the following statement imports the math module
```
import math
```
A module is a collection of variables and functions. The math module provides a variable called pi that contains the value of the mathematical constant denoted 
. We can display its value like this.
```
math.pi #3.141592653589793
```
To use a variable in a module, you have to use the dot operator (.) between the name of the module and the name of the variable.
The math module also contains functions. For example, sqrt computes square roots.
```
math.sqrt(25)
5
```