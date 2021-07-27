##########################
# Author Noe Sancen
# Date: 4/25/2019
# Desc: Final Exam
##########################
#Constant Variables
GangGai = 10.00
PadThai = 8.75
PadCashew = 9.50
PadPrik = 10.25
PeanutCurry = 9.50
CurryNoodle = 11.25

#define statements
def Menu():
    print("Resturant Register\n")
    print("Dish\tDishName\tPrice")
    print("------\t----------\t-------")
    print("1.\tGang Gai\t\t$10.00")
    print("2.\tPad Thai\t\t$8.75")
    print("3.\tPad Cashew\t\t$9.50")
    print("4.\tPad Prik\t\t10.25")
    print("5.\tPeanut Curry\t9.50")
    print("6.\tCurry Noodle\t$11.25\n")

def verify(userNum):
    while True:
        try:
            userInput = int(input(userNum))
        except ValueError:
            print("Not an integer. Please enter an integer.")
        else:
         return int(userInput)

def float_verify(userfloat):
    while True:
        try:
            userInput = float(input(userfloat))
        except ValueError:
            print("Not an string. Please enter a character")
        else:
         return float(userInput)

def selection(userNum):
    dishPrice = 0
    if(userNum == 1):
        dishPrice = GangGai
    elif(userNum == 2):
        dishPrice = PadThai
    elif (userNum == 3):
        dishPrice = PadCashew
    elif (userNum == 4):
        dishPrice = PadPrik
    elif (userNum == 5):
        dishPrice = PeanutCurry
    elif (userNum == 6):
        dishPrice = CurryNoodle

    return dishPrice



#initialize Variables
totalDiscount = 0
totalPrice = 0
salesTax = 0
userCardPay = 0

#looping until customer decides to not order another dish.
while True:
    moreDishPrices = 0 #variable thats adds extra dishes onto the total price.
    Menu()
    userNum = verify("Enter the item number you want (1-6): ")
    while((userNum >= 7) or (userNum <= 0)): #validation
        userNum = verify("Invalid! Enter the item number you want (1-6): ")

    dishPrice = selection(userNum)
    ageChoice = str(input("Are you 65 or Older?(Y/N): "))
    while ageChoice not in ['y', 'Y', 'n', 'N']:
        ageChoice = str(input("Invalid input. Enter Y if you are 65 or older, otherwise press N if you are not: "))
    if ageChoice == 'y' or ageChoice == 'Y':
        dishDiscountPrice = dishPrice * 0.1
        totalDiscount += dishDiscountPrice
        dishPrice -= dishDiscountPrice
        print("%.2f" % dishDiscountPrice)

    moreDishPrices += dishPrice
    totalPrice += moreDishPrices

    userAnswer = str(input("Would you like to order another item (Y or N)? "))
    while userAnswer not in ['y', 'Y','n', 'N']:#validation
        userAnswer = str(input("Invalid input. Enter Y to order another item or N to continue with your purchase: "))
    if userAnswer == 'n' or userAnswer == 'N':
        break;

userGiftCard = str(input("Do you have a gift card? (Y or N?) "))
while userGiftCard not in ['y', 'Y', 'n', 'N']:
    userGiftCard = str(input("Invalid input. Enter Y to add gift card or N to not apply gift card: "))
if userGiftCard == 'y' or userGiftCard == 'Y':
    userCardPay = float_verify("How much money would you like to apply from card? ")
    while(userCardPay > totalPrice):
        userCardPay = float_verify("Invalid! Price cannot be higher than Bill. How much money would you like to apply from card? ")

#displays the information
print("\n\tBill Information\n----------------------")
print("Total of all items:\t\t\t $%.2f" % totalPrice)
if totalDiscount != 0:
    print("Total senior discount:\t\t-$%.2f" % totalDiscount)
print("Taxes:\t\t\t\t\t\t+$%.2f" % salesTax)
totalPrice += salesTax
if userCardPay != 0:
    totalPrice = totalPrice - userCardPay
    print("Gift Card amount applied:  -$%.2f" % userCardPay)
print("\t\t\t\t\t\t\t-------")
print("Bill:\t\t\t\t\t\t $%.2f" % totalPrice)

