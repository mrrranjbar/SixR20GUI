#include "variable.h"



Variable::Variable()
{

}

void Variable::set_Type_v(string type)
{
    _type_v=type;

}
string Variable:: get_Type_v()
{
    return  _type_v;
}

void  Variable::set_IsArray(bool value)
{
    _isArray=value;
}

bool Variable::get_IsArray()
{
    return  _isArray;
}

void  Variable::set_ArraLength(int value)
{
    _arraylength=value;
}

int Variable::get_ArraLength()
{
    return _arraylength;

}

void Variable::set_ArrayDims(vector<double> value)
{
    _listOfNumbers=value;
}
vector<double> Variable::get_Arraydims()
{
    return _listOfNumbers;
}

void Variable::set_ArrayDims(int i, double value)
{
    _listOfNumbers[i] = value;
}
void Variable::set_name(string value)
{
    _name=value;
}
string Variable::get_name()
{
    return _name;
}
void Variable::set_IsLeft(bool value)
{
    _isLeft=value;
}
bool Variable::get_IsLeft()
{
    return _isLeft;
}
void Variable::set_HasValue(bool value)
{
    _hasValue=value;
}
bool Variable::get_HasValue()
{
    return _hasValue;
}
void Variable::set_IsReadOnly(bool value)
{
    _isReadOnly=value;
}
bool Variable::get_IsReadOnly()
{
    return _isReadOnly;
}



