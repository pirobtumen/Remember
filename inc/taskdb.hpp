// -----------------------------------------------------------------------------

#ifndef __TASK_DB_HPP
#define __TASK_DB_HPP

#include <vector>
#include <fstream>
#include "task.hpp"

// -----------------------------------------------------------------------------

class TaskDB{
private:
  std::vector<Task> task_list;

  void read();

public:
  TaskDB();

  const Task &                get_task( unsigned int id ) const;
  const std::vector<Task> &   get_task_list() const;

  void                        add_task( const Task & task );
  void                        delete_task(unsigned int id);

  void                        finish_task(unsigned int id);

  void                        save() const;

};

// -----------------------------------------------------------------------------

#endif
