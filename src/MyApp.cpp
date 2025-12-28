#include "MyApp.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MainFrame* mainFrame = new MainFrame("Basic GUI App");
    mainFrame->SetClientSize(800, 600);
    mainFrame->Center();
    mainFrame->Show(true);
    return true;
}
