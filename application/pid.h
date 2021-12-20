/**
  ******************************************************************************
  * @file       pid.h
	* @author			sxx
  * @brief      
  * @note       
  * @history
  *  Version    Date            Modification
  *  V1.0.0     Dec-11-2021     1. done
  * @todo				1. move functions out of the typedef
	*							2. move away no use attributes
	*
  ******************************************************************************
  */
	
#ifndef PID_H
#define PID_H

#include "struct_typedef.h"
#include "bsp_can.h"

typedef enum
{
	PID_Position,
	PID_Speed
} pid_id_e;

typedef struct _pid_t
{
	pid_id_e id;
	
	float target;							//Ŀ��ֵ
	float lastNoneZeroTarget;
	float kp;
	float ki;
	float kd;
	
	float   measure;					//����ֵ
	float   err;							//���
	float   last_err;      		//�ϴ����
	
	float pout;
	float iout;
	float dout;
	
	float output;						//�������
	float last_output;			//�ϴ����
	
	float MaxOutput;				//����޷�
	float IntegralLimit;		//�����޷�
	float DeadBand;			  //����������ֵ��
	float ControlPeriod;		//��������
	float  Max_Err;					//������
	
	uint32_t thistime;
	uint32_t lasttime;
	uint8_t dtime;	
	
	void (*f_param_init)(struct _pid_t *pid,  //PID������ʼ��
										pid_id_e id,
										uint16_t maxOutput,
										uint16_t integralLimit,
										float deadband,
										int16_t max_err,     
										int16_t  target,
										const float PID[3]);
	void (*f_pid_reset)(struct _pid_t *pid, float kp,float ki, float kd);		//pid���������޸�
	float (*f_cal_pid)(struct _pid_t *pid, float measure);   //pid����

} pid_t;

void pid_init(pid_t* pid);


#endif
