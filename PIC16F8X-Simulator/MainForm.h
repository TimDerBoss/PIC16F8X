#pragma once

#include "CPU.h"
#include <FormatString.h>

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


	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ lStatus0;
	private: System::Windows::Forms::Label^ lStatus1;
	private: System::Windows::Forms::Label^ lStatus2;
	private: System::Windows::Forms::Label^ lStatus3;
	private: System::Windows::Forms::Label^ lStatus4;
	private: System::Windows::Forms::Label^ lStatus5;
	private: System::Windows::Forms::Label^ lStatus6;
	private: System::Windows::Forms::Label^ lStatus7;
	private: System::Windows::Forms::Label^ lOption0;
	private: System::Windows::Forms::Label^ lOption1;
	private: System::Windows::Forms::Label^ lOption2;
	private: System::Windows::Forms::Label^ lOption3;
	private: System::Windows::Forms::Label^ lOption4;
	private: System::Windows::Forms::Label^ lOption5;
	private: System::Windows::Forms::Label^ lOption6;
	private: System::Windows::Forms::Label^ lOption7;

























	private: System::Windows::Forms::GroupBox^ gbOption;

	private: System::Windows::Forms::GroupBox^ gbStatus;
private: System::Windows::Forms::Button^ btnIgnore;



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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->gbOption = (gcnew System::Windows::Forms::GroupBox());
			this->lOption0 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->lOption1 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->lOption2 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->lOption3 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->lOption4 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->lOption7 = (gcnew System::Windows::Forms::Label());
			this->lOption5 = (gcnew System::Windows::Forms::Label());
			this->lOption6 = (gcnew System::Windows::Forms::Label());
			this->gbStatus = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->lStatus7 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->lStatus6 = (gcnew System::Windows::Forms::Label());
			this->lStatus0 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->lStatus5 = (gcnew System::Windows::Forms::Label());
			this->lStatus1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lStatus2 = (gcnew System::Windows::Forms::Label());
			this->lStatus4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lStatus3 = (gcnew System::Windows::Forms::Label());
			this->lpc = (gcnew System::Windows::Forms::Label());
			this->lpcl = (gcnew System::Windows::Forms::Label());
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
			this->gbFSR->SuspendLayout();
			this->panel1->SuspendLayout();
			this->gbOption->SuspendLayout();
			this->gbStatus->SuspendLayout();
			this->SuspendLayout();
			// 
			// gbFSR
			// 
			this->gbFSR->Controls->Add(this->panel1);
			this->gbFSR->Location = System::Drawing::Point(15, 12);
			this->gbFSR->Name = L"gbFSR";
			this->gbFSR->Size = System::Drawing::Size(306, 197);
			this->gbFSR->TabIndex = 0;
			this->gbFSR->TabStop = false;
			this->gbFSR->Text = L"Special Function Registers";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->gbOption);
			this->panel1->Controls->Add(this->gbStatus);
			this->panel1->Controls->Add(this->lpc);
			this->panel1->Controls->Add(this->lpcl);
			this->panel1->Controls->Add(this->lpclath);
			this->panel1->Controls->Add(this->lwRegValue);
			this->panel1->Controls->Add(this->lwReg);
			this->panel1->Controls->Add(this->lpclValue);
			this->panel1->Controls->Add(this->lpclathValue);
			this->panel1->Controls->Add(this->lpcValue);
			this->panel1->Location = System::Drawing::Point(6, 19);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(295, 172);
			this->panel1->TabIndex = 8;
			// 
			// gbOption
			// 
			this->gbOption->Controls->Add(this->lOption0);
			this->gbOption->Controls->Add(this->label16);
			this->gbOption->Controls->Add(this->label15);
			this->gbOption->Controls->Add(this->lOption1);
			this->gbOption->Controls->Add(this->label14);
			this->gbOption->Controls->Add(this->lOption2);
			this->gbOption->Controls->Add(this->label13);
			this->gbOption->Controls->Add(this->label12);
			this->gbOption->Controls->Add(this->lOption3);
			this->gbOption->Controls->Add(this->label11);
			this->gbOption->Controls->Add(this->label10);
			this->gbOption->Controls->Add(this->lOption4);
			this->gbOption->Controls->Add(this->label9);
			this->gbOption->Controls->Add(this->lOption7);
			this->gbOption->Controls->Add(this->lOption5);
			this->gbOption->Controls->Add(this->lOption6);
			this->gbOption->Location = System::Drawing::Point(6, 107);
			this->gbOption->Name = L"gbOption";
			this->gbOption->Size = System::Drawing::Size(285, 49);
			this->gbOption->TabIndex = 9;
			this->gbOption->TabStop = false;
			this->gbOption->Text = L"Option Register";
			// 
			// lOption0
			// 
			this->lOption0->AutoSize = true;
			this->lOption0->Location = System::Drawing::Point(252, 30);
			this->lOption0->Name = L"lOption0";
			this->lOption0->Size = System::Drawing::Size(10, 13);
			this->lOption0->TabIndex = 54;
			this->lOption0->Text = L"-";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(10, 16);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(29, 13);
			this->label16->TabIndex = 24;
			this->label16->Text = L"RBP";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(37, 16);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(38, 13);
			this->label15->TabIndex = 25;
			this->label15->Text = L"IntEdg";
			// 
			// lOption1
			// 
			this->lOption1->AutoSize = true;
			this->lOption1->Location = System::Drawing::Point(217, 29);
			this->lOption1->Name = L"lOption1";
			this->lOption1->Size = System::Drawing::Size(10, 13);
			this->lOption1->TabIndex = 53;
			this->lOption1->Text = L"-";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(77, 16);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(34, 13);
			this->label14->TabIndex = 26;
			this->label14->Text = L"T0CS";
			// 
			// lOption2
			// 
			this->lOption2->AutoSize = true;
			this->lOption2->Location = System::Drawing::Point(182, 30);
			this->lOption2->Name = L"lOption2";
			this->lOption2->Size = System::Drawing::Size(10, 13);
			this->lOption2->TabIndex = 52;
			this->lOption2->Text = L"-";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(112, 16);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(34, 13);
			this->label13->TabIndex = 27;
			this->label13->Text = L"T0SE";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(147, 16);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(28, 13);
			this->label12->TabIndex = 28;
			this->label12->Text = L"PSA";
			// 
			// lOption3
			// 
			this->lOption3->AutoSize = true;
			this->lOption3->Location = System::Drawing::Point(147, 29);
			this->lOption3->Name = L"lOption3";
			this->lOption3->Size = System::Drawing::Size(10, 13);
			this->lOption3->TabIndex = 51;
			this->lOption3->Text = L"-";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(182, 16);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(27, 13);
			this->label11->TabIndex = 29;
			this->label11->Text = L"PS2";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(217, 16);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(27, 13);
			this->label10->TabIndex = 30;
			this->label10->Text = L"PS1";
			// 
			// lOption4
			// 
			this->lOption4->AutoSize = true;
			this->lOption4->Location = System::Drawing::Point(112, 29);
			this->lOption4->Name = L"lOption4";
			this->lOption4->Size = System::Drawing::Size(10, 13);
			this->lOption4->TabIndex = 50;
			this->lOption4->Text = L"-";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(252, 16);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(27, 13);
			this->label9->TabIndex = 31;
			this->label9->Text = L"PS0";
			// 
			// lOption7
			// 
			this->lOption7->AutoSize = true;
			this->lOption7->Location = System::Drawing::Point(13, 29);
			this->lOption7->Name = L"lOption7";
			this->lOption7->Size = System::Drawing::Size(10, 13);
			this->lOption7->TabIndex = 47;
			this->lOption7->Text = L"-";
			// 
			// lOption5
			// 
			this->lOption5->AutoSize = true;
			this->lOption5->Location = System::Drawing::Point(77, 29);
			this->lOption5->Name = L"lOption5";
			this->lOption5->Size = System::Drawing::Size(10, 13);
			this->lOption5->TabIndex = 49;
			this->lOption5->Text = L"-";
			// 
			// lOption6
			// 
			this->lOption6->AutoSize = true;
			this->lOption6->Location = System::Drawing::Point(46, 29);
			this->lOption6->Name = L"lOption6";
			this->lOption6->Size = System::Drawing::Size(10, 13);
			this->lOption6->TabIndex = 48;
			this->lOption6->Text = L"-";
			// 
			// gbStatus
			// 
			this->gbStatus->Controls->Add(this->label1);
			this->gbStatus->Controls->Add(this->label8);
			this->gbStatus->Controls->Add(this->label7);
			this->gbStatus->Controls->Add(this->label6);
			this->gbStatus->Controls->Add(this->lStatus7);
			this->gbStatus->Controls->Add(this->label5);
			this->gbStatus->Controls->Add(this->lStatus6);
			this->gbStatus->Controls->Add(this->lStatus0);
			this->gbStatus->Controls->Add(this->label4);
			this->gbStatus->Controls->Add(this->lStatus5);
			this->gbStatus->Controls->Add(this->lStatus1);
			this->gbStatus->Controls->Add(this->label3);
			this->gbStatus->Controls->Add(this->lStatus2);
			this->gbStatus->Controls->Add(this->lStatus4);
			this->gbStatus->Controls->Add(this->label2);
			this->gbStatus->Controls->Add(this->lStatus3);
			this->gbStatus->Location = System::Drawing::Point(6, 55);
			this->gbStatus->Name = L"gbStatus";
			this->gbStatus->Size = System::Drawing::Size(285, 46);
			this->gbStatus->TabIndex = 10;
			this->gbStatus->TabStop = false;
			this->gbStatus->Text = L"Status Register";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(25, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"IRP";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(252, 16);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(14, 13);
			this->label8->TabIndex = 23;
			this->label8->Text = L"C";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(217, 16);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(22, 13);
			this->label7->TabIndex = 22;
			this->label7->Text = L"DC";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(182, 16);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(14, 13);
			this->label6->TabIndex = 21;
			this->label6->Text = L"Z";
			// 
			// lStatus7
			// 
			this->lStatus7->AutoSize = true;
			this->lStatus7->Location = System::Drawing::Point(13, 30);
			this->lStatus7->Name = L"lStatus7";
			this->lStatus7->Size = System::Drawing::Size(10, 13);
			this->lStatus7->TabIndex = 39;
			this->lStatus7->Text = L"-";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(147, 16);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(22, 13);
			this->label5->TabIndex = 20;
			this->label5->Text = L"PD";
			// 
			// lStatus6
			// 
			this->lStatus6->AutoSize = true;
			this->lStatus6->Location = System::Drawing::Point(46, 30);
			this->lStatus6->Name = L"lStatus6";
			this->lStatus6->Size = System::Drawing::Size(10, 13);
			this->lStatus6->TabIndex = 40;
			this->lStatus6->Text = L"-";
			// 
			// lStatus0
			// 
			this->lStatus0->AutoSize = true;
			this->lStatus0->Location = System::Drawing::Point(252, 31);
			this->lStatus0->Name = L"lStatus0";
			this->lStatus0->Size = System::Drawing::Size(10, 13);
			this->lStatus0->TabIndex = 46;
			this->lStatus0->Text = L"-";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(112, 16);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(22, 13);
			this->label4->TabIndex = 19;
			this->label4->Text = L"TO";
			// 
			// lStatus5
			// 
			this->lStatus5->AutoSize = true;
			this->lStatus5->Location = System::Drawing::Point(77, 30);
			this->lStatus5->Name = L"lStatus5";
			this->lStatus5->Size = System::Drawing::Size(10, 13);
			this->lStatus5->TabIndex = 41;
			this->lStatus5->Text = L"-";
			// 
			// lStatus1
			// 
			this->lStatus1->AutoSize = true;
			this->lStatus1->Location = System::Drawing::Point(217, 30);
			this->lStatus1->Name = L"lStatus1";
			this->lStatus1->Size = System::Drawing::Size(10, 13);
			this->lStatus1->TabIndex = 45;
			this->lStatus1->Text = L"-";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(77, 16);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(28, 13);
			this->label3->TabIndex = 18;
			this->label3->Text = L"RP0";
			// 
			// lStatus2
			// 
			this->lStatus2->AutoSize = true;
			this->lStatus2->Location = System::Drawing::Point(182, 31);
			this->lStatus2->Name = L"lStatus2";
			this->lStatus2->Size = System::Drawing::Size(10, 13);
			this->lStatus2->TabIndex = 44;
			this->lStatus2->Text = L"-";
			// 
			// lStatus4
			// 
			this->lStatus4->AutoSize = true;
			this->lStatus4->Location = System::Drawing::Point(112, 30);
			this->lStatus4->Name = L"lStatus4";
			this->lStatus4->Size = System::Drawing::Size(10, 13);
			this->lStatus4->TabIndex = 42;
			this->lStatus4->Text = L"-";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(42, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(28, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"RP1";
			// 
			// lStatus3
			// 
			this->lStatus3->AutoSize = true;
			this->lStatus3->Location = System::Drawing::Point(147, 30);
			this->lStatus3->Name = L"lStatus3";
			this->lStatus3->Size = System::Drawing::Size(10, 13);
			this->lStatus3->TabIndex = 43;
			this->lStatus3->Text = L"-";
			// 
			// lpc
			// 
			this->lpc->AutoSize = true;
			this->lpc->Location = System::Drawing::Point(3, 0);
			this->lpc->Name = L"lpc";
			this->lpc->Size = System::Drawing::Size(21, 13);
			this->lpc->TabIndex = 0;
			this->lpc->Text = L"PC";
			// 
			// lpcl
			// 
			this->lpcl->AutoSize = true;
			this->lpcl->Location = System::Drawing::Point(3, 13);
			this->lpcl->Name = L"lpcl";
			this->lpcl->Size = System::Drawing::Size(27, 13);
			this->lpcl->TabIndex = 1;
			this->lpcl->Text = L"PCL";
			// 
			// lpclath
			// 
			this->lpclath->AutoSize = true;
			this->lpclath->Location = System::Drawing::Point(3, 26);
			this->lpclath->Name = L"lpclath";
			this->lpclath->Size = System::Drawing::Size(49, 13);
			this->lpclath->TabIndex = 2;
			this->lpclath->Text = L"PCLATH";
			// 
			// lwRegValue
			// 
			this->lwRegValue->AutoSize = true;
			this->lwRegValue->Location = System::Drawing::Point(81, 39);
			this->lwRegValue->Name = L"lwRegValue";
			this->lwRegValue->Size = System::Drawing::Size(10, 13);
			this->lwRegValue->TabIndex = 7;
			this->lwRegValue->Text = L"-";
			// 
			// lwReg
			// 
			this->lwReg->AutoSize = true;
			this->lwReg->Location = System::Drawing::Point(3, 39);
			this->lwReg->Name = L"lwReg";
			this->lwReg->Size = System::Drawing::Size(15, 13);
			this->lwReg->TabIndex = 6;
			this->lwReg->Text = L"w";
			// 
			// lpclValue
			// 
			this->lpclValue->AutoSize = true;
			this->lpclValue->Location = System::Drawing::Point(81, 13);
			this->lpclValue->Name = L"lpclValue";
			this->lpclValue->Size = System::Drawing::Size(10, 13);
			this->lpclValue->TabIndex = 4;
			this->lpclValue->Text = L"-";
			// 
			// lpclathValue
			// 
			this->lpclathValue->AutoSize = true;
			this->lpclathValue->Location = System::Drawing::Point(81, 26);
			this->lpclathValue->Name = L"lpclathValue";
			this->lpclathValue->Size = System::Drawing::Size(10, 13);
			this->lpclathValue->TabIndex = 5;
			this->lpclathValue->Text = L"-";
			// 
			// lpcValue
			// 
			this->lpcValue->AutoSize = true;
			this->lpcValue->Location = System::Drawing::Point(81, 0);
			this->lpcValue->Name = L"lpcValue";
			this->lpcValue->Size = System::Drawing::Size(10, 13);
			this->lpcValue->TabIndex = 3;
			this->lpcValue->Text = L"-";
			// 
			// btnStart
			// 
			this->btnStart->Location = System::Drawing::Point(327, 55);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(75, 23);
			this->btnStart->TabIndex = 1;
			this->btnStart->Text = L"Start";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &MainForm::btnStart_Click);
			// 
			// btnStop
			// 
			this->btnStop->Location = System::Drawing::Point(327, 26);
			this->btnStop->Name = L"btnStop";
			this->btnStop->Size = System::Drawing::Size(75, 23);
			this->btnStop->TabIndex = 2;
			this->btnStop->Text = L"Stop";
			this->btnStop->UseVisualStyleBackColor = true;
			this->btnStop->Click += gcnew System::EventHandler(this, &MainForm::btnStop_Click);
			// 
			// btnStep
			// 
			this->btnStep->Location = System::Drawing::Point(327, 84);
			this->btnStep->Name = L"btnStep";
			this->btnStep->Size = System::Drawing::Size(75, 23);
			this->btnStep->TabIndex = 3;
			this->btnStep->Text = L"Single Step";
			this->btnStep->UseVisualStyleBackColor = true;
			this->btnStep->Click += gcnew System::EventHandler(this, &MainForm::btnStep_Click);
			// 
			// btnReset
			// 
			this->btnReset->Location = System::Drawing::Point(327, 111);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(75, 23);
			this->btnReset->TabIndex = 4;
			this->btnReset->Text = L"Reset";
			this->btnReset->UseVisualStyleBackColor = true;
			this->btnReset->Click += gcnew System::EventHandler(this, &MainForm::btnReset_Click);
			// 
			// updateTimer
			// 
			this->updateTimer->Enabled = true;
			this->updateTimer->Tick += gcnew System::EventHandler(this, &MainForm::updateTimer_Tick);
			// 
			// rtbprogramOutput
			// 
			this->rtbprogramOutput->Location = System::Drawing::Point(12, 233);
			this->rtbprogramOutput->Name = L"rtbprogramOutput";
			this->rtbprogramOutput->ReadOnly = true;
			this->rtbprogramOutput->Size = System::Drawing::Size(710, 92);
			this->rtbprogramOutput->TabIndex = 7;
			this->rtbprogramOutput->Text = L"";
			// 
			// btnIgnore
			// 
			this->btnIgnore->Location = System::Drawing::Point(327, 140);
			this->btnIgnore->Name = L"btnIgnore";
			this->btnIgnore->Size = System::Drawing::Size(75, 23);
			this->btnIgnore->TabIndex = 8;
			this->btnIgnore->Text = L"Ignore";
			this->btnIgnore->UseVisualStyleBackColor = true;
			this->btnIgnore->Click += gcnew System::EventHandler(this, &MainForm::btnIgnore_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1077, 485);
			this->Controls->Add(this->btnIgnore);
			this->Controls->Add(this->rtbprogramOutput);
			this->Controls->Add(this->btnStep);
			this->Controls->Add(this->btnReset);
			this->Controls->Add(this->btnStop);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->gbFSR);
			this->Name = L"MainForm";
			this->Text = L"Form1";
			this->gbFSR->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->gbOption->ResumeLayout(false);
			this->gbOption->PerformLayout();
			this->gbStatus->ResumeLayout(false);
			this->gbStatus->PerformLayout();
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
				lpcValue->Text = gcnew String(fmt::format("%04X", cpuRef->registerData.getPC()).c_str());
				lpclValue->Text = gcnew String(fmt::format("%02X", cpuRef->registerData.getPC() & 0xFF).c_str());
				lpclathValue->Text = gcnew String(fmt::format("%02X", cpuRef->registerData.getPC() >> 8 & 0xFF).c_str());
				lwRegValue->Text = gcnew String(fmt::format("%02X", cpuRef->cpuRegisters.w).c_str());

				gbStatus->Text = gcnew String(fmt::format("Status Register - %02X", cpuRef->registerData.readData(0x3)).c_str());
				lStatus0->Text = gcnew String(fmt::format("%d", cpuRef->registerData.getBit(0x3, 0)).c_str());
				lStatus1->Text = gcnew String(fmt::format("%d", cpuRef->registerData.getBit(0x3, 1)).c_str());
				lStatus2->Text = gcnew String(fmt::format("%d", cpuRef->registerData.getBit(0x3, 2)).c_str());
				lStatus3->Text = gcnew String(fmt::format("%d", cpuRef->registerData.getBit(0x3, 3)).c_str());
				lStatus4->Text = gcnew String(fmt::format("%d", cpuRef->registerData.getBit(0x3, 4)).c_str());
				lStatus5->Text = gcnew String(fmt::format("%d", cpuRef->registerData.getBit(0x3, 5)).c_str());
				lStatus6->Text = gcnew String(fmt::format("%d", cpuRef->registerData.getBit(0x3, 6)).c_str());
				lStatus7->Text = gcnew String(fmt::format("%d", cpuRef->registerData.getBit(0x3, 7)).c_str());

				gbOption->Text = gcnew String(fmt::format("Option Register - %02X", cpuRef->registerData.readData(0xB)).c_str());
				lOption0->Text = gcnew String(fmt::format("%d", cpuRef->registerData.getBit(0xB, 0)).c_str());
				lOption1->Text = gcnew String(fmt::format("%d", cpuRef->registerData.getBit(0xB, 1)).c_str());
				lOption2->Text = gcnew String(fmt::format("%d", cpuRef->registerData.getBit(0xB, 2)).c_str());
				lOption3->Text = gcnew String(fmt::format("%d", cpuRef->registerData.getBit(0xB, 3)).c_str());
				lOption4->Text = gcnew String(fmt::format("%d", cpuRef->registerData.getBit(0xB, 4)).c_str());
				lOption5->Text = gcnew String(fmt::format("%d", cpuRef->registerData.getBit(0xB, 5)).c_str());
				lOption6->Text = gcnew String(fmt::format("%d", cpuRef->registerData.getBit(0xB, 6)).c_str());
				lOption7->Text = gcnew String(fmt::format("%d", cpuRef->registerData.getBit(0xB, 7)).c_str());
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
			highlightConsoleLine(cpuRef->parser.getLstOpcodeInfo()[cpuRef->registerData.getPC()].lineInFile, System::Drawing::Color::Gold);
		}
	}
	private: System::Void btnReset_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void btnIgnore_Click(System::Object^ sender, System::EventArgs^ e) {
		if (cpuRef) {
			cpuRef->registerData.increasePCBy(1);
			highlightConsoleLine(cpuRef->parser.getLstOpcodeInfo()[cpuRef->registerData.getPC()].lineInFile, System::Drawing::Color::OrangeRed);
		}
	}
};
}
