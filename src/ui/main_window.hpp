#pragma once

#include <QtWidgets>

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow();

    private slots:
        void addClicked();
        void subtractClicked();
        void multiplyClicked();
        void divideClicked();
        void convertClicked();
};
