#include "subroutine.h"

Subroutine::Subroutine()
{
}
string Subroutine::getSubRoutineName()
{
    return _subRoutineName;
}

void Subroutine::setSubRoutineName( string subRoutineName)
{
    _subRoutineName = subRoutineName;
}

SixRGrammerParser::StatementListContext *Subroutine::getSubRoutineStatements()
{
    return _subRoutineStatements;
}

void Subroutine::setSubRoutineStatements(SixRGrammerParser::StatementListContext *subRoutineStatements)
{
    _subRoutineStatements = subRoutineStatements;
}

string Subroutine::ToString()
{
    string returnS = "";
    returnS += returnVal.name + "!"+_subRoutineName+"\r\n";
    for(int i=0; i<variableCtx.size(); i++){
        returnS += variableCtx.at(i).ToString();
    }
    returnS += "Return Value: "+returnVal.ToString();
    returnS += "\r\n";
    return returnS;
}


vector<Variable *> Subroutine::getSubRoutineVariables()
{
    vector<Variable *> varByRef;
    for(int i=0; i<variableCtx.size(); i++)
        varByRef.push_back(&variableCtx[i]);
    return varByRef;
}

vector<Interrupt *> Subroutine::getSubRoutineInterrupts()
{
    vector<Interrupt *> intByRef;
    for(int i=0; i<interruptCtx.size(); i++)
        intByRef.push_back(&interruptCtx[i]);
    return intByRef;
}



bool Subroutine::isReturnValReady()
{
    return returnVal.evaluated;
}

bool Subroutine::getVariableByIdx(int idx, Variable &localVar)
{
    if(idx<variableCtx.size()){
        localVar = variableCtx.at(idx);
        return true;
    }
    else
        return false;
}



bool Subroutine::setVariableByName(Variable &localVar)
{
    for(int i=0; i<variableCtx.size(); i++)
        if(localVar.name == variableCtx[i].name){
            variableCtx.at(i)=localVar;
            return true;
        }
    return false;
}

bool Subroutine::setVariableByIdx(int idx, Variable &localVar)
{
    if(idx<variableCtx.size()){
        variableCtx.at(idx)=localVar;
        return true;
    }
    else
        return false;
}

void Subroutine::addVariableToCtx(Variable localVar)
{
    variableCtx.push_back(localVar);
}

bool Subroutine::getVariableByName(string name, Variable &localVar)
{
    for(int i=0; i<variableCtx.size(); i++)
        if(name == variableCtx[i].name){
            //Variable *localVar1 = variableCtx.at(i);
            localVar = variableCtx.at(i);
            return true;
        }
    return false;
}

bool Subroutine::setInterruptPriorityByName(string name, int priority)
{
    for(int i=0; i<interruptCtx.size(); i++)
        if(name == interruptCtx[i].getName()){
            interruptCtx[i].setPriority(priority);
            return true;
        }
    return false;
}

void Subroutine::addInterruptToCtx(Interrupt localInt)
{
    interruptCtx.push_back(localInt);
}

bool Subroutine::getInterruptByName(string name, Interrupt &localInt)
{
    for(int i=0; i<interruptCtx.size(); i++)
        if(name == interruptCtx[i].getName()){
            //Variable *localVar1 = variableCtx.at(i);
            localInt = interruptCtx.at(i);
            return true;
        }
    return false;
}
bool Subroutine::getInterruptByIdx(int idx, Interrupt &localInt)
{
    if(idx<interruptCtx.size()){
        localInt = interruptCtx.at(idx);
        return true;
    }
    else
        return false;
}


Variable *Subroutine::getReturnVal()
{
    return &returnVal;
}

string Subroutine::getSubRoutineReturnType()
{
    return returnVal.type;
}

void Subroutine::setSubRoutineReturnType(string subRoutineReturnType)
{
    returnVal.type = subRoutineReturnType;
}
