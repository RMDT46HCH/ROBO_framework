#ifndef ROBOT_DEF_H
#define ROBOT_DEF_H

//底盘参数(MM)
#define R_WHEEL 50.0f
#define REDUCTION_RATIO_WHEEL 19.0f


typedef enum
{
    ROBOT_STOP=0,
    ROBOT_READY,
}robot_mode_e;

typedef enum
{
    CHASSIS_NONE_FORCE=0,
    CHASSIS_ROTATE,
    CHASSIS_NORMAL,
}chassis_mode_e;

typedef struct 
{
    float vx;
    float vy;
    float wz;
    chassis_mode_e chassis_mode;
}chassis_ctrl_t;

typedef struct 
{
    float real_vx;
    float real_vy;
    float real_wz;
}chassis_feedback_t;





#endif // !ROBOT_DEF_H 