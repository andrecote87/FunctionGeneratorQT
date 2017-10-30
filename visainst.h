#ifndef __VISAINST_H
#define __VISAINST_H
#include <visa.h>


class visainst
{

protected:
	ViStatus status;
    ViSession viDG1022;
    ViSession defaultRM;
    ViFindList fList;
    ViChar desc[VI_FIND_BUFLEN];
    ViUInt32 numInst;
    ViChar resultBuffer[256];
    ViUInt32 resultCount;

public:
	visainst();
	void OpenInstrument();
	virtual void IDN();
};




#endif