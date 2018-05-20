#include <stdio.h>



class Castle{
public:
    float defense = 0.75;
    int capacity = 50;
    int taxis = 100;
    bool my = false;
};

class CastleDecorator{
public:
    Castle *cCastle;
    CastleDecorator(){
        cCastle = new Castle();
    }
};

class CastleDefender : public CastleDecorator{
public:
    CastleDefender(CastleDecorator *castle){
        cCastle = castle->cCastle;
        cCastle->defense = 0.95;
    }
    
};

class CastleBig : public CastleDecorator{
public:
    CastleBig(CastleDecorator *castle){
        cCastle = castle->cCastle;
        cCastle->capacity = 120;
    }
};

class CastleRich : public CastleDecorator{
public:
    CastleRich(CastleDecorator *castle){
        cCastle = castle->cCastle;
        cCastle->taxis = 200;
    }
};

