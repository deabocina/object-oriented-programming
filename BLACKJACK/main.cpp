#include "Card.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "Scenes.hpp"

int main() {
    char choice;
    int value = 1;
    int bet;
    Deck deck;
    Player guest, croupier;
    guest.sum = 0;
    croupier.sum = 0;
    printIntro();
    
    while (1) {
        do {
            system("cls");
            printMenu(); 
            choice = _getch();
            if(choice != '1' && choice != '2') {
                system("cls");
                cout << "Wrong input! Please try again." << endl;
                _getch();
            }
        } while (choice != '1' && choice != '2');
        
        if (choice == '1') {
            guest.wallet = 200;
            cout << "Good luck and have fun!" << endl;
            _getch();
            while (guest.wallet > 0) {
                int value = 1;
                deck.shuffle();
                do {
                    system("cls");
                    cout << "Wallet: " << guest.wallet << " Euros." << endl << endl;
                    cout << "Minimum bet is 1 Euro and maximum is 100 Euro. Enter your bet: ";
                    cin >> bet;
                    if (bet > guest.wallet) {
                        cout << "You can't bet more money than what you have in your wallet." << endl;
                        continue;
                    }
                } while ((bet > guest.wallet) || bet < 0 || bet > 100);
                if (bet == 0) {
                    cout << endl << endl;
                    cout << "You have left the game with " << guest.wallet << " Euros. Congratulations!" << endl;
                    _getch();
                    break;
                }

                guest.wallet -= bet;
                guest.deal(deck);
                guest.check();
                guest.deal(deck);
                guest.check();
                croupier.deal(deck);

                if (croupier.hand[0].value == "A") {
                    croupier.sum += 10;
                }
                printHand(guest, croupier);

                while (1) {
                    if (guest.sum == 21) {
                        cout << "BlackJack!" << endl;
                        _getch();
                        break;
                    }
                    cout << "Hit or stand? [h/s] ";
                    cin >> choice;
                    if (choice == 'h') {
                        guest.deal(deck);
                        guest.check();
                        
                        printHand(guest, croupier);
                        if (guest.sum > 21) {
                            cout << "You have lost!" << endl;;
                            value = -1;
                            _getch();
                            break;
                        }
                        else if (guest.sum == 21) {
                            _getch();
                            break;
                        }
                    }
                    else if (choice == 's') {
                        break;
                    }
                    else {
                        cout << "Wrong input! Please try again." << endl;
                        _getch();
                    }
                }

                if (value > 0) {
                    while (1) {
                        if (croupier.sum < 17) {
                            croupier.deal(deck);
                            if (croupier.hand[croupier.hand.size() - 1].value == "A") {
                                if (croupier.sum < 12) {
                                    croupier.sum += 10;
                                }
                            }
                            
                            printHand(guest, croupier);
                            if (croupier.sum > 21) {
                                cout << "Croupier has lost!" << endl;
                                if (guest.hand.size() == 2 && guest.sum == 21) {
                                    guest.wallet += bet * 2;
                                }
                                cout << "Your prize is " << bet * 2 << " Euros!" << endl;
                                break;
                            }
                            else if (croupier.sum == 21) {
                                if (croupier.hand.size() == 2) {
                                    cout << "BlackJack!" << endl;
                                }
                                cout << "Croupier has won!" << endl;
                                break;
                            }
                            else if (croupier.sum > guest.sum) {
                                cout << "Croupier has won!" << endl;
                                break;
                            }
                        }
                        else if (croupier.sum == guest.sum) {
                            cout << "It's a stand-off." << endl;
                            guest.wallet += bet;
                            break;
                        }
                        else if (croupier.sum < guest.sum) {
                            cout << "Croupier has lost!" << endl;
                            guest.wallet += bet * 2;
                            cout << "Your prize is " << bet * 2 << " Euros!" << endl;
                            break;
                        }
                    }
                    _getch();
                }
                guest.remove();
                croupier.remove();
            }
            if (bet != 0) {
                cout << endl;
                cout << "You have lost everything. Try again?" << endl;
                _getch();
            }
        }

        else if (choice == '2') {
            cout << "Thanks for playing." << endl;
            _getch();
            break;
        }
    }
}