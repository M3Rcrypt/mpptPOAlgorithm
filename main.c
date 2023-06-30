#include <stdio.h>
#include <math.h>

float Pprevious, Vprevious, Dprevious; // These are previous values (threshold)
float Ppv, Vpv, Ipv; // These are new values that are scanned
float deltaD = 110e-6; // One unit increasing of duty cycle
float DutyCycle = 2000.0; // Duty Cycle for updating

float scanVoltage(){
  printf("Scanning for Voltage...\n");
  scanf("%f",&Vpv);
  return Vpv;
}

float calculatePower()
{
  printf("Scanning for Current...\n");
  scanf("%f",&Ipv);
  Ppv = Ipv*Vpv;
  return Ppv;
}

void pAndqAlgorithm()
{
  if((Ppv-Pprevious) != 0){
    if((Ppv-Pprevious) > 0){
      if((Vpv-Vprevious) > 0){
        DutyCycle = Dprevious - deltaD;
        printf("Duty Cycle decreased.\n");
      }
      else{
        DutyCycle = Dprevious + deltaD;
        printf("Duty Cycle increased.\n");
      }
    }
    else{
      if((Vpv-Vprevious) > 0){
        DutyCycle = Dprevious + deltaD;
        printf("Duty Cycle increased.\n");
      }
      else{
        DutyCycle = Dprevious - deltaD;
        printf("Duty Cycle decreased.\n");
      } 
    }
  }
}

int main()
{
  Vprevious = scanVoltage();
  Pprevious = calculatePower();
  while(1){
    Vpv = scanVoltage();
    Ppv = calculatePower();
    pAndqAlgorithm();
    Vprevious = Vpv;
    Pprevious = Ppv;
  }
}
