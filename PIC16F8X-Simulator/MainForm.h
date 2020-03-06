#pragma once

#include "CPU.h"
#include "RegisterData.h"
#include <FormatString.h>
#include <assert.h>
#include <Windows.h>
#include <functional>

#include <msclr\marshal_cppstd.h>

#undef max

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
















	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lTrisA;

	private: System::Windows::Forms::Label^ lPortA;


	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::NumericUpDown^ nudSimSpeed;
	private: System::Windows::Forms::Label^ lRuntime;

	private: System::Windows::Forms::Label^ btnRA0;

	private: System::Windows::Forms::Label^ btnRA1;

	private: System::Windows::Forms::Label^ btnRA2;

	private: System::Windows::Forms::Label^ btnRA3;

	private: System::Windows::Forms::Label^ btnRA4;
	private: System::Windows::Forms::Label^ btnRA5;
	private: System::Windows::Forms::Label^ btnRA6;
	private: System::Windows::Forms::Label^ btnRA7;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ btnRB0;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ btnRB1;
	private: System::Windows::Forms::Label^ lTrisB;
	private: System::Windows::Forms::Label^ btnRB2;
	private: System::Windows::Forms::Label^ btnRB7;
	private: System::Windows::Forms::Label^ btnRB3;

	private: System::Windows::Forms::Label^ btnRB6;
	private: System::Windows::Forms::Label^ btnRB4;

	private: System::Windows::Forms::Label^ btnRB5;
	private: System::Windows::Forms::Button^ btnRuntimeReset;
	private: System::Windows::Forms::GroupBox^ groupBox6;
	private: System::Windows::Forms::GroupBox^ groupBox7;



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
			this->btnRuntimeReset = (gcnew System::Windows::Forms::Button());
			this->lRuntime = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->nudSimSpeed = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lTrisA = (gcnew System::Windows::Forms::Label());
			this->lPortA = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnRB0 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->btnRB1 = (gcnew System::Windows::Forms::Label());
			this->lTrisB = (gcnew System::Windows::Forms::Label());
			this->btnRB2 = (gcnew System::Windows::Forms::Label());
			this->btnRB7 = (gcnew System::Windows::Forms::Label());
			this->btnRB3 = (gcnew System::Windows::Forms::Label());
			this->btnRB6 = (gcnew System::Windows::Forms::Label());
			this->btnRB4 = (gcnew System::Windows::Forms::Label());
			this->btnRB5 = (gcnew System::Windows::Forms::Label());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->btnRA0 = (gcnew System::Windows::Forms::Label());
			this->btnRA1 = (gcnew System::Windows::Forms::Label());
			this->btnRA2 = (gcnew System::Windows::Forms::Label());
			this->btnRA7 = (gcnew System::Windows::Forms::Label());
			this->btnRA3 = (gcnew System::Windows::Forms::Label());
			this->btnRA6 = (gcnew System::Windows::Forms::Label());
			this->btnRA4 = (gcnew System::Windows::Forms::Label());
			this->btnRA5 = (gcnew System::Windows::Forms::Label());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->gbFSR->SuspendLayout();
			this->gbIntcon->SuspendLayout();
			this->gbOption->SuspendLayout();
			this->gbStatus->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudSimSpeed))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox7->SuspendLayout();
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
			this->lIntconValues->Size = System::Drawing::Size(0, 13);
			this->lIntconValues->TabIndex = 11;
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
			this->lOptionValues->Size = System::Drawing::Size(0, 13);
			this->lOptionValues->TabIndex = 11;
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
			this->lStatusValues->Size = System::Drawing::Size(0, 13);
			this->lStatusValues->TabIndex = 10;
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
			this->btnStep->Text = L"Step";
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
			this->updateTimer->Interval = 20;
			this->updateTimer->Tick += gcnew System::EventHandler(this, &MainForm::updateTimer_Tick);
			// 
			// rtbprogramOutput
			// 
			this->rtbprogramOutput->BackColor = System::Drawing::Color::Black;
			this->rtbprogramOutput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->rtbprogramOutput->DetectUrls = false;
			this->rtbprogramOutput->Font = (gcnew System::Drawing::Font(L"Consolas", 8.5F));
			this->rtbprogramOutput->ForeColor = System::Drawing::Color::White;
			this->rtbprogramOutput->Location = System::Drawing::Point(6, 14);
			this->rtbprogramOutput->Name = L"rtbprogramOutput";
			this->rtbprogramOutput->ReadOnly = true;
			this->rtbprogramOutput->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::None;
			this->rtbprogramOutput->Size = System::Drawing::Size(582, 285);
			this->rtbprogramOutput->TabIndex = 7;
			this->rtbprogramOutput->TabStop = false;
			this->rtbprogramOutput->Text = L"";
			this->rtbprogramOutput->WordWrap = false;
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
			this->cpuRunTimer->Interval = 10;
			this->cpuRunTimer->Tick += gcnew System::EventHandler(this, &MainForm::cpuRunTimer_Tick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->rtbprogramOutput);
			this->groupBox1->ForeColor = System::Drawing::Color::White;
			this->groupBox1->Location = System::Drawing::Point(15, 271);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(594, 305);
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
			this->groupBox2->Location = System::Drawing::Point(615, 271);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(88, 161);
			this->groupBox2->TabIndex = 10;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Controls";
			// 
			// btnRuntimeReset
			// 
			this->btnRuntimeReset->BackColor = System::Drawing::Color::Black;
			this->btnRuntimeReset->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRuntimeReset->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F));
			this->btnRuntimeReset->ForeColor = System::Drawing::Color::White;
			this->btnRuntimeReset->Location = System::Drawing::Point(6, 32);
			this->btnRuntimeReset->Name = L"btnRuntimeReset";
			this->btnRuntimeReset->Size = System::Drawing::Size(75, 23);
			this->btnRuntimeReset->TabIndex = 19;
			this->btnRuntimeReset->Text = L"Reset";
			this->btnRuntimeReset->UseVisualStyleBackColor = false;
			this->btnRuntimeReset->Click += gcnew System::EventHandler(this, &MainForm::btnRuntimeReset_Click);
			// 
			// lRuntime
			// 
			this->lRuntime->AutoSize = true;
			this->lRuntime->Location = System::Drawing::Point(3, 16);
			this->lRuntime->Name = L"lRuntime";
			this->lRuntime->Size = System::Drawing::Size(31, 13);
			this->lRuntime->TabIndex = 18;
			this->lRuntime->Text = L"0 us";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 16);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(67, 13);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Speed (Hz)";
			// 
			// nudSimSpeed
			// 
			this->nudSimSpeed->BackColor = System::Drawing::Color::Black;
			this->nudSimSpeed->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->nudSimSpeed->ForeColor = System::Drawing::Color::White;
			this->nudSimSpeed->Location = System::Drawing::Point(6, 32);
			this->nudSimSpeed->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->nudSimSpeed->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nudSimSpeed->Name = L"nudSimSpeed";
			this->nudSimSpeed->Size = System::Drawing::Size(75, 20);
			this->nudSimSpeed->TabIndex = 15;
			this->nudSimSpeed->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->nudSimSpeed->ValueChanged += gcnew System::EventHandler(this, &MainForm::nudSimSpeed_onValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 21;
			this->label1->Text = L"Port A |";
			// 
			// lTrisA
			// 
			this->lTrisA->AutoSize = true;
			this->lTrisA->Location = System::Drawing::Point(6, 23);
			this->lTrisA->Name = L"lTrisA";
			this->lTrisA->Size = System::Drawing::Size(55, 13);
			this->lTrisA->TabIndex = 22;
			this->lTrisA->Text = L"Tris A |";
			// 
			// lPortA
			// 
			this->lPortA->AutoSize = true;
			this->lPortA->Location = System::Drawing::Point(6, 10);
			this->lPortA->Name = L"lPortA";
			this->lPortA->Size = System::Drawing::Size(199, 13);
			this->lPortA->TabIndex = 23;
			this->lPortA->Text = L"Bits   |  7  6  5  4  3  2  1  0";
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
			this->btnClose->Location = System::Drawing::Point(674, -2);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(47, 23);
			this->btnClose->TabIndex = 13;
			this->btnClose->Text = L"X";
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &MainForm::btnClose_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->groupBox5);
			this->groupBox3->Controls->Add(this->groupBox4);
			this->groupBox3->ForeColor = System::Drawing::Color::White;
			this->groupBox3->Location = System::Drawing::Point(310, 12);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(245, 251);
			this->groupBox3->TabIndex = 14;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Ports";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->label4);
			this->groupBox5->Controls->Add(this->btnRB0);
			this->groupBox5->Controls->Add(this->label8);
			this->groupBox5->Controls->Add(this->btnRB1);
			this->groupBox5->Controls->Add(this->lTrisB);
			this->groupBox5->Controls->Add(this->btnRB2);
			this->groupBox5->Controls->Add(this->btnRB7);
			this->groupBox5->Controls->Add(this->btnRB3);
			this->groupBox5->Controls->Add(this->btnRB6);
			this->groupBox5->Controls->Add(this->btnRB4);
			this->groupBox5->Controls->Add(this->btnRB5);
			this->groupBox5->Location = System::Drawing::Point(15, 69);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(214, 55);
			this->groupBox5->TabIndex = 33;
			this->groupBox5->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 10);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(199, 13);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Bits   |  7  6  5  4  3  2  1  0";
			// 
			// btnRB0
			// 
			this->btnRB0->AutoSize = true;
			this->btnRB0->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->btnRB0->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRB0->Location = System::Drawing::Point(192, 36);
			this->btnRB0->Name = L"btnRB0";
			this->btnRB0->Size = System::Drawing::Size(15, 15);
			this->btnRB0->TabIndex = 31;
			this->btnRB0->Text = L"0";
			this->btnRB0->Click += gcnew System::EventHandler(this, &MainForm::btnRB0_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 36);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(55, 13);
			this->label8->TabIndex = 21;
			this->label8->Text = L"Port B |";
			// 
			// btnRB1
			// 
			this->btnRB1->AutoSize = true;
			this->btnRB1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->btnRB1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRB1->Location = System::Drawing::Point(174, 36);
			this->btnRB1->Name = L"btnRB1";
			this->btnRB1->Size = System::Drawing::Size(15, 15);
			this->btnRB1->TabIndex = 30;
			this->btnRB1->Text = L"0";
			this->btnRB1->Click += gcnew System::EventHandler(this, &MainForm::btnRB1_Click);
			// 
			// lTrisB
			// 
			this->lTrisB->AutoSize = true;
			this->lTrisB->Location = System::Drawing::Point(6, 23);
			this->lTrisB->Name = L"lTrisB";
			this->lTrisB->Size = System::Drawing::Size(55, 13);
			this->lTrisB->TabIndex = 22;
			this->lTrisB->Text = L"Tris B |";
			// 
			// btnRB2
			// 
			this->btnRB2->AutoSize = true;
			this->btnRB2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->btnRB2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRB2->Location = System::Drawing::Point(156, 36);
			this->btnRB2->Name = L"btnRB2";
			this->btnRB2->Size = System::Drawing::Size(15, 15);
			this->btnRB2->TabIndex = 29;
			this->btnRB2->Text = L"0";
			this->btnRB2->Click += gcnew System::EventHandler(this, &MainForm::btnRB2_Click);
			// 
			// btnRB7
			// 
			this->btnRB7->AutoSize = true;
			this->btnRB7->BackColor = System::Drawing::Color::Black;
			this->btnRB7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->btnRB7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRB7->Location = System::Drawing::Point(66, 36);
			this->btnRB7->Name = L"btnRB7";
			this->btnRB7->Size = System::Drawing::Size(15, 15);
			this->btnRB7->TabIndex = 24;
			this->btnRB7->Text = L"0";
			this->btnRB7->Click += gcnew System::EventHandler(this, &MainForm::btnRB7_Click);
			// 
			// btnRB3
			// 
			this->btnRB3->AutoSize = true;
			this->btnRB3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->btnRB3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRB3->Location = System::Drawing::Point(138, 36);
			this->btnRB3->Name = L"btnRB3";
			this->btnRB3->Size = System::Drawing::Size(15, 15);
			this->btnRB3->TabIndex = 28;
			this->btnRB3->Text = L"0";
			this->btnRB3->Click += gcnew System::EventHandler(this, &MainForm::btnRB3_Click);
			// 
			// btnRB6
			// 
			this->btnRB6->AutoSize = true;
			this->btnRB6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->btnRB6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRB6->Location = System::Drawing::Point(84, 36);
			this->btnRB6->Name = L"btnRB6";
			this->btnRB6->Size = System::Drawing::Size(15, 15);
			this->btnRB6->TabIndex = 25;
			this->btnRB6->Text = L"0";
			this->btnRB6->Click += gcnew System::EventHandler(this, &MainForm::btnRB6_Click);
			// 
			// btnRB4
			// 
			this->btnRB4->AutoSize = true;
			this->btnRB4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->btnRB4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRB4->Location = System::Drawing::Point(120, 36);
			this->btnRB4->Name = L"btnRB4";
			this->btnRB4->Size = System::Drawing::Size(15, 15);
			this->btnRB4->TabIndex = 27;
			this->btnRB4->Text = L"0";
			this->btnRB4->Click += gcnew System::EventHandler(this, &MainForm::btnRB4_Click);
			// 
			// btnRB5
			// 
			this->btnRB5->AutoSize = true;
			this->btnRB5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->btnRB5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRB5->Location = System::Drawing::Point(102, 36);
			this->btnRB5->Name = L"btnRB5";
			this->btnRB5->Size = System::Drawing::Size(15, 15);
			this->btnRB5->TabIndex = 26;
			this->btnRB5->Text = L"0";
			this->btnRB5->Click += gcnew System::EventHandler(this, &MainForm::btnRB5_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->lPortA);
			this->groupBox4->Controls->Add(this->btnRA0);
			this->groupBox4->Controls->Add(this->label1);
			this->groupBox4->Controls->Add(this->btnRA1);
			this->groupBox4->Controls->Add(this->lTrisA);
			this->groupBox4->Controls->Add(this->btnRA2);
			this->groupBox4->Controls->Add(this->btnRA7);
			this->groupBox4->Controls->Add(this->btnRA3);
			this->groupBox4->Controls->Add(this->btnRA6);
			this->groupBox4->Controls->Add(this->btnRA4);
			this->groupBox4->Controls->Add(this->btnRA5);
			this->groupBox4->Location = System::Drawing::Point(15, 11);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(214, 55);
			this->groupBox4->TabIndex = 32;
			this->groupBox4->TabStop = false;
			// 
			// btnRA0
			// 
			this->btnRA0->AutoSize = true;
			this->btnRA0->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->btnRA0->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRA0->Location = System::Drawing::Point(192, 36);
			this->btnRA0->Name = L"btnRA0";
			this->btnRA0->Size = System::Drawing::Size(15, 15);
			this->btnRA0->TabIndex = 31;
			this->btnRA0->Text = L"0";
			this->btnRA0->Click += gcnew System::EventHandler(this, &MainForm::btnRA0_Click);
			// 
			// btnRA1
			// 
			this->btnRA1->AutoSize = true;
			this->btnRA1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->btnRA1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRA1->Location = System::Drawing::Point(174, 36);
			this->btnRA1->Name = L"btnRA1";
			this->btnRA1->Size = System::Drawing::Size(15, 15);
			this->btnRA1->TabIndex = 30;
			this->btnRA1->Text = L"0";
			this->btnRA1->Click += gcnew System::EventHandler(this, &MainForm::btnRA1_Click);
			// 
			// btnRA2
			// 
			this->btnRA2->AutoSize = true;
			this->btnRA2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->btnRA2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRA2->Location = System::Drawing::Point(156, 36);
			this->btnRA2->Name = L"btnRA2";
			this->btnRA2->Size = System::Drawing::Size(15, 15);
			this->btnRA2->TabIndex = 29;
			this->btnRA2->Text = L"0";
			this->btnRA2->Click += gcnew System::EventHandler(this, &MainForm::btnRA2_Click);
			// 
			// btnRA7
			// 
			this->btnRA7->AutoSize = true;
			this->btnRA7->BackColor = System::Drawing::Color::Black;
			this->btnRA7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->btnRA7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRA7->Location = System::Drawing::Point(66, 36);
			this->btnRA7->Name = L"btnRA7";
			this->btnRA7->Size = System::Drawing::Size(15, 15);
			this->btnRA7->TabIndex = 24;
			this->btnRA7->Text = L"0";
			this->btnRA7->Click += gcnew System::EventHandler(this, &MainForm::btnRA7_Click);
			// 
			// btnRA3
			// 
			this->btnRA3->AutoSize = true;
			this->btnRA3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->btnRA3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRA3->Location = System::Drawing::Point(138, 36);
			this->btnRA3->Name = L"btnRA3";
			this->btnRA3->Size = System::Drawing::Size(15, 15);
			this->btnRA3->TabIndex = 28;
			this->btnRA3->Text = L"0";
			this->btnRA3->Click += gcnew System::EventHandler(this, &MainForm::btnRA3_Click);
			// 
			// btnRA6
			// 
			this->btnRA6->AutoSize = true;
			this->btnRA6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->btnRA6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRA6->Location = System::Drawing::Point(84, 36);
			this->btnRA6->Name = L"btnRA6";
			this->btnRA6->Size = System::Drawing::Size(15, 15);
			this->btnRA6->TabIndex = 25;
			this->btnRA6->Text = L"0";
			this->btnRA6->Click += gcnew System::EventHandler(this, &MainForm::btnRA6_Click);
			// 
			// btnRA4
			// 
			this->btnRA4->AutoSize = true;
			this->btnRA4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->btnRA4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRA4->Location = System::Drawing::Point(120, 36);
			this->btnRA4->Name = L"btnRA4";
			this->btnRA4->Size = System::Drawing::Size(15, 15);
			this->btnRA4->TabIndex = 27;
			this->btnRA4->Text = L"0";
			this->btnRA4->Click += gcnew System::EventHandler(this, &MainForm::btnRA4_Click);
			// 
			// btnRA5
			// 
			this->btnRA5->AutoSize = true;
			this->btnRA5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->btnRA5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRA5->Location = System::Drawing::Point(102, 36);
			this->btnRA5->Name = L"btnRA5";
			this->btnRA5->Size = System::Drawing::Size(15, 15);
			this->btnRA5->TabIndex = 26;
			this->btnRA5->Text = L"0";
			this->btnRA5->Click += gcnew System::EventHandler(this, &MainForm::btnRA5_Click);
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->btnRuntimeReset);
			this->groupBox6->Controls->Add(this->lRuntime);
			this->groupBox6->ForeColor = System::Drawing::Color::White;
			this->groupBox6->Location = System::Drawing::Point(615, 438);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(88, 66);
			this->groupBox6->TabIndex = 15;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Runtime";
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->label6);
			this->groupBox7->Controls->Add(this->nudSimSpeed);
			this->groupBox7->ForeColor = System::Drawing::Color::White;
			this->groupBox7->Location = System::Drawing::Point(615, 510);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(88, 66);
			this->groupBox7->TabIndex = 17;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Simulation";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(720, 586);
			this->Controls->Add(this->groupBox7);
			this->Controls->Add(this->groupBox6);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudSimSpeed))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
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
				rtbprogramOutput->Text += gcnew String(line.c_str());
				for (int i = line.length(); i < 100; i++)
					rtbprogramOutput->Text += " ";
				rtbprogramOutput->Text += "\r\n";
			}
			rtbprogramOutput->Text += "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n";
		}

		std::string asIO(bool value) {
			if (value)
				return "I";
			return "O";
		}

		void highlightConsoleLine(int index)
		{
			static int lastIndex;
			if (lastIndex != index && index < rtbprogramOutput->Lines->Length) {
				rtbprogramOutput->SelectAll();
				rtbprogramOutput->SelectionBackColor = rtbprogramOutput->BackColor;
				rtbprogramOutput->SelectionColor = rtbprogramOutput->ForeColor;
				auto start = rtbprogramOutput->GetFirstCharIndexFromLine(index);  // Get the 1st char index of the appended text
				auto length = rtbprogramOutput->Lines[index]->Length;
				rtbprogramOutput->Select(start, length);                 // Select from there to the end
				rtbprogramOutput->SelectionBackColor = Color::White;
				rtbprogramOutput->SelectionColor = Color::Black;
				start = rtbprogramOutput->GetFirstCharIndexFromLine(std::max(index - 9, 0));  // Get the 1st char index of the appended text
				rtbprogramOutput->Select(start, 0);
				rtbprogramOutput->ScrollToCaret();
			}
			lastIndex = index;
		}

		void updateUI()
		{
			lpcValue->Text = gcnew String(fmt::format("%04X", cpuRef->registerData.getPC()).c_str());
			lpclValue->Text = gcnew String(fmt::format("%02X", cpuRef->registerData.getPC() & 0xFF).c_str());
			lpclathValue->Text = gcnew String(fmt::format("%02X", cpuRef->registerData.getPC() >> 8 & 0xFF).c_str());
			lwRegValue->Text = gcnew String(fmt::format("%02X", cpuRef->cpuRegisters.w).c_str());
			lRuntime->Text = gcnew String(fmt::format("%d us", cpuRef->timeActive).c_str());

			lTrisA->Text = gcnew String(fmt::format("Tris A |  %s  %s  %s  %s  %s  %s  %s  %s"
				, asIO(cpuRef->registerData.readBitFromMemory(0x85, 7))
				, asIO(cpuRef->registerData.readBitFromMemory(0x85, 6))
				, asIO(cpuRef->registerData.readBitFromMemory(0x85, 5))
				, asIO(cpuRef->registerData.readBitFromMemory(0x85, 4))
				, asIO(cpuRef->registerData.readBitFromMemory(0x85, 3))
				, asIO(cpuRef->registerData.readBitFromMemory(0x85, 2))
				, asIO(cpuRef->registerData.readBitFromMemory(0x85, 1))
				, asIO(cpuRef->registerData.readBitFromMemory(0x85, 0))).c_str());

			lTrisB->Text = gcnew String(fmt::format("Tris B |  %s  %s  %s  %s  %s  %s  %s  %s"
				, asIO(cpuRef->registerData.readBitFromMemory(0x86, 7))
				, asIO(cpuRef->registerData.readBitFromMemory(0x86, 6))
				, asIO(cpuRef->registerData.readBitFromMemory(0x86, 5))
				, asIO(cpuRef->registerData.readBitFromMemory(0x86, 4))
				, asIO(cpuRef->registerData.readBitFromMemory(0x86, 3))
				, asIO(cpuRef->registerData.readBitFromMemory(0x86, 2))
				, asIO(cpuRef->registerData.readBitFromMemory(0x86, 1))
				, asIO(cpuRef->registerData.readBitFromMemory(0x86, 0))).c_str());

			lStatusValues->Text = gcnew String(fmt::format("%d    %d    %d    %d    %d    %d    %d    %d"
				, cpuRef->registerData.readBitFromMemory(0x3, 7)
				, cpuRef->registerData.readBitFromMemory(0x3, 6)
				, cpuRef->registerData.readBitFromMemory(0x3, 5)
				, cpuRef->registerData.readBitFromMemory(0x3, 4)
				, cpuRef->registerData.readBitFromMemory(0x3, 3)
				, cpuRef->registerData.readBitFromMemory(0x3, 2)
				, cpuRef->registerData.readBitFromMemory(0x3, 1)
				, cpuRef->registerData.readBitFromMemory(0x3, 0)).c_str());

			lOptionValues->Text = gcnew String(fmt::format("%d    %d    %d    %d    %d    %d    %d    %d"
				, cpuRef->registerData.readBitFromMemory(0x81, 7)
				, cpuRef->registerData.readBitFromMemory(0x81, 6)
				, cpuRef->registerData.readBitFromMemory(0x81, 5)
				, cpuRef->registerData.readBitFromMemory(0x81, 4)
				, cpuRef->registerData.readBitFromMemory(0x81, 3)
				, cpuRef->registerData.readBitFromMemory(0x81, 2)
				, cpuRef->registerData.readBitFromMemory(0x81, 1)
				, cpuRef->registerData.readBitFromMemory(0x81, 0)).c_str());

			lIntconValues->Text = gcnew String(fmt::format("%d    %d    %d    %d    %d    %d    %d    %d"
				, cpuRef->registerData.readBitFromMemory(0xB, 7)
				, cpuRef->registerData.readBitFromMemory(0xB, 6)
				, cpuRef->registerData.readBitFromMemory(0xB, 5)
				, cpuRef->registerData.readBitFromMemory(0xB, 4)
				, cpuRef->registerData.readBitFromMemory(0xB, 3)
				, cpuRef->registerData.readBitFromMemory(0xB, 2)
				, cpuRef->registerData.readBitFromMemory(0xB, 1)
				, cpuRef->registerData.readBitFromMemory(0xB, 0)).c_str());


			btnRA7->Text = gcnew System::String(fmt::format("%d", cpuRef->registerData.readBitFromMemory(0x5, 7)).c_str());
			btnRA6->Text = gcnew System::String(fmt::format("%d", cpuRef->registerData.readBitFromMemory(0x5, 6)).c_str());
			btnRA5->Text = gcnew System::String(fmt::format("%d", cpuRef->registerData.readBitFromMemory(0x5, 5)).c_str());
			btnRA4->Text = gcnew System::String(fmt::format("%d", cpuRef->registerData.readBitFromMemory(0x5, 4)).c_str());
			btnRA3->Text = gcnew System::String(fmt::format("%d", cpuRef->registerData.readBitFromMemory(0x5, 3)).c_str());
			btnRA2->Text = gcnew System::String(fmt::format("%d", cpuRef->registerData.readBitFromMemory(0x5, 2)).c_str());
			btnRA1->Text = gcnew System::String(fmt::format("%d", cpuRef->registerData.readBitFromMemory(0x5, 1)).c_str());
			btnRA0->Text = gcnew System::String(fmt::format("%d", cpuRef->registerData.readBitFromMemory(0x5, 0)).c_str());

			btnRB3->Text = gcnew System::String(fmt::format("%d", cpuRef->registerData.readBitFromMemory(0x6, 7)).c_str());
			btnRB6->Text = gcnew System::String(fmt::format("%d", cpuRef->registerData.readBitFromMemory(0x6, 6)).c_str());
			btnRB5->Text = gcnew System::String(fmt::format("%d", cpuRef->registerData.readBitFromMemory(0x6, 5)).c_str());
			btnRB4->Text = gcnew System::String(fmt::format("%d", cpuRef->registerData.readBitFromMemory(0x6, 4)).c_str());
			btnRB3->Text = gcnew System::String(fmt::format("%d", cpuRef->registerData.readBitFromMemory(0x6, 3)).c_str());
			btnRB2->Text = gcnew System::String(fmt::format("%d", cpuRef->registerData.readBitFromMemory(0x6, 2)).c_str());
			btnRB1->Text = gcnew System::String(fmt::format("%d", cpuRef->registerData.readBitFromMemory(0x6, 1)).c_str());
			btnRB0->Text = gcnew System::String(fmt::format("%d", cpuRef->registerData.readBitFromMemory(0x6, 0)).c_str());
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
		highlightConsoleLine(cpuRef->parser.getLineInFile(cpuRef->registerData.getPC()));
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
		try {
			cpuRef->singleStep();
			highlightConsoleLine(cpuRef->parser.getLineInFile(cpuRef->registerData.getPC()));
		}
		catch (std::exception & e) {
			cpuRunTimer->Stop();
			MessageBoxA(GetActiveWindow(), fmt::format("Simulation Error!\n\n%s", e.what()).c_str(), "CPU Error", MB_OK | MB_ICONERROR);
		}

	}
	private: System::Void btnReset_Click(System::Object^ sender, System::EventArgs^ e) {
		assert(cpuRef != nullptr);
		cpuRef->registerData.setPC(0);
		cpuRef->registerData.resetPowerOn();
		cpuRef->cpuRegisters.w = 0;
		highlightConsoleLine(cpuRef->parser.getLineInFile(cpuRef->registerData.getPC()));
	}
	private: System::Void btnIgnore_Click(System::Object^ sender, System::EventArgs^ e) {
		assert(cpuRef != nullptr);
		try {
			cpuRef->registerData.increasePCBy(1);
			highlightConsoleLine(cpuRef->parser.getLineInFile(cpuRef->registerData.getPC()));
		}
		catch (std::exception & e) {
			cpuRunTimer->Stop();
			MessageBoxA(GetActiveWindow(), fmt::format("Simulation Error!\n\n%s", e.what()).c_str(), "CPU Error", MB_OK | MB_ICONERROR);
		}

	}
	private: System::Void cpuRunTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		assert(cpuRef != nullptr);
		try {
			cpuRef->singleStep();
			highlightConsoleLine(cpuRef->parser.getLineInFile(cpuRef->registerData.getPC()));
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
		cpuRef->registerData.writeBitToMemory(0x5, 7, btnRA7->Text == "0");
	}
	private: System::Void btnRA6_Click(System::Object^ sender, System::EventArgs^ e) {
		cpuRef->registerData.writeBitToMemory(0x5, 6, btnRA6->Text == "0");
	}
	private: System::Void btnRA5_Click(System::Object^ sender, System::EventArgs^ e) {
		cpuRef->registerData.writeBitToMemory(0x5, 5, btnRA5->Text == "0");
	}
	private: System::Void btnRA4_Click(System::Object^ sender, System::EventArgs^ e) {
		cpuRef->registerData.writeBitToMemory(0x5, 4, btnRA4->Text == "0");
	}
	private: System::Void btnRA3_Click(System::Object^ sender, System::EventArgs^ e) {
		cpuRef->registerData.writeBitToMemory(0x5, 3, btnRA3->Text == "0");
	}
	private: System::Void btnRA2_Click(System::Object^ sender, System::EventArgs^ e) {
		cpuRef->registerData.writeBitToMemory(0x5, 2, btnRA2->Text == "0");
	}
	private: System::Void btnRA1_Click(System::Object^ sender, System::EventArgs^ e) {
		cpuRef->registerData.writeBitToMemory(0x5, 1, btnRA1->Text == "0");
	}
	private: System::Void btnRA0_Click(System::Object^ sender, System::EventArgs^ e) {
		cpuRef->registerData.writeBitToMemory(0x5, 0, btnRA0->Text == "0");
	}
	private: System::Void btnRB7_Click(System::Object^ sender, System::EventArgs^ e) {
		cpuRef->registerData.writeBitToMemory(0x6, 7, btnRB7->Text == "0");
	}
	private: System::Void btnRB6_Click(System::Object^ sender, System::EventArgs^ e) {
		cpuRef->registerData.writeBitToMemory(0x6, 6, btnRB6->Text == "0");
	}
	private: System::Void btnRB5_Click(System::Object^ sender, System::EventArgs^ e) {
		cpuRef->registerData.writeBitToMemory(0x6, 5, btnRB5->Text == "0");
	}
	private: System::Void btnRB4_Click(System::Object^ sender, System::EventArgs^ e) {
		cpuRef->registerData.writeBitToMemory(0x6, 4, btnRB4->Text == "0");
	}
	private: System::Void btnRB3_Click(System::Object^ sender, System::EventArgs^ e) {
		cpuRef->registerData.writeBitToMemory(0x6, 3, btnRB3->Text == "0");
	}
	private: System::Void btnRB2_Click(System::Object^ sender, System::EventArgs^ e) {
		cpuRef->registerData.writeBitToMemory(0x6, 2, btnRB2->Text == "0");
	}
	private: System::Void btnRB1_Click(System::Object^ sender, System::EventArgs^ e) {
		cpuRef->registerData.writeBitToMemory(0x6, 1, btnRB1->Text == "0");
	}
	private: System::Void btnRB0_Click(System::Object^ sender, System::EventArgs^ e) {
		cpuRef->registerData.writeBitToMemory(0x6, 0, btnRB0->Text == "0");
	}
	private: System::Void nudSimSpeed_onValueChanged(System::Object^ sender, System::EventArgs^ e) {
		cpuRunTimer->Interval = 1000 / Convert::ToInt32(Math::Round(nudSimSpeed->Value, 0));
	}
	private: System::Void btnRuntimeReset_Click(System::Object^ sender, System::EventArgs^ e) {
		cpuRef->timeActive = 0;
	}
	};
}
