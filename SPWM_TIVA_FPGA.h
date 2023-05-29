#ifndef SPWM_TIVA_FPGA_H_
#define SPWM_TIVA_FPGA_H_

// 波表长度
#define TABLE_LENGTH    4096
// 各个参数的限制范围
#define ADJ_MAX         4.8
#define ADJ_MIN         1
#define KW_MAX          1400    // 100+Hz
#define KW_MIN          200     // 20-Hz
#define BIAS_MAX        4095
#define BIAS_MIN        0

void sendAdj(unsigned char BASE, double adj);           // 向FPGA发送调制比adj
void sendKw(unsigned char BASE, int kw);                // 向FPGA发送频率控制字kw
void sendBias(unsigned char BASE, int bias);            // 向FPGA发送波表偏置bias

void sendFreq(unsigned char BASE, double freq);         // 向FPGA发送频率


#endif
