#include "newfrmLogin.h"
#include "frmMain.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    AshesiMIS::newFrmLogin^ frmlogin = gcnew AshesiMIS::newFrmLogin();
    frmlogin->ShowDialog();
    User^ user = frmlogin->user;

    if (user != nullptr && user->id != 0) {
        AshesiMIS::frmMain^ frmmain = gcnew AshesiMIS::frmMain(user);
        Application::Run(frmmain);
    }
    else {
        MessageBox::Show("Authentication Canceled", "", MessageBoxButtons::OK);
    }
    return 0;
}