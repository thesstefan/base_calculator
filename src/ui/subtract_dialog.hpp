#pragma once

#include <QDialog>

#include <QSpinBox>
#include <QLineEdit>
#include <QLabel>

class SubtractDialog : public QDialog {
    Q_OBJECT

    public:
        SubtractDialog(QWidget *parent);

    public slots:
        void compute();

    private:
        QSpinBox *baseSpinBox;
        QLineEdit *subtrahendLineEdit;
        QLineEdit *minuendLineEdit;
        QLabel *resultLabel;
};
