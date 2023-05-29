/*
 * @ SPWM
 * @ ת��SPWM���������͸�FPGA
 * @ Yuyang
 * @ 2021.07.18
 */
#include "SPWM_TIVA_FPGA.h"
#include "bus_fpga.h"
#include "common.h"

/*
 * ��FPGA���͵��Ʊ�adj
 * ���룺BASEƬѡ��ַ��adj���Ʊ�
 * �������
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
 * ��FPGA����Ƶ�ʿ�����kw
 * ���룺BASEƬѡ��ַ��kwƵ�ʿ�����
 * �������
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
 * ��FPGA���Ͳ���ƫ��bias
 * ���룺BASEƬѡ��ַ��bias����ƫ��
 * �������
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
 * ��FPGA����Ƶ��
 * ���룺BASEƬѡ��ַ��freq���sin��Ƶ��
 * �������
 */
void sendFreq(unsigned char BASE, double freq)
{
    // ��Ƶ��ת��ΪƵ�ʿ����֣�kw = �������� /������Ƶ�� / sinƵ�ʣ��� * 64
    double kw = (TABLE_LENGTH / (20000 / freq)) * 64;
    sendKw(BASE, (int)(kw + 0.5));

}



























