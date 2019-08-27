
#ifndef SUBROUTINE_H
#define SUBROUTINE_H

#include <vector>
#include "SixRGrammerParser.h"
#include "variable.h"
#include "interruptM.h"

class Subroutine
{
public:
    Subroutine();

private:
    string _subRoutineName;
    SixRGrammerParser::StatementListContext* _subRoutineStatements;
    Variable returnVal;
    vector<Variable> variableCtx;
    vector<Interrupt> interruptCtx;
public:

    bool isReturnValReady();
    void addVariableToCtx(Variable localVar);
    void addInterruptToCtx(Interrupt localInt);
    bool getInterruptByName(string name, Interrupt &localInt);
    bool getInterruptByIdx(int idx, Interrupt &localInt);
    bool setInterruptPriorityByName(string name, int priority);
    bool setInterruptPriorityByIdx(int idx, int priority);
    bool getVariableByName(string name, Variable &localVar);
    bool getVariableByIdx(int idx, Variable &localVar);
    bool setVariableByName(Variable &localVar);
    bool setVariableByIdx(int idx, Variable &localVar);
    vector<Variable *> getSubRoutineVariables();
    vector<Interrupt *> getSubRoutineInterrupts();


    Variable* getReturnVal();

    string getSubRoutineReturnType();
    void setSubRoutineReturnType(string getSubRoutineReturnType);

    string getSubRoutineName();
    void setSubRoutineName(string getSubRoutineName);

   // void addSubRoutineVariables(Variable *argument);

//    vector<string> getSubRoutinesParameter() const;
//    void setSubRoutinesParameter(const vector<string> &getSubRoutinesParameter);

    SixRGrammerParser::StatementListContext* getSubRoutineStatements();
    void setSubRoutineStatements(SixRGrammerParser::StatementListContext* subRoutineStatements);

    string ToString();
};


#endif // SUBROUTINE_H
