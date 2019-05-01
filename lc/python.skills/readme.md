python * **  用处 
* 告诉程序进来的当做list处理
** 进来当做dic处理 

#This will return sum of all the arguments you provide.
def sum_all(first, *others):
    return first + sum(others)
print sum_all(0, 1, 2, 3, 4)
#sum = 0 and prints 10

#Same sum function as above.
def sum_all(sum, **others):
    for key in others:
        sum += others[key]
    return sum
print sum_all(0, one=1, two=2)
#prints 3, one and two will become keys for the argument others.
