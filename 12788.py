#!/usr/bin/env python
# coding: utf-8

# # 백준 12788번 제 2회 IUPC는 잘 개최될 수 있을까

# In[1]:


import sys #sys 모듈 임포트

#입력
N = int(input()) #한 줄을 읽어 정수로 입력받기
M, K = map(int,input().split())
arr = list(map(int,input().split()))
#풀이
pen = 0
num = 0
arr.sort(reverse = True)
for i in arr:
    num += 1
    pen += i
    if pen >= M * K:
        print (num)
        break ;
if pen < M * K:
    print("STRESS")


