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

#include "task.hpp"

// -----------------------------------------------------------------------------

Task::Task(){
  data = "";
  finished = false;
  id = 0;
  creation_date.set_current();
  tag = "General";
}

// -----------------------------------------------------------------------------

Task::Task( const std::string & new_data ){
  load_from_str(new_data);
}

// -----------------------------------------------------------------------------

void Task::load_from_str( const std::string & task_data ){
  /*
    Load task data from string.

    String format: field:value,
  */
  std::map<std::string,std::string> data;
  std::map<std::string,std::string>::const_iterator find;
  bool add_field = true;
  std::string field = "";
  std::string value = "";
  char next_char;
  unsigned int data_size = task_data.size();

  // Extract data
  for( unsigned int i = 0; i < data_size; i++ ){

    next_char = task_data[i];

    if(next_char == ','){

      data.insert(std::make_pair(field,value));
      field = "";
      value = "";
      add_field = true;

    }
    else if(next_char == ':')
      add_field = false;
    else if(add_field)
      field += next_char;
    else
      value += next_char;

  }

  data.insert(std::make_pair(field,value));

  // ID
  find = data.find("id");
  if(find != data.cend())
    set_id(std::stoi((*find).second));

  // Task
  find = data.find("task");
  if(find != data.cend())
    set_task((*find).second);

  // Finished
  find = data.find("finished");
  if(find != data.cend())
    set_status((*find).second);

  // Tag
  find = data.find("tag");
  if(find != data.cend())
    set_tag((*find).second);

  // Creation date
  find = data.find("creation_date");
  if(find != data.cend())
    set_creation_date(Date((*find).second));

  // Finish date
  find = data.find("finish_date");
  if(find != data.cend())
    set_finish_date(Date((*find).second));
}

// -----------------------------------------------------------------------------

void Task::set_status(const std::string & status){
  /*
    Set if the task is finished or not.
  */
  if(status == "1")
    finished = 1;
  else
    finished = 0;
}

// -----------------------------------------------------------------------------

void Task::set_task(const std::string & task){
  /*
    Set task.
  */
  data = task;
}
// -----------------------------------------------------------------------------

const std::string & Task::get_task() const{
  /*
    Return task.
  */
  return data;
}

// -----------------------------------------------------------------------------

std::string Task::to_str() const{
  /*
    Turn the task into a string.

    String format: field:vlaue,
  */
  const char separator = ',';

  char char_finished = (finished)? '1' : '0';
  std::string task_data;

  task_data.reserve(64);

  task_data += "task:";
  task_data += data;
  task_data += separator;
  task_data += "finished:";
  task_data += char_finished;
  task_data += separator;
  task_data += "creation_date:";
  task_data += creation_date.to_str();
  task_data += separator;
  task_data += "finish_date:";
  task_data += finish_date.to_str();
  task_data += separator;
  task_data += "id:";
  task_data += std::to_string(id);
  task_data += separator;
  task_data += "tag:";
  task_data += tag;

  return task_data;
}

// -----------------------------------------------------------------------------

void Task::set_id(unsigned int new_id){
  /*
    Set ID.
  */
  id = new_id;
}

// -----------------------------------------------------------------------------

unsigned int Task::get_id() const{
  /*
    Return id.
  */
  return id;
}

// -----------------------------------------------------------------------------

bool Task::is_empty() const{
  /*
    Check if the task is an empty task.
  */
  return id == 0;
}

// -----------------------------------------------------------------------------

bool Task::is_finished() const{
  /*
    Return if the task is finished.
  */
  return finished;
}

// -----------------------------------------------------------------------------

bool Task::finish(){
  /*
    Finish/Start the task.
  */
  bool last_value = finished;
  finished = !finished;
  return last_value;
}

// -----------------------------------------------------------------------------

const Date & Task::get_creation_date() const{
  /*
    Set the creation date.
  */
  return creation_date;
}

// -----------------------------------------------------------------------------

void Task::set_creation_date(const Date & date){
  /*
    Set the creation date.
  */
  creation_date = date;
}

// -----------------------------------------------------------------------------

const Date & Task::get_finish_date() const{
  /*
    Return the finish date.
  */
  return finish_date;
}

// -----------------------------------------------------------------------------

void Task::set_finish_date(const Date & date){
  /*
    Set the finish date.
  */
  finish_date = date;
}

// -----------------------------------------------------------------------------

const std::string & Task::get_tag() const{
  /*
    Return tag.
  */
  return tag;
}

// -----------------------------------------------------------------------------

void Task::set_tag(const std::string & new_tag){
  /*
    Set tag.
  */
  tag = new_tag;
}

// -----------------------------------------------------------------------------
