#!/bin/python
import sys

file = open('passwd1.txt','r').readlines()

for line in file:
	if sys.argv[1] in line:
		fields = line.split(":")
		print("userid: "+fields[0])
		print("uid: "+fields[2])
		print("gid: "+fields[3])
		print("home directory: "+fields[5])
		print("shell: "+fields[6])
