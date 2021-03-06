#ifndef _PROCESS_H_
#define _PROCESS_H_

#include <thread.h>

struct process {
  pid_t pid;

  int did_exit;
  int exit_code;
  int newest_child_pid;

  struct thread *t;
  struct process *children[1000];
  struct process *parent;
};

struct process *process_create(pid_t pid, struct thread *t);
int process_remove_process(pid_t pid);
pid_t process_give_pid();

#endif /* _PROCESS_H_ */
