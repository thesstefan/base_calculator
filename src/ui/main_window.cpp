#include <QVBoxLayout>
#include <QPushButton>

#include "main_window.hpp"

#include "add_dialog.hpp"
#include "subtract_dialog.hpp"
#include "multiply_dialog.hpp"
#include "divide_dialog.hpp"
#include "convert_dialog.hpp"

MainWindow::MainWindow() {
    QWidget *centralWidget = new QWidget(this);

    QVBoxLayout *layout = new QVBoxLayout();

    QPushButton *addButton = new QPushButton("Add");
    QObject::connect(addButton, &QPushButton::clicked,
                     this, &MainWindow::addClicked);

    QPushButton *subtractButton = new QPushButton("Subtract");
    QObject::connect(subtractButton, &QPushButton::clicked,
                     this, &MainWindow::subtractClicked);

    QPushButton *multiplyButton = new QPushButton("Multiply");
    QObject::connect(multiplyButton, &QPushButton::clicked,
                     this, &MainWindow::multiplyClicked);

    QPushButton *divideButton = new QPushButton("Divide");
    QObject::connect(divideButton, &QPushButton::clicked,
                     this, &MainWindow::divideClicked);

    QPushButton *convertButton = new QPushButton("Convert");
    QObject::connect(convertButton, &QPushButton::clicked,
                     this, &MainWindow::convertClicked);

    QLabel *authorLabel = new QLabel("Author: Stefan Stefanache (916/2)");

    layout->addWidget(addButton);
    layout->addWidget(subtractButton);
    layout->addWidget(multiplyButton);
    layout->addWidget(divideButton);
    layout->addWidget(convertButton);
    layout->addWidget(authorLabel);

    centralWidget->setLayout(layout);

    this->setCentralWidget(centralWidget);
}

void MainWindow::addClicked() {
    AddDialog *dialog = new AddDialog(this);

    dialog->show();
}

void MainWindow::subtractClicked() {
    SubtractDialog *dialog = new SubtractDialog(this);

    dialog->show();
}

void MainWindow::multiplyClicked() {
    MultiplyDialog *dialog = new MultiplyDialog(this);

    dialog->show();
}

void MainWindow::divideClicked() {
    DivideDialog *dialog = new DivideDialog(this);

    dialog->show();
}

void MainWindow::convertClicked() {
    ConvertDialog *dialog = new ConvertDialog(this);

    dialog->show();
}
