#include "application.h"
#include "globalselectionhandler.h"

#include <QMessageBox>
#include <QApplication>
#include <QClipboard>

Application::Application(int argc, char *argv[]) :
    QxtApplication(argc, argv)
{
}

void Application::hotkeyPressed()
{
    //unfortunately, this does not work
    //QString selection = globalSelectionHandler::getGlobalMouseSelection();

    //so not preserving clipboard
    QString selection = QApplication::clipboard()->text();

    QMessageBox::information(0, "Quotations", selection);
}
