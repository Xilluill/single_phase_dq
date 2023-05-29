/*
 * pid.h
 *
 *  Created on: 2020��8��25��
 *      Author: EnglishName
 */

#ifndef SRC_PID_H_
#define SRC_PID_H_

struct pid
{
    float purpose;
    float current_value;
    float current_error;
    float last1_error;
    float last2_error;
    float kp;
    float ki;
    float kd;
    float error_min;
    float error_max;
};
void pid_init_I(struct pid *pid_param,float kp,float ki,float kd,float error_min,float error_max);
void pid_init(struct pid *pid_param,float Up,float kp,float ki,float kd,float error_min,float error_max);
void pid_purpose(struct pid *pid_param,float purpose);
void pid_step(struct pid *pid_param,float current_value);
void pid_error(struct pid *pid_param);
float pid_adjust(struct pid *pid_param);

#endif /* SRC_PID_H_ */
