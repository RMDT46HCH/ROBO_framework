#include "robot_def.h"
#include "cmd.h"
#include "remote_control.h"
static chassis_ctrl_t chassis_cmd_send;
static chassis_feedback_t chassis_fetch_data;
static rc_ctrl_t rc_data;

static void remote_control_set()
{
    if(switch_is_down(rc_data.switch_right))
    chassis_cmd_send.chassis_mode=CHASSIS_NONE_FORCE;
    else if(switch_is_mid(rc_data.switch_right))
    chassis_cmd_send.chassis_mode=CHASSIS_NORMAL;
    else if(switch_is_up(rc_data.switch_right))
    chassis_cmd_send.chassis_mode=CHASSIS_ROTATE;

    chassis_cmd_send.vx=rc_data.rocker_left_y;
    chassis_cmd_send.vy=-rc_data.rocker_left_x;
}

void cmd_task()
{
    remote_control_set();
}