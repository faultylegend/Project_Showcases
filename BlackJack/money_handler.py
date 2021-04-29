FILENAME = "D:\\Python\\lab\\money.txt"

def set_money(money):
    with open(FILENAME, "w") as file:
        file.write(str(money))

def get_money():
    try:
        with open(FILENAME, "r") as file:
            line = file.readline()
        money = float(line)
        return money
    except FileNotFoundError:
        print("Data file missing, resetting starting amount to 1000.")
        return 1000
    