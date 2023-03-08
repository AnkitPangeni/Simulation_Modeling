#include<stdio.h> 
#include<stdlib.h> 
#include<math.h>
 int main() 
 {
 
 int i=0; 
 float c1[1000],c2[1000],c3[1000];// C1 C2 C3 are the amount of chemicals Ch1 Ch2 Ch3
 float k1=0.025,k2=0.01,dt=0.001; // k1 k2 are the constants
 c1[0]=60.0,c2[0]=35.0,c3[0]=0.0; // amount of chemicals Ch1 Ch2 Ch3 at time 0
 float t=0.0, time=100.0; // time represents the total reaction time and t represents loop time, that increases by dt
 FILE *fp;
 fp=fopen("lab01.txt","w");  // write the output data to lab01.txt
	 
 while(t<=time) 
 {

c1[i+1]=c1[i]+(k2*c3[i]-k1*c1[i]*c2[i])*dt;  // this represents the amount of change in ch1 ch2 ch3 with respect to dt time
c2[i+1]=c2[i]+(k2*c3[i]-k1*c1[i]*c2[i])*dt;
c3[i+1]=c3[i]+2.0*(k1*c1[i]*c2[i]-k2*c3[i])*dt; 

fprintf(fp,"\n%f %f %f",c1[i],c2[i],c3[i]);
 
 i=i+1; //  i inreases by 1 
 t=t+dt; // and t increases by dt time
 
  } 
  fclose(fp);
  printf("Reaction Simulated");
  return 0;

}

