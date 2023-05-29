/*
 * pid.c
 *
 *  Created on: 2020��8��25��
 *      Author: EnglishName
 */

#include "pid.h"

void pid_init(struct pid *pid_param,float Up,float kp,float ki,float kd,float error_min,float error_max)
{
    pid_param->purpose = Up;
    pid_param->kp = kp;
    pid_param->ki = ki;
    pid_param->kd = kd;
    pid_param->last1_error = 0;
    pid_param->last2_error = 0;
    pid_param->current_error = 0;
    pid_param->error_min = error_min;
    pid_param->error_max = error_max;
}
void pid_init_I(struct pid *pid_param,float kp,float ki,float kd,float error_min,float error_max)
{
    pid_param->purpose = 1;
    pid_param->kp = kp;
    pid_param->ki = ki;
    pid_param->kd = kd;
    pid_param->last1_error = 0;
    pid_param->last2_error = 0;
    pid_param->current_error = 0;
    pid_param->error_min = error_min;
    pid_param->error_max = error_max;
}

void pid_purpose(struct pid *pid_param,float purpose)
{
    pid_param->purpose = purpose;
    pid_param->current_error = 0;
    pid_param->last1_error = 0;
    pid_param->last2_error = 0;
}
void pid_step(struct pid *pid_param,float current_value)
{
    pid_param->current_value = current_value;
}
void pid_error(struct pid *pid_param)
{
    float current_error;
    pid_param->last2_error = pid_param->last1_error;
    pid_param->last1_error = pid_param->current_error;
    current_error = pid_param->purpose-pid_param->current_value;
    if(current_error<pid_param->error_min)
        current_error = pid_param->error_min;
    else if(current_error>pid_param->error_max)
        current_error = pid_param->error_max;
    pid_param->current_error = current_error;
}
float pid_adjust(struct pid *pid_param)
{
    float delta_result;
    float p1 = pid_param->last1_error-pid_param->current_error;
    float p2 = pid_param->current_error;
    float p3 = pid_param->current_error - 2*pid_param->last1_error + pid_param->last2_error;
    delta_result = pid_param->kp*p1 + pid_param->ki*p2 + pid_param->kd*p3;
    return delta_result;
}

