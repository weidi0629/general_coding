Usually, a Python dictionary throws a KeyError if you try to get an item with a key that is not currently in the dictionary. The defaultdict in contrast will simply create any items that you try to access (provided of course they do not exist yet). To create such a "default" item, it calls the function object that you pass to the constructor (more precisely, it's an arbitrary "callable" object, which includes function and type objects). For the first example, default items are created using int(), which will return the integer object 0. For the second example, default items are created using list(), which returns a new empty list object

s = 'mississippi'
d = defaultdict(int)
for k in s:
  d[k] += 1

d.items()
[('i', 4), ('p', 2), ('s', 4), ('m', 1)]


s = [('yellow', 1), ('blue', 2), ('yellow', 3), ('blue', 4), ('red', 1)]
d = defaultdict(list)
for k, v in s:
  d[k].append(v)

d.items()
[('blue', [2, 4]), ('red', [1]), ('yellow', [1, 3])]
