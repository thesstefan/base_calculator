#include "add_dialog.hpp"

#include <QFormLayout>
#include <QVBoxLayout>
#include <QDialog>
#include <QDialogButtonBox>
#include <QMessageBox>

#include "../number.hpp"

AddDialog::AddDialog(QWidget *parent) : 
    QDialog(parent) {
    this->setWindowTitle("Add Operation");
    this->baseSpinBox = new QSpinBox(this);
    this->baseSpinBox->setRange(2, 16);

    this->firstTermLineEdit= new QLineEdit(this);
    this->firstTermLineEdit->setMaxLength(32);

    this->secondTermLineEdit= new QLineEdit(this);
    this->secondTermLineEdit->setMaxLength(32);

    this->resultLabel = new QLabel("");

    QFormLayout *formLayout = new QFormLayout();

    formLayout->addRow(tr("&Base: "), this->baseSpinBox);
    formLayout->addRow(tr("&First Term: "), this->firstTermLineEdit);
    formLayout->addRow(tr("&Second Term: "), this->secondTermLineEdit);
    formLayout->addRow(tr("&Result: "), this->resultLabel);

    QDialogButtonBox *buttonBox = 
        new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &AddDialog::compute);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &AddDialog::reject);

    QVBoxLayout *mainLayout = new QVBoxLayout();

    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(buttonBox);

    this->setLayout(mainLayout);
}

void AddDialog::compute() {
    unsigned int base = this->baseSpinBox->value();

    try {
        Number sum = Number(base, this->firstTermLineEdit->text().toStdString()) +
                     Number(base, this->secondTermLineEdit->text().toStdString());

        this->resultLabel->setText(tr(sum.get_value().c_str()));
    } catch (const std::runtime_error& exception) {
        QMessageBox::critical(this, tr("Error"), tr(exception.what()));
    }
}
