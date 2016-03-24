#pragma once
#include <iostream>
#include <string>
#include "Mzda.h"
using namespace std;

namespace pkrim {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  hruba_mzda;
	private: System::Windows::Forms::TextBox^  cista_mzda;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->hruba_mzda = (gcnew System::Windows::Forms::TextBox());
			this->cista_mzda = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(50, 114);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(186, 33);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Vypoèítaj èistú mzdu";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// hruba_mzda
			// 
			this->hruba_mzda->Location = System::Drawing::Point(50, 42);
			this->hruba_mzda->Name = L"hruba_mzda";
			this->hruba_mzda->Size = System::Drawing::Size(186, 20);
			this->hruba_mzda->TabIndex = 1;
			this->hruba_mzda->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// cista_mzda
			// 
			this->cista_mzda->Location = System::Drawing::Point(52, 203);
			this->cista_mzda->Name = L"cista_mzda";
			this->cista_mzda->Size = System::Drawing::Size(184, 20);
			this->cista_mzda->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(50, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(205, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Hrubá mzda zatial davaj ciarku nie bodku ";
			this->label1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(50, 174);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Èistá mzda";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cista_mzda);
			this->Controls->Add(this->hruba_mzda);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		try{
			try{
				double hrubaDobule = Convert::ToDouble(hruba_mzda->Text);
				Mzda *m = new Mzda(hrubaDobule);
				m->calculate();
				/*double poistne = hrubaDobule * 0.134;
				double ciastkovyZakladDane = hrubaDobule - poistne;
				double nezanitelnaCast = 316.94;
				double zdanitelnaMzda = ciastkovyZakladDane - nezanitelnaCast;
				double dan = zdanitelnaMzda * 0.19;
				double cistaMzda = hrubaDobule - poistne - dan;*/

				cista_mzda->Text = Convert::ToString(m->getCistaMzda());

			}catch(FormatException^ ex){
				MessageBox::Show("FormatException Occured.  Message: " + ex->Message);
				throw;
			}
			catch(OverflowException^ ex){
				MessageBox::Show("Overflow Occured. Message: " + ex->Message);
				throw;
			}
		}catch(Exception^ ex){
			MessageBox::Show("tomas testuje");
		}

				 
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {

			 }
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}
