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
	/// Summary for frmAddUsers
	/// </summary>
	public ref class frmAddUsers : public System::Windows::Forms::Form
	{
	public:
		frmAddUsers(void)
		{
			InitializeComponent();
			LoadRoles();
			LoadUserData();
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
		int globalUserID = 0;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmAddUsers()
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
	private: System::Windows::Forms::TextBox^ txtFirstName;
	private: System::Windows::Forms::TextBox^ txtLastName;
	private: System::Windows::Forms::TextBox^ txtEmail;
	private: System::Windows::Forms::TextBox^ txtPassword;





	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ btnUpdate;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::Button^ btnCancel;



	private: System::Windows::Forms::Button^ btnSave;

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::TextBox^ txtFind;
	private: System::Windows::Forms::Button^ btnFind;



	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;

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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtFirstName = (gcnew System::Windows::Forms::TextBox());
			this->txtLastName = (gcnew System::Windows::Forms::TextBox());
			this->txtEmail = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->txtFind = (gcnew System::Windows::Forms::TextBox());
			this->btnFind = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label1->Location = System::Drawing::Point(14, 81);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(112, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"First Name:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(14, 133);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(112, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Last Name:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label3->Location = System::Drawing::Point(14, 184);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 25);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Email:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label4->Location = System::Drawing::Point(14, 242);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(104, 25);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Password:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label5->Location = System::Drawing::Point(14, 306);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(57, 25);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Role:";
			// 
			// txtFirstName
			// 
			this->txtFirstName->Location = System::Drawing::Point(169, 81);
			this->txtFirstName->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->txtFirstName->Name = L"txtFirstName";
			this->txtFirstName->Size = System::Drawing::Size(429, 24);
			this->txtFirstName->TabIndex = 5;
			// 
			// txtLastName
			// 
			this->txtLastName->Location = System::Drawing::Point(169, 133);
			this->txtLastName->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->txtLastName->Name = L"txtLastName";
			this->txtLastName->Size = System::Drawing::Size(429, 24);
			this->txtLastName->TabIndex = 6;
			// 
			// txtEmail
			// 
			this->txtEmail->Location = System::Drawing::Point(169, 189);
			this->txtEmail->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(573, 24);
			this->txtEmail->TabIndex = 7;
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(169, 246);
			this->txtPassword->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->PasswordChar = '*';
			this->txtPassword->Size = System::Drawing::Size(429, 24);
			this->txtPassword->TabIndex = 8;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(169, 306);
			this->comboBox1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(137, 26);
			this->comboBox1->TabIndex = 9;
			// 
			// btnUpdate
			// 
			this->btnUpdate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnUpdate->Location = System::Drawing::Point(320, 352);
			this->btnUpdate->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(124, 42);
			this->btnUpdate->TabIndex = 10;
			this->btnUpdate->Text = L"Update";
			this->btnUpdate->UseVisualStyleBackColor = true;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &frmAddUsers::btnUpdate_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnDelete->Location = System::Drawing::Point(502, 352);
			this->btnDelete->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(110, 42);
			this->btnDelete->TabIndex = 11;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &frmAddUsers::btnDelete_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnCancel->Location = System::Drawing::Point(695, 352);
			this->btnCancel->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(112, 42);
			this->btnCancel->TabIndex = 12;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &frmAddUsers::btnCancel_Click);
			// 
			// btnSave
			// 
			this->btnSave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnSave->Location = System::Drawing::Point(169, 352);
			this->btnSave->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(104, 42);
			this->btnSave->TabIndex = 13;
			this->btnSave->Text = L"Save";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &frmAddUsers::btnSave_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->Location = System::Drawing::Point(169, 400);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 50;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(673, 226);
			this->dataGridView1->TabIndex = 14;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &frmAddUsers::dataGridView1_CellClick);
			// 
			// txtFind
			// 
			this->txtFind->Location = System::Drawing::Point(454, 640);
			this->txtFind->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->txtFind->Name = L"txtFind";
			this->txtFind->Size = System::Drawing::Size(236, 24);
			this->txtFind->TabIndex = 15;
			// 
			// btnFind
			// 
			this->btnFind->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnFind->Location = System::Drawing::Point(724, 632);
			this->btnFind->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->btnFind->Name = L"btnFind";
			this->btnFind->Size = System::Drawing::Size(83, 34);
			this->btnFind->TabIndex = 16;
			this->btnFind->Text = L"Find";
			this->btnFind->UseVisualStyleBackColor = true;
			this->btnFind->Click += gcnew System::EventHandler(this, &frmAddUsers::btnFind_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label6->Location = System::Drawing::Point(261, 637);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(154, 25);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Find User By ID:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label7->Location = System::Drawing::Point(412, 10);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(76, 29);
			this->label7->TabIndex = 18;
			this->label7->Text = L"Users";
			// 
			// frmAddUsers
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->ClientSize = System::Drawing::Size(940, 742);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->btnFind);
			this->Controls->Add(this->txtFind);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnUpdate);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->txtEmail);
			this->Controls->Add(this->txtLastName);
			this->Controls->Add(this->txtFirstName);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->Name = L"frmAddUsers";
			this->Text = L"frmAddUsers";
			this->Load += gcnew System::EventHandler(this, &frmAddUsers::frmAddUsers_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmAddUsers_Load(System::Object^ sender, System::EventArgs^ e) {
	}


	private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ firstName = txtFirstName->Text->Trim();
		String^ lastName = txtLastName->Text->Trim();
		String^ email = txtEmail->Text->Trim();
		String^ password = txtPassword->Text->Trim();

		if (firstName == "" || lastName == "" || email == "" || password == "") {
			MessageBox::Show("Please fill all fields", "Data Entry Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		if (comboBox1->SelectedIndex == -1) {
			MessageBox::Show("Please select a role", "Data Entry Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;

			// Check if email already exists
			sqlCmd->CommandText = "SELECT * FROM users WHERE Email = @email";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@email", email);
			sqlDR = sqlCmd->ExecuteReader();

			if (sqlDR->Read()) {
				MessageBox::Show("Email already exists", "Data Entry Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				sqlDR->Close();
			}
			else {
				sqlDR->Close();

				// Get role ID from combobox
				int roleID = Convert::ToInt32(comboBox1->SelectedValue);

				sqlCmd->CommandText = "INSERT INTO users(FirstName, LastName, Email, Password, role) VALUES (@fname, @lname, @email, @password, @role)";
				sqlCmd->Parameters->Clear();
				sqlCmd->Parameters->AddWithValue("@fname", firstName);
				sqlCmd->Parameters->AddWithValue("@lname", lastName);
				sqlCmd->Parameters->AddWithValue("@email", email);
				sqlCmd->Parameters->AddWithValue("@password", password);
				sqlCmd->Parameters->AddWithValue("@role", roleID);
				sqlCmd->ExecuteNonQuery();

				MessageBox::Show("User saved successfully", "Success",
					MessageBoxButtons::OK, MessageBoxIcon::Information);

				LoadUserData();
				ClearFields();
			}
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

	private: System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
		if (globalUserID == 0) {
			MessageBox::Show("No user selected for update", "Update Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		String^ firstName = txtFirstName->Text->Trim();
		String^ lastName = txtLastName->Text->Trim();
		String^ email = txtEmail->Text->Trim();
		String^ password = txtPassword->Text->Trim();

		if (firstName == "" || lastName == "" || email == "") {
			MessageBox::Show("Please fill all required fields", "Data Entry Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->Parameters->Clear();

			int roleID = Convert::ToInt32(comboBox1->SelectedValue);

			if (password != "") {
				sqlCmd->CommandText = "UPDATE users SET FirstName=@fname, LastName=@lname, Email=@email, Password=@password, role=@role WHERE ID=@id";
				sqlCmd->Parameters->AddWithValue("@password", password);
			}
			else {
				sqlCmd->CommandText = "UPDATE users SET FirstName=@fname, LastName=@lname, Email=@email, role=@role WHERE ID=@id";
			}

			sqlCmd->Parameters->AddWithValue("@fname", firstName);
			sqlCmd->Parameters->AddWithValue("@lname", lastName);
			sqlCmd->Parameters->AddWithValue("@email", email);
			sqlCmd->Parameters->AddWithValue("@role", roleID);
			sqlCmd->Parameters->AddWithValue("@id", globalUserID);
			sqlCmd->ExecuteNonQuery();

			MessageBox::Show("User updated successfully", "Success",
				MessageBoxButtons::OK, MessageBoxIcon::Information);

			LoadUserData();
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
		if (globalUserID == 0) {
			MessageBox::Show("No user selected for deletion", "Delete Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		System::Windows::Forms::DialogResult result = MessageBox::Show(
			"Are you sure you want to delete this user?",
			"Confirm Delete",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question);

		if (result == System::Windows::Forms::DialogResult::Yes) {
			try {
				sqlConn->ConnectionString = ConnectionStr;
				sqlConn->Open();
				sqlCmd->Connection = sqlConn;
				sqlCmd->Parameters->Clear();
				sqlCmd->CommandText = "DELETE FROM users WHERE ID = @id";
				sqlCmd->Parameters->AddWithValue("@id", globalUserID);
				sqlCmd->ExecuteNonQuery();

				MessageBox::Show("User deleted successfully", "Success",
					MessageBoxButtons::OK, MessageBoxIcon::Information);

				LoadUserData();
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
			MessageBox::Show("Please enter a User ID", "Find Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			int userID = Convert::ToInt32(txtFind->Text->Trim());
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->Parameters->Clear();
			sqlCmd->CommandText = "SELECT * FROM users WHERE ID = @id";
			sqlCmd->Parameters->AddWithValue("@id", userID);
			sqlDR = sqlCmd->ExecuteReader();

			if (sqlDR->Read()) {
				txtFirstName->Text = sqlDR["FirstName"]->ToString();
				txtLastName->Text = sqlDR["LastName"]->ToString();
				txtEmail->Text = sqlDR["Email"]->ToString();
				txtPassword->Text = "";
				comboBox1->SelectedValue = Convert::ToInt32(sqlDR["role"]);
				globalUserID = Convert::ToInt32(sqlDR["ID"]);
				sqlDR->Close();
			}
			else {
				MessageBox::Show("User not found", "Find Error",
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

	private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0) {
			DataGridViewRow^ row = dataGridView1->Rows[e->RowIndex];
			globalUserID = Convert::ToInt32(row->Cells["ID"]->Value);
			txtFirstName->Text = row->Cells["FirstName"]->Value->ToString();
			txtLastName->Text = row->Cells["LastName"]->Value->ToString();
			txtEmail->Text = row->Cells["Email"]->Value->ToString();
			txtPassword->Text = "";
			comboBox1->SelectedValue = Convert::ToInt32(row->Cells["role"]->Value);
		}
	}

		   void LoadRoles() {
			   try {
				   sqlConn->ConnectionString = ConnectionStr;
				   sqlConn->Open();
				   MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT ID, RoleName FROM roles", sqlConn);
				   DataTable^ dt = gcnew DataTable();
				   da->Fill(dt);
				   comboBox1->DataSource = dt;
				   comboBox1->DisplayMember = "RoleName";
				   comboBox1->ValueMember = "ID";
				   sqlConn->Close();
			   }
			   catch (Exception^ ex) {
				   MessageBox::Show("Error loading roles: " + ex->Message, "Error",
					   MessageBoxButtons::OK, MessageBoxIcon::Error);
			   }
		   }

		   void LoadUserData() {
			   try {
				   if (sqlConn->State == ConnectionState::Open) {
					   sqlConn->Close();
				   }
				   sqlConn->ConnectionString = ConnectionStr;
				   sqlConn->Open();
				   DataTable^ dt = gcnew DataTable();
				   MySqlDataAdapter^ da = gcnew MySqlDataAdapter(
					   "SELECT u.ID, u.FirstName, u.LastName, u.Email, r.RoleName, u.role " +
					   "FROM users u INNER JOIN roles r ON u.role = r.ID ORDER BY u.ID DESC", sqlConn);
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
			   txtFirstName->Text = "";
			   txtLastName->Text = "";
			   txtEmail->Text = "";
			   txtPassword->Text = "";
			   txtFind->Text = "";
			   comboBox1->SelectedIndex = -1;
			   globalUserID = 0;
		   }

	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
