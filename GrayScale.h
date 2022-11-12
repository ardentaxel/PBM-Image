#ifndef GRAYSCALE_H_INCLUDED
#define GRAYSCALE_H_INCLUDED

class GrayScale
{
public:
    GrayScale();
    GrayScale(int intPixValDefault);

    int getPixVal() const;

    void setPixVal(int intValue);

    static const int ERR_PIXEL_RANGE = -1;
    static const int MAX_PIXEL_VAL = 255;
    static const int MIN_PIXEL_VAL = 0;
    static const int DEF_PIX_VAL = 0;


private:
    void ValidateColor(int intVal);
    int _pixVal;

};

#endif // GRAYSCALE_H_INCLUDED
