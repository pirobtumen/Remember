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

#ifndef __TASKITEM_HPP
#define __TASKITEM_HPP

// -----------------------------------------------------------------------------

#include <gtkmm.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/button.h>
#include <gtkmm/checkbutton.h>
#include <string>

#include "task.hpp"
#include "tasker.hpp"

// -----------------------------------------------------------------------------

class TaskItem : public Gtk::ListBoxRow {
private:
  unsigned int id;
  std::string task_txt;

  // Widgets
  // ---------------------------------------------------------------------------
  Gtk::Box          hbox;
  Gtk::CheckButton  check_button;
  Gtk::Label        task;
  Gtk::Label        empty_label;
  Gtk::Button       del_button;

  // Model
  static Tasker * tasker;

  // ---------------------------------------------------------------------------

  void create_view();

  void on_delete_button_clicked();
  void on_check_button_clicked();

public:
  TaskItem();
  TaskItem(const TaskItem & task_item);
  TaskItem(const Task & task);

  unsigned int get_task_id();

  void set_task(const std::string & task_txt);
  void load_task(const Task & task);
  void load_task_with_tag(const Task & task);

  void set_status(bool status);
  static void set_tasker(Tasker * new_tasker);

  TaskItem & operator=(const TaskItem & taskitem);
  friend bool operator<(const TaskItem & t1,const TaskItem & t2);

};

// -----------------------------------------------------------------------------

bool operator<(const TaskItem & t1,const TaskItem & t2);

// -----------------------------------------------------------------------------

#endif
