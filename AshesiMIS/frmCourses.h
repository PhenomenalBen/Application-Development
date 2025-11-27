#pragma once
#include "User.h"
namespace AshesiMIS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for frmCourses
	/// </summary>
	public ref class frmCourses : public System::Windows::Forms::Form
	{
	public:
		frmCourses(void)
		{
			InitializeComponent();
			LoadProgrammes();
			LoadData();
			//
			//TODO: Add the constructor code here
			//
			

		}
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		MySqlDataAdapter^ sqlDA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlDR;
		DataTable^ sqlDT = gcnew DataTable();
		// fixed connection string quoting and formatting
		String^ ConnectionStr = "server=localhost;port=3307;uid=root;pwd=;database=ahsesimis;";
		int globalCourseID = 0;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmCourses()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::ComboBox^ cmbProgramme;
	private: System::Windows::Forms::ComboBox^ cmbLevel;
	private: System::Windows::Forms::ComboBox^ cmbSemester;
	private: System::Windows::Forms::TextBox^ txtCourseCode;
	private: System::Windows::Forms::TextBox^ txtCourseTitle;
	private: System::Windows::Forms::ComboBox^ cmbCourseCredit;

	private: System::Windows::Forms::Button^ btnUpdate;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::Button^ btnCancel;



	private: System::Windows::Forms::Button^ btnSave;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ btnFind;
	private: System::Windows::Forms::TextBox^ txtBox1;


	private: System::Windows::Forms::DataGridView^ dataGridView1;








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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->cmbProgramme = (gcnew System::Windows::Forms::ComboBox());
			this->cmbLevel = (gcnew System::Windows::Forms::ComboBox());
			this->cmbSemester = (gcnew System::Windows::Forms::ComboBox());
			this->txtCourseCode = (gcnew System::Windows::Forms::TextBox());
			this->txtCourseTitle = (gcnew System::Windows::Forms::TextBox());
			this->cmbCourseCredit = (gcnew System::Windows::Forms::ComboBox());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->btnFind = (gcnew System::Windows::Forms::Button());
			this->txtBox1 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label1->Location = System::Drawing::Point(12, 62);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(119, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Programme:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(12, 149);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(96, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Semester";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label3->Location = System::Drawing::Point(12, 98);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 25);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Level:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label4->Location = System::Drawing::Point(12, 197);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(129, 25);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Course Code";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label5->Location = System::Drawing::Point(12, 238);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(124, 25);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Course Title:";
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label6->Location = System::Drawing::Point(214, 9);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(236, 29);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Programme Courses";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label7->Location = System::Drawing::Point(12, 280);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(149, 25);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Course Credits:";
			// 
			// cmbProgramme
			// 
			this->cmbProgramme->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbProgramme->FormattingEnabled = true;
			this->cmbProgramme->Location = System::Drawing::Point(166, 66);
			this->cmbProgramme->Name = L"cmbProgramme";
			this->cmbProgramme->Size = System::Drawing::Size(304, 24);
			this->cmbProgramme->TabIndex = 7;
			// 
			// cmbLevel
			// 
			this->cmbLevel->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbLevel->FormattingEnabled = true;
			this->cmbLevel->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"100", L"200", L"300", L"400", L"500", L"600",
					L"700"
			});
			this->cmbLevel->Location = System::Drawing::Point(166, 102);
			this->cmbLevel->Name = L"cmbLevel";
			this->cmbLevel->Size = System::Drawing::Size(195, 24);
			this->cmbLevel->TabIndex = 8;
			// 
			// cmbSemester
			// 
			this->cmbSemester->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbSemester->FormattingEnabled = true;
			this->cmbSemester->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"First Semester", L"Second Semester" });
			this->cmbSemester->Location = System::Drawing::Point(166, 149);
			this->cmbSemester->Name = L"cmbSemester";
			this->cmbSemester->Size = System::Drawing::Size(195, 24);
			this->cmbSemester->TabIndex = 9;
			// 
			// txtCourseCode
			// 
			this->txtCourseCode->Location = System::Drawing::Point(167, 200);
			this->txtCourseCode->Name = L"txtCourseCode";
			this->txtCourseCode->Size = System::Drawing::Size(194, 22);
			this->txtCourseCode->TabIndex = 10;
			// 
			// txtCourseTitle
			// 
			this->txtCourseTitle->Location = System::Drawing::Point(167, 242);
			this->txtCourseTitle->Name = L"txtCourseTitle";
			this->txtCourseTitle->Size = System::Drawing::Size(370, 22);
			this->txtCourseTitle->TabIndex = 11;
			// 
			// cmbCourseCredit
			// 
			this->cmbCourseCredit->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbCourseCredit->FormattingEnabled = true;
			this->cmbCourseCredit->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"1", L"2", L"3", L"4" });
			this->cmbCourseCredit->Location = System::Drawing::Point(167, 284);
			this->cmbCourseCredit->Name = L"cmbCourseCredit";
			this->cmbCourseCredit->Size = System::Drawing::Size(121, 24);
			this->cmbCourseCredit->TabIndex = 12;
			// 
			// btnUpdate
			// 
			this->btnUpdate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnUpdate->Location = System::Drawing::Point(268, 334);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(108, 38);
			this->btnUpdate->TabIndex = 13;
			this->btnUpdate->Text = L"Update";
			this->btnUpdate->UseVisualStyleBackColor = true;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &frmCourses::btnUpdate_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnDelete->Location = System::Drawing::Point(382, 334);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(88, 38);
			this->btnDelete->TabIndex = 14;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &frmCourses::btnDelete_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnCancel->Location = System::Drawing::Point(490, 334);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(97, 38);
			this->btnCancel->TabIndex = 15;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &frmCourses::btnCancel_Click);
			// 
			// btnSave
			// 
			this->btnSave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnSave->Location = System::Drawing::Point(167, 334);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(86, 38);
			this->btnSave->TabIndex = 16;
			this->btnSave->Text = L"Save";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &frmCourses::btnSave_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label8->Location = System::Drawing::Point(181, 596);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(125, 25);
			this->label8->TabIndex = 17;
			this->label8->Text = L"Find Course:";
			// 
			// btnFind
			// 
			this->btnFind->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnFind->Location = System::Drawing::Point(567, 591);
			this->btnFind->Name = L"btnFind";
			this->btnFind->Size = System::Drawing::Size(75, 33);
			this->btnFind->TabIndex = 18;
			this->btnFind->Text = L"Find";
			this->btnFind->UseVisualStyleBackColor = true;
			this->btnFind->Click += gcnew System::EventHandler(this, &frmCourses::btnFind_Click);
			// 
			// txtBox1
			// 
			this->txtBox1->Location = System::Drawing::Point(349, 599);
			this->txtBox1->Name = L"txtBox1";
			this->txtBox1->Size = System::Drawing::Size(198, 22);
			this->txtBox1->TabIndex = 19;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(166, 395);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(420, 160);
			this->dataGridView1->TabIndex = 20;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &frmCourses::dataGridView1_CellClick);
			// 
			// frmCourses
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(975, 654);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->txtBox1);
			this->Controls->Add(this->btnFind);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnUpdate);
			this->Controls->Add(this->cmbCourseCredit);
			this->Controls->Add(this->txtCourseTitle);
			this->Controls->Add(this->txtCourseCode);
			this->Controls->Add(this->cmbSemester);
			this->Controls->Add(this->cmbLevel);
			this->Controls->Add(this->cmbProgramme);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"frmCourses";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"frmCourses";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void LoadProgrammes()
		{
			try {
				if (sqlConn->State == ConnectionState::Open) {
					sqlConn->Close();
				}
				sqlConn->ConnectionString = ConnectionStr;
				sqlConn->Open();
				sqlCmd->Connection = sqlConn;
				sqlCmd->CommandText = "SELECT ID, Programme FROM programmes ORDER BY Programme";
				MySqlDataReader^ reader = sqlCmd->ExecuteReader();
				cmbProgramme->Items->Clear();
				while (reader->Read()) {
					cmbProgramme->Items->Add(reader["ID"]->ToString() + " - " + reader["Programme"]->ToString());
				}
				reader->Close();
				sqlConn->Close();
			}
			catch (Exception^ e) {
				MessageBox::Show("Error loading programmes: " + e->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		void LoadData()
		{
			try {
				if (sqlConn->State == ConnectionState::Open) {
					sqlConn->Close();
				}
				sqlConn->ConnectionString = ConnectionStr;
				sqlConn->Open();
				DataTable^ dt = gcnew DataTable();
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT c.*, p.Programme FROM courses c INNER JOIN programmes p ON c.Programme = p.ID ORDER BY c.ID DESC", sqlConn);
				da->Fill(dt);
				dataGridView1->DataSource = dt;
				sqlConn->Close();
			}
			catch (Exception^ e) {
				MessageBox::Show("Error loading data: " + e->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
#pragma region Event Handlers
private:
	System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
		if (cmbProgramme->SelectedIndex == -1 || cmbLevel->SelectedIndex == -1 ||
			cmbSemester->SelectedIndex == -1 || txtCourseCode->Text->Trim() == "" ||
			txtCourseTitle->Text->Trim() == "" || cmbCourseCredit->SelectedIndex == -1) {
			MessageBox::Show("Please fill all fields", "Validation Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->Parameters->Clear();

			// Extract programme ID from combobox
			String^ programmeText = cmbProgramme->SelectedItem->ToString();
			int programmeID = Convert::ToInt32(programmeText->Split('-')[0]->Trim());

			sqlCmd->CommandText = "INSERT INTO courses (Programme, Level, Semester, CourseCode, CourseTitle, CourseCredit) VALUES (@programme, @level, @semester, @coursecode, @coursetitle, @coursecredit)";
			sqlCmd->Parameters->AddWithValue("@programme", programmeID);
			sqlCmd->Parameters->AddWithValue("@level", Convert::ToInt32(cmbLevel->SelectedItem->ToString()));
			sqlCmd->Parameters->AddWithValue("@semester", cmbSemester->SelectedItem->ToString());
			sqlCmd->Parameters->AddWithValue("@coursecode", txtCourseCode->Text);
			sqlCmd->Parameters->AddWithValue("@coursetitle", txtCourseTitle->Text);
			sqlCmd->Parameters->AddWithValue("@coursecredit", Convert::ToInt32(cmbCourseCredit->SelectedItem->ToString()));

			sqlCmd->ExecuteNonQuery();
			MessageBox::Show("Course saved successfully", "Success",
				MessageBoxButtons::OK, MessageBoxIcon::Information);

			LoadData();
			ClearFields();
			sqlConn->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error saving course: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
		if (globalCourseID == 0) {
			MessageBox::Show("No course selected for update", "Validation Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->Parameters->Clear();

			String^ programmeText = cmbProgramme->SelectedItem->ToString();
			int programmeID = Convert::ToInt32(programmeText->Split('-')[0]->Trim());

			sqlCmd->CommandText = "UPDATE courses SET Programme=@programme, Level=@level, Semester=@semester, CourseCode=@coursecode, CourseTitle=@coursetitle, CourseCredit=@coursecredit WHERE ID=@id";
			sqlCmd->Parameters->AddWithValue("@programme", programmeID);
			sqlCmd->Parameters->AddWithValue("@level", Convert::ToInt32(cmbLevel->SelectedItem->ToString()));
			sqlCmd->Parameters->AddWithValue("@semester", cmbSemester->SelectedItem->ToString());
			sqlCmd->Parameters->AddWithValue("@coursecode", txtCourseCode->Text);
			sqlCmd->Parameters->AddWithValue("@coursetitle", txtCourseTitle->Text);
			sqlCmd->Parameters->AddWithValue("@coursecredit", Convert::ToInt32(cmbCourseCredit->SelectedItem->ToString()));
			sqlCmd->Parameters->AddWithValue("@id", globalCourseID);

			sqlCmd->ExecuteNonQuery();
			MessageBox::Show("Course updated successfully", "Success",
				MessageBoxButtons::OK, MessageBoxIcon::Information);

			LoadData();
			ClearFields();
			sqlConn->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error updating course: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		if (globalCourseID == 0) {
			MessageBox::Show("No course selected for deletion", "Validation Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		if (MessageBox::Show("Are you sure you want to delete this course?", "Confirm Delete",
			MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		{
			try {
				if (sqlConn->State == ConnectionState::Open) {
					sqlConn->Close();
				}
				sqlConn->ConnectionString = ConnectionStr;
				sqlConn->Open();
				sqlCmd->Connection = sqlConn;
				sqlCmd->Parameters->Clear();
				sqlCmd->CommandText = "DELETE FROM courses WHERE ID=@id";
				sqlCmd->Parameters->AddWithValue("@id", globalCourseID);

				sqlCmd->ExecuteNonQuery();
				MessageBox::Show("Course deleted successfully", "Success",
					MessageBoxButtons::OK, MessageBoxIcon::Information);

				LoadData();
				ClearFields();
				sqlConn->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error deleting course: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
	System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

    System::Void btnFind_Click(System::Object^ sender, System::EventArgs^ e) {

		int courseID = Convert::ToInt32(txtBox1->Text->Trim());
		if (courseID <= 0) {
			MessageBox::Show("Please enter a valid Course ID.", "Data Entry Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "SELECT * FROM Courses WHERE ID = @courseID";
			sqlCmd->Parameters->AddWithValue("@courseID", courseID);
			sqlDR = sqlCmd->ExecuteReader();

			if (sqlDR->Read()) {
				txtCourseTitle->Text = sqlDR["CourseTitle"]->ToString();

				globalCourseID = Convert::ToInt32(sqlDR["ID"]);
				sqlDT->Load(sqlDR);

				sqlDR->Close();
				dataGridView1->DataSource = nullptr;
				dataGridView1->DataSource = sqlDT;

				// Optional: Adjust column widths
				dataGridView1->Columns[0]->Width = 50;
				dataGridView1->Columns[1]->Width = 300;

				sqlCmd->Cancel();
				sqlConn->Close();
			}
			else {
				MessageBox::Show("The Course ID does not exist.", "Data Entry Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				sqlDR->Close();
				sqlCmd->Cancel();
				sqlConn->Close();
			}
		}
		catch (Exception^ e) {
			MessageBox::Show("Database Connection Error: " + e->ToString(), "Data Entry Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			sqlDR->Close();
			sqlCmd->Cancel();
			sqlConn->Close();
			return;
		}
	}


	System::Void dataGridView1_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0) {
			DataGridViewRow^ row = dataGridView1->Rows[e->RowIndex];
			globalCourseID = Convert::ToInt32(row->Cells["ID"]->Value);

			// Set programme
			String^ programmeInfo = row->Cells["Programme"]->Value->ToString();
			for (int i = 0; i < cmbProgramme->Items->Count; i++) {
				if (cmbProgramme->Items[i]->ToString()->Contains(programmeInfo)) {
					cmbProgramme->SelectedIndex = i;
					break;
				}
			}

			cmbLevel->SelectedItem = row->Cells["Level"]->Value->ToString();
			cmbSemester->SelectedItem = row->Cells["Semester"]->Value->ToString();
			txtCourseCode->Text = row->Cells["CourseCode"]->Value->ToString();
			txtCourseTitle->Text = row->Cells["CourseTitle"]->Value->ToString();
			cmbCourseCredit->SelectedItem = row->Cells["CourseCredit"]->Value->ToString();
		}
	}
#pragma endregion
	void ClearFields()
	{
		globalCourseID = 0;
		cmbProgramme->SelectedIndex = -1;
		cmbLevel->SelectedIndex = -1;
		cmbSemester->SelectedIndex = -1;
		txtCourseCode->Clear();
		txtCourseTitle->Clear();
		cmbCourseCredit->SelectedIndex = -1;
		txtBox1->Clear();
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}



	};
}
