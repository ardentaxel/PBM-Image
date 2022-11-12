#include "GrayScale.h"
#include <iostream>

GrayScale::GrayScale() : GrayScale(DEF_PIX_VAL)
{

}

GrayScale::GrayScale(int intVal)
{
    _pixVal = intVal;
}

int GrayScale::getPixVal() const
{
    return _pixVal;
}

void GrayScale::setPixVal(int intValue)
{
    ValidateColor(intValue);
    _pixVal = intValue;
}

void GrayScale::ValidateColor(int intVal)
{
    if(intVal < MIN_PIXEL_VAL || intVal > MAX_PIXEL_VAL)
    {
        std::cerr << "Value of pixel must be between 0 and 255" << std::endl;
        exit(ERR_PIXEL_RANGE);
    }
}
