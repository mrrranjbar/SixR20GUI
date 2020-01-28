#ifndef VARIABLE_H
#define VARIABLE_H
#include <list>
#include <iterator>

#include <vector>
#include "SixRGrammerParser.h"
#include <map>
using namespace::std;
#define motorNumber 6

enum PrimitiveType
{
    BOOL = 0,
    CHAR = 1,
    INT = 2,
    FLOAT = 3,
    POINTJ = 4,
    POINTP = 5,
    POS = 6,
    ORIENT = 7
};

const string PrimitiveTypeS[]
{
    "BOOL",
    "CHAR",
    "INT",
    "FLOAT",
    "POINTJ" ,
    "POINTP" ,
    "POS" ,
    "ORIENT"
};

class Variable
{
//protected:
    //static vector<double> lastData;
    //    SixRGrammerParser::TypeContext typeCtx;

public:
    string type;
    string name;
    vector<double> data;
    bool evaluated=false;

public:
    Variable(){
        //lastData.resize(6);
    }
    void CopyTo(Variable *dest){
        dest->name = name;
        dest->type = type;
        dest->evaluated = evaluated;
        for(int i=0; i<data.size(); i++)
            dest->setDataAt(data[i], i);
    }
    vector<double> getData(){
        return data;
    }
    void removeOtherIndex(int idx){
        double d = data.at(idx);
        data.clear();
        data.push_back(d);
    }
    double getDataAt(int idx){
        return data.at(idx);
    }
    void setSize(int size){
        data.resize(size);
    }
    void setData(vector<double> newData){
        for(int i=0; i<newData.size(); i++)
            setDataAt(newData.at(i), i);
        //data = newData;
        evaluated = true;
    }
    void setDataAt(double newData, int idx){
        if(data.size()<idx+1)
            for(int i=data.size(); i<idx+1; i++)
                data.push_back(0);
        data.at(idx) = newData;
        evaluated = true;
    }

    void setX(double x){
        data.at(0) = x;
    }
    void setY(double x){
        data.at(1) = x;
    }
    void setZ(double x){
        data.at(2) = x;
    }

    void setA(double x){
        data.at(3) = x;
    }
    void setB(double x){
        data.at(4) = x;
    }
    void setC(double x){
        data.at(5) = x;
    }

    void setJ1(double x){
        data.at(0) = x;
    }
    void setJ2(double x){
        data.at(1) = x;
    }
    void setJ3(double x){
        data.at(2) = x;
    }
    void setJ4(double x){
        data.at(3) = x;
    }
    void setJ5(double x){
        data.at(4) = x;
    }
    void setJ6(double x){
        data.at(5) = x;
    }

    string ToString(){
        string returnS = "";
        returnS += type+" "+name+"("+to_string(data.size())+"): ";
        for(int i=0; i<data.size(); i++)
            returnS += to_string(data.at(i))+", ";
        returnS += "\r\n";
        return returnS;
    }
};

#endif // VARIABLE_H
