import serial
ard = serial.Serial('com3',250000)
while(1==1):
    msg = input("What is your message? ")
    msg = msg.replace(" ","^")
    print (msg)
    j=len(msg)
    output=""
    i=0;
    while(j!=0):
            output+='{0:b}'.format(ord(msg[i]))
            j-=1
            i+=1
    print(output)
    ard.write(output.encode('utf-8'))
