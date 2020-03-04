#pragma once

#include "CPU.h"
#include <FormatString.h>
#include <assert.h>
#include <Windows.h>
#include <functional>

#include <msclr\marshal_cppstd.h>

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
	private: System::Windows::Forms::Label^ lIntconValues;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ btnRA7;
	private: System::Windows::Forms::Button^ btnRA6;
	private: System::Windows::Forms::Button^ btnRA0;

	private: System::Windows::Forms::Button^ btnRA1;

	private: System::Windows::Forms::Button^ btnRA2;

	private: System::Windows::Forms::Button^ btnRA3;


	private: System::Windows::Forms::Button^ btnRA4;

	private: System::Windows::Forms::Button^ btnRA5;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::GroupBox^ groupBox3;
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
			this->gbIntcon = (gcnew System::Windows::Forms::GroupBox());
			this->lIntconValues = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->gbOption = (gcnew System::Windows::Forms::GroupBox());
			this->lOptionValues = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lpc = (gcnew System::Windows::Forms::Label());
			this->gbStatus = (gcnew System::Windows::Forms::GroupBox());
			this->lStatusValues = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->lpcl = (gcnew System::Windows::Forms::Label());
			this->lpcValue = (gcnew System::Windows::Forms::Label());
			this->lpclathValue = (gcnew System::Windows::Forms::Label());
			this->lpclath = (gcnew System::Windows::Forms::Label());
			this->lpclValue = (gcnew System::Windows::Forms::Label());
			this->lwRegValue = (gcnew System::Windows::Forms::Label());
			this->lwReg = (gcnew System::Windows::Forms::Label());
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
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnRA0 = (gcnew System::Windows::Forms::Button());
			this->btnRA1 = (gcnew System::Windows::Forms::Button());
			this->btnRA2 = (gcnew System::Windows::Forms::Button());
			this->btnRA3 = (gcnew System::Windows::Forms::Button());
			this->btnRA4 = (gcnew System::Windows::Forms::Button());
			this->btnRA5 = (gcnew System::Windows::Forms::Button());
			this->btnRA6 = (gcnew System::Windows::Forms::Button());
			this->btnRA7 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->gbFSR->SuspendLayout();
			this->gbIntcon->SuspendLayout();
			this->gbOption->SuspendLayout();
			this->gbStatus->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->groupBox3->SuspendLayout();
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
			this->gbFSR->ForeColor = System::Drawing::Color::White;
			this->gbFSR->Location = System::Drawing::Point(15, 12);
			this->gbFSR->Name = L"gbFSR";
			this->gbFSR->Size = System::Drawing::Size(283, 251);
			this->gbFSR->TabIndex = 0;
			this->gbFSR->TabStop = false;
			this->gbFSR->Text = L"Special Function Registers";
			// 
			// gbIntcon
			// 
			this->gbIntcon->Controls->Add(this->lIntconValues);
			this->gbIntcon->Controls->Add(this->label3);
			this->gbIntcon->ForeColor = System::Drawing::Color::White;
			this->gbIntcon->Location = System::Drawing::Point(15, 189);
			this->gbIntcon->Name = L"gbIntcon";
			this->gbIntcon->Size = System::Drawing::Size(253, 53);
			this->gbIntcon->TabIndex = 12;
			this->gbIntcon->TabStop = false;
			this->gbIntcon->Text = L"INTCON Register";
			// 
			// lIntconValues
			// 
			this->lIntconValues->AutoSize = true;
			this->lIntconValues->Location = System::Drawing::Point(6, 29);
			this->lIntconValues->Name = L"lIntconValues";
			this->lIntconValues->Size = System::Drawing::Size(223, 13);
			this->lIntconValues->TabIndex = 11;
			this->lIntconValues->Text = L"-    -    -    -    -    -    -    -";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 16);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(241, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"GIE  PIE  T0IE INTE RBIE T0IF INTF RBIF";
			// 
			// gbOption
			// 
			this->gbOption->Controls->Add(this->lOptionValues);
			this->gbOption->Controls->Add(this->label2);
			this->gbOption->ForeColor = System::Drawing::Color::White;
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
			this->lpc->ForeColor = System::Drawing::Color::White;
			this->lpc->Location = System::Drawing::Point(12, 16);
			this->lpc->Name = L"lpc";
			this->lpc->Size = System::Drawing::Size(19, 13);
			this->lpc->TabIndex = 0;
			this->lpc->Text = L"PC";
			// 
			// gbStatus
			// 
			this->gbStatus->Controls->Add(this->lStatusValues);
			this->gbStatus->Controls->Add(this->label17);
			this->gbStatus->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F));
			this->gbStatus->ForeColor = System::Drawing::Color::White;
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
			// lpcl
			// 
			this->lpcl->AutoSize = true;
			this->lpcl->ForeColor = System::Drawing::Color::White;
			this->lpcl->Location = System::Drawing::Point(12, 29);
			this->lpcl->Name = L"lpcl";
			this->lpcl->Size = System::Drawing::Size(25, 13);
			this->lpcl->TabIndex = 1;
			this->lpcl->Text = L"PCL";
			// 
			// lpcValue
			// 
			this->lpcValue->AutoSize = true;
			this->lpcValue->ForeColor = System::Drawing::Color::White;
			this->lpcValue->Location = System::Drawing::Point(90, 16);
			this->lpcValue->Name = L"lpcValue";
			this->lpcValue->Size = System::Drawing::Size(13, 13);
			this->lpcValue->TabIndex = 3;
			this->lpcValue->Text = L"-";
			// 
			// lpclathValue
			// 
			this->lpclathValue->AutoSize = true;
			this->lpclathValue->ForeColor = System::Drawing::Color::White;
			this->lpclathValue->Location = System::Drawing::Point(90, 42);
			this->lpclathValue->Name = L"lpclathValue";
			this->lpclathValue->Size = System::Drawing::Size(13, 13);
			this->lpclathValue->TabIndex = 5;
			this->lpclathValue->Text = L"-";
			// 
			// lpclath
			// 
			this->lpclath->AutoSize = true;
			this->lpclath->ForeColor = System::Drawing::Color::White;
			this->lpclath->Location = System::Drawing::Point(12, 42);
			this->lpclath->Name = L"lpclath";
			this->lpclath->Size = System::Drawing::Size(43, 13);
			this->lpclath->TabIndex = 2;
			this->lpclath->Text = L"PCLATH";
			// 
			// lpclValue
			// 
			this->lpclValue->AutoSize = true;
			this->lpclValue->ForeColor = System::Drawing::Color::White;
			this->lpclValue->Location = System::Drawing::Point(90, 29);
			this->lpclValue->Name = L"lpclValue";
			this->lpclValue->Size = System::Drawing::Size(13, 13);
			this->lpclValue->TabIndex = 4;
			this->lpclValue->Text = L"-";
			// 
			// lwRegValue
			// 
			this->lwRegValue->AutoSize = true;
			this->lwRegValue->ForeColor = System::Drawing::Color::White;
			this->lwRegValue->Location = System::Drawing::Point(90, 55);
			this->lwRegValue->Name = L"lwRegValue";
			this->lwRegValue->Size = System::Drawing::Size(13, 13);
			this->lwRegValue->TabIndex = 7;
			this->lwRegValue->Text = L"-";
			// 
			// lwReg
			// 
			this->lwReg->AutoSize = true;
			this->lwReg->ForeColor = System::Drawing::Color::White;
			this->lwReg->Location = System::Drawing::Point(12, 55);
			this->lwReg->Name = L"lwReg";
			this->lwReg->Size = System::Drawing::Size(13, 13);
			this->lwReg->TabIndex = 6;
			this->lwReg->Text = L"w";
			// 
			// btnStart
			// 
			this->btnStart->BackColor = System::Drawing::Color::Black;
			this->btnStart->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnStart->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F));
			this->btnStart->ForeColor = System::Drawing::Color::White;
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
			this->btnStop->ForeColor = System::Drawing::Color::White;
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
			this->btnStep->ForeColor = System::Drawing::Color::White;
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
			this->btnReset->ForeColor = System::Drawing::Color::White;
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
			this->updateTimer->Interval = 10;
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
			this->btnIgnore->ForeColor = System::Drawing::Color::White;
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
			this->groupBox1->ForeColor = System::Drawing::Color::White;
			this->groupBox1->Location = System::Drawing::Point(304, 269);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(594, 253);
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
			this->groupBox2->ForeColor = System::Drawing::Color::White;
			this->groupBox2->Location = System::Drawing::Point(904, 269);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(88, 253);
			this->groupBox2->TabIndex = 10;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Controls";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel1->ColumnCount = 9;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->Controls->Add(this->btnRA0, 8, 2);
			this->tableLayoutPanel1->Controls->Add(this->btnRA1, 7, 2);
			this->tableLayoutPanel1->Controls->Add(this->btnRA3, 5, 2);
			this->tableLayoutPanel1->Controls->Add(this->btnRA4, 4, 2);
			this->tableLayoutPanel1->Controls->Add(this->btnRA5, 3, 2);
			this->tableLayoutPanel1->Controls->Add(this->btnRA6, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->btnRA7, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->label4, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->label5, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->btnRA2, 6, 2);
			this->tableLayoutPanel1->Location = System::Drawing::Point(15, 19);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(253, 80);
			this->tableLayoutPanel1->TabIndex = 12;
			// 
			// btnRA0
			// 
			this->btnRA0->CausesValidation = false;
			this->btnRA0->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnRA0->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gray;
			this->btnRA0->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btnRA0->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRA0->ForeColor = System::Drawing::Color::White;
			this->btnRA0->Location = System::Drawing::Point(229, 56);
			this->btnRA0->Name = L"btnRA0";
			this->btnRA0->Size = System::Drawing::Size(18, 18);
			this->btnRA0->TabIndex = 15;
			this->btnRA0->Text = L"0";
			this->btnRA0->UseCompatibleTextRendering = true;
			this->btnRA0->UseMnemonic = false;
			this->btnRA0->UseVisualStyleBackColor = false;
			this->btnRA0->Click += gcnew System::EventHandler(this, &MainForm::btnRA0_Click);
			// 
			// btnRA1
			// 
			this->btnRA1->CausesValidation = false;
			this->btnRA1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnRA1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gray;
			this->btnRA1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btnRA1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRA1->ForeColor = System::Drawing::Color::White;
			this->btnRA1->Location = System::Drawing::Point(204, 56);
			this->btnRA1->Name = L"btnRA1";
			this->btnRA1->Size = System::Drawing::Size(18, 18);
			this->btnRA1->TabIndex = 17;
			this->btnRA1->Text = L"0";
			this->btnRA1->UseCompatibleTextRendering = true;
			this->btnRA1->UseMnemonic = false;
			this->btnRA1->UseVisualStyleBackColor = false;
			this->btnRA1->Click += gcnew System::EventHandler(this, &MainForm::btnRA1_Click);
			// 
			// btnRA2
			// 
			this->btnRA2->CausesValidation = false;
			this->btnRA2->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnRA2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gray;
			this->btnRA2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btnRA2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRA2->ForeColor = System::Drawing::Color::White;
			this->btnRA2->Location = System::Drawing::Point(179, 56);
			this->btnRA2->Name = L"btnRA2";
			this->btnRA2->Size = System::Drawing::Size(18, 18);
			this->btnRA2->TabIndex = 16;
			this->btnRA2->Text = L"0";
			this->btnRA2->UseCompatibleTextRendering = true;
			this->btnRA2->UseMnemonic = false;
			this->btnRA2->UseVisualStyleBackColor = false;
			this->btnRA2->Click += gcnew System::EventHandler(this, &MainForm::btnRA2_Click);
			// 
			// btnRA3
			// 
			this->btnRA3->CausesValidation = false;
			this->btnRA3->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnRA3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gray;
			this->btnRA3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btnRA3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRA3->ForeColor = System::Drawing::Color::White;
			this->btnRA3->Location = System::Drawing::Point(154, 56);
			this->btnRA3->Name = L"btnRA3";
			this->btnRA3->Size = System::Drawing::Size(18, 18);
			this->btnRA3->TabIndex = 19;
			this->btnRA3->Text = L"0";
			this->btnRA3->UseCompatibleTextRendering = true;
			this->btnRA3->UseMnemonic = false;
			this->btnRA3->UseVisualStyleBackColor = false;
			this->btnRA3->Click += gcnew System::EventHandler(this, &MainForm::btnRA3_Click);
			// 
			// btnRA4
			// 
			this->btnRA4->CausesValidation = false;
			this->btnRA4->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnRA4->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gray;
			this->btnRA4->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btnRA4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRA4->ForeColor = System::Drawing::Color::White;
			this->btnRA4->Location = System::Drawing::Point(129, 56);
			this->btnRA4->Name = L"btnRA4";
			this->btnRA4->Size = System::Drawing::Size(18, 18);
			this->btnRA4->TabIndex = 18;
			this->btnRA4->Text = L"0";
			this->btnRA4->UseCompatibleTextRendering = true;
			this->btnRA4->UseMnemonic = false;
			this->btnRA4->UseVisualStyleBackColor = false;
			this->btnRA4->Click += gcnew System::EventHandler(this, &MainForm::btnRA4_Click);
			// 
			// btnRA5
			// 
			this->btnRA5->CausesValidation = false;
			this->btnRA5->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnRA5->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gray;
			this->btnRA5->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btnRA5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRA5->ForeColor = System::Drawing::Color::White;
			this->btnRA5->Location = System::Drawing::Point(104, 56);
			this->btnRA5->Name = L"btnRA5";
			this->btnRA5->Size = System::Drawing::Size(18, 18);
			this->btnRA5->TabIndex = 20;
			this->btnRA5->Text = L"0";
			this->btnRA5->UseCompatibleTextRendering = true;
			this->btnRA5->UseMnemonic = false;
			this->btnRA5->UseVisualStyleBackColor = false;
			this->btnRA5->Click += gcnew System::EventHandler(this, &MainForm::btnRA5_Click);
			// 
			// btnRA6
			// 
			this->btnRA6->CausesValidation = false;
			this->btnRA6->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnRA6->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gray;
			this->btnRA6->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btnRA6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRA6->ForeColor = System::Drawing::Color::White;
			this->btnRA6->Location = System::Drawing::Point(79, 56);
			this->btnRA6->Name = L"btnRA6";
			this->btnRA6->Size = System::Drawing::Size(18, 18);
			this->btnRA6->TabIndex = 14;
			this->btnRA6->Text = L"0";
			this->btnRA6->UseCompatibleTextRendering = true;
			this->btnRA6->UseMnemonic = false;
			this->btnRA6->UseVisualStyleBackColor = false;
			this->btnRA6->Click += gcnew System::EventHandler(this, &MainForm::btnRA6_Click);
			// 
			// btnRA7
			// 
			this->btnRA7->CausesValidation = false;
			this->btnRA7->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnRA7->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gray;
			this->btnRA7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btnRA7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRA7->ForeColor = System::Drawing::Color::White;
			this->btnRA7->Location = System::Drawing::Point(54, 56);
			this->btnRA7->Name = L"btnRA7";
			this->btnRA7->Size = System::Drawing::Size(18, 18);
			this->btnRA7->TabIndex = 13;
			this->btnRA7->Text = L"0";
			this->btnRA7->UseCompatibleTextRendering = true;
			this->btnRA7->UseMnemonic = false;
			this->btnRA7->UseVisualStyleBackColor = false;
			this->btnRA7->Click += gcnew System::EventHandler(this, &MainForm::btnRA7_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(4, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(25, 13);
			this->label1->TabIndex = 21;
			this->label1->Text = L"Bit";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(4, 27);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 13);
			this->label4->TabIndex = 22;
			this->label4->Text = L"Tris A";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(4, 1);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(43, 13);
			this->label5->TabIndex = 23;
			this->label5->Text = L"Port A";
			// 
			// btnClose
			// 
			this->btnClose->BackColor = System::Drawing::Color::Red;
			this->btnClose->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btnClose->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnClose->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClose->Location = System::Drawing::Point(958, 0);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(47, 23);
			this->btnClose->TabIndex = 13;
			this->btnClose->Text = L"X";
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &MainForm::btnClose_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->tableLayoutPanel1);
			this->groupBox3->ForeColor = System::Drawing::Color::White;
			this->groupBox3->Location = System::Drawing::Point(15, 269);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(283, 253);
			this->groupBox3->TabIndex = 14;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Ports";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1003, 534);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->gbFSR);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F));
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MainForm";
			this->Text = L"PIC16F8X Simulator";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseUp);
			this->gbFSR->ResumeLayout(false);
			this->gbFSR->PerformLayout();
			this->gbIntcon->ResumeLayout(false);
			this->gbIntcon->PerformLayout();
			this->gbOption->ResumeLayout(false);
			this->gbOption->PerformLayout();
			this->gbStatus->ResumeLayout(false);
			this->gbStatus->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
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

			lStatusValues->Text = gcnew String(fmt::format("%d    %d    %d    %d    %d    %d    %d    %d"
				, cpuRef->registerData.getRawBit(0x3, 7)
				, cpuRef->registerData.getRawBit(0x3, 6)
				, cpuRef->registerData.getRawBit(0x3, 5)
				, cpuRef->registerData.getRawBit(0x3, 4)
				, cpuRef->registerData.getRawBit(0x3, 3)
				, cpuRef->registerData.getRawBit(0x3, 2)
				, cpuRef->registerData.getRawBit(0x3, 1)
				, cpuRef->registerData.getRawBit(0x3, 0)).c_str());

			lOptionValues->Text = gcnew String(fmt::format("%d    %d    %d    %d    %d    %d    %d    %d"
				, cpuRef->registerData.getRawBit(0x81, 7)
				, cpuRef->registerData.getRawBit(0x81, 6)
				, cpuRef->registerData.getRawBit(0x81, 5)
				, cpuRef->registerData.getRawBit(0x81, 4)
				, cpuRef->registerData.getRawBit(0x81, 3)
				, cpuRef->registerData.getRawBit(0x81, 2)
				, cpuRef->registerData.getRawBit(0x81, 1)
				, cpuRef->registerData.getRawBit(0x81, 0)).c_str());

			lIntconValues->Text = gcnew String(fmt::format("%d    %d    %d    %d    %d    %d    %d    %d"
				, cpuRef->registerData.getRawBit(0xB, 7)
				, cpuRef->registerData.getRawBit(0xB, 6)
				, cpuRef->registerData.getRawBit(0xB, 5)
				, cpuRef->registerData.getRawBit(0xB, 4)
				, cpuRef->registerData.getRawBit(0xB, 3)
				, cpuRef->registerData.getRawBit(0xB, 2)
				, cpuRef->registerData.getRawBit(0xB, 1)
				, cpuRef->registerData.getRawBit(0xB, 0)).c_str());


			btnRA7->Text = gcnew System::String(fmt::format("%d", cpuRef->registerData.getRawBit(0x5, 7)).c_str());
			btnRA6->Text = gcnew System::String(fmt::format("%d", cpuRef->registerData.getRawBit(0x5, 6)).c_str());
			btnRA5->Text = gcnew System::String(fmt::format("%d", cpuRef->registerData.getRawBit(0x5, 5)).c_str());
			btnRA4->Text = gcnew System::String(fmt::format("%d", cpuRef->registerData.getRawBit(0x5, 4)).c_str());
			btnRA3->Text = gcnew System::String(fmt::format("%d", cpuRef->registerData.getRawBit(0x5, 3)).c_str());
			btnRA2->Text = gcnew System::String(fmt::format("%d", cpuRef->registerData.getRawBit(0x5, 2)).c_str());
			btnRA1->Text = gcnew System::String(fmt::format("%d", cpuRef->registerData.getRawBit(0x5, 1)).c_str());
			btnRA0->Text = gcnew System::String(fmt::format("%d", cpuRef->registerData.getRawBit(0x5, 0)).c_str());

		}

		//------------------------------------------------------------------------------------------------------------------------------------------------

	private: bool dragging = false;
	private: Point dragCursorPoint;
	private: Point dragFormPoint;

	private: void MainForm_MouseDown(System::Object^ sender, MouseEventArgs^ e)
	{
		dragging = true;
		dragCursorPoint = Cursor->Position;
		dragFormPoint = this->Location;
	}

	private: void MainForm_MouseMove(System::Object^ sender, MouseEventArgs^ e)
	{
		if (dragging)
		{
			Point dif = Point::Subtract(Cursor->Position, System::Drawing::Size(dragCursorPoint));
			this->Location = Point::Add(dragFormPoint, System::Drawing::Size(dif));
		}
	}

	private: void MainForm_MouseUp(System::Object^ sender, MouseEventArgs^ e)
	{
		dragging = false;
	}

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
		assert(cpuRef != nullptr);
		cpuRef->registerData.setPC(0);
		cpuRef->registerData.resetPowerOn();
		cpuRef->cpuRegisters.w = 0;
		highlightConsoleLine(cpuRef->parser.getLstOpcodeInfo()[cpuRef->registerData.getPC()].lineInFile);
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
	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void btnRA7_Click(System::Object^ sender, System::EventArgs^ e) {
		cpuRef->registerData.setRawBit(0x5, 7, btnRA7->Text == "0");
	}
	private: System::Void btnRA6_Click(System::Object^ sender, System::EventArgs^ e) {
		cpuRef->registerData.setRawBit(0x5, 6, btnRA6->Text == "0");
	}
	private: System::Void btnRA5_Click(System::Object^ sender, System::EventArgs^ e) {
		cpuRef->registerData.setRawBit(0x5, 5, btnRA5->Text == "0");
	}
	private: System::Void btnRA4_Click(System::Object^ sender, System::EventArgs^ e) {
		cpuRef->registerData.setRawBit(0x5, 4, btnRA4->Text == "0");
	}
	private: System::Void btnRA3_Click(System::Object^ sender, System::EventArgs^ e) {
		cpuRef->registerData.setRawBit(0x5, 3, btnRA3->Text == "0");
	}
	private: System::Void btnRA2_Click(System::Object^ sender, System::EventArgs^ e) {
		cpuRef->registerData.setRawBit(0x5, 2, btnRA2->Text == "0");
	}
	private: System::Void btnRA1_Click(System::Object^ sender, System::EventArgs^ e) {
		cpuRef->registerData.setRawBit(0x5, 1, btnRA1->Text == "0");
	}
	private: System::Void btnRA0_Click(System::Object^ sender, System::EventArgs^ e) {
		cpuRef->registerData.setRawBit(0x5, 0, btnRA0->Text == "0");
	}
	};
}
