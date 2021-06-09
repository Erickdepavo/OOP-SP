#include <iostream>
#include <string>
#include <vector>
#include <unistd.h> // LIbrería para Sleep
#include <conio.h> // Librería para control de telcado

#include "Character.h"
#include "BattleMove.cpp"
#include "Pavomon.cpp"
#include "Pavodex.cpp"
#include "Battle.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define FPS 60
#define DELAY 1000000

/*
#include "ElectricPavomon.h"
#include "FirePavomon.h"
#include "GrassPavomon.h"
#include "NormalPavomon.h"
#include "WaterPavomon.h"
*/

/*
GitHub: https://github.com/Erickdepavo/OOP-SP
*/

using namespace std;

void clear() {
    cout << "\x1B[2J\x1B[H"; // Clear multiplataforma
}

int menu(vector<string> options, string message) {
     
    // usleep(1000) // Sleeps for 1ms
    int currentOption = 0;

    while (true) {

        usleep(1000000/FPS);
        
        if (currentOption < 0) {
            currentOption = 0;
        } else if (currentOption > options.size()-1) {
            currentOption = options.size()-1; 
        }

        clear();

        cout << message << "\n\n";
        
        for (int i = 0; i < options.size(); i++) {
            if (currentOption == i) {
                cout << " *\t";
            } else {
                cout << "  \t";
            }
            cout << options[i] << endl;
        }

        cout << "\n\n\n";

        int key;
        switch((key = getch())) {
            
            case KEY_UP:
                currentOption--;
                continue;

            case KEY_DOWN:
                currentOption++;
                continue;
            
            case KEY_ENTER:
                return currentOption;
            
            default:
                continue;

        }
    }

    return currentOption;
}

void credits() {
    
    usleep(DELAY);
    cout << "Pavomon, battle like a pro!" << "\n\n";
    usleep(DELAY);
    cout << "A game produced and developed by" << "\n";
    usleep(DELAY);
    cout << "- Erick Daniel Padilla Verdugo, A01740287" << endl;
    cout << "- Kevin Montoya Campaña, A01740352" << endl;
    usleep(DELAY);

}
int main() {

    Pavodex pavodex; // Lee todos los datos al inicializar
    
    /*
    for (int i = 0; i < pavodex.getNormalPavomons().size(); i++) {
        pavodex.getNormalPavomons()[i]->printPavomon();
    }

    for (int i = 0; i < pavodex.getMoves().size(); i++) {
        pavodex.getMoves()[i]->printBattleMove();
    }

    pavodex.printPavomonList();
    pavodex.printMovesList();

    */
    // Inicio del juego //

    string message =  
"   _ (`-.    ('-.          (`-.                _   .-')                     .-') _  \n"
"  ( (OO  )  ( OO ).-.    _(OO  )_             ( '.( OO )_                  ( OO ) ) \n"
" _.`     \\  / . --. /,--(_/   ,. \\ .-'),-----. ,--.   ,--.).-'),-----. ,--./ ,--,'  \n"
"(__...--''  | \\-.  \\ \\   \\   /(__/( OO'  .-.  '|   `.'   |( OO'  .-.  '|   \\ |  |\\  \n"
" |  /  | |.-'-'  |  | \\   \\ /   / /   |  | |  ||         |/   |  | |  ||    \\|  | ) \n"
" |  |_.' | \\| |_.'  |  \\   '   /, \\_) |  |\\|  ||  |'.'|  |\\_) |  |\\|  ||  .     |/  \n"
" |  .___.'  |  .-.  |   \\     /__)  \\ |  | |  ||  |   |  |  \\ |  | |  ||  |\\    |   \n"
" |  |       |  | |  |    \\   /       `'  '-'  '|  |   |  |   `'  '-'  '|  | \\   |   \n"
" `--'       `--' `--'     `-'          `-----' `--'   `--'     `-----' `--'  `--'   \n" 
    
    "\n Welcome to Pavomon!";
    vector<string> mainOptions{"Play match", "Credits", "Exit"};

    int mainMenuOption = menu(mainOptions, message);
    switch(mainMenuOption) {
        
        case 0: {
            vector<string> pavomonTypesOptions{"Normal", "Grass", "Water", "Fire", "Electric"};
            
            int pavomonTypeOption = menu(pavomonTypesOptions, "Choose your Pavomon type: ");
            vector<string> pavomonNames;

            switch (pavomonTypeOption) {

                case 0: {
                    
                    for (int i = 0; i < pavodex.getNormalPavomons().size(); i++){
                        pavomonNames.push_back(pavodex.getNormalPavomons()[i] -> name);
                    }

                    int selectedPavomon = menu(pavomonNames, "Choose the best!");
                }
                break;

                case 1: {
                    
                    for (int i = 0; i < pavodex.getGrassPavomons().size(); i++){
                        pavomonNames.push_back(pavodex.getGrassPavomons()[i] -> name);
                    }

                    int selectedPavomon = menu(pavomonNames, "Choose the best!");
                }
                break;

                case 2: {
                    
                    for (int i = 0; i < pavodex.getWaterPavomons().size(); i++){
                        pavomonNames.push_back(pavodex.getWaterPavomons()[i] -> name);
                    }

                    int selectedPavomon = menu(pavomonNames, "Choose the best!");
                }
                break;

                case 3: {
                    
                    for (int i = 0; i < pavodex.getFirePavomons().size(); i++){
                        pavomonNames.push_back(pavodex.getFirePavomons()[i] -> name);
                    }

                    int selectedPavomon = menu(pavomonNames, "Choose the best!");
                }
                break;

                case 4: {
                    
                    for (int i = 0; i < pavodex.getElectricPavomons().size(); i++){
                        pavomonNames.push_back(pavodex.getElectricPavomons()[i] -> name);
                    }

                    int selectedPavomon = menu(pavomonNames, "Choose the best!");
                }
                break;
            }     
        }
        
        break;

        case 1:
            credits();
            break;
        default:
            clear();
            break;
    }


    // Crear batalla
    // Battle battle(/* ... */); // Crea el administrador de batallas

    return 0;
}