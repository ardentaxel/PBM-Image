#include <iostream>
#include "Canvas2D.h"
#include "GrayScale.h"

using namespace std;

int main()
{
   GrayScale objFace(128);
   GrayScale objFeatures(0);

   Canvas2D objCanvas(1080, 1920, 255);

   objCanvas.DrawFace(540,960,300,objFace,objFeatures);

   //Canvas2D objCopy(objCanvas);

   cout << objCanvas.toPGM() << endl;

    return 0;
}
