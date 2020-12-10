#include "multiply_dialog.hpp"

#include <QFormLayout>
#include <QVBoxLayout>
#include <QDialog>
#include <QDialogButtonBox>
#include <QMessageBox>

#include "../number.hpp"

MultiplyDialog::MultiplyDialog(QWidget *parent) : 
    QDialog(parent) {
    this->baseSpinBox = new QSpinBox(this);
    this->baseSpinBox->setRange(2, 16);

    this->firstFactorLineEdit= new QLineEdit(this);
    this->firstFactorLineEdit->setMaxLength(32);

    this->secondFactorLineEdit= new QLineEdit(this);
    this->secondFactorLineEdit->setMaxLength(1);

    this->resultLabel = new QLabel("");

    QFormLayout *formLayout = new QFormLayout();

    formLayout->addRow(tr("&Base: "), this->baseSpinBox);
    formLayout->addRow(tr("&First Factor: "), this->firstFactorLineEdit);
    formLayout->addRow(tr("&Second Factor: "), this->secondFactorLineEdit);
    formLayout->addRow(tr("&Result: "), this->resultLabel);

    QDialogButtonBox *buttonBox = 
        new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &MultiplyDialog::compute);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &MultiplyDialog::reject);

    QVBoxLayout *mainLayout = new QVBoxLayout();

    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(buttonBox);

    this->setLayout(mainLayout);
}

void MultiplyDialog::compute() {
    unsigned int base = this->baseSpinBox->value();

    try {
        Number product = Number(base, this->firstFactorLineEdit->text().toStdString()) *
                         Number(base, this->secondFactorLineEdit->text().toStdString());

        this->resultLabel->setText(tr(product.get_value().c_str()));
    } catch (const std::runtime_error& exception) {
        QMessageBox::critical(this, tr("Error"), tr(exception.what()));
    }
}
