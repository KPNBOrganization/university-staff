#pragma once

namespace Calc {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  Result;
	private: System::Windows::Forms::TextBox^  SecondOperand;
	private: System::Windows::Forms::TextBox^  FirstOperand;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  operationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  addToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  subtractToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  multiplyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  divideToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  addToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  subToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  mulToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  divToolStripMenuItem;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->addToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->subToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mulToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->divToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Result = (gcnew System::Windows::Forms::TextBox());
			this->SecondOperand = (gcnew System::Windows::Forms::TextBox());
			this->FirstOperand = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->operationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->subtractToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->multiplyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->divideToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->contextMenuStrip1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->ContextMenuStrip = this->contextMenuStrip1;
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->Result);
			this->panel1->Controls->Add(this->SecondOperand);
			this->panel1->Controls->Add(this->FirstOperand);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(12, 75);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(360, 180);
			this->panel1->TabIndex = 0;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->addToolStripMenuItem1, 
				this->subToolStripMenuItem, this->mulToolStripMenuItem, this->divToolStripMenuItem});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(153, 114);
			// 
			// addToolStripMenuItem1
			// 
			this->addToolStripMenuItem1->Name = L"addToolStripMenuItem1";
			this->addToolStripMenuItem1->Size = System::Drawing::Size(152, 22);
			this->addToolStripMenuItem1->Text = L"Add";
			this->addToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::Add);
			// 
			// subToolStripMenuItem
			// 
			this->subToolStripMenuItem->Name = L"subToolStripMenuItem";
			this->subToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->subToolStripMenuItem->Text = L"Sub";
			this->subToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::Sub);
			// 
			// mulToolStripMenuItem
			// 
			this->mulToolStripMenuItem->Name = L"mulToolStripMenuItem";
			this->mulToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->mulToolStripMenuItem->Text = L"Mul";
			this->mulToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::Mul);
			// 
			// divToolStripMenuItem
			// 
			this->divToolStripMenuItem->Name = L"divToolStripMenuItem";
			this->divToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->divToolStripMenuItem->Text = L"Div";
			this->divToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::Div);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(273, 122);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(50, 30);
			this->button4->TabIndex = 9;
			this->button4->Text = L"&Div";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::Div);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(273, 83);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(50, 30);
			this->button3->TabIndex = 8;
			this->button3->Text = L"&Mul";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::Mul);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(273, 47);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(50, 30);
			this->button2->TabIndex = 7;
			this->button2->Text = L"&Sub";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::Sub);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(273, 8);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(50, 30);
			this->button1->TabIndex = 6;
			this->button1->Text = L"&Add";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::Add);
			// 
			// Result
			// 
			this->Result->Location = System::Drawing::Point(106, 118);
			this->Result->Name = L"Result";
			this->Result->ReadOnly = true;
			this->Result->Size = System::Drawing::Size(140, 20);
			this->Result->TabIndex = 5;
			// 
			// SecondOperand
			// 
			this->SecondOperand->Location = System::Drawing::Point(106, 68);
			this->SecondOperand->Name = L"SecondOperand";
			this->SecondOperand->Size = System::Drawing::Size(140, 20);
			this->SecondOperand->TabIndex = 4;
			// 
			// FirstOperand
			// 
			this->FirstOperand->Location = System::Drawing::Point(106, 18);
			this->FirstOperand->Name = L"FirstOperand";
			this->FirstOperand->Size = System::Drawing::Size(140, 20);
			this->FirstOperand->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(8, 122);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Result";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 71);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Second Operand";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"First Operand";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->operationToolStripMenuItem, 
				this->exitToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(390, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// operationToolStripMenuItem
			// 
			this->operationToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->addToolStripMenuItem, 
				this->subtractToolStripMenuItem, this->multiplyToolStripMenuItem, this->divideToolStripMenuItem});
			this->operationToolStripMenuItem->Name = L"operationToolStripMenuItem";
			this->operationToolStripMenuItem->Size = System::Drawing::Size(72, 20);
			this->operationToolStripMenuItem->Text = L"&Operation";
			// 
			// addToolStripMenuItem
			// 
			this->addToolStripMenuItem->Name = L"addToolStripMenuItem";
			this->addToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->addToolStripMenuItem->Text = L"&Add";
			this->addToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::Add);
			// 
			// subtractToolStripMenuItem
			// 
			this->subtractToolStripMenuItem->Name = L"subtractToolStripMenuItem";
			this->subtractToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->subtractToolStripMenuItem->Text = L"&Subtract";
			this->subtractToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::Sub);
			// 
			// multiplyToolStripMenuItem
			// 
			this->multiplyToolStripMenuItem->Name = L"multiplyToolStripMenuItem";
			this->multiplyToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->multiplyToolStripMenuItem->Text = L"&Multiply";
			this->multiplyToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::Mul);
			// 
			// divideToolStripMenuItem
			// 
			this->divideToolStripMenuItem->Name = L"divideToolStripMenuItem";
			this->divideToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->divideToolStripMenuItem->Text = L"&Divide";
			this->divideToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::Div);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->exitToolStripMenuItem->Text = L"&Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::Exit);
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Controls->Add(this->button8);
			this->panel2->Controls->Add(this->button7);
			this->panel2->Controls->Add(this->button6);
			this->panel2->Controls->Add(this->button5);
			this->panel2->Location = System::Drawing::Point(25, 27);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(135, 45);
			this->panel2->TabIndex = 3;
			// 
			// button8
			// 
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button8->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button8.Image")));
			this->button8->Location = System::Drawing::Point(99, 8);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(30, 30);
			this->button8->TabIndex = 3;
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::Div);
			// 
			// button7
			// 
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button7.Image")));
			this->button7->Location = System::Drawing::Point(67, 8);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(30, 30);
			this->button7->TabIndex = 2;
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::Mul);
			// 
			// button6
			// 
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button6.Image")));
			this->button6->Location = System::Drawing::Point(35, 8);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(30, 30);
			this->button6->TabIndex = 1;
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::Sub);
			// 
			// button5
			// 
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button5.Image")));
			this->button5->Location = System::Drawing::Point(3, 8);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(30, 30);
			this->button5->TabIndex = 0;
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::Add);
			// 
			// button9
			// 
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button9.Image")));
			this->button9->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button9->Location = System::Drawing::Point(287, 41);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(67, 23);
			this->button9->TabIndex = 4;
			this->button9->Text = L"&Exit";
			this->button9->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::Exit);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(390, 267);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Calculator (Nikita Burcena)";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->contextMenuStrip1->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Exit(System::Object^  sender, System::EventArgs^  e) {
				 Close();
			 }
private: System::Void Add(System::Object^  sender, System::EventArgs^  e) {
			 try{
				 Result->Text = Convert::ToString(
					 Convert::ToDouble(FirstOperand->Text) +
					 Convert::ToDouble(SecondOperand->Text)
				);
			 }
			catch(...){
				MessageBox::Show("Error in operands!","Calculator Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		 }
private: System::Void Sub(System::Object^  sender, System::EventArgs^  e) {
			 try{
				 Result->Text = Convert::ToString(
					 Convert::ToDouble(FirstOperand->Text) -
					 Convert::ToDouble(SecondOperand->Text)
				);
			 }
			catch(...){
				MessageBox::Show("Error in operands!","Calculator Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		 }
private: System::Void Mul(System::Object^  sender, System::EventArgs^  e) {
			  try{
				 Result->Text = Convert::ToString(
					 Convert::ToDouble(FirstOperand->Text) *
					 Convert::ToDouble(SecondOperand->Text)
				);
			 }
			catch(...){
				MessageBox::Show("Error in operands!","Calculator Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		 }
private: System::Void Div(System::Object^  sender, System::EventArgs^  e) {
			 try{
				 Result->Text = Convert::ToString(
					 Convert::ToDouble(FirstOperand->Text) /
					 Convert::ToDouble(SecondOperand->Text)
				);
			 }
			catch(...){
				MessageBox::Show("Error in operands!","Calculator Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		 }
};
}

