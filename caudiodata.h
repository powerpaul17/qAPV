#ifndef CAUDIODATA_H
#define CAUDIODATA_H

#include "cdata.h"

class CAudioData:public CData {
    int samplerate;
public:
    int getSamplerate();
};

#endif // CAUDIODATA_H
