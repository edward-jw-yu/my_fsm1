/* finite state machine */
#ifndef __MY_FSM1_H__
#define __MY_FSM1_H__

typedef struct
{
    int event;             // 事件
    int cur_state;         // 当前状态
    int nxt_state;         // 下一个状态
    void (*handler)(void *data); // 事件处理句柄
} my_fsm1_table_t, *my_fsm1_table_pt;

typedef struct
{
    int lst_state; // 上一次状态
    int cur_state; // 当前状态
    int tb_size;
    my_fsm1_table_pt table;
} my_fsm1_t, *my_fsm1_pt;

/* 初始化有限状态机 */
void my_fsm1_init(my_fsm1_pt p_fsm1, my_fsm1_table_pt p_fsm1_tb, int tb_size);

/* 切换状态 */
void my_fsm1_transform(my_fsm1_pt p_fsm1, int state);

/* 状态机处理事件 */
void my_fsm1_handle_event(my_fsm1_pt p_fsm1, int event, void *data);

#endif // __MY_FSM1_H__
