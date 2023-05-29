/*
 * @ ADS8688
 * @ ��ȡ˲ʱֵ����Чֵ��ƽ��ֵ
 * @ Yuyang
 * @ 2021.07.11
 */
#include "ADS8688_TIVA_FPGA.h"
#include "bus_fpga.h"
#include "common.h"

/*
 * ��õ�ѹ��˲ʱֵ
 * ���룺BASEƬѡ��ַ��OFFSETƬ�ڵ�ַ
 * �������ѹ��˲ʱֵ
 */
double getVoltage(unsigned char BASE, unsigned char OFFSET)
{
    double proportion = MEASURING_RANGE * 2 / 65536;
    unsigned int volt16bit = 0;
    double voltage = 0;
    volt16bit = IORD(BASE, OFFSET);

    if (volt16bit > 0x8000)
        voltage = proportion * (volt16bit - 0x8000);
    else
        voltage = -proportion * (0x8000 - volt16bit);
    return voltage;

}

/*
 * ��õ�ѹ����Чֵ
 * ���룺BASEƬѡ��ַ��OFFSETƬ���׵�ַ��SAMPLE_NUM_OFFSET��������Ƭ�ڵ�ַ
 * �������ѹ����Чֵ
 */
double getVoltageRMS(unsigned char BASE, unsigned char OFFSET, unsigned char SAMPLE_NUM_OFFSET)
{
    double proportion = MEASURING_RANGE * 2 / 65536;
    long long int Power[3] = { 0 };
    double voltage_rms = 0;
    // ��ȡ��Чֵ���ݣ�48λ���ݣ������ζ�ȡ
    Power[2] = IORD(BASE, OFFSET);
    Power[1] = IORD(BASE, OFFSET + 1);
    Power[0] = IORD(BASE, OFFSET + 2);
    int sample_num = IORD(BASE, SAMPLE_NUM_OFFSET);

    Power[2] = Power[2] << 32;
    Power[1] = Power[1] << 16;
    voltage_rms = (sqrt(1.0*(Power[0] + Power[1] + Power[2]) / sample_num)) * proportion;     // ������Чֵ

    return voltage_rms;

}

/*
 * ��õ�ѹ�ľ�ֵ
 * ���룺BASEƬѡ��ַ��OFFSETƬ���׵�ַ��CNT_MEAN_OFFSET��������Ƭ�ڵ�ַ
 * �������ѹ��ƽ��ֵ
 */
double getVoltageMean(unsigned char BASE, unsigned char OFFSET, unsigned char CNT_MEAN_OFFSET)
{
    double proportion = MEASURING_RANGE * 2 / 65536;
    long long int Mean[3] = { 0 };
    double voltage_mean = 0;
    // ��ȡƽ��ֵ���ݣ�48λ���ݣ������ζ�ȡ
    Mean[2] = IORD(BASE, OFFSET);
    Mean[1] = IORD(BASE, OFFSET + 1);
    Mean[0] = IORD(BASE, OFFSET + 2);
    int cntMean = IORD(BASE, CNT_MEAN_OFFSET);

    Mean[2] = Mean[2] << 32;
    Mean[1] = Mean[1] << 16;
    voltage_mean = 1.0 * (Mean[0] + Mean[1] + Mean[2]) / cntMean  * proportion;     // �����ֵ
    return voltage_mean;

}









