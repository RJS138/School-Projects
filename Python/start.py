# This is a comment line! It is started with a "#"!

# change the following line to open different file
file_path='start.py'

print("Now I am going to open file: "+file_path)
file1=open(file_path)
lines=file1.readlines()
print("Now that the data is got, this file is now to be closed!")
file1.close()

# change the following line to search for another term
term='am'
for line in lines:
    if term in line:
        print(line)
