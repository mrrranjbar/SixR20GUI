#ifndef VARIABLE_H
#define VARIABLE_H
#include <list>
#include <iterator>

#include <vector>

using namespace::std;


enum PrimitiveType
{
    BOOL = 1,
    CHAR = 2,
    INT = 4,
    FLOAT = 8,
    POINTJ = 16,
    POINTP = 32,
    POS = 64,
    ORIENT = 128
};
class Variable
{
private:
    string _type_v;
    bool _isArray;
    int _arraylength;
    vector<double> _listOfNumbers;
    string _name;
    bool _isLeft;
    //Object Value;
    bool _hasValue;
    bool _isReadOnly;


public:
     Variable();
     string get_Type_v();
     void set_Type_v(string type);
     bool get_IsArray();
     void set_IsArray(bool value);
     int get_ArraLength();
     void set_ArraLength(int value);
     vector<double> get_Arraydims();
     void set_ArrayDims(int i,double value);
     void set_ArrayDims(vector<double> value);
     string get_name();
     void set_name(string value);
     //object
     void set_Value();
     //get_Value();
     //object
     bool get_IsLeft();
     void set_IsLeft(bool value);
     bool get_HasValue();
     void set_HasValue(bool value);
     bool get_IsReadOnly();
     void set_IsReadOnly(bool value);

};

#endif // VARIABLE_H
