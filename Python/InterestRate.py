#This program calculaates the simple interst or Compounded interest


def Answer(P,I,T,flag):
    if(flag=='Simple'):
        return P*T*I/100.0

    elif(flag=='Compounded'):
        return P*(1+I/100.0)**T


def main():

    Principle=float(raw_input('>> Principle '))
    Interest=float(raw_input('>> Interest '))
    Time=float(raw_input('>> Time '))
    Sim=(raw_input('>> Simple or Compounded '))


    print Principle
    print Interest
    print Time
    print Sim

    print Answer(Principle,Interest,Time,Sim)

main()
