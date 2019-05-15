#include "msixrlistener.h"
#include "SixRGrammerParser.h"
#include "variable.h"
//badeyd_1*************************
#include<QDebug>
#include <map>
//badeyd_1*************************

using namespace std;
using namespace antlr4;



MsixRlistener::MsixRlistener()
{

}

void MsixRlistener::enterModuleRoutines(SixRGrammerParser::ModuleRoutinesContext *ctx)
{
    //************************ali
    vector<SixRGrammerParser::MainRoutineContext *>mainroutincontext=ctx->mainRoutine();
    for (auto & element : ctx->mainRoutine()) {
        enterMainRoutine(element);
    }

    for (auto & element : ctx->subRoutine()) {
        enterSubRoutine(element);
    }

    //************************ali


    for (auto & element : ctx->variableDeclaration()) {
        enterVariableDeclaration(element);
    }


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
    for(int i=0;i<6;i++)
    {
       lp_JCIR_walker1.push_back(0);
       lp_PCIR_walker1.push_back(0);
       lp_JCIR_walker2.push_back(0);
       lp_PCIR_walker2.push_back(0);
    }
    lastPointCIR_J_walker1.set_ArrayDims(lp_JCIR_walker1);
    lastPointCIR_P_walker1.set_ArrayDims(lp_PCIR_walker1);
    lastPointCIR_J_walker2.set_ArrayDims(lp_JCIR_walker2);
    lastPointCIR_P_walker2.set_ArrayDims(lp_PCIR_walker2);

    flag_walker1=0;
    flag_walker2=0;

    waitSec=0;
    //akhar*********************************
    //badeyd_1*******************************
    enterModuleRoutines(ctx->moduleRoutines());

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
        if(variable->get_Type_v()=="pointj")
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
       parameter.push_back(*variable);

    }
}

void MsixRlistener::enterMainRoutine(SixRGrammerParser::MainRoutineContext *ctx)
{

   enterRoutineBody(ctx->routineBody());
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
    enterStatementList(ctx->statementList());
}

void MsixRlistener::enterStatementList(SixRGrammerParser::StatementListContext *ctx)
{

    for(int i=0;i<ctx->children.size();i++)
    {

            SixRGrammerParser::StatementContext* stat=ctx->statement().at(i);
            if(dynamic_cast<SixRGrammerParser::VariableDeclarationContext *>(stat->children.at(0))!=nullptr)
            {
                enterVariableDeclaration((SixRGrammerParser::VariableDeclarationContext *)(stat->children.at(0)));
            }
            else if(dynamic_cast<SixRGrammerParser::STATPTPContext *>(stat)!=nullptr)
            {
                enterSTATPTP((SixRGrammerParser::STATPTPContext *) (stat));
            }
            else if(dynamic_cast<SixRGrammerParser::STATLINContext *>(stat)!=nullptr)
            {
            //bad eyd*************************************
                enterSTATLIN((SixRGrammerParser::STATLINContext *) (stat));
            }
            //akhar******************
            else if (dynamic_cast<SixRGrammerParser::STATCIRContext *>(stat)!=nullptr)
            {
                enterSTATCIR((SixRGrammerParser::STATCIRContext *) (stat));
            }
            //akhar******************
            else if(dynamic_cast<SixRGrammerParser::STATWAITSECContext  *>(stat)!=nullptr)
            {
                enterSTATWAITSEC((SixRGrammerParser::STATWAITSECContext *) (stat));
            }
            //bad eyd**************************************


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
    if(nameOfFF=="F")
    {
        l_FF=stod(ffPart);
    }
    if(nameOfCON=="CON")
    {
        l_CON=stod(conPart);
    }
    //badeyd_2*************************************

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

        for(int i=0;i<parameter.size();i++)
        {
            if(parameter.at(i).get_name()==Var)
            {
                var=parameter.at(i);
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
                //********** with lastPoint_J and
                //controller

            var.set_ArrayDims(lastPoint_J.get_Arraydims());
            var.set_Type_v("pointj");
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
            //********** with lastPoint_P and use l_FF and l_CON
            //controller

            var.set_ArrayDims(lastPoint_P.get_Arraydims());
            var.set_Type_v("pointp");

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
    string expression="";

    expression=(ctx->children.at(3)->getText()!="\n"?ctx->children.at(3)->getText():"");
    nameOfFF=(ctx->children.at(4)->getText()!="\n"?ctx->children.at(4)->getText():"");
    if(nameOfFF!="")
    {
        ffPart=ctx->children.at(5)->getText();
    }
    nameOfCON=(ctx->children.at(6)->getText()!="\n"?ctx->children.at(6)->getText():"");
    if(nameOfCON!="")
    {
        conPart=ctx->children.at(7)->getText();
    }
    if(nameOfFF=="FF")
    {
        l_FF=stod(ffPart);
    }
    if(nameOfCON=="CON")
    {
        l_CON=stod(conPart);
    }
    auto walker1=ctx->children.at(1);
    auto walker2=ctx->children.at(2);
    auto walker3=ctx->children.at(3);
    Variable var;

    if(dynamic_cast<SixRGrammerParser::VariableNameContext *>( walker1)!=nullptr)
    {
        string Var=walker1->getText();

        for(int i=0;i<parameter.size();i++)
        {
            if(parameter.at(i).get_name()==Var)
            {
                var=parameter.at(i);
                break;
            }
        }
    }

    if(dynamic_cast<SixRGrammerParser::VariableNameContext *>( walker2)!=nullptr)
    {
        string Var=walker2->getText();

        for(int i=0;i<parameter.size();i++)
        {
            if(parameter.at(i).get_name()==Var)
            {
                var=parameter.at(i);
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

            //controller
            //********** with lastPointCIR_J_walker1
            //controller
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
            //controller
            //********** with lastPointCIR_P_walker1 and use l_FF and l_CON
            //controller
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

            //controller
            //********** with lastPointCIR_J_walker2
            //controller

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
            //controller
            //********** with lastPointCIR_P_walker2 and use l_FF and l_CON
            //controller
            flag_walker2=2;
            var.set_ArrayDims(lastPointCIR_P_walker2.get_Arraydims());
            var.set_Type_v("pointp");
        }
    }

    //controller
    //********** if flag_walker1=1 & flag_walker2=1 ======>lastPointCIR_J_walker1 and lastPointCIR_J_walker2 and l_FF and l_CON and expression
    //********** if flag_walker1=1 & flag_walker2=2 ======>lastPointCIR_J_walker1 and lastPointCIR_P_walker2 and l_FF and l_CON and expression
    //********** if flag_walker1=2 & flag_wlaker2=1 ======>lastPointCIR_P_walker1 and lastPointCIR_J_walker2 and l_FF and l_CON and expression
    //********** if flag_walker1=2 & flag_wlaker2=2 ======>lastPointCIR_P_walker1 and lastPointCIR_P_walker2 and l_FF and l_CON and expression
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

        for(int i=0;i<parameter.size();i++)
        {
            if(parameter.at(i).get_name()==Var)
            {
                var=parameter.at(i);
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
            for(int i=0;subwalker->children.at(i*2)->getText()!=")";i++)
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
                 //********** with lastPoint_P and
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
            for(int i=0;subwalker->children.at(i*2)->getText()!=")";i++)
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
            //********** with lastPoint_P and l_FF and l_CON
            //controller
            var.set_ArrayDims(lastPoint_P.get_Arraydims());
            var.set_Type_v("pointp");

        }
    }

}




