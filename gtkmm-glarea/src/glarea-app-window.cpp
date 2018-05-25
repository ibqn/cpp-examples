#include <iostream>


#include "glarea-app-window.hpp"


GlareaAppWindow::~GlareaAppWindow()
{
}

GlareaAppWindow::GlareaAppWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder)
:Gtk::ApplicationWindow(cobject),
builder(builder)
{

}

void ExampleWindow::on_action_something()
{
  std::cout << G_STRFUNC << std::endl;
}

void ExampleWindow::on_action_close()
{
  std::cout << G_STRFUNC << std::endl;

  hide();
}

void ExampleWindow::on_action_send_notification()
{
  std::cout << G_STRFUNC << std::endl;

  auto note = Gio::Notification::create("Unimportant message!");
  note->set_body("Notification from " + Glib::get_application_name());
  note->add_button("Print", "app.print", Glib::ustring("Hello, world!"));
  note->add_button("Quit Application", "app.quit");
  get_application()->send_notification("note", note);
}

void ExampleWindow::on_action_withdraw_notification()
{
  std::cout << G_STRFUNC << std::endl;

  get_application()->withdraw_notification("note");
}
