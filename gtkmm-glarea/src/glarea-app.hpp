#ifndef __GLAREA_APP_HPP__
#define __GLAREA_APP_HPP__


#include <gtkmm.h>


class GlareaApp: public Gtk::Application
{
protected:
  GlareaApp();

public:
  static Glib::RefPtr<GlareaApp> create();

protected:
  // Override default signal handlers:
  void on_startup() override;
  void on_activate() override;
  void on_open(const Gio::Application::type_vec_files & files,
    const Glib::ustring & hint) override;

private:
  GlareaApp* create_appwindow();
  void on_hide_window(Gtk::Window* window);
  void on_action_preferences();
  void on_action_quit();
};

#endif /* __GLAREA_APP_HPP__ */
