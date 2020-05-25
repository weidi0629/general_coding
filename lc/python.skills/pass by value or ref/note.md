There are essentially three kinds of 'function calls':

Pass by value
Pass by reference
Pass by object reference
Python is a PASS-BY-OBJECT-REFERENCE programming language.

Firstly, it is important to understand that a variable, and the value of the variable (the object) are two seperate things. The variable 'points to' the object. The variable is not the object. Again:

THE VARIABLE IS NOT THE OBJECT

Example: in the following line of code:

>>> x = []
[ ] is the empty list, x is a variable that points to the empty list, but x itself is not the empty list

Consider the variable (x, in the above case) as a box, and 'the value' of the variable ( [ ] ) as the object inside the box.

PASS BY OBJECT REFERENCE (Case in python):

Here, "Object references are passed by value."

def append_one(li):
    li.append(1)
x = [0]
append_one(x)
print x
Here, the statement x = [0] makes a variable x (box) that points towards the object [0]

On the function being called, a new box li is created. The contents of li is the SAME as the contents of box x. Both the boxes contain the same object. That is, both the variables point to the same object in memory. Hence, any change to the object pointed at by li will also be reflected by the object pointed at by x.

In conclusion, the output of the above program will be:

[0, 1]

Note:

If the variable li is reassigned in the function, then li will point to a seperate object in memory. x however, will continue pointing to the same object in memory it was pointing to earlier.

Example:

def append_one(li):
    li = [0, 1]
x = [0]
append_one(x)
print x
The output of the program will be:

[0]

PASS BY REFERENCE:

The box from the calling function is passed on to the called function. Implicitly, the contents of the box (the value of the variable) is passed on to the called function. Hence, any change to the contents of the box in the called function will be reflected in the calling function.

PASS BY VALUE:

A new box is created in the called function, and copies of contents of the box from the calling function is stored into the new boxes.

Hope this helps.
