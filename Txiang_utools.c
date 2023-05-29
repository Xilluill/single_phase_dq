#include "Txiang_utools.h"
#include "common.h"
void write_int_to_flash(uint32_t* value_arr,uint32_t address,uint32_t count)
{
    FlashErase(address);
    FlashProgram(value_arr,address, count*4);
}
void read_int_from_flash(uint32_t* value_arr,uint32_t address,uint32_t count)
{
    uint32_t flash_pointer=address;
    int i=0;
    for(i=0;i<count;i++)
    {
        value_arr[i]=*(uint32_t*)flash_pointer;
        flash_pointer+=4;
    }
}
void write_float_to_flash(float** value_arr,uint32_t address,uint32_t count)
{
    uint32_t buf[PAREMETER_COUNT];
    int i=0;
    for(i=0;i<count;i++)
    {
        buf[i]=*((unsigned int*)value_arr[i]);
    }
    write_int_to_flash(buf,address,count);
    free(buf);
}
void read_float_from_flash(float** value_arr,uint32_t address,uint32_t count)
{
    uint32_t flash_pointer=address;
    int i=0;
    for(i=0;i<count;i++)
    {
        *(value_arr[i])=*(float*)flash_pointer;
        flash_pointer+=4;
    }
}
void float_ave_init(float_ave * fa)
{
    fa->ave_out=0;
    fa->old=0;
    fa->mid=0;
    fa->new=0;
}
float float_ave_step(float_ave * fa,float datain)
{
    fa->old=fa->mid;
    fa->mid=fa->new;
    fa->new=datain;
    fa->ave_out=(fa->old+fa->mid+fa->new)/3;
    return fa->ave_out;
}