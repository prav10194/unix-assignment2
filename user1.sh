#!/bin/bash
result=$(grep $1 passwd1.txt)
IFS=':' read -r var1 var2 var3 var4 var5 var6 var7 <<< "$result"
echo "userid: $var1"
echo "uid: $var3"	
echo "gid: $var4"
echo "home directory: $var6"
echo "shell: $var7"

