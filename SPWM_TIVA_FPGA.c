/*
 * @ SPWM
 * @ 转化SPWM参数并发送给FPGA
 * @ Yuyang
 * @ 2021.07.18
 */
#include "SPWM_TIVA_FPGA.h"
#include "bus_fpga.h"
#include "common.h"

/*
 * 向FPGA发送调制比adj
 * 输入：BASE片选地址，adj调制比
 * 输出：无
 */
void sendAdj(unsigned char BASE, double adj)
{
    if(adj > ADJ_MAX)
        adj = ADJ_MAX;
    else if(adj < ADJ_MIN)
        adj = ADJ_MIN;
    IOWR(BASE, 0, (int)(adj * 1024 + 0.5));

}

/*
 * 向FPGA发送频率控制字kw
 * 输入：BASE片选地址，kw频率控制字
 * 输出：无
 */
void sendKw(unsigned char BASE, int kw)
{
    if(kw > KW_MAX)
        kw = KW_MAX;
    else if(kw < KW_MIN)
        kw = KW_MIN;
    IOWR(BASE, 1, kw);

}

/*
 * 向FPGA发送波表偏置bias
 * 输入：BASE片选地址，bias波表偏置
 * 输出：无
 */
void sendBias(unsigned char BASE, int bias)
{
    if(bias > BIAS_MAX)
        bias = BIAS_MAX;
    else if(bias < BIAS_MIN)
        bias = BIAS_MIN;
    IOWR(BASE, 2, bias);

}

/*
 * 向FPGA发送频率
 * 输入：BASE片选地址，freq输出sin波频率
 * 输出：无
 */
void sendFreq(unsigned char BASE, double freq)
{
    // 将频率转化为频率控制字，kw = （波表长度 /（开关频率 / sin频率）） * 64
    double kw = (TABLE_LENGTH / (20000 / freq)) * 64;
    sendKw(BASE, (int)(kw + 0.5));

}



























