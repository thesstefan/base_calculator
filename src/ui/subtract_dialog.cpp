#include "subtract_dialog.hpp"

#include <QFormLayout>
#include <QVBoxLayout>
#include <QDialog>
#include <QDialogButtonBox>
#include <QMessageBox>

#include "../number.hpp"

SubtractDialog::SubtractDialog(QWidget *parent) : 
    QDialog(parent) {
    this->baseSpinBox = new QSpinBox(this);
    this->baseSpinBox->setRange(2, 16);

    this->subterhandLineEdit= new QLineEdit(this);
    this->subterhandLineEdit->setMaxLength(32);

    this->minuendLineEdit= new QLineEdit(this);
    this->minuendLineEdit->setMaxLength(32);

    this->resultLabel = new QLabel("");

    QFormLayout *formLayout = new QFormLayout();

    formLayout->addRow(tr("&Base: "), this->baseSpinBox);
    formLayout->addRow(tr("&Subterhand: "), this->subterhandLineEdit);
    formLayout->addRow(tr("&Minuend: "), this->minuendLineEdit);
    formLayout->addRow(tr("&Result: "), this->resultLabel);

    QDialogButtonBox *buttonBox = 
        new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &SubtractDialog::compute);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &SubtractDialog::reject);

    QVBoxLayout *mainLayout = new QVBoxLayout();

    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(buttonBox);

    this->setLayout(mainLayout);
}

void SubtractDialog::compute() {
    unsigned int base = this->baseSpinBox->value();

    try {
        Number difference = Number(base, this->subterhandLineEdit->text().toStdString()) -
                            Number(base, this->minuendLineEdit->text().toStdString());

        this->resultLabel->setText(tr(difference.get_value().c_str()));
    } catch (const std::runtime_error& exception) {
        QMessageBox::critical(this, tr("Error"), tr(exception.what()));
    }
}
