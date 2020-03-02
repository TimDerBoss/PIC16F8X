#pragma once

#include "CPU.h"
#include "format.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ gbFSR;
	protected:
	private: System::Windows::Forms::Label^ lpclath;
	private: System::Windows::Forms::Label^ lpcl;
	private: System::Windows::Forms::Label^ lpc;
	private: System::Windows::Forms::Label^ lpclathValue;
	private: System::Windows::Forms::Label^ lpclValue;
	private: System::Windows::Forms::Label^ lpcValue;
	private: System::Windows::Forms::Button^ btnStart;
	private: System::Windows::Forms::Button^ btnStop;
	private: System::Windows::Forms::Button^ btnStep;
	private: System::Windows::Forms::Button^ btnReset;

	private: System::Windows::Forms::Label^ lProgram;
	private: System::Windows::Forms::Timer^ updateTimer;
	private: System::Windows::Forms::Label^ lwRegValue;
	private: System::Windows::Forms::Label^ lwReg;
	private: System::Windows::Forms::RichTextBox^ rtbprogramOutput;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->gbFSR = (gcnew System::Windows::Forms::GroupBox());
			this->lwRegValue = (gcnew System::Windows::Forms::Label());
			this->lwReg = (gcnew System::Windows::Forms::Label());
			this->lpclathValue = (gcnew System::Windows::Forms::Label());
			this->lpclValue = (gcnew System::Windows::Forms::Label());
			this->lpcValue = (gcnew System::Windows::Forms::Label());
			this->lpclath = (gcnew System::Windows::Forms::Label());
			this->lpcl = (gcnew System::Windows::Forms::Label());
			this->lpc = (gcnew System::Windows::Forms::Label());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->btnStop = (gcnew System::Windows::Forms::Button());
			this->btnStep = (gcnew System::Windows::Forms::Button());
			this->btnReset = (gcnew System::Windows::Forms::Button());
			this->lProgram = (gcnew System::Windows::Forms::Label());
			this->updateTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->rtbprogramOutput = (gcnew System::Windows::Forms::RichTextBox());
			this->gbFSR->SuspendLayout();
			this->SuspendLayout();
			// 
			// gbFSR
			// 
			this->gbFSR->Controls->Add(this->lwRegValue);
			this->gbFSR->Controls->Add(this->lwReg);
			this->gbFSR->Controls->Add(this->lpclathValue);
			this->gbFSR->Controls->Add(this->lpclValue);
			this->gbFSR->Controls->Add(this->lpcValue);
			this->gbFSR->Controls->Add(this->lpclath);
			this->gbFSR->Controls->Add(this->lpcl);
			this->gbFSR->Controls->Add(this->lpc);
			this->gbFSR->Location = System::Drawing::Point(12, 12);
			this->gbFSR->Name = L"gbFSR";
			this->gbFSR->Size = System::Drawing::Size(156, 183);
			this->gbFSR->TabIndex = 0;
			this->gbFSR->TabStop = false;
			this->gbFSR->Text = L"Special Function Registers";
			// 
			// lwRegValue
			// 
			this->lwRegValue->AutoSize = true;
			this->lwRegValue->Location = System::Drawing::Point(77, 86);
			this->lwRegValue->Name = L"lwRegValue";
			this->lwRegValue->Size = System::Drawing::Size(10, 13);
			this->lwRegValue->TabIndex = 7;
			this->lwRegValue->Text = L"-";
			// 
			// lwReg
			// 
			this->lwReg->AutoSize = true;
			this->lwReg->Location = System::Drawing::Point(7, 86);
			this->lwReg->Name = L"lwReg";
			this->lwReg->Size = System::Drawing::Size(15, 13);
			this->lwReg->TabIndex = 6;
			this->lwReg->Text = L"w";
			// 
			// lpclathValue
			// 
			this->lpclathValue->AutoSize = true;
			this->lpclathValue->Location = System::Drawing::Point(77, 64);
			this->lpclathValue->Name = L"lpclathValue";
			this->lpclathValue->Size = System::Drawing::Size(10, 13);
			this->lpclathValue->TabIndex = 5;
			this->lpclathValue->Text = L"-";
			// 
			// lpclValue
			// 
			this->lpclValue->AutoSize = true;
			this->lpclValue->Location = System::Drawing::Point(77, 42);
			this->lpclValue->Name = L"lpclValue";
			this->lpclValue->Size = System::Drawing::Size(10, 13);
			this->lpclValue->TabIndex = 4;
			this->lpclValue->Text = L"-";
			// 
			// lpcValue
			// 
			this->lpcValue->AutoSize = true;
			this->lpcValue->Location = System::Drawing::Point(77, 20);
			this->lpcValue->Name = L"lpcValue";
			this->lpcValue->Size = System::Drawing::Size(10, 13);
			this->lpcValue->TabIndex = 3;
			this->lpcValue->Text = L"-";
			// 
			// lpclath
			// 
			this->lpclath->AutoSize = true;
			this->lpclath->Location = System::Drawing::Point(7, 64);
			this->lpclath->Name = L"lpclath";
			this->lpclath->Size = System::Drawing::Size(49, 13);
			this->lpclath->TabIndex = 2;
			this->lpclath->Text = L"PCLATH";
			// 
			// lpcl
			// 
			this->lpcl->AutoSize = true;
			this->lpcl->Location = System::Drawing::Point(7, 42);
			this->lpcl->Name = L"lpcl";
			this->lpcl->Size = System::Drawing::Size(27, 13);
			this->lpcl->TabIndex = 1;
			this->lpcl->Text = L"PCL";
			// 
			// lpc
			// 
			this->lpc->AutoSize = true;
			this->lpc->Location = System::Drawing::Point(7, 20);
			this->lpc->Name = L"lpc";
			this->lpc->Size = System::Drawing::Size(21, 13);
			this->lpc->TabIndex = 0;
			this->lpc->Text = L"PC";
			// 
			// btnStart
			// 
			this->btnStart->Location = System::Drawing::Point(174, 22);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(75, 23);
			this->btnStart->TabIndex = 1;
			this->btnStart->Text = L"Start";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &Form1::btnStart_Click);
			// 
			// btnStop
			// 
			this->btnStop->Location = System::Drawing::Point(174, 51);
			this->btnStop->Name = L"btnStop";
			this->btnStop->Size = System::Drawing::Size(75, 23);
			this->btnStop->TabIndex = 2;
			this->btnStop->Text = L"Stop";
			this->btnStop->UseVisualStyleBackColor = true;
			this->btnStop->Click += gcnew System::EventHandler(this, &Form1::btnStop_Click);
			// 
			// btnStep
			// 
			this->btnStep->Location = System::Drawing::Point(174, 81);
			this->btnStep->Name = L"btnStep";
			this->btnStep->Size = System::Drawing::Size(75, 23);
			this->btnStep->TabIndex = 3;
			this->btnStep->Text = L"Single Step";
			this->btnStep->UseVisualStyleBackColor = true;
			this->btnStep->Click += gcnew System::EventHandler(this, &Form1::btnStep_Click);
			// 
			// btnReset
			// 
			this->btnReset->Location = System::Drawing::Point(174, 111);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(75, 23);
			this->btnReset->TabIndex = 4;
			this->btnReset->Text = L"Reset";
			this->btnReset->UseVisualStyleBackColor = true;
			// 
			// lProgram
			// 
			this->lProgram->AutoSize = true;
			this->lProgram->Location = System::Drawing::Point(12, 241);
			this->lProgram->Name = L"lProgram";
			this->lProgram->Size = System::Drawing::Size(46, 13);
			this->lProgram->TabIndex = 6;
			this->lProgram->Text = L"Program";
			// 
			// updateTimer
			// 
			this->updateTimer->Enabled = true;
			this->updateTimer->Tick += gcnew System::EventHandler(this, &Form1::updateTimer_Tick);
			// 
			// rtbprogramOutput
			// 
			this->rtbprogramOutput->Location = System::Drawing::Point(12, 257);
			this->rtbprogramOutput->Name = L"rtbprogramOutput";
			this->rtbprogramOutput->ReadOnly = true;
			this->rtbprogramOutput->Size = System::Drawing::Size(710, 181);
			this->rtbprogramOutput->TabIndex = 7;
			this->rtbprogramOutput->Text = L"";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(734, 450);
			this->Controls->Add(this->rtbprogramOutput);
			this->Controls->Add(this->lProgram);
			this->Controls->Add(this->btnReset);
			this->Controls->Add(this->btnStep);
			this->Controls->Add(this->btnStop);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->gbFSR);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->gbFSR->ResumeLayout(false);
			this->gbFSR->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		CPU* cpuRef = nullptr;
		void setCpu(CPU* cpu)
		{
			cpuRef = cpu;
		}

		void setProgram(const std::vector<std::string>& program)
		{
			for (auto& line : program) {
				rtbprogramOutput->Text += gcnew String(line.c_str()) + "\r\n";
			}
		}

		void highlightConsoleLine(int index, Color color)
		{
			rtbprogramOutput->SelectAll();
			rtbprogramOutput->SelectionBackColor = rtbprogramOutput->BackColor;
			if (index > rtbprogramOutput->Lines->Length)
				index = rtbprogramOutput->Lines->Length;
			auto start = rtbprogramOutput->GetFirstCharIndexFromLine(index);  // Get the 1st char index of the appended text
			auto length = rtbprogramOutput->Lines[index]->Length;
			rtbprogramOutput->Select(start, length);                 // Select from there to the end
			rtbprogramOutput->SelectionBackColor = color;
			rtbprogramOutput->SelectionStart = rtbprogramOutput->Find(rtbprogramOutput->Lines[index]);
			rtbprogramOutput->ScrollToCaret();
		}

		void updateUI()
		{
			if (cpuRef) {
				lpcValue->Text = gcnew String(fmt::format("%X", cpuRef->registerData.getPC()).c_str());
				lpclValue->Text = gcnew String(fmt::format("%X", cpuRef->registerData.getPC() & 0xFF).c_str());
				lpclathValue->Text = gcnew String(fmt::format("%X", cpuRef->registerData.getPC() >> 8 & 0xFF).c_str());
				lwRegValue->Text = gcnew String(fmt::format("%X", static_cast<uint16_t>(cpuRef->cpuRegisters.w)).c_str());
			}
		}
	private:
		System::Void updateTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
			updateUI();
		}
	private:
		System::Void btnStart_Click(System::Object^ sender, System::EventArgs^ e) {
			btnStart->Enabled = false;
			btnReset->Enabled = false;
			btnStop->Enabled = true;
			btnStep->Enabled = false;
		}
	private:
		System::Void btnStop_Click(System::Object^ sender, System::EventArgs^ e) {
			btnStart->Enabled = true;
			btnReset->Enabled = true;
			btnStop->Enabled = false;
			btnStep->Enabled = true;
		}
	private: System::Void btnStep_Click(System::Object^ sender, System::EventArgs^ e) {
		if (cpuRef) {
			cpuRef->singleStep();
			highlightConsoleLine(cpuRef->parser.getLstOpcodeInfo()[cpuRef->registerData.getPC()].lineInFile, System::Drawing::Color::OrangeRed);
		}
	}
	};
}
