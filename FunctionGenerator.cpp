#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>
#include <windows.h>
#include <FunctionGenerator.h>
#include <visainst.h>


FunctionGenerator::FunctionGenerator():visainst()
{
  freq = 20000.0;
  volt = 5.0;
  offset = 0.5;
  phase = 10.0;
  output = 0;
  ch2output = 0;
  freqstart=100.0;
  freqstop=10000.0;
  sweeptime=1.0;
  sweepfunc=0;
}


void FunctionGenerator::setsweeptime(float f)
{

  char commandstring3[128];

  sprintf(commandstring3,"SWE:TIME %f", f);
  Sleep(2000);

  viWrite(viDG1022, (unsigned char*)commandstring3,sizeof commandstring3,VI_NULL);
  Sleep(2000);
  sweeptime = f;

}
void FunctionGenerator::setfreqstart(float f)
{


  char commandstring1[128];
  
  sprintf(commandstring1,"FREQ:STAR %f", f);
  Sleep(2000);

  viWrite(viDG1022, (unsigned char*)commandstring1,sizeof commandstring1,VI_NULL);
  Sleep(2000);


if(f<0) f = 100;
if(f > 20000000) f = 100;
  freqstart = f;

}

void FunctionGenerator::setfreqstop(float f)
{
  
  char commandstring2[128];
 
  sprintf(commandstring2,"FREQ:STOP %f", f);
  Sleep(2000);
 
  viWrite(viDG1022, (unsigned char*)commandstring2,sizeof commandstring2,VI_NULL);
  Sleep(2000);

  if(f<0) f = 19000000;
  if(f > 20000000) f = 19000000;
  freqstop = f;

}



void FunctionGenerator::setoutput(int f)
{

   char commandstring[128];
   Sleep(2000);

  if(f==1)
  {

    sprintf(commandstring, "OUTP ON");
    status=viWrite(viDG1022, (unsigned char*)commandstring,100,VI_NULL);

  }

  else
  {

  sprintf(commandstring, "OUTP OFF");
  status=viWrite(viDG1022, (unsigned char*)commandstring,100,VI_NULL);

  }
output=f;
  Sleep(2000);

}
void FunctionGenerator::setch2output(int f)
{

   char commandstring[128];
   Sleep(2000);

  if(f==1)
  {

    sprintf(commandstring, "OUTP:CH2 ON");
    status=viWrite(viDG1022, (unsigned char*)commandstring,100,VI_NULL);

  }

  else
  {

  sprintf(commandstring, "OUTP:CH2 OFF");
  status=viWrite(viDG1022, (unsigned char*)commandstring,100,VI_NULL);

  }
ch2output=f;
  Sleep(2000);

}

void FunctionGenerator::SweepFunc(int f)
{
  char commandstring[128];
  if(f==1)
  {
  sprintf(commandstring, "SWE:STAT ON");
  status=viWrite(viDG1022,(unsigned char*)commandstring,50,VI_NULL);
  }
  else
{
      sprintf(commandstring, "SWE:STAT OFF");
      status=viWrite(viDG1022,(unsigned char*)commandstring,50,VI_NULL);
  }
  sweepfunc=f;
  Sleep(2000);
  sprintf(commandstring, "SWE:SPAC LIN");
  status=viWrite(viDG1022, (unsigned char*)commandstring,50,VI_NULL);
  Sleep(2000);

  sprintf(commandstring, "FUNC SIN" );
  Sleep(2000);
  status=viWrite(viDG1022, (unsigned char*)commandstring, sizeof commandstring,VI_NULL);
  Sleep(2000);

}
/*void FunctionGenerator::setdcoffset(float f)
{
  return;
}*/

void FunctionGenerator::setvolt(float f)
{
  char commandstring[128];
  char commandstring1[128];

  sprintf(commandstring, "VOLT:UNIT VPP");
  Sleep(2000);
  sprintf(commandstring1, "VOLT %f", f);
  Sleep(2000);
  status=viWrite(viDG1022,(unsigned char*)commandstring1 ,100,VI_NULL);
  Sleep(2000);
  status=viWrite(viDG1022,(unsigned char*)commandstring ,100,VI_NULL);
  Sleep(2000);
  volt=f;
  return;
}
void FunctionGenerator::setoffset(float f)
{
  char commandstring[128];


  sprintf(commandstring, "VOLT:OFFS %f", f);
  Sleep(2000);

  status=viWrite(viDG1022,(unsigned char*)commandstring ,100,VI_NULL);
  Sleep(2000);
  offset=f;
  return;
}
 void FunctionGenerator::setphase(float f)
{

  char commandstring[128];


  sprintf(commandstring, "PHAS %f", f);
  Sleep(2000);

  status=viWrite(viDG1022,(unsigned char*)commandstring ,100,VI_NULL);
  Sleep(2000);
  if(f<0) f = 0;
  phase = f;
  return;
}

void FunctionGenerator::setfreq(float f)
{

  char commandstring[128];


  sprintf(commandstring, "FREQ %f", f);
  Sleep(2000);

  status=viWrite(viDG1022,(unsigned char*)commandstring ,100,VI_NULL);
  Sleep(2000);
  if(f < 0) f = 100;
  if(f > 20000000) f = 19000000;
  freq = f;
  return;
}

/*float FunctionGenerator::setfunc(const char* f)
{
    char commandstring1[128];


  sprintf(commandstring1,"FUNC %s", f);
  status=viWrite(GenID, commandstring1,sizeof commandstring1,VI_NULL);

  sleep(2);

  return;
}*/
  void FunctionGenerator::GenerateSin()
  {
      Sleep(2000);
         char commandstring[128];



        sprintf(commandstring, "FUNC SIN" );
        Sleep(2000);
        status=viWrite(viDG1022, (unsigned char*)commandstring, sizeof commandstring,VI_NULL);
        Sleep(2000);

       return;
  }

  void FunctionGenerator::GenerateSquare()
  {
      Sleep(2000);
         char commandstring[128];



        sprintf(commandstring, "FUNC SQU" );
        Sleep(2000);
        status=viWrite(viDG1022, (unsigned char*)commandstring, sizeof commandstring,VI_NULL);
        Sleep(2000);

       return;
  }
  void FunctionGenerator::GenerateNoise()
  {
      Sleep(2000);
         char commandstring[128];



        sprintf(commandstring, "FUNC NOIS" );
        Sleep(2000);
        status=viWrite(viDG1022, (unsigned char*)commandstring, sizeof commandstring,VI_NULL);
        Sleep(2000);

       return;
  }

/*void FunctionGenerator::GenerateSin()
{
Sleep(2000);
   char commandstring[128];



  sprintf(commandstring, "APPL:SIN %f, %f, %f, %f", freq, volt, dcoffset, phase);
  Sleep(2000);
  status=viWrite(viDG1022, (unsigned char*)commandstring, sizeof commandstring,VI_NULL);
  Sleep(2000);

 return;
}*/
