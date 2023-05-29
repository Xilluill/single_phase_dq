#ifndef SPWM_TIVA_FPGA_H_
#define SPWM_TIVA_FPGA_H_

// ������
#define TABLE_LENGTH    4096
// �������������Ʒ�Χ
#define ADJ_MAX         4.8
#define ADJ_MIN         1
#define KW_MAX          1400    // 100+Hz
#define KW_MIN          200     // 20-Hz
#define BIAS_MAX        4095
#define BIAS_MIN        0

void sendAdj(unsigned char BASE, double adj);           // ��FPGA���͵��Ʊ�adj
void sendKw(unsigned char BASE, int kw);                // ��FPGA����Ƶ�ʿ�����kw
void sendBias(unsigned char BASE, int bias);            // ��FPGA���Ͳ���ƫ��bias

void sendFreq(unsigned char BASE, double freq);         // ��FPGA����Ƶ��


#endif
