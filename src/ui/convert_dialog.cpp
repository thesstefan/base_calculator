#include "convert_dialog.hpp"

#include <QFormLayout>
#include <QVBoxLayout>
#include <QDialog>
#include <QDialogButtonBox>
#include <QMessageBox>

#include "../convert.hpp"

ConvertDialog::ConvertDialog(QWidget *parent) : 
    QDialog(parent) {
    this->srcBaseSpinBox = new QSpinBox(this);
    this->srcBaseSpinBox->setRange(2, 16);

    this->dstBaseSpinBox = new QSpinBox(this);
    this->dstBaseSpinBox->setRange(2, 16);

    this->numberLineEdit = new QLineEdit(this);

    this->resultLabel = new QLabel("");
    this->conversionUsed = new QLabel("None");

    QFormLayout *formLayout = new QFormLayout();

    formLayout->addRow(tr("&Source Base: "), this->srcBaseSpinBox);
    formLayout->addRow(tr("&Number: "), this->numberLineEdit);
    formLayout->addRow(tr("&Destination Base: "), this->dstBaseSpinBox);
    formLayout->addRow(tr("&Result: "), this->resultLabel);
    formLayout->addRow(tr("&Conversion used: "), this->conversionUsed);

    QDialogButtonBox *buttonBox = 
        new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &ConvertDialog::compute);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &ConvertDialog::reject);

    QVBoxLayout *mainLayout = new QVBoxLayout();

    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(buttonBox);

    this->setLayout(mainLayout);
}

void ConvertDialog::compute() {
    unsigned int srcBase = this->srcBaseSpinBox->value();
    unsigned int dstBase = this->dstBaseSpinBox->value();

    if (srcBase == dstBase)
        this->conversionUsed->setText("None");
    else if (is_power_of_two(srcBase) && is_power_of_two(dstBase))
        this->conversionUsed->setText("Fast Conversion");
    else if (srcBase < dstBase)
        this->conversionUsed->setText("Substitution Method");
    else if (srcBase > dstBase)
        this->conversionUsed->setText("Successive Division Method");

    try {
        Number srcNumber = Number(srcBase, this->numberLineEdit->text().toStdString());
        Number dstNumber = convert_base(dstBase, srcNumber);

        this->resultLabel->setText(tr(dstNumber.get_value().c_str()));
    } catch (const std::runtime_error& exception) {
        QMessageBox::critical(this, tr("Error"), tr(exception.what()));
    }
}
