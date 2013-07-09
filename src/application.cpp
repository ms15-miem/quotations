#include "application.h"

#include <QMessageBox>

Application::Application(int argc, char *argv[]) :
    QxtApplication(argc, argv)
{
}

void Application::hotkeyPressed()
{
    QMessageBox::information(0, "Quotations", "void Application::hotkeyPressed()");
}
