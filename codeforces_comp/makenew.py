import sys

content = ""
fn = sys.argv[1]

with open('base.cpp') as f:
    content = f.read()

print(content)

with open(fn,'w') as f:
    f.write(content)