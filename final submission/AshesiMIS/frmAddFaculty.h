#pragma once

namespace AshesiMIS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	public ref class frmAddFaculty : public System::Windows::Forms::Form
	{
	public:
		frmAddFaculty(void)
		{
			InitializeComponent();
			LoadDepartments();
			LoadPositions();
			LoadFacultyData();
		}

		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		MySqlDataAdapter^ sqlDA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlDR;
		DataTable^ sqlDT = gcnew DataTable();
		String^ ConnectionStr = "server=localhost;port=4306;uid=root;pwd=;database=ahsesimis;";
		int globalFacultyID = 0;

	protected:
		~frmAddFaculty()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ cmbDepartment;
	private: System::Windows::Forms::ComboBox^ cmbPosition;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::TextBox^ txtEmail;
	private: System::Windows::Forms::TextBox^ txtFacultyID;
	private: System::Windows::Forms::TextBox^ txtLastName;
	private: System::Windows::Forms::TextBox^ txtFirstName;
	private: System::Windows::Forms::TextBox^ txtFind;
	private: System::Windows::Forms::Button^ btnSave;
	private: System::Windows::Forms::Button^ btnUpdate;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::Button^ btnFind;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->cmbDepartment = (gcnew System::Windows::Forms::ComboBox());
			this->cmbPosition = (gcnew System::Windows::Forms::ComboBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->txtEmail = (gcnew System::Windows::Forms::TextBox());
			this->txtFacultyID = (gcnew System::Windows::Forms::TextBox());
			this->txtLastName = (gcnew System::Windows::Forms::TextBox());
			this->txtFirstName = (gcnew System::Windows::Forms::TextBox());
			this->txtFind = (gcnew System::Windows::Forms::TextBox());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnFind = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(364, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(89, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Faculty";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(12, 47);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(105, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Faculty ID:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label3->Location = System::Drawing::Point(12, 92);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(112, 25);
			this->label3->TabIndex = 2;
			this->label3->Text = L"First Name:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label4->Location = System::Drawing::Point(12, 129);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(112, 25);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Last Name:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label5->Location = System::Drawing::Point(12, 172);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(66, 25);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Email:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label6->Location = System::Drawing::Point(12, 234);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(119, 25);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Department:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 250);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 16);
			this->label7->TabIndex = 6;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label8->Location = System::Drawing::Point(14, 291);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(87, 25);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Position:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label9->Location = System::Drawing::Point(222, 625);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(157, 25);
			this->label9->TabIndex = 8;
			this->label9->Text = L"Find Faculty(ID):";
			// 
			// cmbDepartment
			// 
			this->cmbDepartment->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbDepartment->FormattingEnabled = true;
			this->cmbDepartment->Location = System::Drawing::Point(142, 235);
			this->cmbDepartment->Name = L"cmbDepartment";
			this->cmbDepartment->Size = System::Drawing::Size(324, 24);
			this->cmbDepartment->TabIndex = 9;
			// 
			// cmbPosition
			// 
			this->cmbPosition->FormattingEnabled = true;
			this->cmbPosition->Location = System::Drawing::Point(142, 291);
			this->cmbPosition->Name = L"cmbPosition";
			this->cmbPosition->Size = System::Drawing::Size(324, 24);
			this->cmbPosition->TabIndex = 10;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(142, 387);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(588, 219);
			this->dataGridView1->TabIndex = 11;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &frmAddFaculty::dataGridView1_CellClick);
			// 
			// txtEmail
			// 
			this->txtEmail->Location = System::Drawing::Point(142, 172);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->ReadOnly = true;
			this->txtEmail->Size = System::Drawing::Size(324, 22);
			this->txtEmail->TabIndex = 12;
			// 
			// txtFacultyID
			// 
			this->txtFacultyID->Location = System::Drawing::Point(142, 50);
			this->txtFacultyID->Name = L"txtFacultyID";
			this->txtFacultyID->ReadOnly = true;
			this->txtFacultyID->Size = System::Drawing::Size(228, 22);
			this->txtFacultyID->TabIndex = 13;
			// 
			// txtLastName
			// 
			this->txtLastName->Location = System::Drawing::Point(142, 129);
			this->txtLastName->Name = L"txtLastName";
			this->txtLastName->ReadOnly = true;
			this->txtLastName->Size = System::Drawing::Size(315, 22);
			this->txtLastName->TabIndex = 14;
			// 
			// txtFirstName
			// 
			this->txtFirstName->Location = System::Drawing::Point(142, 92);
			this->txtFirstName->Name = L"txtFirstName";
			this->txtFirstName->ReadOnly = true;
			this->txtFirstName->Size = System::Drawing::Size(311, 22);
			this->txtFirstName->TabIndex = 15;
			// 
			// txtFind
			// 
			this->txtFind->Location = System::Drawing::Point(412, 628);
			this->txtFind->Name = L"txtFind";
			this->txtFind->Size = System::Drawing::Size(207, 22);
			this->txtFind->TabIndex = 16;
			// 
			// btnSave
			// 
			this->btnSave->Enabled = false;
			this->btnSave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnSave->Location = System::Drawing::Point(142, 347);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(95, 34);
			this->btnSave->TabIndex = 17;
			this->btnSave->Text = L"Save";
			this->btnSave->UseVisualStyleBackColor = true;
			// 
			// btnUpdate
			// 
			this->btnUpdate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnUpdate->Location = System::Drawing::Point(274, 347);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(105, 34);
			this->btnUpdate->TabIndex = 18;
			this->btnUpdate->Text = L"Update";
			this->btnUpdate->UseVisualStyleBackColor = true;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &frmAddFaculty::btnUpdate_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnDelete->Location = System::Drawing::Point(412, 347);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(111, 34);
			this->btnDelete->TabIndex = 19;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &frmAddFaculty::btnDelete_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnCancel->Location = System::Drawing::Point(571, 347);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(97, 34);
			this->btnCancel->TabIndex = 20;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &frmAddFaculty::btnCancel_Click);
			// 
			// btnFind
			// 
			this->btnFind->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnFind->Location = System::Drawing::Point(625, 626);
			this->btnFind->Name = L"btnFind";
			this->btnFind->Size = System::Drawing::Size(75, 28);
			this->btnFind->TabIndex = 21;
			this->btnFind->Text = L"Find";
			this->btnFind->UseVisualStyleBackColor = true;
			this->btnFind->Click += gcnew System::EventHandler(this, &frmAddFaculty::btnFind_Click);
			// 
			// frmAddFaculty
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(794, 729);
			this->Controls->Add(this->btnFind);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnUpdate);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->txtFind);
			this->Controls->Add(this->txtFirstName);
			this->Controls->Add(this->txtLastName);
			this->Controls->Add(this->txtFacultyID);
			this->Controls->Add(this->txtEmail);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->cmbPosition);
			this->Controls->Add(this->cmbDepartment);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"frmAddFaculty";
			this->Text = L"Faculty Management";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private: System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
		if (globalFacultyID == 0) {
			MessageBox::Show("No faculty selected for update", "Update Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		if (cmbDepartment->SelectedIndex == -1 || cmbPosition->Text->Trim() == "") {
			MessageBox::Show("Please select department and position", "Validation Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->Parameters->Clear();

			int deptID = Convert::ToInt32(cmbDepartment->SelectedValue);
			String^ position = cmbPosition->Text;

			sqlCmd->CommandText = "UPDATE faculty SET DepartmentID=@deptID, Position=@position WHERE ID=@id";
			sqlCmd->Parameters->AddWithValue("@deptID", deptID);
			sqlCmd->Parameters->AddWithValue("@position", position);
			sqlCmd->Parameters->AddWithValue("@id", globalFacultyID);
			sqlCmd->ExecuteNonQuery();

			MessageBox::Show("Faculty updated successfully", "Success",
				MessageBoxButtons::OK, MessageBoxIcon::Information);

			LoadFacultyData();
			ClearFields();
			sqlConn->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Database Error: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
		}
	}

	private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		if (globalFacultyID == 0) {
			MessageBox::Show("No faculty selected for deletion", "Delete Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		System::Windows::Forms::DialogResult result = MessageBox::Show(
			"Are you sure you want to delete this faculty record?",
			"Confirm Delete",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question);

		if (result == System::Windows::Forms::DialogResult::Yes) {
			try {
				sqlConn->ConnectionString = ConnectionStr;
				sqlConn->Open();
				sqlCmd->Connection = sqlConn;
				sqlCmd->Parameters->Clear();
				sqlCmd->CommandText = "DELETE FROM faculty WHERE ID = @id";
				sqlCmd->Parameters->AddWithValue("@id", globalFacultyID);
				sqlCmd->ExecuteNonQuery();

				MessageBox::Show("Faculty deleted successfully", "Success",
					MessageBoxButtons::OK, MessageBoxIcon::Information);

				LoadFacultyData();
				ClearFields();
				sqlConn->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Database Error: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				if (sqlConn->State == ConnectionState::Open) {
					sqlConn->Close();
				}
			}
		}
	}

	private: System::Void btnFind_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtFind->Text->Trim() == "") {
			MessageBox::Show("Please enter a Faculty ID", "Find Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			int facID = Convert::ToInt32(txtFind->Text->Trim());
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->Parameters->Clear();
			sqlCmd->CommandText = "SELECT f.*, u.FirstName, u.LastName, u.Email, d.Department " +
				"FROM faculty f " +
				"INNER JOIN users u ON f.UserID = u.ID " +
				"INNER JOIN department d ON f.DepartmentID = d.ID " +
				"WHERE f.ID = @id";
			sqlCmd->Parameters->AddWithValue("@id", facID);
			sqlDR = sqlCmd->ExecuteReader();

			if (sqlDR->Read()) {
				txtFacultyID->Text = sqlDR["FacultyID"]->ToString();
				txtFirstName->Text = sqlDR["FirstName"]->ToString();
				txtLastName->Text = sqlDR["LastName"]->ToString();
				txtEmail->Text = sqlDR["Email"]->ToString();
				cmbDepartment->SelectedValue = Convert::ToInt32(sqlDR["DepartmentID"]);
				cmbPosition->Text = sqlDR["Position"]->ToString();
				globalFacultyID = Convert::ToInt32(sqlDR["ID"]);
				sqlDR->Close();
			}
			else {
				MessageBox::Show("Faculty not found", "Find Error",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
				sqlDR->Close();
			}
			sqlConn->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
		}
	}

	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0) {
			DataGridViewRow^ row = dataGridView1->Rows[e->RowIndex];
			globalFacultyID = Convert::ToInt32(row->Cells["ID"]->Value);
			txtFacultyID->Text = row->Cells["FacultyID"]->Value->ToString();
			txtFirstName->Text = row->Cells["FirstName"]->Value->ToString();
			txtLastName->Text = row->Cells["LastName"]->Value->ToString();
			txtEmail->Text = row->Cells["Email"]->Value->ToString();
			cmbDepartment->SelectedValue = Convert::ToInt32(row->Cells["DepartmentID"]->Value);
			cmbPosition->Text = row->Cells["Position"]->Value->ToString();
		}
	}

		   void LoadDepartments() {
			   try {
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

		   void LoadPositions() {
			   cmbPosition->Items->Clear();
			   cmbPosition->Items->Add("Professor");
			   cmbPosition->Items->Add("Associate Professor");
			   cmbPosition->Items->Add("Assistant Professor");
			   cmbPosition->Items->Add("Lecturer");
			   cmbPosition->Items->Add("Senior Lecturer");
			   cmbPosition->Items->Add("Instructor");
		   }

		   void LoadFacultyData() {
			   try {
				   if (sqlConn->State == ConnectionState::Open) {
					   sqlConn->Close();
				   }
				   sqlConn->ConnectionString = ConnectionStr;
				   sqlConn->Open();
				   DataTable^ dt = gcnew DataTable();
				   MySqlDataAdapter^ da = gcnew MySqlDataAdapter(
					   "SELECT f.ID, f.FacultyID, u.FirstName, u.LastName, u.Email, " +
					   "d.Department, f.Position, f.status, f.hire_date, f.DepartmentID " +
					   "FROM faculty f " +
					   "INNER JOIN users u ON f.UserID = u.ID " +
					   "INNER JOIN department d ON f.DepartmentID = d.ID " +
					   "ORDER BY f.ID DESC", sqlConn);
				   da->Fill(dt);
				   dataGridView1->DataSource = dt;
				   sqlConn->Close();
			   }
			   catch (Exception^ ex) {
				   MessageBox::Show("Error loading data: " + ex->Message, "Error",
					   MessageBoxButtons::OK, MessageBoxIcon::Error);
			   }
		   }

		   void ClearFields() {
			   txtFacultyID->Text = "";
			   txtFirstName->Text = "";
			   txtLastName->Text = "";
			   txtEmail->Text = "";
			   txtFind->Text = "";
			   cmbDepartment->SelectedIndex = -1;
			   cmbPosition->SelectedIndex = -1;
			   globalFacultyID = 0;
		   }
	};
}