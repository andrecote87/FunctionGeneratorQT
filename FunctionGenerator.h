
#ifndef __FUNCTIONGENERATOR_H
#define __FUNCTIONGENERATOR_H
#include <visa.h>
#include <visainst.h>


class FunctionGenerator : public visainst
{

    private:
    
    float ch2output;
    float freq;
    float volt;
    float offset;
    float phase;
    int output;
    float start;
    float stop;
    float time;
    int OnOff;
    float freqstart;
    float freqstop;
    float sweeptime;
    const char* func;
    int sweepfunc;


  public:


  FunctionGenerator();

   

 //  void OpenInstrument();

 //  void IDN();
  void setch2output(int f);

   void SweepFunc(int f);

   void setoutput(int f);

   void setfreqstart(float f);

   void setfreqstop(float f);

   void setsweeptime(float f);

   void GenerateSin();

   void GenerateNoise();

   void GenerateSquare();

   void setvolt(float f);

   void setoffset(float f);

   void setphase(float f);

   void setfreq(float f);
   /*


   void IDN();





   */

  
  
};

#endif
