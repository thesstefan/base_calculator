#include "divide_dialog.hpp"

#include <QFormLayout>
#include <QVBoxLayout>
#include <QDialog>
#include <QDialogButtonBox>
#include <QMessageBox>

#include "../number.hpp"

DivideDialog::DivideDialog(QWidget *parent) : 
    QDialog(parent) {
    this->setWindowTitle("Divide Operation");
    this->baseSpinBox = new QSpinBox(this);
    this->baseSpinBox->setRange(2, 16);

    this->dividendLineEdit= new QLineEdit(this);
    this->dividendLineEdit->setMaxLength(32);

    this->divisorLineEdit= new QLineEdit(this);
    this->divisorLineEdit->setMaxLength(1);

    this->resultLabel = new QLabel("");

    QFormLayout *formLayout = new QFormLayout();

    formLayout->addRow(tr("&Base: "), this->baseSpinBox);
    formLayout->addRow(tr("&Dividend: "), this->dividendLineEdit);
    formLayout->addRow(tr("&Divisor: "), this->divisorLineEdit);
    formLayout->addRow(tr("&Result: "), this->resultLabel);

    QDialogButtonBox *buttonBox = 
        new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &DivideDialog::compute);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &DivideDialog::reject);

    QVBoxLayout *mainLayout = new QVBoxLayout();

    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(buttonBox);

    this->setLayout(mainLayout);
}

void DivideDialog::compute() {
    unsigned int base = this->baseSpinBox->value();

    try {
        auto result = Number(base, this->dividendLineEdit->text().toStdString()) /
                      Number(base, this->divisorLineEdit->text().toStdString());

        auto result_str = tr(result.first.get_value().c_str()) + ", Remainder: " +
                          tr(result.second.get_value().c_str());

        this->resultLabel->setText(result_str);
    } catch (const std::runtime_error& exception) {
        QMessageBox::critical(this, tr("Error"), tr(exception.what()));
    }
}
