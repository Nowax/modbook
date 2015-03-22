#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <map>
#include "operations.h"
#include <QCheckBox>
#include "log/logger.h"

typedef std::map<EOperation, EType> oper_map_t;
typedef std::shared_ptr<QCheckBox> checkbox_t;

namespace Ui {
class main_window;
}

class main_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit main_window(QWidget *parent = 0);
    ~main_window();



private slots:
    void on_checkbox_link_sent_small_stateChanged(int is_checked);
    void on_checkbox_link_sent_big_stateChanged(int is_checked);

    void on_choose_button_clicked();

private:
    void setup_operation_list();
    EType get_operation_type(const checkbox_t& type_check_box) const;
    void remove_planned_oper(EOperation oper);
    void update_planned_oper_list(int is_oper_checked,
                                  checkbox_t type_check_box,
                                  EOperation oper);

    std::shared_ptr<basic_logger> logger;
    Ui::main_window *ui;
    oper_map_t operations;
};

#endif // MAIN_WINDOW_H
