#pragma once

namespace AshesiMIS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for frmRegisterStudent
	/// </summary>
	public ref class frmRegisterStudent : public System::Windows::Forms::Form
	{
	public:
		frmRegisterStudent(void)
		{
			InitializeComponent();
			LoadUsers();
			LoadProgrammes();
			LoadLevels();
			LoadStudentData();
			//
			//TODO: Add the constructor code here
			//
		}
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		MySqlDataAdapter^ sqlDA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlDR;
		DataTable^ sqlDT = gcnew DataTable();
		String^ ConnectionStr = "server=localhost;port=4306;uid=root;pwd=;database=ahsesimis;";

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmRegisterStudent()
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

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::ComboBox^ cmbSelectUser;
	private: System::Windows::Forms::ComboBox^ cmbLevel;


	private: System::Windows::Forms::ComboBox^ cmbProgramme;

	private: System::Windows::Forms::TextBox^ txtStudentID;
	private: System::Windows::Forms::TextBox^ txtEnrollmentDate;
	private: System::Windows::Forms::CheckBox^ chkStatus;
	private: System::Windows::Forms::Button^ btnRegister;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ txtFind;
	private: System::Windows::Forms::Button^ btnFind;








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
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->cmbSelectUser = (gcnew System::Windows::Forms::ComboBox());
			this->cmbLevel = (gcnew System::Windows::Forms::ComboBox());
			this->cmbProgramme = (gcnew System::Windows::Forms::ComboBox());
			this->txtStudentID = (gcnew System::Windows::Forms::TextBox());
			this->txtEnrollmentDate = (gcnew System::Windows::Forms::TextBox());
			this->chkStatus = (gcnew System::Windows::Forms::CheckBox());
			this->btnRegister = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->txtFind = (gcnew System::Windows::Forms::TextBox());
			this->btnFind = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label1->Location = System::Drawing::Point(31, 49);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(119, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Select User:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(31, 98);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(110, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Student ID:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label3->Location = System::Drawing::Point(31, 154);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(119, 25);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Programme:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(412, 156);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(65, 25);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Level:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label5->Location = System::Drawing::Point(68, 200);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(74, 25);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Status:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label6->Location = System::Drawing::Point(325, 204);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(156, 25);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Enrollment Date:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(338, 9);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(250, 29);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Student Registration";
			// 
			// cmbSelectUser
			// 
			this->cmbSelectUser->FormattingEnabled = true;
			this->cmbSelectUser->Location = System::Drawing::Point(168, 50);
			this->cmbSelectUser->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->cmbSelectUser->Name = L"cmbSelectUser";
			this->cmbSelectUser->Size = System::Drawing::Size(160, 24);
			this->cmbSelectUser->TabIndex = 8;
			// 
			// cmbLevel
			// 
			this->cmbLevel->FormattingEnabled = true;
			this->cmbLevel->Location = System::Drawing::Point(500, 157);
			this->cmbLevel->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->cmbLevel->Name = L"cmbLevel";
			this->cmbLevel->Size = System::Drawing::Size(176, 24);
			this->cmbLevel->TabIndex = 9;
			// 
			// cmbProgramme
			// 
			this->cmbProgramme->FormattingEnabled = true;
			this->cmbProgramme->Location = System::Drawing::Point(167, 155);
			this->cmbProgramme->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->cmbProgramme->Name = L"cmbProgramme";
			this->cmbProgramme->Size = System::Drawing::Size(217, 24);
			this->cmbProgramme->TabIndex = 10;
			this->cmbProgramme->SelectedIndexChanged += gcnew System::EventHandler(this, &frmRegisterStudent::cmbProgramme_SelectedIndexChanged);
			// 
			// txtStudentID
			// 
			this->txtStudentID->Location = System::Drawing::Point(167, 99);
			this->txtStudentID->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtStudentID->Name = L"txtStudentID";
			this->txtStudentID->Size = System::Drawing::Size(201, 23);
			this->txtStudentID->TabIndex = 11;
			// 
			// txtEnrollmentDate
			// 
			this->txtEnrollmentDate->Location = System::Drawing::Point(472, 204);
			this->txtEnrollmentDate->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtEnrollmentDate->Name = L"txtEnrollmentDate";
			this->txtEnrollmentDate->Size = System::Drawing::Size(153, 23);
			this->txtEnrollmentDate->TabIndex = 13;
			// 
			// chkStatus
			// 
			this->chkStatus->AutoSize = true;
			this->chkStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->chkStatus->Location = System::Drawing::Point(167, 200);
			this->chkStatus->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->chkStatus->Name = L"chkStatus";
			this->chkStatus->Size = System::Drawing::Size(88, 29);
			this->chkStatus->TabIndex = 14;
			this->chkStatus->Text = L"Active";
			this->chkStatus->UseVisualStyleBackColor = true;
			// 
			// btnRegister
			// 
			this->btnRegister->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegister->Location = System::Drawing::Point(167, 245);
			this->btnRegister->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btnRegister->Name = L"btnRegister";
			this->btnRegister->Size = System::Drawing::Size(112, 34);
			this->btnRegister->TabIndex = 15;
			this->btnRegister->Text = L"Register";
			this->btnRegister->UseVisualStyleBackColor = true;
			this->btnRegister->Click += gcnew System::EventHandler(this, &frmRegisterStudent::btnRegister_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancel->Location = System::Drawing::Point(351, 249);
			this->btnCancel->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(100, 28);
			this->btnCancel->TabIndex = 16;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &frmRegisterStudent::btnCancel_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(167, 284);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(510, 224);
			this->dataGridView1->TabIndex = 17;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label7->Location = System::Drawing::Point(246, 521);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(181, 25);
			this->label7->TabIndex = 18;
			this->label7->Text = L"Find Student By ID:";
			// 
			// txtFind
			// 
			this->txtFind->Location = System::Drawing::Point(396, 522);
			this->txtFind->Name = L"txtFind";
			this->txtFind->Size = System::Drawing::Size(179, 23);
			this->txtFind->TabIndex = 19;
			// 
			// btnFind
			// 
			this->btnFind->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnFind->Location = System::Drawing::Point(597, 522);
			this->btnFind->Name = L"btnFind";
			this->btnFind->Size = System::Drawing::Size(76, 31);
			this->btnFind->TabIndex = 20;
			this->btnFind->Text = L"Find";
			this->btnFind->UseVisualStyleBackColor = true;
			this->btnFind->Click += gcnew System::EventHandler(this, &frmRegisterStudent::btnFind_Click);
			// 
			// frmRegisterStudent
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(745, 706);
			this->Controls->Add(this->btnFind);
			this->Controls->Add(this->txtFind);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnRegister);
			this->Controls->Add(this->chkStatus);
			this->Controls->Add(this->txtEnrollmentDate);
			this->Controls->Add(this->txtStudentID);
			this->Controls->Add(this->cmbProgramme);
			this->Controls->Add(this->cmbLevel);
			this->Controls->Add(this->cmbSelectUser);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"frmRegisterStudent";
			this->Text = L"frmRegisterStudent";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void cmbProgramme_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}

	   private: System::Void btnRegister_Click(System::Object^ sender, System::EventArgs^ e) {
		   if (cmbSelectUser->SelectedIndex == -1) {
			   MessageBox::Show("Please select a user", "Validation Error",
				   MessageBoxButtons::OK, MessageBoxIcon::Warning);
			   return;
		   }

		   String^ studentID = txtStudentID->Text->Trim();
		   String^ enrollmentDate = txtEnrollmentDate->Text->Trim();

		   if (studentID == "" || enrollmentDate == "") {
			   MessageBox::Show("Please fill all required fields", "Validation Error",
				   MessageBoxButtons::OK, MessageBoxIcon::Warning);
			   return;
		   }

		   if (cmbProgramme->SelectedIndex == -1 || cmbLevel->SelectedIndex == -1) {
			   MessageBox::Show("Please select programme and level", "Validation Error",
				   MessageBoxButtons::OK, MessageBoxIcon::Warning);
			   return;
		   }

		   try {
			   sqlConn->ConnectionString = ConnectionStr;
			   sqlConn->Open();
			   sqlCmd->Connection = sqlConn;

			   // Check if user is already registered as student
			   int userID = Convert::ToInt32(cmbSelectUser->SelectedValue);
			   sqlCmd->CommandText = "SELECT * FROM students WHERE UserID = @userID";
			   sqlCmd->Parameters->Clear();
			   sqlCmd->Parameters->AddWithValue("@userID", userID);
			   sqlDR = sqlCmd->ExecuteReader();

			   if (sqlDR->Read()) {
				   MessageBox::Show("This user is already registered as a student", "Registration Error",
					   MessageBoxButtons::OK, MessageBoxIcon::Warning);
				   sqlDR->Close();
				   sqlConn->Close();
				   return;
			   }
			   sqlDR->Close();

			   // Check if Student ID already exists
			   sqlCmd->CommandText = "SELECT * FROM students WHERE StudentID = @studID";
			   sqlCmd->Parameters->Clear();
			   sqlCmd->Parameters->AddWithValue("@studID", studentID);
			   sqlDR = sqlCmd->ExecuteReader();

			   if (sqlDR->Read()) {
				   MessageBox::Show("Student ID already exists", "Registration Error",
					   MessageBoxButtons::OK, MessageBoxIcon::Warning);
				   sqlDR->Close();
				   sqlConn->Close();
				   return;
			   }
			   sqlDR->Close();

			   // Insert student record
			   int progID = Convert::ToInt32(cmbProgramme->SelectedValue);
			   int level = Convert::ToInt32(cmbLevel->SelectedValue);
			   String^ status = chkStatus->Checked ? "active" : "inactive";

			   sqlCmd->CommandText = "INSERT INTO students(UserID, StudentID, ProgrammeID, Level, status, date_of_enrollment) " +
				   "VALUES (@userID, @studID, @progID, @level, @status, @enrollDate)";
			   sqlCmd->Parameters->Clear();
			   sqlCmd->Parameters->AddWithValue("@userID", userID);
			   sqlCmd->Parameters->AddWithValue("@studID", studentID);
			   sqlCmd->Parameters->AddWithValue("@progID", progID);
			   sqlCmd->Parameters->AddWithValue("@level", level);
			   sqlCmd->Parameters->AddWithValue("@status", status);
			   sqlCmd->Parameters->AddWithValue("@enrollDate", enrollmentDate);
			   sqlCmd->ExecuteNonQuery();

			   // Update user role to Student (role ID = 3)
			   sqlCmd->CommandText = "UPDATE users SET role = 3 WHERE ID = @userID";
			   sqlCmd->Parameters->Clear();
			   sqlCmd->Parameters->AddWithValue("@userID", userID);
			   sqlCmd->ExecuteNonQuery();

			   MessageBox::Show("Student registered successfully", "Success",
				   MessageBoxButtons::OK, MessageBoxIcon::Information);

			   sqlConn->Close();
			   ClearFields();
			   LoadStudentData();
			   
		   }
		   catch (Exception^ ex) {
			   MessageBox::Show("Error: " + ex->Message, "Registration Error",
				   MessageBoxButtons::OK, MessageBoxIcon::Error);
			   if (sqlConn->State == ConnectionState::Open) {
				   sqlConn->Close();
			   }
		   }
	   }

			  void LoadUsers() {
				  try {
					  // Close connection if it's open
					  if (sqlConn->State == ConnectionState::Open) {
						  sqlConn->Close();
					  }

					  sqlConn->ConnectionString = ConnectionStr;
					  sqlConn->Open();

					  // Load users who are not already students
					  MySqlDataAdapter^ da = gcnew MySqlDataAdapter(
						  "SELECT u.ID, CONCAT(u.FirstName, ' ', u.LastName) AS FullName " +
						  "FROM users u LEFT JOIN students s ON u.ID = s.UserID " +
						  "WHERE s.UserID IS NULL", sqlConn);
					  DataTable^ dt = gcnew DataTable();
					  da->Fill(dt);
					  cmbSelectUser->DataSource = dt;
					  cmbSelectUser->DisplayMember = "FullName";
					  cmbSelectUser->ValueMember = "ID";
					  cmbSelectUser->SelectedIndex = -1;
					  sqlConn->Close();
				  }
				  catch (Exception^ ex) {
					  MessageBox::Show("Error loading users: " + ex->Message, "Error",
						  MessageBoxButtons::OK, MessageBoxIcon::Error);
					  if (sqlConn->State == ConnectionState::Open) {
						  sqlConn->Close();
					  }
				  }
			  }

			  void LoadProgrammes() {
				  try {
					  if (sqlConn->State == ConnectionState::Open) {
						  sqlConn->Close();
					  }
					  sqlConn->ConnectionString = ConnectionStr;
					  sqlConn->Open();
					  MySqlDataAdapter^ da = gcnew MySqlDataAdapter(
						  "SELECT ID, Programme FROM programmes", sqlConn);
					  DataTable^ dt = gcnew DataTable();
					  da->Fill(dt);
					  cmbProgramme->DataSource = dt;
					  cmbProgramme->DisplayMember = "Programme";
					  cmbProgramme->ValueMember = "ID";
					  cmbProgramme->SelectedIndex = -1;
					  sqlConn->Close();
				  }
				  catch (Exception^ ex) {
					  MessageBox::Show("Error loading programmes: " + ex->Message, "Error",
						  MessageBoxButtons::OK, MessageBoxIcon::Error);
				  }
			  }

			  void LoadLevels() {
				  DataTable^ dt = gcnew DataTable();
				  dt->Columns->Add("LevelValue", int::typeid);
				  dt->Columns->Add("LevelName", String::typeid);

				  dt->Rows->Add(100, "Level 100");
				  dt->Rows->Add(200, "Level 200");
				  dt->Rows->Add(300, "Level 300");
				  dt->Rows->Add(400, "Level 400");
				  dt->Rows->Add(500, "Level 500");
				  dt->Rows->Add(600, "Level 600");
				  dt->Rows->Add(600, "Level 700");

				  cmbLevel->DataSource = dt;
				  cmbLevel->DisplayMember = "LevelName";
				  cmbLevel->ValueMember = "LevelValue";
				  cmbLevel->SelectedIndex = -1;
			  }

			  void ClearFields() {
				  cmbSelectUser->SelectedIndex = -1;
				  txtStudentID->Text = "";
				  cmbProgramme->SelectedIndex = -1;
				  cmbLevel->SelectedIndex = -1;
				  txtEnrollmentDate->Text = "";
				  chkStatus->Checked = true;
				  LoadUsers(); 
				  LoadStudentData();
			  }

			  private: System::Void btnFind_Click(System::Object^ sender, System::EventArgs^ e) {
				  String^ studentID = txtFind->Text->Trim();
				  if (studentID == "") {
					  MessageBox::Show("Please enter a Student ID", "Find Error",
						  MessageBoxButtons::OK, MessageBoxIcon::Warning);
					  return;
				  }

				  try {
					  // Search for the student in the DataGridView
					  bool found = false;
					  for (int i = 0; i < dataGridView1->Rows->Count; i++) {
						  DataGridViewRow^ row = dataGridView1->Rows[i];
						  if (row->Cells["StudentID"]->Value != nullptr &&
							  row->Cells["StudentID"]->Value->ToString()->Equals(studentID, StringComparison::OrdinalIgnoreCase)) {

							  // Clear previous selections
							  dataGridView1->ClearSelection();

							  // Select and highlight the found row
							  row->Selected = true;

							  // Scroll to make the row visible
							  dataGridView1->FirstDisplayedScrollingRowIndex = i;

							  found = true;
							  MessageBox::Show("Student found and highlighted", "Search Result",
								  MessageBoxButtons::OK, MessageBoxIcon::Information);
							  break;
						  }
					  }

					  if (!found) {
						  MessageBox::Show("Student with ID '" + studentID + "' not found", "Search Result",
							  MessageBoxButtons::OK, MessageBoxIcon::Information);
					  }
				  }
				  catch (Exception^ ex) {
					  MessageBox::Show("Error: " + ex->Message, "Error",
						  MessageBoxButtons::OK, MessageBoxIcon::Error);
				  }
			  }
					 void LoadStudentData() {
						 try {
							 if (sqlConn->State == ConnectionState::Open) {
								 sqlConn->Close();
							 }
							 sqlConn->ConnectionString = ConnectionStr;
							 sqlConn->Open();
							 sqlDT->Clear();
							 MySqlDataAdapter^ da = gcnew MySqlDataAdapter(
								 "SELECT s.ID, s.StudentID, u.FirstName, u.LastName, u.Email, " +
								 "p.Programme, s.Level, s.status, s.date_of_enrollment " +
								 "FROM students s " +
								 "INNER JOIN users u ON s.UserID = u.ID " +
								 "INNER JOIN programmes p ON s.ProgrammeID = p.ID " +
								 "ORDER BY s.ID DESC", sqlConn);
							 da->Fill(sqlDT);
							 dataGridView1->DataSource = sqlDT;
							 sqlConn->Close();
						 }
						 catch (Exception^ ex) {
							 MessageBox::Show("Error loading student data: " + ex->Message, "Error",
								 MessageBoxButtons::OK, MessageBoxIcon::Error);
							 if (sqlConn->State == ConnectionState::Open) {
								 sqlConn->Close();
							 }
						 }
					 }
};
}
