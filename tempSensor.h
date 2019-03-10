/**********************************************
 * Name: LM35 temperature Sensor header file
 * Created: 11/18/2018 10:43:34 AM
 * Author: Eng_Fawzy
 **********************************************/ 


#ifndef TEMPSENSOR_H_
#define TEMPSENSOR_H_

#define SENSOR_CHANEL     CH0

void sensorInit(void);
double sensorTempRead(void);

#endif /* TEMPSENSOR_H_ */