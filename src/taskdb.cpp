// -----------------------------------------------------------------------------
//
// MIT License
//
// Copyright (c) 2016 Alberto Sola
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

#include "taskdb.hpp"

// -----------------------------------------------------------------------------

TaskDB::TaskDB(){
  initialize();
}

// -----------------------------------------------------------------------------

TaskDB::TaskDB(const std::string & name){
  initialize();
  set_name(name);
}

// -----------------------------------------------------------------------------

void TaskDB::initialize(){
  /*
    Initialize the ID count, and set an empty task (ID: 0).
  */

  Task task;

  last_id = 0;      // Start ID count
  task.set_id(last_id);
  add_task(task);   // Empty Task - 0

}

// -----------------------------------------------------------------------------

void TaskDB::set_name(const std::string & name){
  /*
    Set the TaskDB file name.
  */
  db_file_name = name;
}

// -----------------------------------------------------------------------------

// TODO: return error code
void TaskDB::read(){
  /*
    Read the TaskDB file.
  */
  std::ifstream file(db_file_name, std::ofstream::in );
  std::string line;
  Task task;
  unsigned int id = 0;

  if( file.is_open() ){

    std::getline(file,line);

    while(!file.eof()){
      task.load_from_str(line);
      id = task.get_id();
      task_list.insert(std::make_pair(id,task));

      if(id > last_id)
        last_id = id;

      std::getline(file,line);
    }

  }

  if(last_id > 1 || id == 1)
    last_id += 1;

  file.close();
}

// -----------------------------------------------------------------------------

void TaskDB::save() const{
  /*
    Save all tasks.
  */
  std::ofstream file(db_file_name, std::ofstream::out | std::ofstream::trunc);

  for( auto & task : task_list )
        file << task.second.to_str() << std::endl;

  file.close();

}

// -----------------------------------------------------------------------------

void TaskDB::add_task( Task & task ){
  /*
    Add a new task.
  */
  task.set_id(last_id);
  task_list.insert(std::make_pair(last_id, task));
  last_id += 1;
}

// -----------------------------------------------------------------------------

const Task & TaskDB::get_task( unsigned int id ) const{
  /*
      Get a task by its ID.
  */
  std::map<unsigned int,Task>::const_iterator it = task_list.find(id);

  if( it != task_list.end() )
    return (*it).second;
  else
    return (*task_list.find(0)).second;
}

// -----------------------------------------------------------------------------

void TaskDB::delete_task(unsigned int id){
  /*
      Delete a task by its ID.
  */
  task_list.erase(id);
}

// -----------------------------------------------------------------------------

bool TaskDB::finish_task(unsigned int id){
  /*
      Finish/Starts a task by its ID.
  */
  std::map<unsigned int,Task>::iterator it = task_list.find(id);
  bool status = false;

  if( it != task_list.end() )
    status = (*it).second.finish();

  return status;
}

// -----------------------------------------------------------------------------

void TaskDB::get_task_list(std::vector<Task> & tasks) const{
  /*
      Get all tasks.
  */
  std::map<unsigned int, Task>::const_iterator start = task_list.cbegin();
  std::map<unsigned int, Task>::const_iterator end = task_list.cend();

  start++; // Skip ID:0

  for(auto & t = start; t != end; t++ )
    tasks.push_back((*t).second);
}

// -----------------------------------------------------------------------------

void TaskDB::get_task_list(std::vector<Task> & tasks, const std::string & tag) const{

  std::map<unsigned int, Task>::const_iterator start = task_list.cbegin();
  std::map<unsigned int, Task>::const_iterator end = task_list.cend();

  start++; // Skip ID:0

  for(auto & t = start; t != end; t++ )
    if((*t).second.get_tag() == tag)
      tasks.push_back((*t).second);

}

// -----------------------------------------------------------------------------
