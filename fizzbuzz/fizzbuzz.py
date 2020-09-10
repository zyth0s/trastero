# coding: utf-8
for i in range(1,101):
    print(i,end='')
    if ((i % 3) == 0) and ((i % 5) == 0):
        print(" FizzBuzz",end='')
    elif (i % 3) == 0:
        print(" Fizz",end='')
    elif (i % 5) == 0:
        print(" Buzz",end='')
    print()
   
