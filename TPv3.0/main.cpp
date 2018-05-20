#include <iostream>
#include "UnitsClasses/Army.cpp"
#include "Castles.cpp"
#include "vector"
#include "GameComand.cpp"


using std::cout;
using std::cin;
using std::string;
using std::vector;



ArmyFactory* setRace();
void helpComand();      //необходимо дописать

int main() {
    
    cout << "Добро пожаловать в игру" << '\n';
    cout << "Выведите ваше имя: " << '\n';
    std::string playerName;
    cin >> playerName;
    
    
    ArmyFactory *armyFactory = setRace();
    ArmyCreator creator;
    Army *mArmy = creator.create(*armyFactory);
    mArmy->increaseCntOfArchers(*armyFactory, 10);
    mArmy->increaseCntOfInfantries(*armyFactory, 10);
    mArmy->increaseCntOfWizards(*armyFactory, 10);
    mArmy->increaseCntOfCavalries(*armyFactory, 10);
    mArmy->update();
    
    CastleDecorator *castle = new CastleDecorator();
    castle = new CastleBig(castle);
    castle = new CastleRich(castle);
    castle = new CastleDefender(castle);
    
    vector<GameObjs> army;
    GameObjs gObj;
    gObj.Army = mArmy;
    gObj.property = mArmy;
    gObj.locat = 1;
    army.push_back(gObj);
    
    
    cout << "Лорд " << playerName << ", в вашем распоряжении 40 бравых ребят и хороший замок Winterfell." <<'\n'
    << "Ваша задача захватить замки Harrenhal и The Dreadfort за 5 ходов." <<'\n'
    << "На каждом ходу вы можете, либо атаковать замок противника, либо переждать и получить золото." <<'\n'
    << "За золото можно улучшать или увеличивать армию" <<'\n'
    << "Будьте осторожны, вы можете быть атакованы противником в любой момент." <<'\n'
    << "Если вы потеряете все замки и всё войско, то проиграете." <<'\n' << '\n';
    helpComand();
    
    for(int i = 0; i < 5; i++){
        if (i == 2){
            //тут надо атаковать войско
        }
        if (i == 4){
            //тут надо атаковать базовый замок
        }
        
        vector<Comand> comands;
        int sComand;
        cin >> sComand;
        while (sComand != 7){
            switch (sComand) {
                case 1: {
                    helpComand();
                    break;
                }
                case 2: {
                    GetInfoComand comand2;
                    comand2.setConfig(army);
                    comands.push_back(comand2);
                    break;
                }
                case 3: {
                    int from;
                    cout << "Введите индекс аримии которой вы будете атаковать: " << '\n';
                    cin >> from;
                    int to;
                    cout << "Введите индекс армии, которую будете атаковать: " << '\n';
                    cin >> to;
                    AttackComand comand3;
                    comand3.setConfig(from, to, army);
                    comands.push_back(comand3);
                    break;
                }
                case 4: {
                    int who;
                    cout << "Введите индекс аримии которую вы будете атаковать: " << '\n';
                    cin >> who;
                    int to;
                    cout << "Введите индекс местоположения, куда вы хотитет переместить войско: " << '\n';
                    cin >> to;
                    MoveComand comand4;
                    comand4.setConfig(who, to, army);
                    comands.push_back(comand4);
                    break;
                }
                case 5: {
                    cout << "Данный функционал пока не реализован!" << '\n';
                    break;
                }
                case 6: {
                    cout << "Данный функционал пока не реализован!" << '\n';
                    break;
                }
                default: {
                    cout << "Команда введена неправильно!" << '\n';
                    break;
                }
            }
            cout << "Введите следующиую команду: " << '\n';
            cin >> sComand;
        }
        
    }
    
    
    delete mArmy;
    delete castle;
    
    return 0;
}


ArmyFactory* setRace(){
    cout << "Выберите расу: "<< '\n'
    << "1: Люди" << '\n'
    << "2: Эльфы" << '\n'
    << "3: Орки" <<'\n';
    int race;
    cin >> race;
    ArmyFactory *armyFactory;
    switch (race) {
        case 1: {
            armyFactory = new PeopleArmyFactory();
            break;
        }
        case 2: {
            armyFactory = new OrcsArmyFactory();
            break;
        }
        case 3: {
            armyFactory = new ElfsArmyFactory();
            break;
        }
        default: {
            cout << "Неправильный формат ввода";
            armyFactory = setRace();
            break;
        }
    }
    return armyFactory;
}

void helpComand(){
    cout << "В вашем распоряжении есть следующие комнды:" <<'\n'
    << " '1'  - показывает все возможные команды" <<'\n'
    << " '2'  - выводит информацию о ваших замках и вашей армии, а также о замках и армии вашего противника" <<'\n'
    << " '3'  - aтаковать" <<'\n'
    << " '4'  - переместить войско" <<'\n'
    << " '5'  - улучшить армию" <<'\n'
    << " '6'  - увеличить войско" <<'\n'
    << " '7'  - закончить ход" <<'\n';
}
