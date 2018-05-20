#include "CORChecker.cpp"



class Comand {
public:
    virtual void doIt(){}
};

class AttackComand : public Comand{
public:
    void doIt(){
        int ind = 0;
        int Ui = 0;
        while (ind < mFrom){
            if (mArmy[Ui].property){
                ind ++;
            }
            Ui++;
        }
        ind = 0;
        int Oi = 0;
        while (ind < mTo){
            if (mArmy[Oi].property){
                ind ++;
            }
            Oi++;
        }
        CheckerArmyLive *UArmlive = new CheckerArmyLive;
        UArmlive->getParametr(Ui, mArmy);
        CheckerArmyLive *OArmlive = new CheckerArmyLive;
        OArmlive->getParametr(Oi, mArmy);
        Attack *attack = new Attack;
        attack->getParametr(Ui, Oi, mArmy);
        UArmlive->setNext(OArmlive);
        OArmlive->setNext(attack);
        UArmlive->active();
    }
    void setConfig(int from, int to, vector<GameObjs> &obj){
        mFrom = from;
        mTo = to;
        mArmy = obj;
    }
    int mFrom;
    int mTo;
    vector<GameObjs> mArmy;
};

class MoveComand : public Comand{
public:
    void doIt(){
        
    }
    void setConfig(int who, int to, vector<GameObjs> &obj){
        mWho = who;
        mTo = to;
        mArmy = obj;
    }
    int mWho;
    int mTo;
    vector<GameObjs> mArmy;
};

class GetInfoComand : public Comand{
public:
    void doIt(){
        
    }
    void setConfig(vector<GameObjs> &obj){
        mArmy = obj;
    }
    vector<GameObjs> mArmy;
};
