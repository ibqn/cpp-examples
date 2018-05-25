#ifndef __GLAREA_APP_WINDOW_HPP__
#define __GLAREA_APP_WINDOW_HPP__


#include <gtkmm.h>


class GlareaAppWindow: public Gtk::ApplicationWindow
{
public:
    GlareaAppWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder> & glade);
    virtual ~GlareaAppWindow();

protected:
    Glib::RefPtr<Gtk::Builder> builder;

private:
    void on_action_something();
    void on_action_close();
    void on_action_send_notification();
    void on_action_withdraw_notification();
};

#endif /* __GLAREA_APP_WINDOW_HPP__ */
