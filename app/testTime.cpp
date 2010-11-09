
/* Test of time methods in class Time */

#include "PSTime/Time.h"

#include <stdio.h>
#include <time.h>


using namespace PSTime;

int main ()
{
  printf ("\n\nTest implementation of the class PSTime\n");
  //-------------

  printf ( "\n\n\nTest  Time *UTCtime1 = new Time();\n");   
  Time *UTCtime1 = new Time();
        UTCtime1 -> Print();

  //-------------

  printf ( "\n\n\nTest getPSTZoneTimeOffsetSec() = %d sec = %f h.\n", (int)(Time::getPSTZoneTimeOffsetSec()),
                                                              (float)(UTCtime1 -> getPSTZoneTimeOffsetSec()/3600) );
  //-------------

  printf ( "\n\n\nTest Time *UTCtime2 = new Time(*UTCtime1);\n");   
  Time *UTCtime2 = new Time(*UTCtime1);
        UTCtime2 -> Print();

  //-------------

  printf ( "\n\n\nTest Time *UTCtime3 = new Time(UTCtime1->getUTCSec()+10,UTCtime1->getUTCNsec()+10);\n");   
  Time *UTCtime3 = new Time(UTCtime1->getUTCSec()+10,UTCtime1->getUTCNsec()+10);
        UTCtime3 -> Print();

  //-------------

  printf ( "\n\n\nTest Time *UTCtime4 = new Time(year,month,day,hour,min,sec,nsec,zone)");
  printf ( "\n  for parameters (2010,10,8,17,04,43,123456,Time::UTC);\n");
  Time *UTCtime4 = new Time(2010,10,8,17,04,43,123456,Time::UTC);
        UTCtime4 -> Print();

  printf ( "\n  for parameters (2010,10,8,17,04,43,123456,Time::PST);\n");
  Time *UTCtime5 = new Time(2010,10,8,17,04,43,123456,Time::PST);
        UTCtime5 -> Print();

  printf ( "\n  for parameters (2010,10,8,17,04,43,123456,Time::Local);\n");
  Time *UTCtime6 = new Time(2010,10,8,17,04,43,123456,Time::Local);
        UTCtime6 -> Print();

  //-------------
  struct timespec currentHRTime;
  int gettimeStatus = 0;
      gettimeStatus = clock_gettime( CLOCK_REALTIME, &currentHRTime );
  printf ( "\n\n\nTest   Time *UTCtime7 = new Time(currentHRTime,Time::Local);\n");   
  Time *UTCtime7 = new Time(currentHRTime,Time::Local);
        UTCtime7 -> Print();

  //-------------
  time_t     local=time(NULL);                // current local time
  tm         locTime=*localtime(&local);      // convert local to local, store as tm
  tm         utcTime=*gmtime(&local);         // convert local to GMT, store as tm

  printf ( "\n\n\nTest   Time *UTCtime8 = new Time(utcTime,Time::UTC);\n");   
  Time *UTCtime8 = new Time(utcTime,Time::UTC);
        UTCtime8 -> Print();

  //-------------

	printf ( "\n\nTest UTCtime8->strZoneHuman(Time::UTC)   : %s\n", UTCtime8->strZoneHuman(Time::UTC)  .data() );   
	printf ( "\n\nTest UTCtime8->strZoneHuman(Time::Local) : %s\n", UTCtime8->strZoneHuman(Time::Local).data() );   

	printf ( "\n\nTest UTCtime8->strZoneBasic(Time::UTC)   : %s\n", UTCtime8->strZoneBasic(Time::UTC)  .data() );   
	printf ( "\n\nTest UTCtime8->strZoneBasic(Time::Local) : %s\n", UTCtime8->strZoneBasic(Time::Local).data() );   

  //-------------

	printf ( "\n\nTest UTCtime8->strDateHuman(Time::UTC)   : %s\n", UTCtime8->strDateHuman(Time::UTC)  .data() );   
	printf ( "\n\nTest UTCtime8->strDateHuman(Time::Local) : %s\n", UTCtime8->strDateHuman(Time::Local).data() );   

	printf ( "\n\nTest UTCtime8->strDateBasic(Time::UTC)   : %s\n", UTCtime8->strDateBasic(Time::UTC)  .data() );   
	printf ( "\n\nTest UTCtime8->strDateBasic(Time::Local) : %s\n", UTCtime8->strDateBasic(Time::Local).data() );   

  //-------------

	printf ( "\n\nTest UTCtime8->strTimeHuman(Time::UTC)   : %s\n", UTCtime8->strTimeHuman(Time::UTC)  .data() );   
	printf ( "\n\nTest UTCtime8->strTimeHuman(Time::Local) : %s\n", UTCtime8->strTimeHuman(Time::Local).data() );   

	printf ( "\n\nTest UTCtime8->strTimeBasic(Time::UTC)   : %s\n", UTCtime8->strTimeBasic(Time::UTC)  .data() );   
	printf ( "\n\nTest UTCtime8->strTimeBasic(Time::Local) : %s\n", UTCtime8->strTimeBasic(Time::Local).data() );   

	printf ( "\n\nTest UTCtime8->strDateTimeFreeFormat()   : %s\n", UTCtime8->strDateTimeFreeFormat()  .data() );   
	printf ( "\n\nTest UTCtime8->strDateTimeFreeFormat(<DateTime format>,Time::Local)   : %s\n", 
                           UTCtime8->strDateTimeFreeFormat("%B %D %Z %Y%m%d %H:%M:%S",Time::Local)  .data() );   

  //-------------

	//Time UTCtime9 = Time::getTimeNow();

       time_t sec  = 1287712731;
       time_t nsec = 123456789;

       Time *UTCtime9 = new Time(sec,nsec);

        UTCtime9 -> Print();
	printf ( "\nTest UTCtime9->strNsec(0)  : %s\n", UTCtime9->strNsec(0).data() );   
	printf ( "\nTest UTCtime9->strNsec(1)  : %s\n", UTCtime9->strNsec(1).data() );   
	printf ( "\nTest UTCtime9->strNsec(6)  : %s\n", UTCtime9->strNsec(6).data() );   
	printf ( "\nTest UTCtime9->strNsec(9)  : %s\n", UTCtime9->strNsec(9).data() );   
	printf ( "\nTest UTCtime9->strNsec(15) : %s\n", UTCtime9->strNsec(15).data() );   

  //-------------

	printf ( "\n\nTest UTCtime9->strTimeStampBasic(Time::Local)   : %s\n", UTCtime9->strTimeStampBasic(Time::Local).data() ); 
	printf ( "\n\nTest UTCtime9->strTimeStampBasic(Time::Local,5) : %s\n", UTCtime9->strTimeStampBasic(Time::Local,5).data() ); 
	printf ( "\n\nTest UTCtime9->strTimeStampBasic(Time::Local,0) : %s\n", UTCtime9->strTimeStampBasic(Time::Local,0).data() ); 

	printf ( "\n\nTest UTCtime9->strTimeStampHuman(Time::Local)   : %s\n", UTCtime9->strTimeStampHuman(Time::Local).data() ); 
	printf ( "\n\nTest UTCtime9->strTimeStampHuman(Time::Local,3) : %s\n", UTCtime9->strTimeStampHuman(Time::Local,3).data() ); 
	printf ( "\n\nTest UTCtime9->strTimeStampHuman(Time::Local,0) : %s\n", UTCtime9->strTimeStampHuman(Time::Local,0).data() ); 

	printf ( "\n\nTest UTCtime9->strTimeStampFreeFormat()   : %s\n", UTCtime9->strTimeStampFreeFormat()  .data() );   
	printf ( "\n\nTest UTCtime9->strTimeStampFreeFormat(<DateTime format>,Time::Local,4)   : %s\n", 
                           UTCtime9->strTimeStampFreeFormat("%B %D %Z %Y%m%d %H:%M:%S",Time::Local,4)  .data() );   


  //-------------  
  return 0;
  //-------------
}