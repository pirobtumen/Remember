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

#include "gui/taskitem.hpp"

// -----------------------------------------------------------------------------

Tasker * TaskItem::tasker = nullptr;

TaskItem::TaskItem(){
  create_view();
}

// -----------------------------------------------------------------------------

TaskItem::TaskItem(const TaskItem & task_item){
  create_view();
  (*this) = task_item;
}

// -----------------------------------------------------------------------------

TaskItem::TaskItem(const Task & task){
  create_view();
  load_task(task);
}

// -----------------------------------------------------------------------------

unsigned int TaskItem::get_task_id(){
  return id;
}

// -----------------------------------------------------------------------------

void TaskItem::on_check_button_clicked(){
  tasker -> finish_task(id,check_button.get_active());
  tasker -> save();
  set_task(task_txt);
}

// -----------------------------------------------------------------------------

void TaskItem::set_tasker(Tasker * new_tasker){
  tasker = new_tasker;
}

// -----------------------------------------------------------------------------

void TaskItem::on_delete_button_clicked(){
  tasker -> delete_task(id);
  tasker -> save();

  // TODO: remove from task_list
  get_parent() -> remove((*this));
}

// -----------------------------------------------------------------------------

void TaskItem::create_view(){

  set_task("Default GUI Task text.");

  task.set_use_markup(true);

  del_button.set_label("Delete");
  del_button.get_style_context() -> add_class("destructive-action");

  check_button.signal_clicked().connect(
    sigc::mem_fun(this, &TaskItem::on_check_button_clicked)
  );

  del_button.signal_clicked().connect(sigc::mem_fun(this, &TaskItem::on_delete_button_clicked));

  hbox.set_orientation(Gtk::Orientation::ORIENTATION_HORIZONTAL);
  hbox.pack_start(check_button,0,0,0);
  hbox.pack_start(task,0,0,0);
  hbox.pack_start(empty_label);
  hbox.pack_start(del_button,0,0,0);

  add(hbox);
}

// -----------------------------------------------------------------------------

void TaskItem::set_task(const std::string & task_txt){
  if(check_button.get_active())
    task.set_label("<s>" + task_txt + "</s>");
  else
    task.set_label(task_txt);
}

// -----------------------------------------------------------------------------

void TaskItem::load_task(const Task & task){
  task_txt = task.get_task();
  id = task.get_id();

  set_status(task.is_finished());
  set_task(task_txt);
}

// -----------------------------------------------------------------------------

void TaskItem::load_task_with_tag(const Task & task){
  task_txt = task.get_tag();
  if(task_txt != "")
    task_txt += " - ";

  task_txt += task.get_task();
  id = task.get_id();

  set_status(task.is_finished());
  set_task(task_txt);
}

// -----------------------------------------------------------------------------

void TaskItem::set_status(bool status){
    check_button.set_active(status);
}

// -----------------------------------------------------------------------------

TaskItem & TaskItem::operator=(const TaskItem & taskitem){
  if( this != &taskitem ){
    id = taskitem.id;
    task_txt = taskitem.task_txt;
    set_task(task_txt);
    check_button.set_active(taskitem.check_button.get_active());
  }

  return (*this);
}

// -----------------------------------------------------------------------------

bool operator<(const TaskItem & t1,const TaskItem & t2){
  return t1.id < t2.id;
}

// -----------------------------------------------------------------------------
