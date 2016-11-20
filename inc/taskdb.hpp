// -----------------------------------------------------------------------------

#ifndef __TASK_DB_HPP
#define __TASK_DB_HPP

#include <vector>
#include <map>
#include <fstream>
#include "task.hpp"

// -----------------------------------------------------------------------------

class TaskDB{
private:
  std::map<unsigned int, Task> task_list;
  std::string db_file_name;
  unsigned int last_id;

public:
  TaskDB();
  TaskDB(const std::string & name);

  void                        set_name(const std::string & name);

  Task                        get_task( unsigned int id ) const;
  void                        get_task_list(std::vector<Task> & tasks) const;

  void                        add_task( const Task & task );
  void                        delete_task(unsigned int id);

  bool                        finish_task(unsigned int id);

  void                        read();
  void                        save() const;

};

// -----------------------------------------------------------------------------

#endif
