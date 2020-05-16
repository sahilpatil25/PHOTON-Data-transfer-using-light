import serial
ard = serial.Serial('com4',1000000)
bit=""
output=""
while (1==1):
        myData = (ard.readline().strip())
        a=int(myData.decode('utf-8'))
        #print(a)
        if a>220 and a<=450:
                bit+='0'
        if a>450 and a<1200:
                bit+='1'
        if a>2000:
                i=len(bit)/7
                print(len(bit))
                j=0
                while(i!=0):
                        c=chr(int(bit[(j*7):((j*7)+7)],2))
                        if(c=='^'):
                                c=' '
                        output+=c
                        j+=1
                        i-=1
                print(output)
                ard.write(output.encode('utf-8'))
                bit=""
                output=""
