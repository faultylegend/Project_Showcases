import random 
import money_handler
import locale as lc
from datetime import time, datetime

result = lc.setlocale(lc.LC_ALL, "")
if result == "C":
    lc.setlocale(lc.LC_ALL, "en_US")

FILENAME = "D:\\Python\\lab\\money.txt"

def header(start_time):
    print("BLACKJACK!\nBlackjack payout is 3:2\nEnter 'x' for bet to exit")
    print("Start Time:", start_time.strftime("%I:%M:%S %p"))
    print()

def deck_generator(deck):
    suits = ["Clubs" , "Spades", "Diamonds", "Hearts"]
    numbers = ["Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"]
    for suit in suits:
        for number in numbers:
            card = (number, suit)
            deck.append(card)
def shuffle(deck):
    random.shuffle(deck)

def start_money():
    money = money_handler.get_money()
    if money < 5:
        print("You were out of money.\nWe gave you 100 so you can play.\n")
        return 100
    else:
        return money
    

def input_bet(money):
    dont_continue = True
    while dont_continue:
        try:
            bet = str(input("Bet Amount: "))
            if bet.lower() == "x":
                break 
            bet = float(bet)
            if bet < 5:
                print("The minimum bet is 5.")
            elif bet > 1000:
                print("The maximum bet is 1,000.")
            elif bet > money:
                print("You do not have enough money to make that bet.")
            else:
                dont_continue = False
        except ValueError:
            print("Invalid amount, try again.")
            continue
    return bet

def print_player(player):
    print("YOUR CARDS:")
    for card in player:
        print(card[0] + " of " + card[1])

def print_dealer(player):
    print("DEALER'S CARDS:")
    for card in player:
        print(card[0] + " of " + card[1])

def draw(deck,hand):
    card = deck.pop()
    hand.append(card)

def calculate(hand):
    score = 0
    aces = 0
    for card in hand:
        if card[0] == "Jack" or card[0] == "Queen" or card[0] == "King":
            score += 10
        elif card[0] == "Ace":
            score += 11
            aces += 1
        else:
            score += int(card[0])
    while aces != 0:
        if score < 22:
            break
        else:
            score -= 10
            aces -= 1
    return score

def play_game(cash):
    again = "y"
    money = cash
    while again.lower() == "y":
        if money < 5:
            print("You are out of money.")
            get_more = input("Would you like to buy more chips? (y/n): ").lower()
            if get_more == "y":
                while True:
                    chips = float(input("Amount: "))
                    if 0 < chips <= 10000:
                        money += chips
                        break
                    else:
                        print("Invalid amount, must be from 0 to 10,000")
                print("Player's money", lc.currency(money, grouping=True))
                print()
                money_handler.set_money(money)
            else:
                break     

        bet = 0
        bet = input_bet(money)
        bet = str(bet)
        if bet.lower() == "x":
            print()
            break
        bet = float(bet)
        deck = []
        deck_generator(deck)
        shuffle(deck)
        player = []
        dealer = []
        draw(deck,player)
        draw(deck,player)
        draw(deck,dealer)
        draw(deck,dealer)
        print("\nDEALER'S SHOW CARD:\n" + dealer[0][0] + " of " + dealer[0][1])
        print()
        status = "h"
        print_player(player)
        while True: 
            print()
            status = input("Hit, Stand, or Double Down ? (h/s/d): ")
            print()
            if status.lower() == "s":
                print_player(player)
                print()
                break
            elif status.lower() == "h":
                draw(deck,player)
                print_player(player)
            elif status.lower() == "d":
                temp_bet = bet * 2 
                if temp_bet > money:
                    print("Insufficient funds to do that.")
                else:
                    bet = temp_bet
                    draw(deck,player)
                    print_player(player)
                    print()
                    score = calculate(player)
                    if score > 21:
                        print("Whoops! You Busted. You Lose.")
                        print()
                    break
            else:
                print("Invalid Input")
            score = calculate(player)
            if score > 21:
                print("\nWhoops! You Busted. You Lose.")
                print()
                break
        score = calculate(player)    
        if score < 22:
            while calculate(dealer) < 17:
                draw(deck,dealer)
        
        print_dealer(dealer)
        print()
        score = calculate(player)
        d_score = calculate(dealer)
        print("YOUR POINTS:     " + str(score))
        print("DEALER'POINTS:   " + str(d_score))
        print()

        if score > 21:
            money -= bet
        elif d_score > 21:
            print("Yay! Dealer busted. You win!")
            money += bet
        elif score == 21 and len(player) == 2:
            if d_score == 21 and len(dealer) == 2:
                print("You both have blackjack: You push")
            else:
                print("Blackjack!")
                money += bet * 1.5
                money = round(money,2)
        else:
            if score > d_score:
                print("You Win!")
                money += bet
            elif score < d_score:
                print("You Lose.")
                money -= bet
            elif score == d_score:
                print("You Push.")
            else:
                print("Error - Something went wrong")

        print("Player's money", lc.currency(money, grouping=True))
        money_handler.set_money(money)
        # if money < 5:
        #     print("You do not have enough money to start a new game.\n")
        #     break

        again = input("\nPlay Again? (y/n): ")
        print()


def main():
    start_time = datetime.now()
    header(start_time)
    money = start_money()
    print("Player's money", lc.currency(money, grouping=True))
    print()
    play_game(money)
    end_time = datetime.now()
    time_elapse = end_time - start_time
    minutes = time_elapse.seconds // 60
    seconds = time_elapse.seconds % 60
    hour = minutes // 60
    minutes = minutes % 60

    final_time = time(hour, minutes, seconds)

    print("Stop time:", end_time.strftime("%I:%M:%S %p"))
    print("Elapsed time:", final_time)
    print("Goodbye")

if __name__ == "__main__":
    main()