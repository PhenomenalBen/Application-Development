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
	/// Summary for frmRegisterFaculty
	/// </summary>
	public ref class frmRegisterFaculty : public System::Windows::Forms::Form
	{
	public:
		frmRegisterFaculty(void)
		{
			InitializeComponent();
			LoadUsers();
			LoadDepartments();
			LoadPositions();
			//
			//TODO: Add the constructor code here
			//
		}
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		MySqlDataAdapter^ sqlDA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlDR;
		String^ ConnectionStr = "server=localhost;port=4306;uid=root;pwd=;database=ahsesimis;";

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmRegisterFaculty()
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
	private: System::Windows::Forms::CheckBox^ chkStatus;
	private: System::Windows::Forms::ComboBox^ cmbDepartment;



	private: System::Windows::Forms::ComboBox^ cmbPosition;
	private: System::Windows::Forms::ComboBox^ cmbSelectUser;


	private: System::Windows::Forms::TextBox^ txtFacultyID;

	private: System::Windows::Forms::TextBox^ txtHireDate;


	private: System::Windows::Forms::Button^ btnRegister;
	private: System::Windows::Forms::Button^ btnCancel;








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
			this->chkStatus = (gcnew System::Windows::Forms::CheckBox());
			this->cmbDepartment = (gcnew System::Windows::Forms::ComboBox());
			this->cmbPosition = (gcnew System::Windows::Forms::ComboBox());
			this->cmbSelectUser = (gcnew System::Windows::Forms::ComboBox());
			this->txtFacultyID = (gcnew System::Windows::Forms::TextBox());
			this->txtHireDate = (gcnew System::Windows::Forms::TextBox());
			this->btnRegister = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(292, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(244, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Faculty Registration";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(60, 79);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Select User:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label3->Location = System::Drawing::Point(60, 156);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(105, 25);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Faculty ID:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label4->Location = System::Drawing::Point(60, 216);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(119, 25);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Department:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label5->Location = System::Drawing::Point(60, 269);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(87, 25);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Position:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label6->Location = System::Drawing::Point(60, 318);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(99, 25);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Hire Date:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label7->Location = System::Drawing::Point(105, 383);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(74, 25);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Status:";
			// 
			// chkStatus
			// 
			this->chkStatus->AutoSize = true;
			this->chkStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->chkStatus->Location = System::Drawing::Point(206, 379);
			this->chkStatus->Name = L"chkStatus";
			this->chkStatus->Size = System::Drawing::Size(88, 29);
			this->chkStatus->TabIndex = 8;
			this->chkStatus->Text = L"Active";
			this->chkStatus->UseVisualStyleBackColor = true;
			// 
			// cmbDepartment
			// 
			this->cmbDepartment->FormattingEnabled = true;
			this->cmbDepartment->Location = System::Drawing::Point(206, 217);
			this->cmbDepartment->Name = L"cmbDepartment";
			this->cmbDepartment->Size = System::Drawing::Size(378, 24);
			this->cmbDepartment->TabIndex = 9;
			// 
			// cmbPosition
			// 
			this->cmbPosition->FormattingEnabled = true;
			this->cmbPosition->Location = System::Drawing::Point(206, 269);
			this->cmbPosition->Name = L"cmbPosition";
			this->cmbPosition->Size = System::Drawing::Size(378, 24);
			this->cmbPosition->TabIndex = 10;
			// 
			// cmbSelectUser
			// 
			this->cmbSelectUser->FormattingEnabled = true;
			this->cmbSelectUser->Location = System::Drawing::Point(206, 79);
			this->cmbSelectUser->Name = L"cmbSelectUser";
			this->cmbSelectUser->Size = System::Drawing::Size(203, 24);
			this->cmbSelectUser->TabIndex = 11;
			// 
			// txtFacultyID
			// 
			this->txtFacultyID->Location = System::Drawing::Point(206, 159);
			this->txtFacultyID->Name = L"txtFacultyID";
			this->txtFacultyID->Size = System::Drawing::Size(203, 22);
			this->txtFacultyID->TabIndex = 12;
			// 
			// txtHireDate
			// 
			this->txtHireDate->Location = System::Drawing::Point(206, 322);
			this->txtHireDate->Name = L"txtHireDate";
			this->txtHireDate->Size = System::Drawing::Size(203, 22);
			this->txtHireDate->TabIndex = 14;
			// 
			// btnRegister
			// 
			this->btnRegister->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegister->Location = System::Drawing::Point(206, 501);
			this->btnRegister->Name = L"btnRegister";
			this->btnRegister->Size = System::Drawing::Size(135, 33);
			this->btnRegister->TabIndex = 15;
			this->btnRegister->Text = L"Register";
			this->btnRegister->UseVisualStyleBackColor = true;
			this->btnRegister->Click += gcnew System::EventHandler(this, &frmRegisterFaculty::btnRegister_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancel->Location = System::Drawing::Point(451, 501);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(117, 33);
			this->btnCancel->TabIndex = 16;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &frmRegisterFaculty::btnCancel_Click);
			// 
			// frmRegisterFaculty
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->ClientSize = System::Drawing::Size(853, 731);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnRegister);
			this->Controls->Add(this->txtHireDate);
			this->Controls->Add(this->txtFacultyID);
			this->Controls->Add(this->cmbSelectUser);
			this->Controls->Add(this->cmbPosition);
			this->Controls->Add(this->cmbDepartment);
			this->Controls->Add(this->chkStatus);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"frmRegisterFaculty";
			this->Text = L"frmRegisterFaculty";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void btnRegister_Click(System::Object^ sender, System::EventArgs^ e) {
		if (cmbSelectUser->SelectedIndex == -1) {
			MessageBox::Show("Please select a user", "Validation Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		String^ facultyID = txtFacultyID->Text->Trim();
		String^ hireDate = txtHireDate->Text->Trim();

		if (facultyID == "" || hireDate == "") {
			MessageBox::Show("Please fill all required fields", "Validation Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		if (cmbDepartment->SelectedIndex == -1 || cmbPosition->SelectedIndex == -1) {
			MessageBox::Show("Please select department and position", "Validation Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;

			// Check if user is already registered as faculty
			int userID = Convert::ToInt32(cmbSelectUser->SelectedValue);
			sqlCmd->CommandText = "SELECT * FROM faculty WHERE UserID = @userID";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@userID", userID);
			sqlDR = sqlCmd->ExecuteReader();

			if (sqlDR->Read()) {
				MessageBox::Show("This user is already registered as faculty", "Registration Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				sqlDR->Close();
				sqlConn->Close();
				return;
			}
			sqlDR->Close();

			// Check if Faculty ID already exists
			sqlCmd->CommandText = "SELECT * FROM faculty WHERE FacultyID = @facID";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@facID", facultyID);
			sqlDR = sqlCmd->ExecuteReader();

			if (sqlDR->Read()) {
				MessageBox::Show("Faculty ID already exists", "Registration Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				sqlDR->Close();
				sqlConn->Close();
				return;
			}
			sqlDR->Close();

			// Insert faculty record
			int deptID = Convert::ToInt32(cmbDepartment->SelectedValue);
			String^ position = cmbPosition->Text;
			String^ status = chkStatus->Checked ? "active" : "inactive";

			sqlCmd->CommandText = "INSERT INTO faculty(UserID, DepartmentID, FacultyID, Position, status, hire_date) " +
				"VALUES (@userID, @deptID, @facID, @position, @status, @hireDate)";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@userID", userID);
			sqlCmd->Parameters->AddWithValue("@deptID", deptID);
			sqlCmd->Parameters->AddWithValue("@facID", facultyID);
			sqlCmd->Parameters->AddWithValue("@position", position);
			sqlCmd->Parameters->AddWithValue("@status", status);
			sqlCmd->Parameters->AddWithValue("@hireDate", hireDate);
			sqlCmd->ExecuteNonQuery();

			// Update user role to Faculty (role ID = 2)
			sqlCmd->CommandText = "UPDATE users SET role = 2 WHERE ID = @userID";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@userID", userID);
			sqlCmd->ExecuteNonQuery();

			MessageBox::Show("Faculty registered successfully", "Success",
				MessageBoxButtons::OK, MessageBoxIcon::Information);

			sqlConn->Close();
			ClearFields();
			
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message, "Registration Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
		}
	}

		void LoadDepartments() {
			try {
				if (sqlConn->State == ConnectionState::Open) {
					sqlConn->Close();
				}
				sqlConn->ConnectionString = ConnectionStr;
				sqlConn->Open();
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT ID, Department FROM department", sqlConn);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);
				cmbDepartment->DataSource = dt;
				cmbDepartment->DisplayMember = "Department";
				cmbDepartment->ValueMember = "ID";
				cmbDepartment->SelectedIndex = -1;
				sqlConn->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error loading departments: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
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

				// Load users who are not already faculty
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(
					"SELECT u.ID, CONCAT(u.FirstName, ' ', u.LastName) AS FullName " +
					"FROM users u LEFT JOIN faculty f ON u.ID = f.UserID " +
					"WHERE f.UserID IS NULL", sqlConn);
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

		void LoadPositions() {
			cmbPosition->Items->Clear();
			cmbPosition->Items->Add("Professor");
			cmbPosition->Items->Add("Associate Professor");
			cmbPosition->Items->Add("Assistant Professor");
			cmbPosition->Items->Add("Lecturer");
			cmbPosition->Items->Add("Senior Lecturer");
			cmbPosition->Items->Add("Instructor");
		}

		void ClearFields() {
			cmbSelectUser->SelectedIndex = -1;
			txtFacultyID->Text = "";
			cmbDepartment->SelectedIndex = -1;
			cmbPosition->SelectedIndex = -1;
			txtHireDate->Text = "";
			chkStatus->Checked = true;
			LoadUsers(); // Refresh user list
		}

		
};
}
