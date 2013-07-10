#include "globalselectionhandler.h"
#include <QDebug>

#ifdef Q_WS_WIN

void globalSelectionHandler::winapiGenerateKey(int key, keyActionType actionType, bool extended)
{
    KEYBDINPUT kb;
    INPUT input;

    memset(&kb, 0, sizeof(kb));
    memset(&input, 0, sizeof(input));

    if (actionType == Up)
    {
        kb.dwFlags  =  KEYEVENTF_KEYUP | KEYEVENTF_SCANCODE;
        if (extended)
          kb.dwFlags |= KEYEVENTF_EXTENDEDKEY;
        kb.wVk = key;
        kb.wScan = MapVirtualKey(key, MAPVK_VK_TO_VSC);
        input.type  =  INPUT_KEYBOARD;
        input.tagINPUT::ki = kb;
        SendInput(1,&input,sizeof(input));
    }
    else
    {
        kb.dwFlags = KEYEVENTF_SCANCODE;
        if (extended)
          kb.dwFlags  = KEYEVENTF_EXTENDEDKEY;
        kb.wVk = key;
        kb.wScan = MapVirtualKey(key, MAPVK_VK_TO_VSC);
        input.type  = INPUT_KEYBOARD;
        input.tagINPUT::ki  = kb;
        SendInput(1,&input,sizeof(input));
    }
}
#endif

QString globalSelectionHandler::getGlobalMouseSelection()
{
    if (QApplication::clipboard()->supportsSelection())
    {
        return QApplication::clipboard()->text(QClipboard::Selection);
    }
    else
    {
        qDebug() << "No selection supported :(" << endl;
        //get the previous clipboard contents
        QString buf = QApplication::clipboard()->mimeData()->text();
        QApplication::clipboard()->clear();
        qDebug() << "copied from buffer: " << endl << buf << endl;

        //copy selected text to the clipboard
#ifdef Q_WS_WIN
        qDebug() << "emulate win ctrl+c" << endl;

        /*keybd_event(VK_CONTROL, MapVirtualKey(VK_CONTROL, MAPVK_VK_TO_VSC), 0, 0);
        Sleep(10);
        keybd_event(0x43, MapVirtualKey(0x43, MAPVK_VK_TO_VSC), 0, 0);
        Sleep(100);
        keybd_event(0x43, MapVirtualKey(0x43, MAPVK_VK_TO_VSC), KEYEVENTF_KEYUP, 0);
        Sleep(10);
        keybd_event(VK_CONTROL, MapVirtualKey(VK_CONTROL, MAPVK_VK_TO_VSC), KEYEVENTF_KEYUP, 0);
        Sleep(10)*/
        winapiGenerateKey(VK_CONTROL, Down);
        Sleep(10);
        winapiGenerateKey(0x43, Down);
        Sleep(100);
        winapiGenerateKey(0x43, Up);
        Sleep(10);
        winapiGenerateKey(VK_CONTROL, Up);
        Sleep(10);

#endif

        //get text from clipboard
        QString txt = QApplication::clipboard()->text();
        qDebug() << "got selection: " << endl << txt << endl;
        //retrieve previous clipboard content
        QApplication::clipboard()->setText(buf);
        qDebug() << "restoring buffer" << endl;
        return txt;
    }

    return QString();
}
