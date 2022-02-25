import os
print(os.getcwd())
os.chdir('/home/paul/Documents/programming/git/MyProgramming')
print(os.getcwd())
os.system('git add .')
s = input("message: ")
s = '\''+s+'\''
s = "git commit -m "+s
print(s)
os.system(s)
os.system('git push')
print('done')