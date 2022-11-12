#ifndef CANVAS2D_H_INCLUDED
#define CANVAS2D_H_INCLUDED
#include <iostream>
#include "GrayScale.h"



class Canvas2D
{
public:
    Canvas2D(); //Default Constructor
    Canvas2D(int intRows, int intCols); //Constructor w/ specified dimensions
    Canvas2D(const Canvas2D& objOriginal); // Copy Constructor
    Canvas2D(int intRows, int intCols, int intDefPixValue); // Constructor w/ specified dimensions and default pixel value

    //Getters/Accessors
    int getRows();
    int getCols();
    GrayScale getPixel(int intRow, int intCol);

    //Setters/Mutators
    void setPixel(int intRow, int intCol);

    //Class Functions
    std::string toPGM() const;
    void DrawFace(int intCRow, int intCCol, double dblRadius, GrayScale objFaceColor, GrayScale objFeatureColor);

    //Class Constants
    static const int MAX_VALUE = 1981;
    static const int MIN_VALUE = 0;
    static const int DEF_ROW = 500;
    static const int DEF_COL = 500;

    //Destructor
    ~Canvas2D();

private:
    void EnforceRange(int intValue, int intMax, int intMin);
    int _rows;
    int _cols;
    GrayScale** _pixels;
};


#endif // CANVAS2D_H_INCLUDED
