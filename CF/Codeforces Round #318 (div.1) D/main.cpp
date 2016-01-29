# from Tools.scripts.treesync import raw_input
#
# name=raw_input("input your name")
# print(name)


# print("Hello World!")
# a='Hello World!'
# print(a)


# a=str("10000000")
# print(a)

# print(repr(100000))

# temp=42
# print("one is " + str(temp))

# name=input("What's your name?")
# print("Hello,"+name)


# print("My name is Devin,\
# I like code,\
# and i like make friends.\
# ")


# print(r"C:\\users\\crazyacking\\Desktop")

# print(u"Hello World!")

# from Tools.scripts.treesync import raw_input
#
# name=input("hehe")
# print(name)
#
# name=raw_input("hebe")
# print(name)


# edward=['Edward Gumby',42]
# john=['John Smith',50]
# database=[edward,john]
# print(database)
# print(edward[0])
# print(edward[-1])
#
#
# print("Hello"[1])


# four=input("")[3]
# print(four)





#####################################
# month_en=[
# 	"January","February","March","April",
# 	"May","June","July","August",
# 	"September","October","November","December"]
#
# day_en=['st','nd','rd']+17*['th']+['st','nd','rd']+7*['th']+['st']
#
#
# year=int(input("Year"))
# month=int(input("Month"))
# day=int(input("Day"))
#
# day_name=repr(day)+day_en[int(day-1)]
#
# print(month_en[month-1]+" "+day_name+","+repr(year))


######################################

# num= '123456789'
# print(num[1:3])		#23
# print(num[5:-2])	#67
# print(num[-3:])		#789
# print(num[:3])		#123
# print(num[:])
# print(num[0:10:2])

# num1=[1,2,3,4]
# num2=[5,6,7,8]
# num3=num1+num2
# print(num3)

# sequence=[None]*10
# print(sequence)



# content='rw'
# print('r' in content)
# print('x' in content)


# content='abcdefg'
# print('def' in content)	#True
# print('abs' in content)	#False


# database=[
# 	['albert','1235'],
# 	['dilbert','2323'],
# 	['smith','1235'],
# 	['joins','4584']
# ]
#
# username=input("user name:")
# pin=input("PIN　CODE:")
#
# if[username,pin] in database:
# 	print("Yes")

# num=[2,3,4,5,6,7]
# length=len(num)
# print(length)
# maxnum=max(num)
# print(maxnum)
# minnum=min(num)
# print(minnum)

# li=list("Hello World!")
# print(li)
#
# str=''.join(li)
# print(str)

# num=[1,2,3]
# print(num)
#
# num[2]=0
# print(num)
#
# del(num[2])
# print(num)


# name=list('Perl')
# print(name)
#
# name[2:]=list('ar')
# print(name)


# name=list('Perl')
# name[1:]=list('ython')
# print(name)

# num=[1,5]
# num[1:1]=[2,3,4]
# print(num)


# num=[1,2,3,4,5]
# num[1:4]=[]
# print(num)


# num=[1,2,3]
# num.append(4)
# print(num)


# word=['to','be','ro','not','to','be','be']
# n=word.count('to')
# print(n)



# a=[1,2,3]
# b=[4,5,6]
# a.extend(b)
# print(a)


# knights=['we','are','the','knights','who','say','ni','who']
# idx=knights.index('who')
# print(idx)


# num=[1,2,3,5,6,7]
# num.insert(3,'four')
# num[3:3]=['four']
# print(num)


# num=[1,2,3]
# x=num.pop()
# print(x)
# print(num)

# x=['to','be','or','not','to','be']
# x.remove('be')
# print(x)



# x=[2,6,3,4]
# x.sort()
# print(x)

# x=[2,6,3,4]
# y=sorted(x)
# print(x)
# print(y)

# x=['aardvark','abalone','acme','add','aerate']
# x.sort(key=len)
# print(x)

# x=(1,2,3)
# print(x)

# string='Hello'
# tupl=tuple(string)
# print(tupl)

# string="Hello,%s. todday is %s"
# values=("crazyacking","Friday")
# print(string%values)


# format="Pi with three decimals:%.3f"
# from math import pi
# print( format % pi)


# from string import Template
# s=Template("$x, nice $x!")
# print(s.substitute(x='girl'))

# from string import Template
# s=Template("It's ${x}ful")
# print(s.substitute(x="wonder"))

# string=" %s plus %s equal %s" % (1,1,2)
# print(string)


# print("Price of eggs: $%d" %42)

# print("Hexadeciaml price of eggs:%x" %42)


# from math import pi
# print("Pi is %.3f" %pi)

# from math import pi
# print("%10.3f" %pi)

# from math import pi
# print("%-10.2f" % pi)


# print("%+d"%10+'\n' + "%+d"%-10)


# width=int(input('Please enter width:'))
# price_width=10
# item_width=width-price_width
# header_format='%-*s%*s'
# format		 ='%-*s%*.2f'
# print("="*width)
# print(header_format%(item_width,'Item',price_width,'Price'))
# print('-'*width)
# print(format%(item_width,'Apples',price_width,0.4))
# print(format%(item_width,'Pears',price_width,0.5))
# print(format%(item_width,'Cantaloupes',price_width,1.93))
# print(format%(item_width,'Dried Apricots(16 0z.)',price_width,9))
# print(format%(item_width,'Prunes(4 1bs.',price_width,12))
# print('='*width)




# str='With a moo-moo here,and a moo-moo there'
# print(str.find('moo'))

# str='With a moo-moo here,and a moo-moo there'
# print(str.find('moo',20,25))

# seq='My name is Devin'
# a=seq.split()
# print(a)
# b=''.join(seq)
# print(b)
# c='+'.join(seq)
# print(c)


# str="123ABCdef"
# a=str.lower()
# print(a)
# b=str.upper()
# print(b)

# str="that's all,folks"
# a=str.title()
# print(a)
# b=str.capitalize()
# print(b)

# str='This is a test'
# a=str.replace('is','eez')
# print(a)

# str='         Hello World!        '
# a=str.strip()
# print(a)

# phonebook={"Alice":"123","Beth":"234","Cecil":"345"}
# print(phonebook["Alice"])
# print(phonebook["Beth"])
# print(phonebook["Cecil"])


# items=[("name","Gumby"),("age",42)]
# d=dict(items)
# print(d)
# print(d['name'])
# print(d["age"])
# del d["name"]

#简单的key/value数据库
# people={
# 	"Alice":
# 		{
# 			"phone":"123",
# 			"add":"Foo dirve 23"
# 		},
# 	"Beth":
# 		{
# 			"phone":"234",
# 			"add":"Bar street 42"
# 		},
# 	"Cecil":
# 		{
# 			"phone":"345",
# 			"add":"Baz avenue 90"
# 		}
# }
#
# labels={
# 	"phone":"phone number",
# 	"add":"address"
# }
#
#
# name=input("name:")
# request=input("Please input Phone number(p) or address(a)?")
#
# if(request=='p'):key='phone'
# elif(request=='a'):key='add'
# if(name in people):
# 	print("%s's %s is %s."% (name,labels[key],people[name][key]))

# phonebook={"Alice":"123","Beth":"234","Cecil":"345"}
# print("Cecil's phone is %(Cecil)s." %phonebook)


# template=\
# """<html>
# <head><title>%(title)s</title></head>
# <body>
# <h1>%(title)s</h1>
# <p>%(text)s</p>
# </body>
# """
#
# data={"title":"My Home Page","text":"Welcome to my home page!"}
# print(template%data)


# phonebook={"Alice":"123","Beth":"234","Cecil":["345","456","567"]}
# y=phonebook.copy()
# print(y)
# y["Cecil"].remove("345")
# print(y)
# print(phonebook)

# from copy import deepcopy
# phonebook={"Alice":"123","Beth":"234","Cecil":["345","456","567"]}
# y=deepcopy(phonebook)
# print(y)
# y["Cecil"].remove("345")
# print(y)
# print(phonebook)

# d={}.fromkeys(['name','age'])
# d=dict.fromkeys(['name','age'])
# print(d)

# d=dict.fromkeys(['name','age'],'unknown')
# print(d)


# phonebook={"Alice":"123","Beth":"234","Cecil":"345"}
# print(phonebook["Devin"])

# phonebook={"Alice":"123","Beth":"234","Cecil":"345"}
# print(phonebook.get("Devin","N/A"))

# d={"a":1,"b":2,"c":3,"d":4}
# while(len(d)>0):
# 	v=d.popitem()
# 	print(v)

# d={"Alice":"123","Beth":"234","Cecil":"345"}
# print(d.setdefault("Devin","495"))
# print(d)

# d={"Alice":"123","Beth":"234","Cecil":"345","Devin":"123"}
# print(d.keys())
# print(d.values())

# int = 1
# double =3
# if(int!=double):
# 	print("Different")

# x=y=[1,2,3]
# z=[1,2,3]
# print(x==y)
# print(x==z)
# print(x is y)
# print(x is z)


# age=10
# assert 0<age<100
# print("OK")
# age=-1
# assert 0<age<100,"age Must between 0 to 100"

# output
# Traceback (most recent call last):
#   File "H:/Code_Fantasy/Python/PythonLearn/main.py", line 441, in <module>
#     assert 0<age<100,"age Must between 0 to 100"
# AssertionError: age Must between 0 to 100


# x=1
# while(x<=100):
# 	print(x)
# 	x+=1



# words=["this","is","an","ex","parrot"]
# for word in words:
# 	print(word)

# a=range(0,10)
# print(a)
# for num in a:
# 	print(num)


# range(0, 10)
# 0
# 1
# 2
# 3
# 4
# 5
# 6
# 7
# 8
# 9

# names=["Alice","Devin","Mary","Bob"]
# ages=[1,2,3,4]
# zip(names,ages)

# word="dummy"
# while word:
# 	word=input("Please input word:")
# 	print("The word was "+word)


# from math import sqrt
# for n in range(99,81,-1):
# 	root=sqrt(n)
# 	if root==int(root):
# 		print(n)
# 		break
# else:
# 	print("can't find it")


# print([x for x in range(10)if x%3==0])
#
# print([(x,y) for x in range(3) for y in range(3)])


# a=4
# if a==1:
# 	print(a)
# elif a==2:
# 	pass
# else:
# 	print(a*a)


# a=input("please input your python code:\n")
# exec (a)

# please input your python code:
# print("Hello World!")
# Hello World!

# a=input("please input your expression:\n")
# b=eval(a)
# print(b)

# please input your expression:
# 5+6+7
# 18

# from Tools.scripts.treesync import raw_input
#
# str1=raw_input("")
# str2=raw_input("")
# if(str1>str2):
# 	print(">")
# elif(str1==str2):
# 	print("=")
# elif(str1<str2):
# 	print("<")

# def hello(name):
# 	return "Hello, "+name+"!"
#
# print(hello('crazyacking'))
#
#
# def fibs(num):
# 	result=[0,1]
# 	for i in range(num-2):
# 		result.append(result[-1]+result[-2])
# 	return result
# print(fibs(10))


# def square(x):
# 	'Calculates the square of the number x.'
# 	return x*x
# print(square(4))
# print(square.__doc__)


# def change(str):
# 	str='Hello World!'
# a="Devin"
# change(a)
# print(a)
#
#
# def change(dic):
# 	dic["Devin"]=122
# d={"A":1,"B":2}
# change(d)
# print(d)


# My_sister="Alice Bob Cecil"
# database={}
# database["first"]={}
# database["middle"]={}
# database["last"]={}
# database["first"]["Alice"]=My_sister
# database["middle"]["Bob"]=My_sister
# database["last"]["Cecil"]=My_sister
# print(database)


# def init_database(data):
# 	data["first"]={}
# 	data["middle"]={}
# 	data["last"]={}
#
# def insert(database,name_str):
# 	a=name_str.split()
# 	print(a)
# 	database["first"][str(a[0])]=name_str
# 	database["middle"][str(a[1])]=name_str
# 	database["last"][str(a[2])]=name_str
#
# name="Alice Bob Cecil"
# database={}
# init_database(database)
# print(database)
# insert(database,name)
# print(database)
# print(database["first"].get("Alice"))
# print(database["middle"].get("Bob"))
# print(database["last"].get("Cecil"))


# def fun(name,num):
# 	print("%s : %d"%(name,num))
# na="Devin"
# nu=22
# fun(na,nu)
# # fun(num,na)		# Error
# fun(num=nu,name=na)	# Ok


# def fun(name="crazyacking",num=33):
# 	print("%s : %d"%(name,num))
#
# fun()	#crazyacking : 33	(default value)
# fun(num=343,name="flsdjfklsd")	#flsdjfklsd : 343
# fun(num=999)	#crazyacking : 999		(provide a part of value)


# def store(data,*full_names):
# 	for full_name in full_names:
# 		names=full_name.split()
# 		if(len(names)==2):
# 			names.insert(1,"")		# zai direction 1 cha ru yi ge kong chuan
# 		labels="first","middle","last"
# 		for label,name in zip(labels,names):
# 			people=lookup(data,label,name)
# 			if people:
# 				people.append(full_name)
# 			else:
# 				data[label][name]=[full_name]
# def init(d):
# 	d["first"]={}
# 	d["middle"]={}
# 	d["last"]={}
#
# d={}
# init(d)
# store(d,"Devin Jeason")

# def factorinal(n):
# 	if(n==1):
# 		return 1
# 	return n*factorinal(n-1)
# print(factorinal(5))


# def Binary_Search(squences,number,lower,upper):
# 	mid=(lower+upper)/2
# 	if(squences[mid]==number):
# 		return mid
# 	elif(squences[mid]>number):
# 		lower=mid+1
# 	else:
# 		upper=mid
# 	return Binary_Search(squences,number,lower,upper)
#


# def fun(a):
# 	print(a)
#
# squ=[]
# for i in range(20):
# 	squ.append(i)
# print(squ)


 
