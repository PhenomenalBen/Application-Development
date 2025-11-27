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
	/// Summary for frmprogrammes
	/// </summary>
	public ref class frmprogrammes : public System::Windows::Forms::Form
	{
	public:
		frmprogrammes(void)
		{
			InitializeComponent();
			LoadDepartments();
			LoadProgrammes();


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
		String^ ConnectionString = "server=localhost;port=3307;uid=root;pwd=;database=ahsesimis;";
		int currentProgrammeID;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmprogrammes()
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
	private: System::Windows::Forms::ComboBox^ cmbDepartment;

	private: System::Windows::Forms::ComboBox^ cmbProgrammeType;
	private: System::Windows::Forms::TextBox^ txtProgramme;


	private: System::Windows::Forms::Button^ btnSave;
	private: System::Windows::Forms::Button^ btnUpdate;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::Button^ btnCancel;




	private: System::Windows::Forms::Button^ btnFind;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ txtFind;

	private: System::Windows::Forms::DataGridView^ dgvProgrammes;



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
			this->cmbDepartment = (gcnew System::Windows::Forms::ComboBox());
			this->cmbProgrammeType = (gcnew System::Windows::Forms::ComboBox());
			this->txtProgramme = (gcnew System::Windows::Forms::TextBox());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnFind = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtFind = (gcnew System::Windows::Forms::TextBox());
			this->dgvProgrammes = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvProgrammes))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(198, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(264, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Academic Programmes";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(12, 70);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Department:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label3->Location = System::Drawing::Point(12, 120);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(119, 25);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Programme:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label4->Location = System::Drawing::Point(12, 182);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(169, 25);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Programme Type:";
			// 
			// cmbDepartment
			// 
			this->cmbDepartment->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbDepartment->FormattingEnabled = true;
			this->cmbDepartment->Location = System::Drawing::Point(203, 70);
			this->cmbDepartment->Name = L"cmbDepartment";
			this->cmbDepartment->Size = System::Drawing::Size(345, 24);
			this->cmbDepartment->TabIndex = 4;
			// 
			// cmbProgrammeType
			// 
			this->cmbProgrammeType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbProgrammeType->FormattingEnabled = true;
			this->cmbProgrammeType->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"Bsc", L"BA", L"Msc", L"MA", L"Phd" });
			this->cmbProgrammeType->Location = System::Drawing::Point(203, 182);
			this->cmbProgrammeType->Name = L"cmbProgrammeType";
			this->cmbProgrammeType->Size = System::Drawing::Size(121, 24);
			this->cmbProgrammeType->TabIndex = 5;
			// 
			// txtProgramme
			// 
			this->txtProgramme->Location = System::Drawing::Point(203, 124);
			this->txtProgramme->Name = L"txtProgramme";
			this->txtProgramme->Size = System::Drawing::Size(345, 22);
			this->txtProgramme->TabIndex = 6;
			// 
			// btnSave
			// 
			this->btnSave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnSave->Location = System::Drawing::Point(203, 262);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(75, 33);
			this->btnSave->TabIndex = 7;
			this->btnSave->Text = L"Save";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &frmprogrammes::btnSave_Click);
			// 
			// btnUpdate
			// 
			this->btnUpdate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnUpdate->Location = System::Drawing::Point(309, 261);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(92, 34);
			this->btnUpdate->TabIndex = 8;
			this->btnUpdate->Text = L"Update";
			this->btnUpdate->UseVisualStyleBackColor = true;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &frmprogrammes::btnUpdate_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnDelete->Location = System::Drawing::Point(433, 262);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(92, 33);
			this->btnDelete->TabIndex = 9;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &frmprogrammes::btnDelete_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnCancel->Location = System::Drawing::Point(558, 262);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(92, 33);
			this->btnCancel->TabIndex = 10;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &frmprogrammes::btnCancel_Click);
			// 
			// btnFind
			// 
			this->btnFind->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnFind->Location = System::Drawing::Point(588, 473);
			this->btnFind->Name = L"btnFind";
			this->btnFind->Size = System::Drawing::Size(75, 30);
			this->btnFind->TabIndex = 11;
			this->btnFind->Text = L"Find";
			this->btnFind->UseVisualStyleBackColor = true;
			this->btnFind->Click += gcnew System::EventHandler(this, &frmprogrammes::btnFind_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label5->Location = System::Drawing::Point(227, 478);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(156, 25);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Find Programme";
			// 
			// txtFind
			// 
			this->txtFind->Location = System::Drawing::Point(403, 478);
			this->txtFind->Name = L"txtFind";
			this->txtFind->Size = System::Drawing::Size(166, 22);
			this->txtFind->TabIndex = 13;
			// 
			// dgvProgrammes
			// 
			this->dgvProgrammes->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvProgrammes->Location = System::Drawing::Point(203, 301);
			this->dgvProgrammes->Name = L"dgvProgrammes";
			this->dgvProgrammes->RowHeadersWidth = 51;
			this->dgvProgrammes->RowTemplate->Height = 24;
			this->dgvProgrammes->Size = System::Drawing::Size(447, 150);
			this->dgvProgrammes->TabIndex = 14;
			this->dgvProgrammes->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &frmprogrammes::dgvProgrammes_CellClick);
			// 
			// frmprogrammes
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(705, 544);
			this->Controls->Add(this->dgvProgrammes);
			this->Controls->Add(this->txtFind);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->btnFind);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnUpdate);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->txtProgramme);
			this->Controls->Add(this->cmbProgrammeType);
			this->Controls->Add(this->cmbDepartment);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"frmprogrammes";
			this->Text = L"frmprogrammes";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvProgrammes))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		private:
			// Simple class to hold department data
			ref class DepartmentInfo
			{
			public:
				int ID;
				String^ Name;

				DepartmentInfo(int id, String^ name)
				{
					ID = id;
					Name = name;
				}

				virtual String^ ToString() override
				{
					return Name;
				}
			};

			// Load departments into combobox
			void LoadDepartments()
			{
				try
				{
					if (sqlConn->State == ConnectionState::Open) {
						sqlConn->Close();
					}
					sqlConn->ConnectionString = ConnectionString;
					sqlConn->Open();
					sqlCmd->Connection = sqlConn;
					sqlCmd->CommandText = "SELECT ID, Department FROM Department ORDER BY Department";

					MySqlDataReader^ reader = sqlCmd->ExecuteReader();
					cmbDepartment->Items->Clear();

					while (reader->Read())
					{
						int deptID = safe_cast<int>(reader["ID"]);
						String^ deptName = safe_cast<String^>(reader["Department"]);
						cmbDepartment->Items->Add(gcnew DepartmentInfo(deptID, deptName));
					}

					reader->Close();
					sqlConn->Close();
				}
				catch (Exception^ ex)
				{
					MessageBox::Show("Error loading departments: " + ex->Message, "Error",
						MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}

			// Load programmes into DataGridView
			void LoadProgrammes()
			{
				try
				{
					if (sqlConn->State == ConnectionState::Open) {
						sqlConn->Close();
					}
					sqlConn->ConnectionString = ConnectionString;
					sqlConn->Open();

					DataTable^ dt = gcnew DataTable();
					MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT p.ID, d.Department, p.Programme, p.ProgrammeType FROM programmes p INNER JOIN Department d ON p.Department = d.ID ORDER BY p.ID DESC", sqlConn);
					da->Fill(dt);
					dgvProgrammes->DataSource = dt;

					sqlConn->Close();
				}
				catch (Exception^ ex)
				{
					MessageBox::Show("Error loading programmes: " + ex->Message, "Error",
						MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}

			// Clear form fields
			void ClearFields()
			{
				cmbDepartment->SelectedIndex = -1;
				txtProgramme->Clear();
				cmbProgrammeType->SelectedIndex = -1;
				txtFind->Clear();
				currentProgrammeID = 0;
			}
#pragma endregion
private:
	System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
		if (cmbDepartment->SelectedIndex == -1 || txtProgramme->Text->Trim() == "" ||
			cmbProgrammeType->SelectedIndex == -1) {
			MessageBox::Show("Please fill all fields", "Validation Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
			sqlConn->ConnectionString = ConnectionString;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->Parameters->Clear();

			DepartmentInfo^ selectedDept = safe_cast<DepartmentInfo^>(cmbDepartment->SelectedItem);

			sqlCmd->CommandText = "INSERT INTO programmes (Department, Programme, ProgrammeType) VALUES (@department, @programme, @programmetype)";
			sqlCmd->Parameters->AddWithValue("@department", selectedDept->ID);
			sqlCmd->Parameters->AddWithValue("@programme", txtProgramme->Text);
			sqlCmd->Parameters->AddWithValue("@programmetype", cmbProgrammeType->SelectedItem->ToString());

			sqlCmd->ExecuteNonQuery();
			MessageBox::Show("Programme saved successfully", "Success",
				MessageBoxButtons::OK, MessageBoxIcon::Information);

			LoadProgrammes();
			ClearFields();
			sqlConn->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error saving programme: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
		if (currentProgrammeID == 0) {
			MessageBox::Show("No programme selected for update", "Validation Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		if (cmbDepartment->SelectedIndex == -1 || txtProgramme->Text->Trim() == "" ||
			cmbProgrammeType->SelectedIndex == -1) {
			MessageBox::Show("Please fill all fields", "Validation Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
			sqlConn->ConnectionString = ConnectionString;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->Parameters->Clear();

			DepartmentInfo^ selectedDept = safe_cast<DepartmentInfo^>(cmbDepartment->SelectedItem);

			sqlCmd->CommandText = "UPDATE programmes SET Department=@department, Programme=@programme, ProgrammeType=@programmetype WHERE ID=@id";
			sqlCmd->Parameters->AddWithValue("@department", selectedDept->ID);
			sqlCmd->Parameters->AddWithValue("@programme", txtProgramme->Text);
			sqlCmd->Parameters->AddWithValue("@programmetype", cmbProgrammeType->SelectedItem->ToString());
			sqlCmd->Parameters->AddWithValue("@id", currentProgrammeID);

			sqlCmd->ExecuteNonQuery();
			MessageBox::Show("Programme updated successfully", "Success",
				MessageBoxButtons::OK, MessageBoxIcon::Information);

			LoadProgrammes();
			ClearFields();
			sqlConn->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error updating programme: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		if (currentProgrammeID == 0) {
			MessageBox::Show("No programme selected for deletion", "Validation Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		if (MessageBox::Show("Are you sure you want to delete this programme?", "Confirm Delete",
			MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		{
			try {
				if (sqlConn->State == ConnectionState::Open) {
					sqlConn->Close();
				}
				sqlConn->ConnectionString = ConnectionString;
				sqlConn->Open();
				sqlCmd->Connection = sqlConn;
				sqlCmd->Parameters->Clear();

				sqlCmd->CommandText = "DELETE FROM programmes WHERE ID=@id";
				sqlCmd->Parameters->AddWithValue("@id", currentProgrammeID);

				sqlCmd->ExecuteNonQuery();
				MessageBox::Show("Programme deleted successfully", "Success",
					MessageBoxButtons::OK, MessageBoxIcon::Information);

				LoadProgrammes();
				ClearFields();
				sqlConn->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error deleting programme: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

	System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

    System::Void btnFind_Click(System::Object^ sender, System::EventArgs^ e) {

		int programmeID = Convert::ToInt32(txtFind->Text->Trim());
		if (programmeID <= 0) {
			MessageBox::Show("Please enter a valid Programme ID.", "Data Entry Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			sqlConn->ConnectionString = ConnectionString;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "SELECT * FROM programmes WHERE ID = @progID";
			sqlCmd->Parameters->AddWithValue("@progID", programmeID);
			sqlDR = sqlCmd->ExecuteReader();

			if (sqlDR->Read()) {
				txtProgramme->Text = sqlDR["Programme"]->ToString();

				currentProgrammeID = Convert::ToInt32(sqlDR["ID"]);
				sqlDT->Load(sqlDR);

				sqlDR->Close();
				dgvProgrammes->DataSource = nullptr;
				dgvProgrammes->DataSource = sqlDT;

				// Adjust columns (if needed)
				dgvProgrammes->Columns[0]->Width = 50;
				dgvProgrammes->Columns[1]->Width = 300;

				sqlCmd->Cancel();
				sqlConn->Close();
			}
			else {
				MessageBox::Show("The Programme ID does not exist.", "Data Entry Error",
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



	System::Void dgvProgrammes_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0) {
			DataGridViewRow^ row = dgvProgrammes->Rows[e->RowIndex];
			currentProgrammeID = Convert::ToInt32(row->Cells["ID"]->Value);

			// Set department
			String^ departmentName = row->Cells["Department"]->Value->ToString();
			for (int i = 0; i < cmbDepartment->Items->Count; i++) {
				DepartmentInfo^ dept = safe_cast<DepartmentInfo^>(cmbDepartment->Items[i]);
				if (dept->Name == departmentName) {
					cmbDepartment->SelectedIndex = i;
					break;
				}
			}

			txtProgramme->Text = row->Cells["Programme"]->Value->ToString();
			cmbProgrammeType->SelectedItem = row->Cells["ProgrammeType"]->Value->ToString();
		}
	}
#pragma endregion
};
}
