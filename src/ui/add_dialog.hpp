#pragma once

#include <QDialog>

#include <QSpinBox>
#include <QLineEdit>
#include <QLabel>

class AddDialog : public QDialog {
    Q_OBJECT

    public:
        AddDialog(QWidget *parent);

    public slots:
        void compute();

    private:
        QSpinBox *baseSpinBox;
        QLineEdit *firstTermLineEdit;
        QLineEdit *secondTermLineEdit;
        QLabel *resultLabel;
};
