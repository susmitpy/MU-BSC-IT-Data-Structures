import os
files = os.listdir()
pwd = os.getcwd() + "/";
for file in files:
    if "." not in file:
        print("Running " + file)
        os.system(pwd+file)
