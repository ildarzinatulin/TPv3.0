#include "UnitsClasses/Army.cpp"


struct GameObjs{
    Army *Army;
    bool property;
    int locat;
};


class BaseChecker{
public:
    BaseChecker *next;
    void setNext(BaseChecker * n){
        next = n;
    }
    virtual void active(){}
    void nextChain(){
        next->active();
    }
};


class CheckerIsYourCastle : public BaseChecker{
public:
    void active(){
        for (int i = 0; i < objs.size(); i++){
            if (objs[i].property && objs[i].locat == ind){
                nextChain();
                break;
            }
        }
        cout << "Ошибка команды: этот замок вам не принадлежит" << '\n';
    }
    void getParametr(int i, vector<GameObjs> &obj){
        ind = i;
        objs = obj;
    }
    
    int ind;
    vector<GameObjs> objs;
};

class CheckerIsNotYour : public BaseChecker{
public:
    void active(){
        for (int i = 0; i < objs.size(); i++){
            if (objs[i].property && objs[i].locat == ind){
                cout << "Ошибка команды: этот замок вам принадлежит" << '\n';
                break;
            }
        }
        nextChain();
    }
    void getParametr(int i, vector<GameObjs> &obj){
        ind = i;
        objs = obj;
    }
    
    int ind;
    vector<GameObjs> objs;
};


class CheckerArmyLive : public BaseChecker{
public:
    void active(){
        bool live = false;
        for(int i = 0; i < objs[ind].Army->archers.size(); i++){
            if (objs[ind].Army->archers[i]->Health > 0){
                live = true;
                break;
            }
        }
        for(int i = 0; i < objs[ind].Army->infantries.size() && !live; i++){
            if (objs[ind].Army->infantries[i]->Health > 0){
                live = true;
                break;
            }
        }
        for(int i = 0; i < objs[ind].Army->wizards.size() && !live; i++){
            if (objs[ind].Army->wizards[i]->Health > 0){
                live = true;
                break;
            }
        }
        for(int i = 0; i < objs[ind].Army->cavalries.size() && !live; i++){
            if (objs[ind].Army->cavalries[i]->Health > 0){
                live = true;
                break;
            }
        }
        if (live) {
            nextChain();
        } else {
            
        }
    }
    
    void getParametr(int i, vector<GameObjs> &obj){
        ind = i;
        objs = obj;
    }
    
    int ind;
    vector<GameObjs> objs;
};

class CheckerTransp : public BaseChecker{
public:
    void getParametr(int i, vector<GameObjs> &obj){
        ind = i;
        objs = obj;
    }
    
    void active(){
        bool can = true;
        for(int i = 0; i < objs.size(); i++){
            if (objs[i].locat == ind){
                can = false;
            }
        }
        if (can){
            nextChain();
        }
    }
    
    int ind;
    vector<GameObjs> objs;
};

class ChangeLoc : public BaseChecker{
public:
    void active(){
        objs[who].locat = to;
    }
    void getParametr(int fromP, int toP, vector<GameObjs> &obj){
        who = fromP;
        to = toP;
        objs = obj;
    }
    int who;
    int to;
    vector<GameObjs> objs;
};

class Attack : public BaseChecker {
public:
    void active(){
        int force = 0;
        for (int j = 0; j < objs[who].Army->archers.size(); j++)
            force += objs[who].Army->archers[j]->Force;
        
        for (int j = 0; j < objs[who].Army->infantries.size(); j++)
            force += objs[who].Army->infantries[j]->Force;
        
        for (int j = 0; j < objs[who].Army->wizards.size(); j++)
            force += objs[who].Army->wizards[j]->Force;
        
        for (int j = 0; j < objs[who].Army->cavalries.size(); j++)
            force += objs[who].Army->cavalries[j]->Force;
        
        for (int j = 0; j < objs[to].Army->archers.size() && force > 0; j++){
            if (force > objs[to].Army->archers[j]->Health){
                force -= objs[to].Army->archers[j]->Health;
                objs[to].Army->archers[j]->Health = 0;
            }
        }
        
        for (int j = 0; j < objs[to].Army->infantries.size() && force > 0; j++){
            if (force > objs[to].Army->infantries[j]->Health){
                force -= objs[to].Army->infantries[j]->Health;
                objs[to].Army->infantries[j]->Health = 0;
            }
        }
        
        for (int j = 0; j < objs[to].Army->cavalries.size() && force > 0; j++){
            if (force > objs[to].Army->cavalries[j]->Health){
                force -= objs[to].Army->cavalries[j]->Health;
                objs[to].Army->cavalries[j]->Health = 0;
            }
        }
        
        for (int j = 0; j < objs[to].Army->wizards.size() && force > 0; j++){
            if (force > objs[to].Army->wizards[j]->Health){
                force -= objs[to].Army->wizards[j]->Health;
                objs[to].Army->wizards[j]->Health = 0;
            }
        }
        
        for (int j = 0; j < objs[to].Army->archers.size() && force > 0; j++){
            if (force > objs[to].Army->archers[j]->Health){
                force -= objs[to].Army->archers[j]->Health;
                objs[to].Army->archers[j]->Health = 0;
            }
        }
        
        
    }
    void getParametr(int fromP, int toP, vector<GameObjs> &obj){
        who = fromP;
        to = toP;
        objs = obj;
    }
    int who;
    int to;
    vector<GameObjs> objs;
};
