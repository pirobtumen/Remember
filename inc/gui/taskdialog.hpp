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

#ifndef __TASKDIALOG_HPP
#define __TASKDIALOG_HPP

// -----------------------------------------------------------------------------

#include <gtkmm.h>
#include <gtkmm/dialog.h>
#include <gtkmm/button.h>
#include <gtkmm/grid.h>
#include <string>

// -----------------------------------------------------------------------------

class TaskDialog : public Gtk::Dialog{
protected:
  Gtk::Grid   task_view;
  Gtk::Button ok_button;
  Gtk::Button cancel_button;

  Gtk::Entry task;
  Gtk::Label txt_task;

  // TODO: ComboBox
  Gtk::Entry tag;
  Gtk::Label txt_tag;

  // TODO: DateEntry
  // TODO: creation date
  // TODO: finish date

  void load_view();
  void set_actions();

public:
  TaskDialog(const std::string & title, Gtk::Window & parent);

  std::string get_task();
  std::string get_tag();

  void set_task(const std::string & task_txt);
  void set_tag(const std::string & tag_txt);
};

// -----------------------------------------------------------------------------

#endif
