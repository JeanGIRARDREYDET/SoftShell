
#include "../minishell.h"

void mi_exec (t_pipe *pipe, t_sys *mi_sys)
{
	if (mi_sys->nb_pipe == 0)
		mi_execone(pipe, mi_sys);
	else
	{}
}