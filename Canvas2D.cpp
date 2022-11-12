#include "Canvas2D.h"
#include <cassert>
#include <sstream>
#include <cmath>


Canvas2D::Canvas2D() : Canvas2D(DEF_ROW,DEF_COL) //Default Constructor
{

}

Canvas2D::Canvas2D(int intRows, int intCols) // Constructor w/ specified dimensions
{
    EnforceRange(intRows, MAX_VALUE, MIN_VALUE);
    EnforceRange(intCols, MAX_VALUE, MIN_VALUE);

    _rows = intRows;
    _cols = intCols;

    _pixels = new GrayScale*[_rows];
    for(auto r = 0; r < _rows; r++)
    {
        _pixels[r] = new GrayScale[getCols()];
        for(auto c = 0; c < getCols(); c++)
        {
            GrayScale objBG(255);
            _pixels[r][c] = objBG;
        }
    }


}

Canvas2D::Canvas2D(int intRows, int intCols, int intDefPixValue) // Constructor w/ specified dimensions and default pixel value
{
    EnforceRange(intRows, MAX_VALUE, MIN_VALUE);
    EnforceRange(intCols, MAX_VALUE, MIN_VALUE);

    _rows = intRows;
    _cols = intCols;

    _pixels = new GrayScale*[getRows()];
    for(auto r = 0; r < getRows(); r++)
    {
        _pixels[r] = new GrayScale[getCols()];
        for(auto c = 0; c < getCols(); c++)
        {
            GrayScale objBG(intDefPixValue);
            _pixels[r][c] = objBG;
        }
    }
}

Canvas2D::Canvas2D(const Canvas2D& objOriginal) : Canvas2D(objOriginal._rows, objOriginal._cols) // Copy constructor
{
    for(auto r = 0; r < getRows(); r++)
    {
        for(auto c = 0; c < getCols(); c++)
        {
            _pixels[r][c] = objOriginal._pixels[r][c];
        }
    }
}

int Canvas2D::getRows()
{
     return _rows;
}

int Canvas2D::getCols()
{
    return _cols;
}

std::string Canvas2D::toPGM() const
{
    std::stringstream ssPGM;
    ssPGM << "P2" << ' '<< std::endl
          << _cols << ' ' << _rows << ' ' << std::endl
          << "255" << std::endl;
    for(auto r = 0; r < _rows; r++)
    {
        for(auto c = 0; c < _cols; c++)
        {
            GrayScale objPixel = _pixels[r][c];
            ssPGM << objPixel.getPixVal() << ' ';
        }
        ssPGM << std::endl;
    }
    return ssPGM.str();
}

GrayScale Canvas2D::getPixel(int intRow, int intCol)
{
    EnforceRange(intRow, getRows(), 0);
    EnforceRange(intCol, getRows(), 0);

    return _pixels[intRow][intCol];
}

void Canvas2D::EnforceRange(int intValue, int intMax, int intMin)
{
    assert(intValue > intMin);
    assert(intValue < intMax);
}

double Distance(int r1, int c1, int r2, int c2)
{
    return sqrt(pow(r1-r2, 2) + pow(c1-c2, 2)); //Distance Formula
}


void Canvas2D::DrawFace(int intCRow, int intCCol, double dblRadius, GrayScale objFaceColor, GrayScale objFeatureColor)
{

    for(auto r = 0; r < getRows(); r++)
    {
        for(auto c = 0; c < getCols(); c++)
        {
            if(Distance(r,c,intCRow, intCCol) < dblRadius)
            {
                //Drawing the head
                _pixels[r][c] = objFaceColor;

                //Drawing left Eye
                if(Distance(r,c,(intCRow-(dblRadius/2)), (intCCol-(dblRadius/2))) < (dblRadius/6))
                {
                    _pixels[r][c] = objFeatureColor;
                }

                //Drawing right Eye
                if(Distance(r,c,(intCRow-(dblRadius/2)), (intCCol+(dblRadius/2))) < (dblRadius/6))
                {
                    _pixels[r][c] = objFeatureColor;
                }

                //Drawing the nose
                int NoseOffset = dblRadius/8;
                for(auto i = (intCRow-NoseOffset); i <= (intCRow+NoseOffset); i++)
                {
                    for(auto j = (intCCol-NoseOffset); j <= (intCCol+NoseOffset); j++)
                    {
                        _pixels[i][j] = objFeatureColor;
                    }
                }

                //Drawing the mouth
                int intOffset = dblRadius/2;
                int intOffset2 = dblRadius/6;
                for(auto i = (intCRow+intOffset); i <= (intCRow+intOffset+intOffset2); i++)
                {
                    for(auto j = (intCCol-intOffset); j <= (intCCol+intOffset); j++)
                    {
                        _pixels[i][j] = objFeatureColor;
                    }
                }
            }
        }
    }
}


Canvas2D::~Canvas2D()
{
    for(auto r = 0; r < getRows(); r++)
    {
        delete [] _pixels[r];
    }
    delete [] _pixels;
}

