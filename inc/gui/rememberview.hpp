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

#ifndef __REMEMBERVIEW_HPP
#define __REMEMBERVIEW_HPP

// -----------------------------------------------------------------------------

#include <gtkmm.h>
#include <gtkmm/headerbar.h>
#include <gtkmm/button.h>
#include <gtkmm/stylecontext.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/listbox.h>
#include <gtkmm/menubutton.h>
#include <gtkmm/menu.h>
#include <gtkmm/checkmenuitem.h>

#include <vector>
#include <list>

#include "gui/taskitem.hpp"
#include "gui/taskdialog.hpp"
#include "tasker.hpp"

class RememberView : public Gtk::Window{
private:

  // Attrs
  // ---------------------------------------------------------------------------

  // Header widgets
  Gtk::HeaderBar header_bar;
  Gtk::Button add_task;
  Gtk::MenuButton menu_bttn;
  Gtk::Menu menu;
  Gtk::CheckMenuItem mi_show_finished;
  Gtk::CheckMenuItem mi_group_tag;

  // Main window widgets
  Gtk::ScrolledWindow scrolled_window;
  Gtk::ListBox listbox;

  // Task Widgets
  // TODO: unordered_set (hash) ??
  std::list<TaskItem> task_list;

  // Model
  Tasker * tasker;


  // Widgets
  // ---------------------------------------------------------------------------
  void create_task_list();
  void create_header_bar();

  // Data
  // ---------------------------------------------------------------------------
  void load_tasks();

  // Actions
  // ---------------------------------------------------------------------------
  void on_button_add_clicked();
  void row_clicked(Gtk::ListBoxRow* row);

public:
  RememberView(Tasker * tasker);
  void init();
};

// -----------------------------------------------------------------------------

#endif
