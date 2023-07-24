#include "Scenes.hpp"

void printIntro() {
    system("MODE CON COLS=150 LINES=30");

    cout << " _____                         .______    __          ___       ______  __  ___        __       ___       ______  __  ___" << endl;
    cout << "|  A .| _____                  | _    \\  |  |        /   \\     /      ||  |/  /       |  |     /   \\     /      ||  |/  /" << endl;
    cout << "| /.\\ || A ^ | _____           |  |_) |  |  |       /  ^  \\   |  ,----'|  '  /        |  |    /  ^  \\   |  ,----'|  '  /" << endl;
    cout << "|(_._)|| / \\ || A _ | _____    | _  <    |  |      /  /_\\  \\  |  |     |    <   .--.  |  |   /  /_\\  \\  |  |     |    <" << endl;
    cout << "|  |  || \\ / || () || A_ _ |   |  |_) |  |  `----./  _____  \\ |  `----.|  .  \\  |  `--'  |  /  _____  \\ |  `----.|  .  \\  " << endl;
    cout << "|____V||  .  ||(_'_)||( v )|   |______/  |_______/__/     \\__\\ \\______||__|\\__\\  \\______/  /__/     \\__\\ \\______||__|\\__\\ " << endl;
    cout << "       |____V||  |  || \\ / |" << endl;
    cout << "              |____V||  .  |" << endl;
    cout << "                     |____V|                               ";

    system("pause");
    system("cls");
}
void printMenu() {
    cout << "What do you want to do?" << endl << endl;
    cout << "1: Play" << endl << "2: Exit" << endl << endl;
}

void printHand(Player guest, Player croupier) {
    system("cls");
    cout << "Money: " << guest.wallet << endl;
    cout << "Player has: ";
    for (Card i : guest.hand) {
        cout << i.value << i.suit << " ";
    }
    cout << endl << guest.sum << endl << endl;

    cout << "Croupier has: " ;
    for (Card i : croupier.hand) {
        cout << i.value << i.suit << " " ;
    }
    cout << endl << croupier.sum << endl << endl;
}