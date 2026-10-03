Repeating my advice from the previous chapter, whenever you learn a new feature, you should make errors on purpose to see what goes wrong.

We’ve seen that n = 17 is legal. What about 17 = n?

How about x = y = 1?

In some languages every statement ends with a semi-colon (;). What happens if you put a semi-colon at the end of a Python statement?

What if you put a period at the end of a statement?

What happens if you spell the name of a module wrong and try to import maath?




Practice using the Python interpreter as a calculator:

Part 1. The volume of a sphere with radius 
 is 
 
. What is the volume of a sphere with radius 5? Start with a variable named radius and then assign the result to a variable named volume. Display the result. Add comments to indicate that radius is in centimeters and volume in cubic centimeters.

Part 2. A rule of trigonometry says that for any value of 
, 
. Let’s see if it’s true for a specific value of 
 like 42.

Create a variable named x with this value. Then use math.cos and math.sin to compute the sine and cosine of 
, and the sum of their squared.

The result should be close to 1. It might not be exactly 1 because floating-point arithmetic is not exact—it is only approximately correct.

Part 3. In addition to pi, the other variable defined in the math module is e, which represents the base of the natural logarithm, written in math notation as 
. If you are not familiar with this value, ask a virtual assistant “What is math.e?” Now let’s compute 
 three ways:

Use math.e and the exponentiation operator (**).

Use math.pow to raise math.e to the power 2.

Use math.exp, which takes as an argument a value, 
, and computes 
.

You might notice that the last result is slightly different from the other two. See if you can find out which is correct.