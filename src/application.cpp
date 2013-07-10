#include "application.h"
#include "globalselectionhandler.h"

#include <QMessageBox>

Application::Application(int argc, char *argv[]) :
    QxtApplication(argc, argv)
{
}

void Application::hotkeyPressed()
{
    //unfortunately, this does not always work (for example, doesn't work for Notepad or Skype)
    //QString selection =
    globalSelectionHandler::getGlobalMouseSelection();

    //so not preserving clipboard
    //QString selection = QApplication::clipboard()->text();

    //QMessageBox::information(0, "Quotations", selection);
}

void Application::copyExecuted()
{
    if (globalSelectionHandler::waiting)
    {
    QString selection = globalSelectionHandler::signalDelivered();

    QMessageBox::information(0, "Quotations", selection);
    }
}
