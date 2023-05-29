#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long mytime = 0;

/*
* 
*/
unsigned int signal_generation(double period, double offset) {
    double signal = 0;
    double amplitude = 0.5;

    if((amplitude + offset) > 1) {
        amplitude = 1 - offset;
    }

    unsigned int return_value = 0;
    signal = amplitude*sin(2*M_PI*(double) mytime/period) + offset; /* from 0 to 1 */
    mytime++;
    if(mytime==period) mytime = 0;
    return_value = (unsigned int) ((signal+1)*127);
    return return_value;
}

int main()
{
    while(1) {
        printf("mytime = %d, signal = %d\n",mytime,signal_generation(50,0.6));
        usleep(100000);
    }
    return 0;
}
