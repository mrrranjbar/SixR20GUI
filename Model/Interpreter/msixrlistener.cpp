#include "msixrlistener.h"
#include "SixRGrammerParser.h"
#include "variable.h"
//badeyd_1*************************
#include<QDebug>
#include <QThread>
#include <map>
//badeyd_1*************************


using namespace std;
using namespace antlr4;



MsixRlistener::MsixRlistener()
{
    controller = Controller::getInstance();
}

void MsixRlistener::enterModuleRoutines(SixRGrammerParser::ModuleRoutinesContext *ctx)
{
    //************************ali
   // vector<SixRGrammerParser::MainRoutineContext *>mainroutincontext=ctx->mainRoutine();
//    int k = ctx->children.size();
//    for (int i=0; i< ctx->children.size();i++) {
//        if(dynamic_cast<SixRGrammerParser::MainRoutineContext *>(ctx->children.at(i))!=nullptr)
//        {
//            enterMainRoutine(static_cast<SixRGrammerParser::MainRoutineContext *>(ctx->children.at(i)));
//        }else if(dynamic_cast<SixRGrammerParser::VariableDeclarationContext *>(ctx->children.at(i))!=nullptr)
//        {
//            enterVariableDeclaration(static_cast<SixRGrammerParser::VariableDeclarationContext *>(ctx->children.at(i)));
//        }else if(dynamic_cast<SixRGrammerParser::SubRoutineContext *>(ctx->children.at(i))!=nullptr)
//        {
//            enterSubRoutine(static_cast<SixRGrammerParser::SubRoutineContext *>(ctx->children.at(i)));
//        }
//    }

}
void MsixRlistener::enterStart(SixRGrammerParser::StartContext * ctx)
{

    //badeyd_1*******************************
    //    Variable lastPoint_J;
    //    Variable lastPoint_P;
    //    vector <double>lp_J;
    //    vector <double>lp_P;
    lastPoint_J.set_Type_v("pointj");
    lastPoint_P.set_Type_v("pointp");
    for(int i=0;i<6;i++)
    {
        lp_J.push_back(0);
        lp_P.push_back(0);
    }
    lastPoint_J.set_ArrayDims(lp_J);
    lastPoint_P.set_ArrayDims(lp_P);
    l_FF=0.0;
    l_CON=0.0;
    //akhar*********************************
    lastPointCIR_J_walker1.set_Type_v("pointj");
    lastPointCIR_P_walker1.set_Type_v("pointp");

    lastPointCIR_J_walker2.set_Type_v("pointj");
    lastPointCIR_P_walker2.set_Type_v("pointp");

    lastPointCIR_J_walker3.set_Type_v("pointj");
    lastPointCIR_P_walker3.set_Type_v("pointp");

    for(int i=0;i<6;i++)
    {
        lp_JCIR_walker1.push_back(0);
        lp_PCIR_walker1.push_back(0);

        lp_JCIR_walker2.push_back(0);
        lp_PCIR_walker2.push_back(0);

        lp_JCIR_walker3.push_back(0);
        lp_PCIR_walker3.push_back(0);
    }
    lastPointCIR_J_walker1.set_ArrayDims(lp_JCIR_walker1);
    lastPointCIR_P_walker1.set_ArrayDims(lp_PCIR_walker1);

    lastPointCIR_J_walker2.set_ArrayDims(lp_JCIR_walker2);
    lastPointCIR_P_walker2.set_ArrayDims(lp_PCIR_walker2);

    lastPointCIR_J_walker3.set_ArrayDims(lp_JCIR_walker3);
    lastPointCIR_P_walker3.set_ArrayDims(lp_PCIR_walker3);

    flag_walker1=0;
    flag_walker2=0;
    flag_walker3=0;
    waitSec=0;
    lastApproximate=0.0;
    frameTypeVariable="";
    //result=0.0;
    parameter=new vector<Variable>();
    //akhar*********************************
    //badeyd_1*******************************
    //enterModuleRoutines(ctx->moduleRoutines());

}



void MsixRlistener::enterVariableDeclaration(SixRGrammerParser::VariableDeclarationContext *ctx)
{
    SixRGrammerParser::TypeContext *type=ctx->type();
    SixRGrammerParser::VariableNameContext *variablename=ctx->variableName();
    SixRGrammerParser::VariableInitialisationContext *variable_init=ctx->variableInitialisation();
    auto value=variable_init->getText();
    auto t1=type->getText();
    auto t2=variablename->getText();
    //***********ali
    Variable *variable=new Variable();
    if(type==nullptr)
    {
        string type1="int";
        variable->set_Type_v(type1);
    }
    else
    {
        variable->set_Type_v(type->getText());
    }

    if(variablename->children.size()==1)
    {
        variable->set_name(variablename->getText());
        variable->set_IsArray(false);
        variable->set_ArraLength(1);
        //akhar********************
        if(variable->get_Type_v()=="int")
        {
            vector<double> jentry;
            jentry.push_back(stod(variable_init->children.at(1)->getText()));
            variable->set_ArrayDims(jentry);
        }
        else if(variable->get_Type_v()=="float")
        {
            vector<double> jentry;
            jentry.push_back(stod(variable_init->children.at(1)->getText()));
            variable->set_ArrayDims(jentry);
        }
        //akhar*********************
        else if(variable->get_Type_v()=="pointj")
        {
            //list<double> jentry;
            //badeyd*******************
            vector<double> jentry;
            //badeyd*******************
            for(int i=0;i<6;i++)
            {
                SixRGrammerParser::SixRJPartContext *test=variable_init->sixRJPR()->sixRJXPoint()->sixRJPoint()->sixRJPart().at(i);

                string temp1=test->expression()->conditionalOrExpression().at(0)->exclusiveOrExpression().at(0)->conditionalAndExpression()
                        .at(0)->additiveExpression().at(0)->multiplicativeExpression().at(0)->unaryNotExpression().at(0)
                        ->unaryPlusMinuxExpression()->primary()->literal()->numberLITERAL()->floatLITERAL()->FragFLOATLITERAL()->getText();
                jentry.push_back(std::stod(temp1));

            }
            variable->set_ArrayDims(jentry);

        }
        else if(variable->get_Type_v()=="pointp")
        {
            //list<double> jentry1;
            //badeyd_1**************
            vector <double> jentry1;
            //badeyd_1**************
            for(int i=0;i<3;i++)
            {
                SixRGrammerParser::SixRRPPartContext *test =variable_init->sixRJPR()->sixRJXPoint()->sixRPPoint()->sixRRPPart().at(i);

                string temp1=test->sixRPPart()->expression()->conditionalOrExpression().at(0)->exclusiveOrExpression().at(0)
                        ->conditionalAndExpression().at(0)->additiveExpression().at(0)->multiplicativeExpression().at(0)->unaryNotExpression()
                        .at(0)->unaryPlusMinuxExpression()->primary()->literal()->numberLITERAL()->floatLITERAL()->FragFLOATLITERAL()->getText();
                jentry1.push_back(std::stod(temp1));

            }
            for(int i=3;i<6;i++)
            {
                SixRGrammerParser::SixRRPPartContext *test =variable_init->sixRJPR()->sixRJXPoint()->sixRPPoint()->sixRRPPart().at(i);

                string temp1=test->sixRRPart()->expression()->conditionalOrExpression().at(0)->exclusiveOrExpression().at(0)
                        ->conditionalAndExpression().at(0)->additiveExpression().at(0)->multiplicativeExpression().at(0)->unaryNotExpression()
                        .at(0)->unaryPlusMinuxExpression()->primary()->literal()->numberLITERAL()->floatLITERAL()->FragFLOATLITERAL()->getText();
                jentry1.push_back(std::stod(temp1));

            }
            variable->set_ArrayDims(jentry1);

        }
        parameter->push_back(*variable);

    }
}

void MsixRlistener::enterMainRoutine(SixRGrammerParser::MainRoutineContext *ctx)
{

//    enterRoutineBody(ctx->routineBody());
    string main="main program has started";
    cout<<main;
}


//void MsixRlistener::enterStatementList(SixRGrammerParser::StatementListContext *ctx)
//{
//    int size=ctx->statement().size();
//    for(int i=0;i<size;i++)
//    {
//        SixRGrammerParser::StatementContext* st=ctx->statement().at(i);

//    }
//}
void MsixRlistener::enterSubRoutine(SixRGrammerParser::SubRoutineContext *ctx)
{

}
void MsixRlistener::enterRoutineBody(SixRGrammerParser::RoutineBodyContext *ctx)
{
    //enterStatementList(ctx->statementList());
}
void MsixRlistener::enterStatementList(SixRGrammerParser::StatementListContext *ctx)
{

//    for(int i=0;i<ctx->children.size();i++)
//    {

//        SixRGrammerParser::StatementContext* stat=ctx->statement().at(i);
//        if(dynamic_cast<SixRGrammerParser::VariableDeclarationContext *>(stat->children.at(0))!=nullptr)
//        {
//            enterVariableDeclaration((SixRGrammerParser::VariableDeclarationContext *)(stat->children.at(0)));
//        }
//        else if(dynamic_cast<SixRGrammerParser::STATPTPContext *>(stat)!=nullptr)
//        {
//            enterSTATPTP((SixRGrammerParser::STATPTPContext *) (stat));
//        }
//        else if(dynamic_cast<SixRGrammerParser::STATLINContext *>(stat)!=nullptr)
//        {
//            //bad eyd*************************************
//            enterSTATLIN((SixRGrammerParser::STATLINContext *) (stat));
//        }
//        //akhar******************
//        else if (dynamic_cast<SixRGrammerParser::STATCIRContext *>(stat)!=nullptr)
//        {
//            enterSTATCIR((SixRGrammerParser::STATCIRContext *) (stat));
//        }
//        //akhar******************
//        else if(dynamic_cast<SixRGrammerParser::STATWAITSECContext  *>(stat)!=nullptr)
//        {
//            enterSTATWAITSEC((SixRGrammerParser::STATWAITSECContext *) (stat));
//        }
//        else if(dynamic_cast<SixRGrammerParser::STATIFContext  *>(stat)!=nullptr)
//        {
//            enterSTATIF((SixRGrammerParser::STATIFContext *) (stat));
//        }
//        else if(dynamic_cast<SixRGrammerParser::STATIFContext  *>(stat)!=nullptr)
//        {
//            enterSTATFOR((SixRGrammerParser::STATFORContext *) (stat));
//        }
//        else if(dynamic_cast<SixRGrammerParser::STATWHILEContext  *>(stat)!=nullptr)
//        {
//            enterSTATWHILE((SixRGrammerParser::STATWHILEContext *) (stat));
//        }
//        else if(dynamic_cast<SixRGrammerParser::STATASINEPRContext *>(stat)!=nullptr)
//        {
//            enterSTATASINEPR((SixRGrammerParser::STATASINEPRContext *)(stat));
//        }
//        else if(dynamic_cast<SixRGrammerParser::STATASINEPRContext *>(stat)!=nullptr)
//        {
//            enterSTATSCF(SixRGrammerParser::STATSCFContext *ctx)  ;
//        }

////        //bad eyd**************************************


//    }

}




//***************************************************************************************assignment
//final********************************
void MsixRlistener::enterSTATASINEPR(SixRGrammerParser::STATASINEPRContext *ctx)

    {
    bool flagParameter1=false;
    bool flagParameter2=false;
    double result=0.0;
    string assignment=ctx->getText();
    int equalIndex=assignment.find("=");
    int endIndex=assignment.find("\n");
    double param1=0.0;
    double param2=0.0;
    int p1Length=0;
    int p2Length=0;
    string p1="";
    string p2="";
    int operationIndex=0;
    string variableName=assignment.substr(0,equalIndex);

    operationIndex=assignment.find("+");
    if(operationIndex==-1)
    {
        operationIndex=assignment.find("-");
        if(operationIndex==-1)
        {
            operationIndex=assignment.find("*");
            if(operationIndex==-1)
            {
                operationIndex=assignment.find("/");
                if(operationIndex==-1)
                {

                }
                else {
                    p1Length=operationIndex-equalIndex;
                    p2Length=endIndex-operationIndex;
                    p1=assignment.substr(equalIndex+1,p1Length-1);
                    p2=assignment.substr(operationIndex+1,p2Length-1);
                    for(int i=0;i<parameter->size()&&flagParameter1==false&&flagParameter2==false;i++)
                    {
                        if(parameter->at(i).get_name()==p1)
                        {
                            param1=parameter->at(i).get_Arraydims().at(0);
                            flagParameter1=true;
                        }
                        else if(parameter->at(i).get_name()==p2)
                        {
                            param1=parameter->at(i).get_Arraydims().at(0);
                            flagParameter2=true;
                        }

                    }
                    if(flagParameter1==false)
                    {
                        param1=stod(p1);
                    }
                    if(flagParameter2==false)
                    {
                        param2=stod(p2);
                    }
                    result=param1/param2;
                }
            }
            else {
                p1Length=operationIndex-equalIndex;
                p2Length=endIndex-operationIndex;
                p1=assignment.substr(equalIndex+1,p1Length-1);
                p2=assignment.substr(operationIndex+1,p2Length-1);
                for(int i=0;i<parameter->size()&&flagParameter1==false&&flagParameter2==false;i++)
                {
                    if(parameter->at(i).get_name()==p1)
                    {
                        param1=parameter->at(i).get_Arraydims().at(0);
                        flagParameter1=true;
                    }
                    else if(parameter->at(i).get_name()==p2)
                    {
                        param1=parameter->at(i).get_Arraydims().at(0);
                        flagParameter2=true;
                    }

                }
                if(flagParameter1==false)
                {
                    param1=stod(p1);
                }
                if(flagParameter2==false)
                {
                    param2=stod(p2);
                }
                result=param1*param2;
            }
        }
        else {
            p1Length=operationIndex-equalIndex;
            p2Length=endIndex-operationIndex;
            p1=assignment.substr(equalIndex+1,p1Length-1);
            p2=assignment.substr(operationIndex+1,p2Length-1);
            for(int i=0;i<parameter->size()&&flagParameter1==false&&flagParameter2==false;i++)
            {
                if(parameter->at(i).get_name()==p1)
                {
                    param1=parameter->at(i).get_Arraydims().at(0);
                    flagParameter1=true;
                }
                else if(parameter->at(i).get_name()==p2)
                {
                    param1=parameter->at(i).get_Arraydims().at(0);
                    flagParameter2=true;
                }

            }
            if(flagParameter1==false)
            {
                param1=stod(p1);
            }
            if(flagParameter2==false)
            {
                param2=stod(p2);
            }
            result=param1-param2;
        }
    }
    else {
        p1Length=operationIndex-equalIndex;
        p2Length=endIndex-operationIndex;
        p1=assignment.substr(equalIndex+1,p1Length-1);
        p2=assignment.substr(operationIndex+1,p2Length-1);
        for(int i=0;i<parameter->size()&&flagParameter1==false&&flagParameter2==false;i++)
        {
            if(parameter->at(i).get_name()==p1)
            {
                param1=parameter->at(i).get_Arraydims().at(0);
                flagParameter1=true;
            }
            else if(parameter->at(i).get_name()==p2)
            {
                param1=parameter->at(i).get_Arraydims().at(0);
                flagParameter2=true;
            }

        }
        if(flagParameter1==false)
        {
            param1=stod(p1);
        }
        if(flagParameter2==false)
        {
            param2=stod(p2);
        }

        result=param1+param2;

    }
    bool flagVariableName=false;
    bool flagDone=false;
    for(int i=0;i<parameter->size()&&flagVariableName==false&&flagDone==false;i++)
    {
        if(parameter->at(i).get_name()==variableName)
        {
//            parameter->at(i).set_ArrayDims(0,result);
//            Variable *index=* parameter->at(i);
            parameter->erase(parameter->begin()+i);
            Variable variable;//=new Variable();
            entry.push_back(result);
            variable.set_ArrayDims(entry);
            variable.set_name(variableName);
            parameter->at(i).set_ArrayDims(entry);
//            flagVariableName=true;
//            parameter->at(i).set_AssignmentValue(result);
            parameter->push_back(variable);
            flagDone=true;

        }
    }


//    SixRGrammerParser::AssignmentExpressionContext *assignment=static_cast<SixRGrammerParser::AssignmentExpressionContext *>(ctx->children.at(0));
//    enterAssignmentExpression(assignment);

}
//final*****************************************************************

void MsixRlistener::enterAssignmentExpression(SixRGrammerParser::AssignmentExpressionContext *ctx)
{

    double result=0.0;
    string variableName=ctx->children.at(0)->getText();
    for(int i=0;i<parameter->size();i++)
    {
        if(parameter->at(i).get_name()==variableName)
        {
            parameter->at(i).set_ArrayDims(0,lastAssignment);
        }
    }
//    SixRGrammerParser::ExpressionContext *complicatedExpression=nullptr;
//    SixRGrammerParser::AdditiveExpressionContext *additiveExpression=nullptr;
//    if(dynamic_cast<SixRGrammerParser::ExpressionContext *>(ctx->children.at(2))!=nullptr)
//    {

//        SixRGrammerParser::ExpressionContext *complicatedExpression=static_cast<SixRGrammerParser::ExpressionContext *>(ctx->children.at(2));
//    }
//    else {
//        qInfo("there is no complicated expression");
//    }

//    if(dynamic_cast<SixRGrammerParser::AdditiveExpressionContext *>(complicatedExpression->conditionalOrExpression().at(0)
//                      ->exclusiveOrExpression().at(0)->conditionalAndExpression().at(0)->additiveExpression().at(0))!=nullptr)
//    {
//        additiveExpression=complicatedExpression->conditionalOrExpression().at(0)
//                ->exclusiveOrExpression().at(0)->conditionalAndExpression().at(0)->additiveExpression().at(0);

//    }
//    for(int i=0;dynamic_cast<SixRGrammerParser::MultiplicativeExpressionContext *>(additiveExpression->children.at(2*i))!=nullptr;i++)
//    {
//        if(2*i-1>0)
//        {
//            if(additiveExpression->children.at(2*i-1)->getText()=="+")
//            {
//                lastMultiplicateExpression=0.0;
//                enterMultiplicativeExpression(static_cast<SixRGrammerParser::MultiplicativeExpressionContext *>
//                                              (additiveExpression->children.at(2*i)));

//                result=result+lastMultiplicateExpression;
//            }
//            else if(additiveExpression->children.at(2*i-1)->getText()=="-")
//            {
//                lastMultiplicateExpression=0.0;
//                enterMultiplicativeExpression(static_cast<SixRGrammerParser::MultiplicativeExpressionContext *>
//                                              (additiveExpression->children.at(2*i)));

//                result=result-lastMultiplicateExpression;
//            }

//        }
//        else {
//            lastMultiplicateExpression=0.0;
//            enterMultiplicativeExpression(static_cast<SixRGrammerParser::MultiplicativeExpressionContext *>(additiveExpression->children.at(2*i)));
//            result=lastMultiplicateExpression;
//        }

//    }
//    for(int i=0;i<parameter->size();i++)
//    {
//        if(parameter->at(i).get_name()==variableName)
//        {
//            parameter->at(i).set_ArrayDims(0,result);
//        }
//    }


}

void MsixRlistener::enterExpression(SixRGrammerParser::ExpressionContext *ctx)
{

}

//void MsixRlistener::enterAdditiveExpression(SixRGrammerParser::AdditiveExpressionContext *ctx)
//{
//  int size=ctx->children.size();

//  if(ctx->children.size()==3)
//  {
//      int flag1=0;
//      int flag2=0;
//      double param1=0.0;
//      double param2=0.0;

//      string operation=ctx->children.at(1)->getText();

//      if(operation=="+")
//      {
//          for(int i=0;i<parameter->size();i++)
//          {
//              if(parameter[i]->get_name()==ctx->children.at(0)->getText())
//              {
//                  flag1=1;
//                  param1=parameter[i]->get_Arraydims().at(0);
//              }
//              if(flag1=0)
//              {
//                  param1=stod(ctx->children.at(0)->getText());
//              }
//              if(parameter[i]->get_name()==ctx->children.at(2)->getText())
//              {
//                  flag2=1;
//                  param2=parameter[i]->get_Arraydims().at(0);
//              }
//              if(flag2==0)
//              {
//                  param2=stod(ctx->children.at(2)->getText());
//              }
//          }
//          lastAssignment=param1+param2;

//      }
//      else if(operation=="-")
//      {
//          for(int i=0;i<parameter->size();i++)
//          {
//              if(parameter[i]->get_name()==ctx->children.at(0)->getText())
//              {
//                  flag1=1;
//                  param1=parameter[i]->get_Arraydims().at(0);
//              }
//              if(flag1=0)
//              {
//                  param1=stod(ctx->children.at(0)->getText());
//              }
//              if(parameter[i]->get_name()==ctx->children.at(2)->getText())
//              {
//                  flag2=1;
//                  param2=parameter[i]->get_Arraydims().at(0);
//              }
//              if(flag2==0)
//              {
//                  param2=stod(ctx->children.at(2)->getText());
//              }
//          }
//          lastAssignment=param1-param2;

//      }
//  }

//}

//void MsixRlistener::enterMultiplicativeExpression(SixRGrammerParser::MultiplicativeExpressionContext *ctx)
//{
//    if(ctx->children.size()==3)
//    {
//        int flag1=0;
//        int flag2=0;
//        double param1=0.0;
//        double param2=0.0;
//        if(ctx->getText().find("*"))
//        {
//            for(int i=0;i<parameter->size();i++)
//            {
//                if(parameter[i]->get_name()==ctx->children.at(0)->getText())
//                {
//                    flag1=1;
//                    param1=parameter[i]->get_Arraydims().at(0);
//                }
//                if(flag1=0)
//                {
//                    param1=stod(ctx->children.at(0)->getText());
//                }
//                if(parameter[i]->get_name()==ctx->children.at(2)->getText())
//                {
//                    flag2=1;
//                    param2=parameter[i]->get_Arraydims().at(0);
//                }
//                if(flag2==0)
//                {
//                    param2=stod(ctx->children.at(2)->getText());
//                }
//            }
//            lastAssignment=param1*param2;
//            //ctx->children.at(0)->getText()+ctx->children.at(2)->getText();
//        }
//        else if(ctx->getText().find("/"))
//        {

//            for(int i=0;i<parameter->size();i++)
//            {
//                if(parameter[i]->get_name()==ctx->children.at(0)->getText())
//                {
//                    flag1=1;
//                    param1=parameter[i]->get_Arraydims().at(0);
//                }
//                if(flag1=0)
//                {
//                    param1=stod(ctx->children.at(0)->getText());
//                }
//                if(parameter[i]->get_name()==ctx->children.at(2)->getText())
//                {
//                    flag2=1;
//                    param2=parameter[i]->get_Arraydims().at(0);
//                }
//                if(flag2==0)
//                {
//                    param2=stod(ctx->children.at(2)->getText());
//                }
//            }
//            lastAssignment=param1/param2;
//        }
//    }

//    }
//    for(int i=0;dynamic_cast<SixRGrammerParser::UnaryNotExpressionContext *>(ctx->children.at(2*i))!=nullptr;i++)
//    {
//        if(ctx->children.at(2*i-1)!=nullptr)
//        {
//            if(ctx->children.at(2*i-1)->getText()=="*")
//            {
//                lastMultiplicateExpression=lastMultiplicateExpression*stod(ctx->children.at(2*i)->getText());
//            }
//            else if(ctx->children.at(2*i-1)->getText()=="/"){
//                if(stod(ctx->children.at(2*i)->getText())!=0.0)
//                {
//                    lastMultiplicateExpression=lastMultiplicateExpression/stod(ctx->children.at(2*i)->getText());
//                }
//                else {
//                    qInfo("devision by zero");
//                }
//            }
//        }
//        else {
//            lastMultiplicateExpression=stod(ctx->children.at(2*i)->getText());
//        }
//    }

//}




//***************************************************************************************assignment


void MsixRlistener::enterSTATWHILE(SixRGrammerParser::STATWHILEContext *ctx)
{
    auto expression=ctx->children.at(1);
    SixRGrammerParser::ExpressionContext *expression1=dynamic_cast<SixRGrammerParser::ExpressionContext *>( expression);

    string firstVariableName=expression1->children.at(0)->getText();
    auto firstVariableValue=0;
    string relationOperation=expression1->children.at(1)->getText();
    auto secondVariableValue=0;
    string secondVarialeName=expression1->children.at(2)->getText();
    for(int i=0;i<parameter->size();i++)
    {
        if(parameter->at(i).get_name()==firstVariableName)
        {
            firstVariableValue=parameter->at(i).get_Arraydims().at(0);
        }
        if(parameter->at(i).get_name()==secondVarialeName)
        {
            secondVariableValue=parameter->at(i).get_Arraydims().at(0);
        }
    }
    if(firstVariableValue==0)
    {
        firstVariableValue=stoi(firstVariableName);
    }
    if(secondVariableValue==0)
    {
        secondVariableValue=stoi(secondVarialeName);
    }
    if(relationOperation=="==")
    {
        if(firstVariableValue==secondVariableValue)
        {
            SixRGrammerParser::StatementListContext* statementList =static_cast<SixRGrammerParser::StatementListContext *>( ctx->children.at(4));
            enterStatementList((SixRGrammerParser::StatementListContext *) (statementList));
        }
    }
    else if(relationOperation=="!=")
    {
        if(firstVariableValue!=secondVariableValue)
        {
            SixRGrammerParser::StatementListContext* statementList =static_cast<SixRGrammerParser::StatementListContext *>( ctx->children.at(4));
            enterStatementList((SixRGrammerParser::StatementListContext *) (statementList));
        }
    }
    else if(relationOperation=="<=")
    {
        if(firstVariableValue<=secondVariableValue)
        {
            SixRGrammerParser::StatementListContext* statementList =static_cast<SixRGrammerParser::StatementListContext *>( ctx->children.at(4));
            enterStatementList((SixRGrammerParser::StatementListContext *) (statementList));
        }
    }
    else if(relationOperation==">=")
    {
        if(firstVariableValue>=secondVariableValue)
        {
            SixRGrammerParser::StatementListContext* statementList =static_cast<SixRGrammerParser::StatementListContext *>( ctx->children.at(4));
            enterStatementList((SixRGrammerParser::StatementListContext *) (statementList));
        }
    }
    else if(relationOperation=="<")
    {
        if(firstVariableValue<secondVariableValue)
        {
            SixRGrammerParser::StatementListContext* statementList =static_cast<SixRGrammerParser::StatementListContext *>( ctx->children.at(4));
            enterStatementList((SixRGrammerParser::StatementListContext *) (statementList));
        }
    }
    else if(relationOperation==">")
    {
        if(firstVariableValue>secondVariableValue)
        {
            SixRGrammerParser::StatementListContext* statementList =static_cast<SixRGrammerParser::StatementListContext *>( ctx->children.at(4));
            enterStatementList((SixRGrammerParser::StatementListContext *) (statementList));
        }
    }
}

void MsixRlistener::enterSTATFOR(SixRGrammerParser::STATFORContext *ctx)
{
    int startForLoop=stoi(ctx->children.at(3)->getText());
    int endForLoop=stoi(ctx->children.at(5)->getText());
    for(int i=startForLoop;i<endForLoop;i++)
    {
        SixRGrammerParser::StatementListContext* statementList =static_cast<SixRGrammerParser::StatementListContext *>( ctx->children.at(7));
        enterStatementList((SixRGrammerParser::StatementListContext *) (statementList));
    }

}
void MsixRlistener::enterSTATIF(SixRGrammerParser::STATIFContext *ctx)
{
    auto expression=ctx->children.at(1);
    SixRGrammerParser::ExpressionContext *expression1=static_cast<SixRGrammerParser::ExpressionContext *>( expression);

    string firstVariableName=expression1->children.at(0)->getText();
    auto firstVariableValue=0;
    string relationOperation=expression1->children.at(1)->getText();
    auto secondVariableValue=0;
    string secondVarialeName=expression1->children.at(2)->getText();
    for(int i=0;i<parameter->size();i++)
    {
        if(parameter->at(i).get_name()==firstVariableName)
        {
            firstVariableValue=parameter->at(i).get_Arraydims().at(0);
        }
        if(parameter->at(i).get_name()==secondVarialeName)
        {
            secondVariableValue=parameter->at(i).get_Arraydims().at(0);
        }
    }

    if(firstVariableValue==0)
    {
        firstVariableValue=stoi(firstVariableName);
    }
    if(secondVariableValue==0)
    {
        secondVariableValue=stoi(secondVarialeName);
    }
    if(relationOperation=="==")
    {
        if(firstVariableValue==secondVariableValue)
        {
            SixRGrammerParser::StatementListContext* statementList=static_cast<SixRGrammerParser::StatementListContext *>(ctx->children.at(4));
            enterStatementList((SixRGrammerParser::StatementListContext *) (statementList));
        }
        else {
            if(ctx->children.at(5)->getText()!="\n")
            {
                SixRGrammerParser::StatementListContext* statementList =static_cast<SixRGrammerParser::StatementListContext *>( ctx->children.at(7));
                enterStatementList((SixRGrammerParser::StatementListContext *) (statementList));

            }
        }
    }
    else if(relationOperation=="!=")
    {
        if(firstVariableValue!=secondVariableValue)
        {
            SixRGrammerParser::StatementListContext* statementList =static_cast<SixRGrammerParser::StatementListContext *>( ctx->children.at(4));
            enterStatementList((SixRGrammerParser::StatementListContext *) (statementList));
        }
        else {
            if(ctx->children.at(5)->getText()!="\n")
            {
                SixRGrammerParser::StatementListContext* statementList =static_cast<SixRGrammerParser::StatementListContext *>( ctx->children.at(7));
                enterStatementList((SixRGrammerParser::StatementListContext *) (statementList));

            }
        }
    }
    else if(relationOperation=="<=")
    {
        if(firstVariableValue<=secondVariableValue)
        {
            SixRGrammerParser::StatementListContext* statementList =static_cast<SixRGrammerParser::StatementListContext *>( ctx->children.at(4));
            enterStatementList((SixRGrammerParser::StatementListContext *) (statementList));
        }
        else {
            if(ctx->children.at(5)->getText()!="\n")
            {
                SixRGrammerParser::StatementListContext* statementList =static_cast<SixRGrammerParser::StatementListContext *>( ctx->children.at(7));
                enterStatementList((SixRGrammerParser::StatementListContext *) (statementList));

            }
        }
    }
    else if(relationOperation==">=")
    {
        if(firstVariableValue>=secondVariableValue)
        {
            SixRGrammerParser::StatementListContext* statementList =static_cast<SixRGrammerParser::StatementListContext *>( ctx->children.at(4));
            enterStatementList((SixRGrammerParser::StatementListContext *) (statementList));
        }
        else {
            if(ctx->children.at(5)->getText()!="\n")
            {
                SixRGrammerParser::StatementListContext* statementList=static_cast<SixRGrammerParser::StatementListContext *>( ctx->children.at(7));
                enterStatementList((SixRGrammerParser::StatementListContext *)(statementList));

            }
        }
    }
    else if(relationOperation=="<")
    {
        if(firstVariableValue<secondVariableValue)
        {
            SixRGrammerParser::StatementListContext* statementList =static_cast<SixRGrammerParser::StatementListContext *>( ctx->children.at(4));
            enterStatementList((SixRGrammerParser::StatementListContext *) (statementList));
        }
        else {
            if(ctx->children.at(5)->getText()=="ELSE")
            {
                SixRGrammerParser::StatementListContext* statementList =static_cast<SixRGrammerParser::StatementListContext *>( ctx->children.at(7));
                enterStatementList((SixRGrammerParser::StatementListContext *) (statementList));
            }
        }
    }
    else if(relationOperation==">")
    {
        if(firstVariableValue>secondVariableValue)
        {
            SixRGrammerParser::StatementListContext* statementList =static_cast<SixRGrammerParser::StatementListContext *>( ctx->children.at(4));
            enterStatementList((SixRGrammerParser::StatementListContext *) (statementList));
        }
        else {
            if(ctx->children.at(5)->getText()!="\n")
            {
                SixRGrammerParser::StatementListContext* statementList =static_cast<SixRGrammerParser::StatementListContext *>( ctx->children.at(7));
                enterStatementList((SixRGrammerParser::StatementListContext *) (statementList));
            }
        }
    }


}
void MsixRlistener::enterSTATSCF(SixRGrammerParser::STATSCFContext *ctx)
{
    string nameOfSetFrame=ctx->children.at(0)->getText();
    string kindOfFrameType=ctx->children.at(1)->getText();
    if(nameOfSetFrame=="SETFRAME")
    {
        if(kindOfFrameType=="TOOL"||kindOfFrameType=="BASE"||kindOfFrameType=="TASK"||kindOfFrameType=="OBJECT")
        {
            frameTypeVariable=kindOfFrameType;
        }
    }

}

void MsixRlistener::enterSTATWAITSEC(SixRGrammerParser::STATWAITSECContext *ctx)
{
    waitSec=stod(ctx->children.at(2)->getText());
    //controller
    //*********** call waitSec
    //controller
}
void MsixRlistener::enterSTATPTP(SixRGrammerParser::STATPTPContext *ctx)
{
    //while(1);
//        Thre
//    }
    string nameOfStatement=ctx->children.at(1)->getText();
    //badeyd_2*************************************
    string nameOfFF="";
    string ffPart="";
    string nameOfCON="";
    string conPart="";
    nameOfFF=(ctx->children.at(2)->getText()!="\n"?ctx->children.at(2)->getText():"");
    if(nameOfFF!="")
    {
        //ffPart=(ctx->children.at(3)!=nullptr?ctx->children.at(3)->getText():"");
        ffPart=ctx->children.at(3)->getText();
    }
    nameOfCON=(ctx->children.at(4)->getText()!="\n"?ctx->children.at(4)->getText():"");
    if(nameOfCON!="")
    {
        //conPart=(ctx->children.at(5)!=nullptr?ctx->children.at(5)->getText():"");
        conPart=ctx->children.at(5)->getText();
    }
    if(nameOfFF=="F" || nameOfFF=="f")
    {
        l_FF=stod(ffPart);
    }
    if(nameOfCON=="CON" || nameOfCON=="con")
    {
        l_CON=stod(conPart);
    }
    //badeyd_2*************************************
    if(ctx->children.at(6)->getText()!="\n")
    {
        lastApproximate=stod(ctx->children.at(6)->getText());
    }

    auto walker=ctx->children.at(1);
    Variable var;
    //badeyd_1*******************************
    //    Variable lastPoint_J;
    //    Variable lastPoint_P;
    //    vector <double>lp_J;
    //    vector <double>lp_P;
    //    lastPoint_J.set_Type_v("pointj");
    //    lastPoint_P.set_Type_v("pointp");
    //    for(int i=0;i<6;i++)
    //    {
    //        lp_J.push_back(0);
    //        lp_P.push_back(0);
    //    }
    //    lastPoint_J.set_ArrayDims(lp_J);
    //    lastPoint_P.set_ArrayDims(lp_P);
    //badeyd_1*******************************

    if(dynamic_cast<SixRGrammerParser::VariableNameContext *>( walker)!=nullptr)
    {
        string Var=walker->getText();

        for(int i=0;i<parameter->size();i++)
        {
            if(parameter->at(i).get_name()==Var)
            {
                var=parameter->at(i);
                break;
            }
        }
    }
    else if(dynamic_cast<SixRGrammerParser::SixRJXPointContext *>( walker)!=nullptr)
    {
        list<double> value;
        auto subwalker=walker->children.at(0);
        if(dynamic_cast<SixRGrammerParser::SixRJPointContext *>(subwalker)!=nullptr)
        {

            //           for(int i=0;i<6;i++)
            //            {
            //                 auto subwalker1=subwalker->children.at(i*2+1);
            //                if(dynamic_cast<SixRGrammerParser::SixRJPartContext*>(subwalker1)!=nullptr)
            //                {
            //                   string axis1=subwalker1->children.at(2)->getText();
            //                   //int k1=5;
            //                   value.push_back(std::stod(axis1));
            //                }


            //badeyd_1***************************************************************************************************
            for(int i=0;subwalker->children.at(i*2)->getText()!="]";i++)
            {
                auto subwalker1=subwalker->children.at(i*2+1);
                if(dynamic_cast<SixRGrammerParser::SixRJPartContext*>(subwalker1)!=nullptr)
                {
                    string axis1=subwalker1->children.at(2)->getText();
                    string axis1Name=subwalker1->children.at(0)->getText();


                    if(axis1Name=="j1")
                    {
                        lastPoint_J.set_ArrayDims(0,std::stod(axis1));
                    }
                    else if(axis1Name=="j2")
                    {
                        lastPoint_J.set_ArrayDims(1,std::stod(axis1));
                    }
                    else if(axis1Name=="j3")
                    {
                        lastPoint_J.set_ArrayDims(2,std::stod(axis1));
                    }
                    else if(axis1Name=="j4")
                    {
                        lastPoint_J.set_ArrayDims(3,std::stod(axis1));
                    }
                    else if(axis1Name=="j5")
                    {
                        lastPoint_J.set_ArrayDims(4,std::stod(axis1));
                    }
                    else if(axis1Name=="j6")
                    {
                        lastPoint_J.set_ArrayDims(5,std::stod(axis1));
                    }

                }
            }

            //badeyd_1***************************************************************************************************

            //            }
            //controller
            //********** with lastPoint_J and l_FF and l_CON and degree and lastAproxiamte
            //controller

            if(controller->beckhoff->IsEnableMovement)
            {
                for(int i=0; i< controller->beckhoff->NumberOfRobotMotors; i++){
                    controller->beckhoff->setTargetPosition(lastPoint_J.get_Arraydims().at(i),i);
                }
                controller->beckhoff->setTargetPosition(l_FF,6);
                controller->beckhoff->setTargetPosition(l_CON,7);
                controller->beckhoff->setGUIManager(8);
                QThread::msleep(300);
                while(controller->beckhoff->getNextCommandSign()==0){
                QThread::msleep(100);
                }
                 currentLine++;
            }
            //var.set_ArrayDims(lastPoint_J.get_Arraydims());
            //var.set_Type_v("pointj");
        }
        else if(dynamic_cast<SixRGrammerParser::SixRPPointContext *>(subwalker)!=nullptr)
        {

            list<double> value;

            //            for(int i=0;i<6;i++)
            //            {
            //                auto subwalker1=subwalker->children.at(i*2+1);
            //                if(dynamic_cast<SixRGrammerParser::SixRPPartContext *>(subwalker1->children.at(0))!=nullptr)
            //                {
            //                   string axis1=subwalker1->children.at(0)->children.at(2)->getText();
            //                   //int k1=5;
            //                   value.push_back(std::stod(axis1));
            //                }
            //                else if(dynamic_cast<SixRGrammerParser::SixRRPartContext *>(subwalker1->children.at(0))!=nullptr)
            //                {

            //                    string axis2=subwalker1->children.at(0)->children.at(2)->getText();
            //                    int k2=5;
            //                    value.push_back(std::stod(axis2));
            //              }
            //            }
            //badeyd_1********************************************************************************
            for(int i=0;subwalker->children.at(i*2)->getText()!="]";i++)
            {
                auto subwalker1=subwalker->children.at(i*2+1);
                if(dynamic_cast<SixRGrammerParser::SixRPPartContext *>(subwalker1->children.at(0))!=nullptr)
                {
                    string axis1=subwalker1->children.at(0)->children.at(2)->getText();
                    string axis1Name=subwalker1->children.at(0)->children.at(0)->getText();

                    if(axis1Name=="x")
                    {
                        lastPoint_P.set_ArrayDims(0,std::stod(axis1));
                    }
                    else if(axis1Name=="y")
                    {
                        lastPoint_P.set_ArrayDims(1,std::stod(axis1));
                    }
                    else if(axis1Name=="z")
                    {
                        lastPoint_P.set_ArrayDims(2,std::stod(axis1));
                    }
                }
                if(dynamic_cast<SixRGrammerParser::SixRRPartContext *>(subwalker1->children.at(0))!=nullptr)
                {
                    string axis1=subwalker1->children.at(0)->children.at(2)->getText();
                    string axis1Name=subwalker1->children.at(0)->children.at(0)->getText();
                    if(axis1Name=="a")
                    {
                        lastPoint_P.set_ArrayDims(3,std::stod(axis1));
                    }
                    else if(axis1Name=="b")
                    {
                        lastPoint_P.set_ArrayDims(4,std::stod(axis1));
                    }
                    else if(axis1Name=="c")
                    {
                        lastPoint_P.set_ArrayDims(5,std::stod(axis1));
                    }
                }
            }
            //badeyd_1********************************************************************************
            //controller
            //********** with lastPoint_P and use l_FF and l_CON and degree and lastAproximate
            //controller


            //var.set_ArrayDims(lastPoint_P.get_Arraydims());
           //var.set_Type_v("pointp");

        }

    }
}
//badeyd****************************
//akhara****************************
//akhara*****************************

void MsixRlistener::enterSTATCIR(SixRGrammerParser::STATCIRContext *ctx)
{
    string nameOfstatement1=ctx->children.at(1)->getText();
    string nameOfstatement2=ctx->children.at(2)->getText();
    string nameOfstatement3=ctx->children.at(3)->getText();
    string nameOfFF="";
    string ffPart="";
    string nameOfCON="";
    string conPart="";
    string nameofDEG="";
    string degPart="";
    double degree=0.0;

//    if(ctx->children.at(4)->getText()!="\n")
//    {
//        degree=stod(ctx->children.at(4)->getText());
//    }
//    else {
//        degree=0.0;
//    }
    nameofDEG=(ctx->children.at(5)->getText()!="\n"?ctx->children.at(5)->getText():"");
    if(nameofDEG!="")
    {
        degPart=ctx->children.at(6)->getText();
    }
    nameOfFF=(ctx->children.at(7)->getText()!="\n"?ctx->children.at(7)->getText():"");
    if(nameOfFF!="")
    {
        ffPart=ctx->children.at(8)->getText();
    }
    nameOfCON=(ctx->children.at(9)->getText()!="\n"?ctx->children.at(9)->getText():"");
    if(nameOfCON!="")
    {
        conPart=ctx->children.at(10)->getText();
    }
    if(nameOfFF=="F")
    {
        l_FF=stod(ffPart);
    }
    if(nameOfCON=="CON")
    {
        l_CON=stod(conPart);
    }
    if(nameofDEG=="DEG")
    {
        degree=stod(degPart);
    }
    if(ctx->children.at(11)->getText()!="\n")
    {
        lastApproximate=stod(ctx->children.at(11)->getText());
    }



    auto walker1=ctx->children.at(1);
    auto walker2=ctx->children.at(2);
    auto walker3=ctx->children.at(3);
    Variable var;

    if(dynamic_cast<SixRGrammerParser::VariableNameContext *>( walker1)!=nullptr)
    {
        string Var=walker1->getText();

        for(int i=0;i<parameter->size();i++)
        {
            if(parameter->at(i).get_name()==Var)
            {
                var=parameter->at(i);
                break;
            }
        }
    }

    if(dynamic_cast<SixRGrammerParser::VariableNameContext *>( walker2)!=nullptr)
    {
        string Var=walker2->getText();

        for(int i=0;i<parameter->size();i++)
        {
            if(parameter->at(i).get_name()==Var)
            {
                var=parameter->at(i);
                break;
            }
        }
    }
    if(dynamic_cast<SixRGrammerParser::VariableNameContext *>( walker3)!=nullptr)
    {
        string Var=walker3->getText();

        for(int i=0;i<parameter->size();i++)
        {
            if(parameter->at(i).get_name()==Var)
            {
                var=parameter->at(i);
                break;
            }
        }
    }

    if(dynamic_cast<SixRGrammerParser::SixRJXPointContext *>(walker1)!=nullptr)
    {
        list<double> value;
        auto subwalker=walker1->children.at(0);
        if(dynamic_cast<SixRGrammerParser::SixRJPointContext *>(subwalker)!=nullptr)
        {
            for(int i=0;subwalker->children.at(i*2)->getText()!="]";i++)
            {
                auto subwalker1=subwalker->children.at(i*2+1);
                if(dynamic_cast<SixRGrammerParser::SixRJPartContext*>(subwalker1)!=nullptr)
                {
                    string axis1=subwalker1->children.at(2)->getText();
                    string axis1Name=subwalker1->children.at(0)->getText();


                    if(axis1Name=="j1")
                    {
                        lastPointCIR_J_walker1.set_ArrayDims(0,std::stod(axis1));
                    }
                    else if(axis1Name=="j2")
                    {
                        lastPointCIR_J_walker1.set_ArrayDims(1,std::stod(axis1));
                    }
                    else if(axis1Name=="j3")
                    {
                        lastPointCIR_J_walker1.set_ArrayDims(2,std::stod(axis1));
                    }
                    else if(axis1Name=="j4")
                    {
                        lastPointCIR_J_walker1.set_ArrayDims(3,std::stod(axis1));
                    }
                    else if(axis1Name=="j5")
                    {
                        lastPointCIR_J_walker1.set_ArrayDims(4,std::stod(axis1));
                    }
                    else if(axis1Name=="j6")
                    {
                        lastPointCIR_J_walker1.set_ArrayDims(5,std::stod(axis1));
                    }

                }
            }
            flag_walker1=1;
            var.set_ArrayDims(lastPointCIR_J_walker1.get_Arraydims());
            var.set_Type_v("pointj");

        }
        else if(dynamic_cast<SixRGrammerParser::SixRPPointContext *>(subwalker)!=nullptr)
        {
            list<double> value;
            for(int i=0;subwalker->children.at(i*2)->getText()!="]";i++)
            {
                auto subwalker1=subwalker->children.at(i*2+1);
                if(dynamic_cast<SixRGrammerParser::SixRPPartContext *>(subwalker1->children.at(0))!=nullptr)
                {
                    string axis1=subwalker1->children.at(0)->children.at(2)->getText();
                    string axis1Name=subwalker1->children.at(0)->children.at(0)->getText();

                    if(axis1Name=="x")
                    {
                        lastPointCIR_P_walker1.set_ArrayDims(0,std::stod(axis1));
                    }
                    else if(axis1Name=="y")
                    {
                        lastPointCIR_P_walker1.set_ArrayDims(1,std::stod(axis1));
                    }
                    else if(axis1Name=="z")
                    {
                        lastPointCIR_P_walker1.set_ArrayDims(2,std::stod(axis1));
                    }
                }
                if(dynamic_cast<SixRGrammerParser::SixRRPartContext *>(subwalker1->children.at(0))!=nullptr)
                {
                    string axis1=subwalker1->children.at(0)->children.at(2)->getText();
                    string axis1Name=subwalker1->children.at(0)->children.at(0)->getText();
                    if(axis1Name=="a")
                    {
                        lastPointCIR_P_walker1.set_ArrayDims(3,std::stod(axis1));
                    }
                    else if(axis1Name=="b")
                    {
                        lastPointCIR_P_walker1.set_ArrayDims(4,std::stod(axis1));
                    }
                    else if(axis1Name=="c")
                    {
                        lastPointCIR_P_walker1.set_ArrayDims(5,std::stod(axis1));
                    }
                }
            }
            flag_walker1=2;
            var.set_ArrayDims(lastPoint_P.get_Arraydims());
            var.set_Type_v("pointp");
        }

    }
    if(dynamic_cast<SixRGrammerParser::SixRJXPointContext *>(walker2)!=nullptr)
    {
        list<double> value;
        auto subwalker=walker1->children.at(0);
        if(dynamic_cast<SixRGrammerParser::SixRJPointContext *>(subwalker)!=nullptr)
        {
            for(int i=0;subwalker->children.at(i*2)->getText()!="]";i++)
            {
                auto subwalker1=subwalker->children.at(i*2+1);
                if(dynamic_cast<SixRGrammerParser::SixRJPartContext*>(subwalker1)!=nullptr)
                {
                    string axis1=subwalker1->children.at(2)->getText();
                    string axis1Name=subwalker1->children.at(0)->getText();


                    if(axis1Name=="j1")
                    {
                        lastPointCIR_J_walker2.set_ArrayDims(0,std::stod(axis1));
                    }
                    else if(axis1Name=="j2")
                    {
                        lastPointCIR_J_walker2.set_ArrayDims(1,std::stod(axis1));
                    }
                    else if(axis1Name=="j3")
                    {
                        lastPointCIR_J_walker2.set_ArrayDims(2,std::stod(axis1));
                    }
                    else if(axis1Name=="j4")
                    {
                        lastPointCIR_J_walker2.set_ArrayDims(3,std::stod(axis1));
                    }
                    else if(axis1Name=="j5")
                    {
                        lastPointCIR_J_walker2.set_ArrayDims(4,std::stod(axis1));
                    }
                    else if(axis1Name=="j6")
                    {
                        lastPointCIR_J_walker2.set_ArrayDims(5,std::stod(axis1));
                    }

                }
            }

            flag_walker2=1;
            var.set_ArrayDims(lastPointCIR_J_walker2.get_Arraydims());
            var.set_Type_v("pointj");

        }
        else if(dynamic_cast<SixRGrammerParser::SixRPPointContext *>(subwalker)!=nullptr)
        {
            list<double> value;
            for(int i=0;subwalker->children.at(i*2)->getText()!="]";i++)
            {
                auto subwalker1=subwalker->children.at(i*2+1);
                if(dynamic_cast<SixRGrammerParser::SixRPPartContext *>(subwalker1->children.at(0))!=nullptr)
                {
                    string axis1=subwalker1->children.at(0)->children.at(2)->getText();
                    string axis1Name=subwalker1->children.at(0)->children.at(0)->getText();

                    if(axis1Name=="x")
                    {
                        lastPointCIR_P_walker2.set_ArrayDims(0,std::stod(axis1));
                    }
                    else if(axis1Name=="y")
                    {
                        lastPointCIR_P_walker2.set_ArrayDims(1,std::stod(axis1));
                    }
                    else if(axis1Name=="z")
                    {
                        lastPointCIR_P_walker2.set_ArrayDims(2,std::stod(axis1));
                    }
                }
                if(dynamic_cast<SixRGrammerParser::SixRRPartContext *>(subwalker1->children.at(0))!=nullptr)
                {
                    string axis1=subwalker1->children.at(0)->children.at(2)->getText();
                    string axis1Name=subwalker1->children.at(0)->children.at(0)->getText();
                    if(axis1Name=="a")
                    {
                        lastPointCIR_P_walker2.set_ArrayDims(3,std::stod(axis1));
                    }
                    else if(axis1Name=="b")
                    {
                        lastPointCIR_P_walker2.set_ArrayDims(4,std::stod(axis1));
                    }
                    else if(axis1Name=="c")
                    {
                        lastPointCIR_P_walker2.set_ArrayDims(5,std::stod(axis1));
                    }
                }
            }
            flag_walker2=2;
            var.set_ArrayDims(lastPointCIR_P_walker2.get_Arraydims());
            var.set_Type_v("pointp");
        }
    }


    if(dynamic_cast<SixRGrammerParser::SixRJXPointContext *>(walker3)!=nullptr)
    {
        list<double> value;
        auto subwalker=walker1->children.at(0);
        if(dynamic_cast<SixRGrammerParser::SixRJPointContext *>(subwalker)!=nullptr)
        {
            for(int i=0;subwalker->children.at(i*2)->getText()!="]";i++)
            {
                auto subwalker1=subwalker->children.at(i*2+1);
                if(dynamic_cast<SixRGrammerParser::SixRJPartContext*>(subwalker1)!=nullptr)
                {
                    string axis1=subwalker1->children.at(2)->getText();
                    string axis1Name=subwalker1->children.at(0)->getText();


                    if(axis1Name=="j1")
                    {
                        lastPointCIR_J_walker3.set_ArrayDims(0,std::stod(axis1));
                    }
                    else if(axis1Name=="j2")
                    {
                        lastPointCIR_J_walker3.set_ArrayDims(1,std::stod(axis1));
                    }
                    else if(axis1Name=="j3")
                    {
                        lastPointCIR_J_walker3.set_ArrayDims(2,std::stod(axis1));
                    }
                    else if(axis1Name=="j4")
                    {
                        lastPointCIR_J_walker3.set_ArrayDims(3,std::stod(axis1));
                    }
                    else if(axis1Name=="j5")
                    {
                        lastPointCIR_J_walker3.set_ArrayDims(4,std::stod(axis1));
                    }
                    else if(axis1Name=="j6")
                    {
                        lastPointCIR_J_walker3.set_ArrayDims(5,std::stod(axis1));
                    }

                }
            }

            flag_walker3=1;
            var.set_ArrayDims(lastPointCIR_J_walker3.get_Arraydims());
            var.set_Type_v("pointj");

        }
        else if(dynamic_cast<SixRGrammerParser::SixRPPointContext *>(subwalker)!=nullptr)
        {
            list<double> value;
            for(int i=0;subwalker->children.at(i*2)->getText()!="]";i++)
            {
                auto subwalker1=subwalker->children.at(i*2+1);
                if(dynamic_cast<SixRGrammerParser::SixRPPartContext *>(subwalker1->children.at(0))!=nullptr)
                {
                    string axis1=subwalker1->children.at(0)->children.at(2)->getText();
                    string axis1Name=subwalker1->children.at(0)->children.at(0)->getText();

                    if(axis1Name=="x")
                    {
                        lastPointCIR_P_walker3.set_ArrayDims(0,std::stod(axis1));
                    }
                    else if(axis1Name=="y")
                    {
                        lastPointCIR_P_walker3.set_ArrayDims(1,std::stod(axis1));
                    }
                    else if(axis1Name=="z")
                    {
                        lastPointCIR_P_walker3.set_ArrayDims(2,std::stod(axis1));
                    }
                }
                if(dynamic_cast<SixRGrammerParser::SixRRPartContext *>(subwalker1->children.at(0))!=nullptr)
                {
                    string axis1=subwalker1->children.at(0)->children.at(2)->getText();
                    string axis1Name=subwalker1->children.at(0)->children.at(0)->getText();
                    if(axis1Name=="a")
                    {
                        lastPointCIR_P_walker3.set_ArrayDims(3,std::stod(axis1));
                    }
                    else if(axis1Name=="b")
                    {
                        lastPointCIR_P_walker3.set_ArrayDims(4,std::stod(axis1));
                    }
                    else if(axis1Name=="c")
                    {
                        lastPointCIR_P_walker3.set_ArrayDims(5,std::stod(axis1));
                    }
                }
            }
            flag_walker3=2;
            var.set_ArrayDims(lastPointCIR_P_walker3.get_Arraydims());
            var.set_Type_v("pointp");
        }
    }



    //controller
    //********** if flag_walker1=1 & flag_walker2=1 & flag_walker3=1 ======>lastPointCIR_J_walker1 and lastPointCIR_J_walker2 and lastPointCIR_J_walker3 and l_FF and l_CON and degree and lastApproximate
    //********** if flag_walker1=1 & flag_walker2=2 & flag_walker3=1======>lastPointCIR_J_walker1 and lastPointCIR_P_walker2 and lastPointCIR_J_walker3 and l_FF and l_CON and degree and lastApproximate
    //**********like others
    //controller
}



void MsixRlistener::enterSTATLIN(SixRGrammerParser::STATLINContext *ctx)
{
    string nameOfStatement=ctx->children.at(1)->getText();

    //badeyd_2*************************************
    string nameOfFF=(ctx->children.at(2)->getText()!="\n"?ctx->children.at(2)->getText():"");
    string ffPart=(ctx->children.at(3)->getText()!="\n"?ctx->children.at(3)->getText():"");
    string nameOfCON=(ctx->children.at(4)->getText()!="\n"?ctx->children.at(4)->getText():"");
    string conPart=(ctx->children.at(5)->getText()!="\n"?ctx->children.at(5)->getText():"");
    if(nameOfFF=="F")
    {
        l_FF=stod(ffPart);
    }
    if(nameOfCON=="CON")
    {
        l_CON=stod(conPart);
    }
    //badeyd_2*************************************
    if(ctx->children.at(6)->getText()!="\n")
    {
        lastApproximate=stod(ctx->children.at(6)->getText());
    }

    auto walker=ctx->children.at(1);
    Variable var;
    //badeyd_1*******************************
    //    Variable lastPoint_J;
    //    vector <double>lp_J;
    //    vector <double>lp_P;
    //    lastPoint_J.set_Type_v("pointj");
    //    for(int i=0;i<6;i++)
    //    {
    //        lp_J.push_back(0);
    //        lp_P.push_back(0);
    //    }
    //    lastPoint_J.set_ArrayDims(lp_J);
    //    Variable lastPoint_P;
    //    lastPoint_P.set_Type_v("pointp");

    //    lastPoint_P.set_ArrayDims(lp_P);
    //badeyd_1*******************************
    if(dynamic_cast<SixRGrammerParser::VariableNameContext *>( walker)!=nullptr)
    {
        string Var=walker->getText();

        for(int i=0;i<parameter->size();i++)
        {
            if(parameter->at(i).get_name()==Var)
            {
                var=parameter->at(i);
                break;
            }
        }
    }
    else if(dynamic_cast<SixRGrammerParser::SixRJXPointContext *>( walker)!=nullptr)
    {
        list<double> value;
        auto subwalker=walker->children.at(0);
        if(dynamic_cast<SixRGrammerParser::SixRJPointContext *>(subwalker)!=nullptr)
        {
            //            for(int i=0;i<6;i++)
            //            {
            //                auto subwalker1=subwalker->children.at(i*2+1);
            //                if(dynamic_cast<SixRGrammerParser::SixRJPartContext*>(subwalker1)!=nullptr)
            //                {
            //                   string axis1=subwalker1->children.at(2)->getText();
            //                   //int k1=5;
            //                   value.push_back(std::stod(axis1));
            //                }

            //            }

            //badeyd_1******************************************************************************************
            for(int i=0;subwalker->children.at(i*2)->getText()!="]";i++)
            {
                auto subwalker1=subwalker->children.at(i*2+1);
                if(dynamic_cast<SixRGrammerParser::SixRJPartContext*>(subwalker1)!=nullptr)
                {
                    if(dynamic_cast<SixRGrammerParser::SixRJPartContext*>(subwalker1)!=nullptr)
                    {
                        string axis1=subwalker1->children.at(2)->getText();
                        string axis1Name=subwalker1->children.at(0)->getText();


                        if(axis1Name=="j1")
                        {
                            lastPoint_J.set_ArrayDims(0,std::stod(axis1));
                        }
                        else if(axis1Name=="j2")
                        {
                            lastPoint_J.set_ArrayDims(1,std::stod(axis1));
                        }
                        else if(axis1Name=="j3")
                        {
                            lastPoint_J.set_ArrayDims(2,std::stod(axis1));
                        }
                        else if(axis1Name=="j4")
                        {
                            lastPoint_J.set_ArrayDims(3,std::stod(axis1));
                        }
                        else if(axis1Name=="j5")
                        {
                            lastPoint_J.set_ArrayDims(4,std::stod(axis1));
                        }
                        else if(axis1Name=="j6")
                        {
                            lastPoint_J.set_ArrayDims(5,std::stod(axis1));
                        }

                    }

                }
                //badeyd_1******************************************************************************************
                //controller
                //********** with lastPoint_J and l_FF and l_CON and degree and lastAproximate
                //controller
                var.set_ArrayDims(lastPoint_J.get_Arraydims());
                var.set_Type_v("pointj");
            }
        }
        else if(dynamic_cast<SixRGrammerParser::SixRPPointContext *>(subwalker)!=nullptr)
        {

            list<double> value;
            //            for(int i=0;i<6;i++)
            //            {
            //                auto subwalker1=subwalker->children.at(i*2+1);
            //                if(dynamic_cast<SixRGrammerParser::SixRPPartContext *>(subwalker1->children.at(0))!=nullptr)
            //                {
            //                   string axis1=subwalker1->children.at(0)->children.at(2)->getText();
            //                   //int k1=5;
            //                   value.push_back(std::stod(axis1));
            //                }
            //                else if(dynamic_cast<SixRGrammerParser::SixRRPartContext *>(subwalker1->children.at(0))!=nullptr)
            //                {

            //                    string axis2=subwalker1->children.at(0)->children.at(2)->getText();
            //                    //int k2=5;
            //                    value.push_back(std::stod(axis2));
            //              }
            //            }
            //badeyd_1****************************************************************************************
            for(int i=0;subwalker->children.at(i*2)->getText()!="]";i++)
            {

                auto subwalker1=subwalker->children.at(i*2+1);
                if(dynamic_cast<SixRGrammerParser::SixRPPartContext *>(subwalker1->children.at(0))!=nullptr)
                {
                    string axis1=subwalker1->children.at(0)->children.at(2)->getText();
                    string axis1Name=subwalker1->children.at(0)->children.at(0)->getText();

                    if(axis1Name=="x")
                    {
                        lastPoint_P.set_ArrayDims(0,std::stod(axis1));
                    }
                    else if(axis1Name=="y")
                    {
                        lastPoint_P.set_ArrayDims(1,std::stod(axis1));
                    }
                    else if(axis1Name=="z")
                    {
                        lastPoint_P.set_ArrayDims(2,std::stod(axis1));
                    }
                }
                if(dynamic_cast<SixRGrammerParser::SixRRPartContext *>(subwalker1->children.at(0))!=nullptr)
                {
                    string axis1=subwalker1->children.at(0)->children.at(2)->getText();
                    string axis1Name=subwalker1->children.at(0)->children.at(0)->getText();
                    if(axis1Name=="a")
                    {
                        lastPoint_P.set_ArrayDims(3,std::stod(axis1));
                    }
                    else if(axis1Name=="b")
                    {
                        lastPoint_P.set_ArrayDims(4,std::stod(axis1));
                    }
                    else if(axis1Name=="c")
                    {
                        lastPoint_P.set_ArrayDims(5,std::stod(axis1));
                    }
                }
            }
            //badeyd_1****************************************************************************************
            //controller
            //********** with lastPoint_P and l_FF and l_CON and degree and lastAproximate
            //controller
            var.set_ArrayDims(lastPoint_P.get_Arraydims());
            var.set_Type_v("pointp");

        }
    }

}




