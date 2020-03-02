#include "MainForm.h"
#include "LogForm.h"
#include "LSTParser.h"

#include <thread>
#include <Windows.h>


using namespace System;
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
using namespace System::Security::Permissions;

[assembly:AssemblyTitleAttribute(L"PIC16F8X_Simulator")] ;
[assembly:AssemblyDescriptionAttribute(L"")] ;
[assembly:AssemblyConfigurationAttribute(L"")] ;
[assembly:AssemblyCompanyAttribute(L"")] ;
[assembly:AssemblyProductAttribute(L"PIC16F8X_Simulator")] ;
[assembly:AssemblyCopyrightAttribute(L"Copyright (c)  2020")] ;
[assembly:AssemblyTrademarkAttribute(L"")] ;
[assembly:AssemblyCultureAttribute(L"")] ;

[assembly:AssemblyVersionAttribute("1.0.*")] ;
[assembly:ComVisible(false)] ;
[assembly:CLSCompliantAttribute(true)] ;



using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	CPU cpu;


	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PIC16F8X_Simulator::MainForm form;

	try {
		cpu.initialize("BCDCounter.lst");
		form.setCpu(&cpu);
		form.setProgram(cpu.parser.getFile());

		Application::Run(% form);
	}
	catch (std::exception& e) {
		MessageBoxA(GetActiveWindow(), fmt::format("%s failed: %s", __FUNCTION__, e.what()).c_str(), "CPU Error", MB_OK | MB_ICONERROR);
	}
	return 0;
}