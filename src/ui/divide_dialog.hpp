#pragma once

#include <QDialog>

#include <QSpinBox>
#include <QLineEdit>
#include <QLabel>

class DivideDialog : public QDialog {
    Q_OBJECT

    public:
        DivideDialog(QWidget *parent);

    public slots:
        void compute();

    private:
        QSpinBox *baseSpinBox;
        QLineEdit *dividendLineEdit;
        QLineEdit *divisorLineEdit;
        QLabel *resultLabel;
};
