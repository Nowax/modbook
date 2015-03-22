#include "main_window.h"
#include "ui_main_window.h"
#include <QFileDialog>
#include <qtextcodec.h>
#include "common_consts.h"

main_window::main_window(QWidget *parent) :
    QMainWindow(parent),
    logger(new basic_logger("main_windows")),
    ui(new Ui::main_window)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("ISO8859-2"));
    ui->setupUi(this);
    setup_operation_list();
}

main_window::~main_window()
{
    delete ui;
}

void main_window::setup_operation_list()
{
    update_planned_oper_list(ui->checkbox_link_sent_small->isChecked(),
                             std::make_shared<QCheckBox>(
                                 ui->checkbox_manual_accept_small),
                             EOperation_small_letter_link);
    update_planned_oper_list(ui->checkbox_link_sent_big->isChecked(),
                             std::make_shared<QCheckBox>(
                                 ui->checkbox_manual_accept_big),
                             EOperation_big_letter_link);
}

void main_window::on_checkbox_link_sent_big_stateChanged(int is_checked)
{
    EOperation oper = EOperation_big_letter_link;
    auto type_check_box = std::make_shared<QCheckBox>(
                                ui->checkbox_manual_accept_big);

    update_planned_oper_list(is_checked, type_check_box, oper);
}

void main_window::on_checkbox_link_sent_small_stateChanged(int is_checked)
{
    EOperation oper = EOperation_small_letter_link;
    auto type_check_box = std::make_shared<QCheckBox>(
                                ui->checkbox_manual_accept_small);

    update_planned_oper_list(is_checked, type_check_box, oper);
}

void main_window::update_planned_oper_list(int is_oper_checked,
                                           checkbox_t type_check_box,
                                           EOperation oper)
{
    if (is_oper_checked) {
        EType oper_type = get_operation_type(type_check_box);

        operations.insert(std::make_pair(oper, oper_type));
        logger->log_debug("Added new operation to planned operation list - "
                          + constants::oper_to_string_map[oper]);
    } else {
        remove_planned_oper(oper);
    }
}

EType main_window::get_operation_type(const checkbox_t& type_check_box) const
{
    if (type_check_box->isChecked()) {
        return EType_manual;
    } else {
        return EType_auto;
    }
}

void main_window::remove_planned_oper(EOperation oper)
{
    oper_map_t::iterator it = operations.find(oper);
    if (it != operations.end()) {
        operations.erase(oper);
        logger->log_debug("Removed operation from planned operations list - "
                          + constants::oper_to_string_map[oper]);
    }
}

void main_window::on_choose_button_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, tr("Open File"), "",
                                                     tr("Text Files (*.txt)"));

    logger->log_debug(file_name.toStdString());

    std::string file_name_dir = file_name.toStdString();
    const size_t last_slash_idx = file_name_dir.find_last_of("\\/");
    if (std::string::npos != last_slash_idx)
    {
        file_name_dir.erase(0, last_slash_idx + 1);
    }
    ui->tittle_label->setText(QString::fromStdString(file_name_dir));
}
