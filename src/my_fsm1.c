#include "my_fsm1.h"
#include <rtthread.h>

/* 初始化有限状态机 */
void my_fsm1_init(my_fsm1_pt p_fsm1, my_fsm1_table_pt p_fsm1_tb, int tb_size)
{
    if ((!p_fsm1) || (!p_fsm1_tb)) return;

    p_fsm1->table = p_fsm1_tb;
    p_fsm1->tb_size = tb_size;
}

/* 切换状态 */
void my_fsm1_transform(my_fsm1_pt p_fsm1, int state)
{
    if (!p_fsm1) return;
    
    p_fsm1->lst_state = p_fsm1->cur_state; // 保存上一次状态
    p_fsm1->cur_state = state;

    rt_kprintf("\r\n[fsm1] lst_state: %d, cur_state: %d\r\n", p_fsm1->lst_state, p_fsm1->cur_state);
}

/* 状态机处理事件 */
void my_fsm1_handle_event(my_fsm1_pt p_fsm1, int event)
{
    if (!p_fsm1) return;

    /* 获取事件处理函数 */
    for (int i = 0; i < p_fsm1->tb_size; i++)
    {
        // 当且仅当当前状态下来个指定的事件，我才执行它
        if ((event == p_fsm1->table[i].event) && (p_fsm1->cur_state == p_fsm1->table[i].cur_state))
        {
            // 进入下一个状态
            my_fsm1_transform(p_fsm1, p_fsm1->table[i].nxt_state);
            if (p_fsm1->table[i].handler)
            { // 执行事件处理函数
                p_fsm1->table[i].handler();
            }
            break;
        }
    }
}
