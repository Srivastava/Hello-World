import pyperclip

message = 'This is my secret message.'

data ='ABCDEFGHIJKLMNOPQRSTUVWXYZ'

message=message.upper()

print(message)

translated=''

key = int(raw_input('Input the key :' ))

for c in message:
    if c in data:
        num=data.find(c)
        #print(c,num)
        num+=key

        if num>=len(data):
            num-=len(data)

        translated+=data[num]

    else:
        #print('here\n')
        translated+=c

print 'Caesar Cipher:',translated

pyperclip.copy(translated)
