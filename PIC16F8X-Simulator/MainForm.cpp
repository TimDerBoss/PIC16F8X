#include "MainForm.h"
#include "LSTParser.h"

#include <thread>
#include <Windows.h>


using namespace System;
using namespace System::IO;
using namespace System::Text;
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

	try {
		cpu.initialize("BCDCounter.lst");
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		PIC16F8X_Simulator::MainForm form;
		form.setCpu(&cpu);
		form.setProgram(cpu.parser.getFile());
		Application::Run(% form);
	}
	catch (std::exception & e) {
		MessageBoxA(GetActiveWindow(), fmt::format("%s", e.what()).c_str(), "CPU Error", MB_OK | MB_ICONERROR);
		exit(0);
	}
	catch(...)
	{
		exit(0);
	}

	return 0;
}