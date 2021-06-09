#include <iostream>
#include <string>
#include <vector>
#include <unistd.h> // LIbrería para Sleep
#include "PlatformVariants.h"
#include "intToString.cpp"

#include "Character.h"
#include "BattleMove.cpp"
#include "Pavomon.cpp"
#include "Pavodex.cpp"
#include "Battle.cpp"

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

const string pavomonLogo =  
"   _ (`-.    ('-.          (`-.                _   .-')                     .-') _  \n"
"  ( (OO  )  ( OO ).-.    _(OO  )_             ( '.( OO )_                  ( OO ) ) \n"
" _.`     \\  / . --. /,--(_/   ,. \\ .-'),-----. ,--.   ,--.).-'),-----. ,--./ ,--,'  \n"
"(__...--''  | \\-.  \\ \\   \\   /(__/( OO'  .-.  '|   `.'   |( OO'  .-.  '|   \\ |  |\\  \n"
" |  /  | |.-'-'  |  | \\   \\ /   / /   |  | |  ||         |/   |  | |  ||    \\|  | ) \n"
" |  |_.' | \\| |_.'  |  \\   '   /, \\_) |  |\\|  ||  |'.'|  |\\_) |  |\\|  ||  .     |/  \n"
" |  .___.'  |  .-.  |   \\     /__)  \\ |  | |  ||  |   |  |  \\ |  | |  ||  |\\    |   \n"
" |  |       |  | |  |    \\   /       `'  '-'  '|  |   |  |   `'  '-'  '|  | \\   |   \n"
" `--'       `--' `--'     `-'          `-----' `--'   `--'     `-----' `--'  `--'   \n";

void clearTerminal() {
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

        clearTerminal();

        cout << message << "\n\n";
        
        for (int i = 0; i < options.size(); i++) {
            if (currentOption == i) {
                cout << " *\t";
            } else {
                cout << "  \t";
            }
            if (options[i] != "") {
                cout << options[i] << endl;
            } else {
                cout << "(Not available)" << endl;
            }
        }

        cout << "\n\n\n";

        int key;
        switch((key = getKey())) {
            
            case KEY_UP:
                currentOption--;
                continue;

            case KEY_DOWN:
                currentOption++;
                continue;
            
            case KEY_ENTER:
                if (options[currentOption] != "") {
                    return currentOption;
                }
            
            default:
                continue;

        }
    }

    return currentOption;
}

int numberInput(string message) {
    int value;
    cout << message << " ";
    cin >> value;
    return value;
}

void credits() {
    clearTerminal();
    usleep(DELAY);
    cout << pavomonLogo << endl;
    usleep(DELAY);
    cout << "Pavomon, battle like a pro!" << "\n\n";
    usleep(DELAY);
    cout << "A game produced and developed by" << "\n";
    usleep(DELAY);
    cout << "- Erick Daniel Padilla Verdugo, A01740287" << endl;
    cout << "- Kevin Montoya Campaña, A01740352" << endl;
    usleep(DELAY);
}

void runBattle(Battle &battle) {
    bool isPlayerTurn = true;
    bool battleIsRunning = true;

    while (battleIsRunning) {
        clearTerminal();
        
        // Dibujar batalla
        string text =
        "Player\t\t\tCPU\n"
        "HP: " + intToString(battle.pavomon1HP) + "/" + intToString(battle.getHP(battle.pavomon1ID, battle.pavomon1Type, battle.pavomon1Level)) + "\t\t" +
        "HP: " + intToString(battle.pavomon2HP) + "/" + intToString(battle.getHP(battle.pavomon2ID, battle.pavomon2Type, battle.pavomon2Level)) + "\n" +
        "Type " + battle.pavomon1Type + "\t\t" + "Type " + battle.pavomon2Type + "\n\n";
        
        // Turnos
        if (isPlayerTurn && battle.pavomon1Fatigue <= 0) {
            // Turno del jugador
            vector<string> moveOptions;

            for (int i = 0; i < battle.pavomon1Moves.size(); i++) {
                if (battle.pavomon1MoveLimits[i] > 0) {
                    string moveText = battle.pavomon1Moves[i] -> moveName;
                    moveText += " – " + (battle.pavomon1Moves[i] -> getMoveDescription());
                    moveText += " — Remaining: " + intToString(battle.pavomon1MoveLimits[i]);
                    moveOptions.push_back(moveText);
                } else {
                    moveOptions.push_back("");
                }
            }

            int attackIndex = menu(moveOptions, text + "It's your turn!\n\nPick your attack:");

            usleep(DELAY);
            cout << " " << endl;
            cout << "You used " << battle.pavomon1Moves[attackIndex]->moveName << "!" << endl;

            battle.registerAttack(1, *battle.pavomon1Moves[attackIndex]);
            battle.pavomon1MoveLimits[attackIndex]--;

            usleep(5*DELAY);

        } else if (!isPlayerTurn && battle.pavomon2Fatigue <= 0) {
            // Turno de la cpu
            cout << text << "It's turn for your opponent." << endl << endl;
            usleep(DELAY);
            cout << "Your opponent is thinking" << endl;
            usleep(0.5 * DELAY);
            cout << "." << endl;
            usleep(0.5 * DELAY);
            cout << "." << endl;
            usleep(0.5 * DELAY);
            cout << "." << endl;
            usleep(DELAY);
            cout << endl;

            int attackIndex = randomInt(0, battle.pavomon2Moves.size() - 1);

            usleep(DELAY);
            cout << " " << endl;
            cout << "The opponent used " << battle.pavomon2Moves[attackIndex]->moveName << "!" << endl;
            
            battle.registerAttack(2, *battle.pavomon2Moves[attackIndex]);
            battle.pavomon2MoveLimits[attackIndex]--;

            usleep(5*DELAY);

        } else if (isPlayerTurn && battle.pavomon1Fatigue > 0) {
            // Fatiga Jugador
            cout << text << "It's your turn but you have " << battle.pavomon1Fatigue << " fatigue." << endl << endl;
            battle.pavomon1Fatigue--;
            usleep(5 * DELAY);

        } else if (!isPlayerTurn && battle.pavomon2Fatigue > 0) {
            // Fatiga CPU
            cout << text << "It's your opponent's turn but he/she has " << battle.pavomon2Fatigue << " fatigue." << endl << endl;
            battle.pavomon2Fatigue--;
            usleep(5 * DELAY);
        }

        // Checar si la batalla ya terminó
        if (battle.pavomon1HP <= 0 || battle.pavomon2HP <= 0) {
            battleIsRunning = false;
        } else {
            isPlayerTurn = !isPlayerTurn;
        }
    }

    clearTerminal();
    usleep(DELAY);
    cout << "THE BATTLE IS OVER!!!" << endl << endl;
    usleep(DELAY);
    if (isPlayerTurn) {
        cout << "You win!" << endl << endl;
    } else {
        cout << "The opponent wins." << endl << endl;
    }
    usleep(DELAY);
    clearTerminal();
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

    // Inicio del juego
    string message = pavomonLogo + "\n Welcome to Pavomon!";
    vector<string> mainOptions{"Play match", "Credits", "Exit"};

    int mainMenuOption = menu(mainOptions, message);
    switch(mainMenuOption) {
        
        case 0: {
            // Variables para añadir pavomon a batalla
            string pavomonID;
            string pavomonType;
            vector<BattleMove*> pavomonMoves;

            // Elegir tipo de Pavomon y Pavomon especifico
            vector<string> pavomonTypesOptions{"Normal", "Grass", "Water", "Fire", "Electric"};
            vector<string> pavomonNames;

            int pavomonTypeOption = menu(pavomonTypesOptions, "Choose your Pavomon type: ");
            switch (pavomonTypeOption) {

                case 0: {
                    
                    for (int i = 0; i < pavodex.getNormalPavomons().size(); i++){
                        pavomonNames.push_back(pavodex.getNormalPavomons()[i] -> name);
                    }

                    int selectedPavomonIndex = menu(pavomonNames, "Choose the best!");
                    pavomonID = pavodex.getNormalPavomons()[selectedPavomonIndex] -> ID;
                    pavomonType = pavodex.getNormalPavomons()[selectedPavomonIndex] -> type;
                    pavomonMoves = pavodex.getNormalPavomons()[selectedPavomonIndex] -> getMoves(pavodex.getMoves());

                }
                break;

                case 1: {
                    
                    for (int i = 0; i < pavodex.getGrassPavomons().size(); i++){
                        pavomonNames.push_back(pavodex.getGrassPavomons()[i] -> name);
                    }

                    int selectedPavomonIndex = menu(pavomonNames, "Choose the best!");
                    pavomonID = pavodex.getGrassPavomons()[selectedPavomonIndex] -> ID;
                    pavomonType = pavodex.getGrassPavomons()[selectedPavomonIndex] -> type;
                    pavomonMoves = pavodex.getGrassPavomons()[selectedPavomonIndex] -> getMoves(pavodex.getMoves());
                }
                break;

                case 2: {
                    
                    for (int i = 0; i < pavodex.getWaterPavomons().size(); i++){
                        pavomonNames.push_back(pavodex.getWaterPavomons()[i] -> name);
                    }

                    int selectedPavomonIndex = menu(pavomonNames, "Choose the best!");
                    pavomonID = pavodex.getWaterPavomons()[selectedPavomonIndex] -> ID;
                    pavomonType = pavodex.getWaterPavomons()[selectedPavomonIndex] -> type;
                    pavomonMoves = pavodex.getWaterPavomons()[selectedPavomonIndex] -> getMoves(pavodex.getMoves());
                }
                break;

                case 3: {
                    
                    for (int i = 0; i < pavodex.getFirePavomons().size(); i++){
                        pavomonNames.push_back(pavodex.getFirePavomons()[i] -> name);
                    }

                    int selectedPavomonIndex = menu(pavomonNames, "Choose the best!");
                    pavomonID = pavodex.getFirePavomons()[selectedPavomonIndex] -> ID;
                    pavomonType = pavodex.getFirePavomons()[selectedPavomonIndex] -> type;
                    pavomonMoves = pavodex.getFirePavomons()[selectedPavomonIndex] -> getMoves(pavodex.getMoves());
                }
                break;

                case 4: {
                    
                    for (int i = 0; i < pavodex.getElectricPavomons().size(); i++){
                        pavomonNames.push_back(pavodex.getElectricPavomons()[i] -> name);
                    }

                    int selectedPavomonIndex = menu(pavomonNames, "Choose the best!");
                    pavomonID = pavodex.getElectricPavomons()[selectedPavomonIndex] -> ID;
                    pavomonType = pavodex.getElectricPavomons()[selectedPavomonIndex] -> type;
                    pavomonMoves = pavodex.getElectricPavomons()[selectedPavomonIndex] -> getMoves(pavodex.getMoves());
                }
                break;
            }

            // Preguntar nivel
            int level = numberInput("Choose your Pavomon Level (1-100):");
            if (level < 1) { level = 1; };
            if (level > 100) { level = 100; };

            // Elegir Pavomon oponente
            tuple<string, string, vector<BattleMove*>> randomPavomon = pavodex.getRandomPavomon();

            // Crear el administrador de batallas
            Battle battle(pavodex, pavomonID, pavomonType, pavomonMoves, level, get<0>(randomPavomon), get<1>(randomPavomon), get<2>(randomPavomon), level);
            runBattle(battle); // Ejecutar la batalla
        }
        break;

        case 1:
            credits();
            break;
        default:
            clearTerminal();
            break;
    }

    return 0;
}