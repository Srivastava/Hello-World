import random
secretNumber = random.randint(1,20)
print('I am thinking of a number between 1 and 20')

for guessTaken in range(1,7):
    print('Take a guess')
    guess=int(input())

    if guess <secretNumber:
        print('Your guess is too low')
    elif guess > secretNumber:
        print('Your guess is too high')

    else:
        break

if guess==secretNumber:
    print('Good Job' +str(guessTaken))
else:
    print('Awwwwww')
