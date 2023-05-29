#ifndef TXIANG_UTOOLS_H_
#define TXIANG_UTOOLS_H_
#define FLASH_USER_DATA_ADDR    0x30080//要+4
#define PAREMETER_COUNT 12
#define PAREMETER_GROUP_COUNT 4
#include "common.h"
typedef struct {
    float old;
    float mid;
    float new;
    float ave_out;
}float_ave;
void init();
void write_int_to_flash(uint32_t* value_arr,uint32_t address,uint32_t count);
void read_int_from_flash(uint32_t* value_arr,uint32_t address,uint32_t count);
void write_float_to_flash(float** value_arr,uint32_t address,uint32_t count);
void read_float_from_flash(float** value_arr,uint32_t address,uint32_t count);

void float_ave_init(float_ave * fa);
float float_ave_step(float_ave * fa,float datain);
#endif
