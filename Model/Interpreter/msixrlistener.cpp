#include "msixrlistener.h"
#include "SixRGrammerParser.h"
#include "variable.h"

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
            list<double> jentry;
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
            list<double> jentry1;
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
//    else
//    {
//          variable->set_name(VName->children.at(0)->getText());
//          VName->arrayVariableSuffix()->expression().at(0)->conditionalOrExpression().at(0)->exclusiveOrExpression()
//                  .at(0)->conditionalAndExpression().at(0)->additiveExpression().at(0)->multiplicativeExpression()
//                  .at(0)->unaryNotExpression().at(0)->unaryPlusMinuxExpression()->primary());

//    }





    //***********ali

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

            }

//            switch (nameOfStatement) {
//            case "PTP":
//            {
//                enterSTATPTP((SixRGrammerParser::STATPTPContext *) &stat);
//                break;
//            }
//            default:
//                break;
//            }


    }
}

void MsixRlistener::enterSTATPTP(SixRGrammerParser::STATPTPContext *ctx)
{
    string nameOfStatement=ctx->children.at(1)->getText();

    auto walker=ctx->children.at(1);
    Variable var;
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
            for(int i=0;i<6;i++)
            {
                auto subwalker1=subwalker->children.at(i*2+1);
                if(dynamic_cast<SixRGrammerParser::SixRJPartContext*>(subwalker1)!=nullptr)
                {
                   string axis1=subwalker1->children.at(2)->getText();
                   //int k1=5;
                   value.push_back(std::stod(axis1));
                }

            }
            var.set_ArrayDims(value);
            var.set_Type_v("pointj");
        }
        else if(dynamic_cast<SixRGrammerParser::SixRPPointContext *>(subwalker)!=nullptr)
        {

            list<double> value;
            for(int i=0;i<6;i++)
            {
                auto subwalker1=subwalker->children.at(i*2+1);
                if(dynamic_cast<SixRGrammerParser::SixRPPartContext *>(subwalker1->children.at(0))!=nullptr)
                {
                   string axis1=subwalker1->children.at(0)->children.at(2)->getText();
                   //int k1=5;
                   value.push_back(std::stod(axis1));
                }
                else if(dynamic_cast<SixRGrammerParser::SixRRPartContext *>(subwalker1->children.at(0))!=nullptr)
                {

                    string axis2=subwalker1->children.at(0)->children.at(2)->getText();
                    int k2=5;
                    value.push_back(std::stod(axis2));
              }
            }
            var.set_ArrayDims(value);
            var.set_Type_v("pointp");

        }

    }
}
