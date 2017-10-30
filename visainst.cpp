#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>
#include <windows.h>
#include <visainst.h>


visainst::visainst()
{

}

void visainst::IDN()
{

  char commandstring[128];

  sprintf(commandstring, "*IDN?");

  status=viWrite(viDG1022, (unsigned char*)commandstring,50,VI_NULL);
  Sleep(2000);

}

void visainst::OpenInstrument()
{

  Sleep(2000);

  status=viOpenDefaultRM(&defaultRM);
  Sleep(2000);

  status=viFindRsrc(defaultRM,"USB[0-9]::0x0400?*INSTR",&fList,&numInst,desc);
  Sleep(2000);

  status=viOpen(defaultRM,desc,VI_NULL,VI_NULL,&viDG1022);
  Sleep(2000);

}