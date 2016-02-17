'''from __future__ import print_function

message= 'Reverse the Message'

for i in range(1,len(message)):
    print(message[-i-1],end='')

print("\nEnd")'''


message =raw_input('Input your message ')


translated=''

i =len(message)-1

while i>=0:
    translated=translated+message[i]
    i-=1

print(translated)
