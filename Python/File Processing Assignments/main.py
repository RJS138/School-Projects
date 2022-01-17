
from os import read


print("Hello world!")

logA = open("Log-A.strace", "r")
logB = open("Log-B.strace", "r")

logA_content = logA.readlines()
logB_content = logB.readlines()

count = 0
count2 = 0

readExp = "read("
keyboardExp = "tty"
pipeExp = "pipe"

for line in logA_content:
    if readExp in line:
        print('Read from Log A: ' + line)
        #count +=1

for line in logB_content:
    if readExp in line:
        print('Read from Log B: ' + line)
       # count2 +=1

for line in logA_content:
        if readExp in line and keyboardExp in line:
            print('Read from Keyboard in Log A: ' + line)
            #count +=1

for line in logB_content:
        if readExp in line and keyboardExp in line:
            print('Read from Keyboard in Log B: ' + line)
            #count2 +=1

for line in logA_content:
    if readExp in line and keyboardExp not in line and pipeExp not in line:
        print("Read from File in Log A: " + line)
        count +=1

for line in logB_content:
    if readExp in line and keyboardExp not in line and pipeExp not in line:
        print("Read from File in Log B: " + line)
        count2 +=1

for line in logA_content:
    if readExp in line and keyboardExp not in line and pipeExp not in line:
        filename_start = line.find('<')
        filename_end = line.find('>')
        filename = line[filename_start + 1:filename_end]
        print(filename)
print(count)
print(count2)
print(count + count2)