#pragma once

#include "CPU.h"
#include <FormatString.h>
#include <assert.h>
#include <Windows.h>

namespace PIC16F8X_Simulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
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


	private: System::Windows::Forms::Timer^ updateTimer;
	private: System::Windows::Forms::Label^ lwRegValue;
	private: System::Windows::Forms::Label^ lwReg;
	private: System::Windows::Forms::RichTextBox^ rtbprogramOutput;




























































	private: System::Windows::Forms::GroupBox^ gbOption;

	private: System::Windows::Forms::GroupBox^ gbStatus;
	private: System::Windows::Forms::Button^ btnIgnore;
	private: System::Windows::Forms::Timer^ cpuRunTimer;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ lStatusValues;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lOptionValues;
private: System::Windows::Forms::GroupBox^ groupBox1;
private: System::Windows::Forms::GroupBox^ groupBox2;
private: System::Windows::Forms::GroupBox^ gbIntcon;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::Label^ label3;




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
			this->gbOption = (gcnew System::Windows::Forms::GroupBox());
			this->lOptionValues = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lpc = (gcnew System::Windows::Forms::Label());
			this->lpcl = (gcnew System::Windows::Forms::Label());
			this->gbStatus = (gcnew System::Windows::Forms::GroupBox());
			this->lStatusValues = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->lpclath = (gcnew System::Windows::Forms::Label());
			this->lwRegValue = (gcnew System::Windows::Forms::Label());
			this->lwReg = (gcnew System::Windows::Forms::Label());
			this->lpclValue = (gcnew System::Windows::Forms::Label());
			this->lpclathValue = (gcnew System::Windows::Forms::Label());
			this->lpcValue = (gcnew System::Windows::Forms::Label());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->btnStop = (gcnew System::Windows::Forms::Button());
			this->btnStep = (gcnew System::Windows::Forms::Button());
			this->btnReset = (gcnew System::Windows::Forms::Button());
			this->updateTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->rtbprogramOutput = (gcnew System::Windows::Forms::RichTextBox());
			this->btnIgnore = (gcnew System::Windows::Forms::Button());
			this->cpuRunTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->gbIntcon = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->gbFSR->SuspendLayout();
			this->gbOption->SuspendLayout();
			this->gbStatus->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->gbIntcon->SuspendLayout();
			this->SuspendLayout();
			// 
			// gbFSR
			// 
			this->gbFSR->Controls->Add(this->gbIntcon);
			this->gbFSR->Controls->Add(this->gbOption);
			this->gbFSR->Controls->Add(this->lpc);
			this->gbFSR->Controls->Add(this->gbStatus);
			this->gbFSR->Controls->Add(this->lpcl);
			this->gbFSR->Controls->Add(this->lpcValue);
			this->gbFSR->Controls->Add(this->lpclathValue);
			this->gbFSR->Controls->Add(this->lpclath);
			this->gbFSR->Controls->Add(this->lpclValue);
			this->gbFSR->Controls->Add(this->lwRegValue);
			this->gbFSR->Controls->Add(this->lwReg);
			this->gbFSR->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gbFSR->ForeColor = System::Drawing::SystemColors::Control;
			this->gbFSR->Location = System::Drawing::Point(15, 12);
			this->gbFSR->Name = L"gbFSR";
			this->gbFSR->Size = System::Drawing::Size(283, 251);
			this->gbFSR->TabIndex = 0;
			this->gbFSR->TabStop = false;
			this->gbFSR->Text = L"Special Function Registers";
			// 
			// gbOption
			// 
			this->gbOption->Controls->Add(this->lOptionValues);
			this->gbOption->Controls->Add(this->label2);
			this->gbOption->ForeColor = System::Drawing::SystemColors::Control;
			this->gbOption->Location = System::Drawing::Point(15, 130);
			this->gbOption->Name = L"gbOption";
			this->gbOption->Size = System::Drawing::Size(253, 53);
			this->gbOption->TabIndex = 9;
			this->gbOption->TabStop = false;
			this->gbOption->Text = L"Option Register";
			// 
			// lOptionValues
			// 
			this->lOptionValues->AutoSize = true;
			this->lOptionValues->Location = System::Drawing::Point(6, 29);
			this->lOptionValues->Name = L"lOptionValues";
			this->lOptionValues->Size = System::Drawing::Size(223, 13);
			this->lOptionValues->TabIndex = 11;
			this->lOptionValues->Text = L"-    -    -    -    -    -    -    -";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(235, 13);
			this->label2->TabIndex = 11;
			this->label2->Text = L"RBP  IEdg T0CS T0SE PS  PS2   PS1  PS0";
			// 
			// lpc
			// 
			this->lpc->AutoSize = true;
			this->lpc->Location = System::Drawing::Point(12, 16);
			this->lpc->Name = L"lpc";
			this->lpc->Size = System::Drawing::Size(19, 13);
			this->lpc->TabIndex = 0;
			this->lpc->Text = L"PC";
			// 
			// lpcl
			// 
			this->lpcl->AutoSize = true;
			this->lpcl->Location = System::Drawing::Point(12, 29);
			this->lpcl->Name = L"lpcl";
			this->lpcl->Size = System::Drawing::Size(25, 13);
			this->lpcl->TabIndex = 1;
			this->lpcl->Text = L"PCL";
			// 
			// gbStatus
			// 
			this->gbStatus->Controls->Add(this->lStatusValues);
			this->gbStatus->Controls->Add(this->label17);
			this->gbStatus->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F));
			this->gbStatus->ForeColor = System::Drawing::SystemColors::Control;
			this->gbStatus->Location = System::Drawing::Point(15, 71);
			this->gbStatus->Name = L"gbStatus";
			this->gbStatus->Size = System::Drawing::Size(253, 53);
			this->gbStatus->TabIndex = 10;
			this->gbStatus->TabStop = false;
			this->gbStatus->Text = L"Status Register";
			// 
			// lStatusValues
			// 
			this->lStatusValues->AutoSize = true;
			this->lStatusValues->Location = System::Drawing::Point(6, 30);
			this->lStatusValues->Name = L"lStatusValues";
			this->lStatusValues->Size = System::Drawing::Size(223, 13);
			this->lStatusValues->TabIndex = 10;
			this->lStatusValues->Text = L"-    -    -    -    -    -    -    -";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(6, 17);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(223, 13);
			this->label17->TabIndex = 9;
			this->label17->Text = L"IRP  RP1  RP0  TO   PD   Z    DC   C\r\n";
			// 
			// lpclath
			// 
			this->lpclath->AutoSize = true;
			this->lpclath->Location = System::Drawing::Point(12, 42);
			this->lpclath->Name = L"lpclath";
			this->lpclath->Size = System::Drawing::Size(43, 13);
			this->lpclath->TabIndex = 2;
			this->lpclath->Text = L"PCLATH";
			// 
			// lwRegValue
			// 
			this->lwRegValue->AutoSize = true;
			this->lwRegValue->Location = System::Drawing::Point(90, 55);
			this->lwRegValue->Name = L"lwRegValue";
			this->lwRegValue->Size = System::Drawing::Size(13, 13);
			this->lwRegValue->TabIndex = 7;
			this->lwRegValue->Text = L"-";
			// 
			// lwReg
			// 
			this->lwReg->AutoSize = true;
			this->lwReg->Location = System::Drawing::Point(12, 55);
			this->lwReg->Name = L"lwReg";
			this->lwReg->Size = System::Drawing::Size(13, 13);
			this->lwReg->TabIndex = 6;
			this->lwReg->Text = L"w";
			// 
			// lpclValue
			// 
			this->lpclValue->AutoSize = true;
			this->lpclValue->Location = System::Drawing::Point(90, 29);
			this->lpclValue->Name = L"lpclValue";
			this->lpclValue->Size = System::Drawing::Size(13, 13);
			this->lpclValue->TabIndex = 4;
			this->lpclValue->Text = L"-";
			// 
			// lpclathValue
			// 
			this->lpclathValue->AutoSize = true;
			this->lpclathValue->Location = System::Drawing::Point(90, 42);
			this->lpclathValue->Name = L"lpclathValue";
			this->lpclathValue->Size = System::Drawing::Size(13, 13);
			this->lpclathValue->TabIndex = 5;
			this->lpclathValue->Text = L"-";
			// 
			// lpcValue
			// 
			this->lpcValue->AutoSize = true;
			this->lpcValue->Location = System::Drawing::Point(90, 16);
			this->lpcValue->Name = L"lpcValue";
			this->lpcValue->Size = System::Drawing::Size(13, 13);
			this->lpcValue->TabIndex = 3;
			this->lpcValue->Text = L"-";
			// 
			// btnStart
			// 
			this->btnStart->BackColor = System::Drawing::Color::Black;
			this->btnStart->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnStart->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F));
			this->btnStart->ForeColor = System::Drawing::SystemColors::Control;
			this->btnStart->Location = System::Drawing::Point(6, 14);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(75, 23);
			this->btnStart->TabIndex = 1;
			this->btnStart->Text = L"Start";
			this->btnStart->UseVisualStyleBackColor = false;
			this->btnStart->Click += gcnew System::EventHandler(this, &MainForm::btnStart_Click);
			// 
			// btnStop
			// 
			this->btnStop->BackColor = System::Drawing::Color::Black;
			this->btnStop->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnStop->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F));
			this->btnStop->ForeColor = System::Drawing::SystemColors::Control;
			this->btnStop->Location = System::Drawing::Point(6, 43);
			this->btnStop->Name = L"btnStop";
			this->btnStop->Size = System::Drawing::Size(75, 23);
			this->btnStop->TabIndex = 2;
			this->btnStop->Text = L"Stop";
			this->btnStop->UseVisualStyleBackColor = false;
			this->btnStop->Click += gcnew System::EventHandler(this, &MainForm::btnStop_Click);
			// 
			// btnStep
			// 
			this->btnStep->BackColor = System::Drawing::Color::Black;
			this->btnStep->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnStep->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F));
			this->btnStep->ForeColor = System::Drawing::SystemColors::Control;
			this->btnStep->Location = System::Drawing::Point(6, 72);
			this->btnStep->Name = L"btnStep";
			this->btnStep->Size = System::Drawing::Size(75, 23);
			this->btnStep->TabIndex = 3;
			this->btnStep->Text = L"Single Step";
			this->btnStep->UseVisualStyleBackColor = false;
			this->btnStep->Click += gcnew System::EventHandler(this, &MainForm::btnStep_Click);
			// 
			// btnReset
			// 
			this->btnReset->BackColor = System::Drawing::Color::Black;
			this->btnReset->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnReset->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F));
			this->btnReset->ForeColor = System::Drawing::SystemColors::Control;
			this->btnReset->Location = System::Drawing::Point(6, 130);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(75, 23);
			this->btnReset->TabIndex = 4;
			this->btnReset->Text = L"Reset";
			this->btnReset->UseVisualStyleBackColor = false;
			this->btnReset->Click += gcnew System::EventHandler(this, &MainForm::btnReset_Click);
			// 
			// updateTimer
			// 
			this->updateTimer->Enabled = true;
			this->updateTimer->Tick += gcnew System::EventHandler(this, &MainForm::updateTimer_Tick);
			// 
			// rtbprogramOutput
			// 
			this->rtbprogramOutput->BackColor = System::Drawing::Color::Black;
			this->rtbprogramOutput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->rtbprogramOutput->Font = (gcnew System::Drawing::Font(L"Consolas", 8.5F));
			this->rtbprogramOutput->ForeColor = System::Drawing::Color::White;
			this->rtbprogramOutput->Location = System::Drawing::Point(6, 19);
			this->rtbprogramOutput->Name = L"rtbprogramOutput";
			this->rtbprogramOutput->ReadOnly = true;
			this->rtbprogramOutput->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::None;
			this->rtbprogramOutput->Size = System::Drawing::Size(582, 230);
			this->rtbprogramOutput->TabIndex = 7;
			this->rtbprogramOutput->Text = L"";
			// 
			// btnIgnore
			// 
			this->btnIgnore->BackColor = System::Drawing::Color::Black;
			this->btnIgnore->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnIgnore->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F));
			this->btnIgnore->ForeColor = System::Drawing::SystemColors::Control;
			this->btnIgnore->Location = System::Drawing::Point(6, 101);
			this->btnIgnore->Name = L"btnIgnore";
			this->btnIgnore->Size = System::Drawing::Size(75, 23);
			this->btnIgnore->TabIndex = 8;
			this->btnIgnore->Text = L"Ignore";
			this->btnIgnore->UseVisualStyleBackColor = false;
			this->btnIgnore->Click += gcnew System::EventHandler(this, &MainForm::btnIgnore_Click);
			// 
			// cpuRunTimer
			// 
			this->cpuRunTimer->Tick += gcnew System::EventHandler(this, &MainForm::cpuRunTimer_Tick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->rtbprogramOutput);
			this->groupBox1->ForeColor = System::Drawing::SystemColors::Control;
			this->groupBox1->Location = System::Drawing::Point(109, 269);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(594, 255);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Program";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->btnStart);
			this->groupBox2->Controls->Add(this->btnStep);
			this->groupBox2->Controls->Add(this->btnIgnore);
			this->groupBox2->Controls->Add(this->btnStop);
			this->groupBox2->Controls->Add(this->btnReset);
			this->groupBox2->ForeColor = System::Drawing::SystemColors::Control;
			this->groupBox2->Location = System::Drawing::Point(15, 269);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(88, 255);
			this->groupBox2->TabIndex = 10;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Controls";
			// 
			// gbIntcon
			// 
			this->gbIntcon->Controls->Add(this->label1);
			this->gbIntcon->Controls->Add(this->label3);
			this->gbIntcon->ForeColor = System::Drawing::SystemColors::Control;
			this->gbIntcon->Location = System::Drawing::Point(15, 189);
			this->gbIntcon->Name = L"gbIntcon";
			this->gbIntcon->Size = System::Drawing::Size(253, 53);
			this->gbIntcon->TabIndex = 12;
			this->gbIntcon->TabStop = false;
			this->gbIntcon->Text = L"Interrupt Register";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(223, 13);
			this->label1->TabIndex = 11;
			this->label1->Text = L"-    -    -    -    -    -    -    -";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 16);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(235, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"RBP  IEdg T0CS T0SE PS  PS2   PS1  PS0";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(719, 534);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->gbFSR);
			this->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F));
			this->ForeColor = System::Drawing::SystemColors::Control;
			this->Name = L"MainForm";
			this->Text = L"PIC16F8X Simulator";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->gbFSR->ResumeLayout(false);
			this->gbFSR->PerformLayout();
			this->gbOption->ResumeLayout(false);
			this->gbOption->PerformLayout();
			this->gbStatus->ResumeLayout(false);
			this->gbStatus->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->gbIntcon->ResumeLayout(false);
			this->gbIntcon->PerformLayout();
			this->ResumeLayout(false);

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
			rtbprogramOutput->Text = "";
			for (auto& line : program) {
				rtbprogramOutput->Text += gcnew String(line.c_str()) + "\r\n";
			}
		}

		void highlightConsoleLine(int index)
		{
			rtbprogramOutput->SelectAll();
			rtbprogramOutput->SelectionBackColor = rtbprogramOutput->BackColor;
			rtbprogramOutput->SelectionColor = rtbprogramOutput->ForeColor;
			if (index > rtbprogramOutput->Lines->Length)
				index = rtbprogramOutput->Lines->Length;
			auto start = rtbprogramOutput->GetFirstCharIndexFromLine(index);  // Get the 1st char index of the appended text
			auto length = rtbprogramOutput->Lines[index]->Length;
			rtbprogramOutput->Select(start, length);                 // Select from there to the end
			rtbprogramOutput->SelectionBackColor = Color::White;
			rtbprogramOutput->SelectionColor = Color::Black;
			start = rtbprogramOutput->GetFirstCharIndexFromLine((index - 10) ? index - 10 : 0);  // Get the 1st char index of the appended text
			rtbprogramOutput->Select(start, 0);
			rtbprogramOutput->ScrollToCaret();
		}

		void updateUI()
		{
			lpcValue->Text = gcnew String(fmt::format("%04X", cpuRef->registerData.getPC()).c_str());
			lpclValue->Text = gcnew String(fmt::format("%02X", cpuRef->registerData.getPC() & 0xFF).c_str());
			lpclathValue->Text = gcnew String(fmt::format("%02X", cpuRef->registerData.getPC() >> 8 & 0xFF).c_str());
			lwRegValue->Text = gcnew String(fmt::format("%02X", cpuRef->cpuRegisters.w).c_str());

			gbStatus->Text = gcnew String(fmt::format("Status Register - %02X", cpuRef->registerData.readData(0x3)).c_str());
			lStatusValues->Text = gcnew String(fmt::format("%d    %d    %d    %d    %d    %d    %d    %d"
				, cpuRef->registerData.getBit(0x3, 7)
				, cpuRef->registerData.getBit(0x3, 6)
				, cpuRef->registerData.getBit(0x3, 5)
				, cpuRef->registerData.getBit(0x3, 4)
				, cpuRef->registerData.getBit(0x3, 3)
				, cpuRef->registerData.getBit(0x3, 2)
				, cpuRef->registerData.getBit(0x3, 1)
				, cpuRef->registerData.getBit(0x3, 0)).c_str());

			gbOption->Text = gcnew String(fmt::format("Option Register - %02X", cpuRef->registerData.readData(0xB)).c_str());
			lOptionValues->Text = gcnew String(fmt::format("%d    %d    %d    %d    %d    %d    %d    %d"
				, cpuRef->registerData.getBit(0xB, 7)
				, cpuRef->registerData.getBit(0xB, 6)
				, cpuRef->registerData.getBit(0xB, 5)
				, cpuRef->registerData.getBit(0xB, 4)
				, cpuRef->registerData.getBit(0xB, 3)
				, cpuRef->registerData.getBit(0xB, 2)
				, cpuRef->registerData.getBit(0xB, 1)
				, cpuRef->registerData.getBit(0xB, 0)).c_str());

		}

		//------------------------------------------------------------------------------------------------------------------------------------------------
	private: System::Void updateTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		assert(cpuRef != nullptr);
		updateUI();
	}

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		btnStart->Enabled = true;
		btnReset->Enabled = true;
		btnStop->Enabled = false;
		btnStep->Enabled = true;
		btnIgnore->Enabled = true;
	}

	private: System::Void btnStart_Click(System::Object^ sender, System::EventArgs^ e) {
		btnStart->Enabled = false;
		btnReset->Enabled = false;
		btnStop->Enabled = true;
		btnStep->Enabled = false;
		btnIgnore->Enabled = false;

		cpuRunTimer->Start();
	}

	private: System::Void btnStop_Click(System::Object^ sender, System::EventArgs^ e) {
		btnStart->Enabled = true;
		btnReset->Enabled = true;
		btnStop->Enabled = false;
		btnStep->Enabled = true;
		btnIgnore->Enabled = true;

		cpuRunTimer->Stop();
	}

	private: System::Void btnStep_Click(System::Object^ sender, System::EventArgs^ e) {
		assert(cpuRef != nullptr);
		cpuRef->singleStep();
		highlightConsoleLine(cpuRef->parser.getLstOpcodeInfo()[cpuRef->registerData.getPC()].lineInFile);

	}
	private: System::Void btnReset_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void btnIgnore_Click(System::Object^ sender, System::EventArgs^ e) {
		assert(cpuRef != nullptr);
		cpuRef->registerData.increasePCBy(1);
		highlightConsoleLine(cpuRef->parser.getLstOpcodeInfo()[cpuRef->registerData.getPC()].lineInFile);

	}
	private: System::Void cpuRunTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		assert(cpuRef != nullptr);
		try {
			cpuRef->singleStep();
			highlightConsoleLine(cpuRef->parser.getLstOpcodeInfo()[cpuRef->registerData.getPC()].lineInFile);
		}
		catch (std::exception & e) {
			cpuRunTimer->Stop();
			MessageBoxA(GetActiveWindow(), fmt::format("Simulation Error!\n\n%s", e.what()).c_str(), "CPU Error", MB_OK | MB_ICONERROR);
		}
	}
	};
}
