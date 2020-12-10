#pragma once

#include <QDialog>

#include <QSpinBox>
#include <QLineEdit>
#include <QLabel>

class MultiplyDialog : public QDialog {
    Q_OBJECT

    public:
        MultiplyDialog(QWidget *parent);

    public slots:
        void compute();

    private:
        QSpinBox *baseSpinBox;
        QLineEdit *firstFactorLineEdit;
        QLineEdit *secondFactorLineEdit;
        QLabel *resultLabel;
};
