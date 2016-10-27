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
  std::string db_file_name;

public:
  TaskDB();
  TaskDB(const std::string & name);

  void set_name(const std::string & name);

  const Task &                get_task( unsigned int id ) const;
  const std::vector<Task> &   get_task_list() const;

  void                        add_task( const Task & task );
  void                        delete_task(unsigned int id);

  bool                        finish_task(unsigned int id);

  void read();
  void                        save() const;

};

// -----------------------------------------------------------------------------

#endif
