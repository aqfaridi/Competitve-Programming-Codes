import sys
t = int(sys.stdin.readline())
while(t>0):
   '''
   sys.stdout.write(str(len(set(sys.stdin.readline().split()))))
   sys.stdout.write('\n')
   '''
   '''
   str = sys.stdin.readline().split()
   out = []
   for i in str:
    if i not in out:
        out.append(i)
   '''
   str = sys.stdin.readline().split()
   str = dict.fromkeys(str)
   print len(str)
   t-=1
    
