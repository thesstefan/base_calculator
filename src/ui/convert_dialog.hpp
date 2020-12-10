#pragma once

#include <QDialog>

#include <QSpinBox>
#include <QLineEdit>
#include <QLabel>

class ConvertDialog : public QDialog {
    Q_OBJECT

    public:
        ConvertDialog(QWidget *parent);

    public slots:
        void compute();

    private:
        QSpinBox *srcBaseSpinBox;
        QSpinBox *dstBaseSpinBox;
        QLineEdit *numberLineEdit;
        QLabel *resultLabel;
        QLabel *conversionUsed;
};
