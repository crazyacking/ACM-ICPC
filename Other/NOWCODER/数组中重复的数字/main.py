# -*- coding:utf-8 -*-
class Solution:
    # 这里要特别注意~返回任意重复的一个，赋值duplication[0]
    # 函数返回True/False
    def duplicate(self, numbers, duplication):
        # write code here
        cnt=0
        list1=[]

        for num in numbers:
        	if(num in list1):
        		duplication.insert(num)
        	else:
        		list1.insert(num)
        
        set(list1)
        if(list1.size()>0):
        	return true
        else:
        	return false
