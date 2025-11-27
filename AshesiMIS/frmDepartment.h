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
	/// Summary for frmDepartment
	/// </summary>
	public ref class frmDepartment : public System::Windows::Forms::Form
	{

	public:
		frmDepartment(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "SELECT * FROM department ORDER By id DESC";
			sqlDR = sqlCmd->ExecuteReader();
			sqlDT->Load(sqlDR);
			sqlDR->Close();
			dataGridView1->DataSource = sqlDT;
			dataGridView1->Columns[0]->Width = 50;
			dataGridView1->Columns[1]->Width = 500;
			sqlCmd->Cancel();
			sqlConn->Close();
		}
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		MySqlDataAdapter^ sqlDA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlDR;
		DataTable^ sqlDT = gcnew DataTable();
		String^ ConnectionStr = "server=localhost;port=3307;uid=root;pwd=;database=ahsesimis;";
		int globalDeptID = 0;
		User^ user = gcnew User();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmDepartment()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtDepartment;
	private: System::Windows::Forms::Button^ btnSave;
	private: System::Windows::Forms::Button^ btnUpdate;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtFind;
	private: System::Windows::Forms::Button^ btnFind;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtDepartment = (gcnew System::Windows::Forms::TextBox());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtFind = (gcnew System::Windows::Forms::TextBox());
			this->btnFind = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Red;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label1->Location = System::Drawing::Point(56, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(119, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Department:";
			// 
			// txtDepartment
			// 
			this->txtDepartment->Location = System::Drawing::Point(199, 48);
			this->txtDepartment->Name = L"txtDepartment";
			this->txtDepartment->Size = System::Drawing::Size(396, 22);
			this->txtDepartment->TabIndex = 1;
			// 
			// btnSave
			// 
			this->btnSave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnSave->Location = System::Drawing::Point(199, 91);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(87, 39);
			this->btnSave->TabIndex = 2;
			this->btnSave->Text = L"Save";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &frmDepartment::btnSave_Click);
			// 
			// btnUpdate
			// 
			this->btnUpdate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnUpdate->Location = System::Drawing::Point(292, 91);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(98, 39);
			this->btnUpdate->TabIndex = 3;
			this->btnUpdate->Text = L"Update";
			this->btnUpdate->UseVisualStyleBackColor = true;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &frmDepartment::btnUpdate_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnDelete->Location = System::Drawing::Point(396, 93);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(100, 37);
			this->btnDelete->TabIndex = 4;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &frmDepartment::btnDelete_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnCancel->Location = System::Drawing::Point(502, 93);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(93, 37);
			this->btnCancel->TabIndex = 5;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &frmDepartment::btnCancel_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Location = System::Drawing::Point(202, 174);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(393, 258);
			this->panel1->TabIndex = 6;
			// 
			// dataGridView1
			// 
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->Location = System::Drawing::Point(3, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 50;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(387, 255);
			this->dataGridView1->TabIndex = 7;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(237, 455);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(143, 25);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Department ID:";
			// 
			// txtFind
			// 
			this->txtFind->Location = System::Drawing::Point(386, 458);
			this->txtFind->Name = L"txtFind";
			this->txtFind->Size = System::Drawing::Size(100, 22);
			this->txtFind->TabIndex = 8;
			// 
			// btnFind
			// 
			this->btnFind->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnFind->Location = System::Drawing::Point(502, 455);
			this->btnFind->Name = L"btnFind";
			this->btnFind->Size = System::Drawing::Size(75, 29);
			this->btnFind->TabIndex = 9;
			this->btnFind->Text = L"Find";
			this->btnFind->UseVisualStyleBackColor = true;
			this->btnFind->Click += gcnew System::EventHandler(this, &frmDepartment::btnFind_Click);
			// 
			// frmDepartment
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Red;
			this->ClientSize = System::Drawing::Size(720, 541);
			this->Controls->Add(this->btnFind);
			this->Controls->Add(this->txtFind);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnUpdate);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->txtDepartment);
			this->Controls->Add(this->label1);
			this->Name = L"frmDepartment";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Department";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ department = txtDepartment->Text->Trim();
		if (department == "") {
			MessageBox::Show("Please Enter Department", "Data Entry Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;

			// Check if department already exists
			sqlCmd->CommandText = "SELECT * FROM department WHERE department = @dept";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@dept", department);
			sqlDR = sqlCmd->ExecuteReader();

			if (sqlDR->Read()) {
				MessageBox::Show("Department already exists", "Data Entry Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				sqlDR->Close();
				sqlCmd->Cancel();
			}
			else {
				sqlDR->Close();
				sqlCmd->Cancel();
				sqlCmd->CommandText = "INSERT INTO department(Department) VALUES (@department)";
				sqlCmd->Parameters->AddWithValue("@department", department);
				sqlCmd->ExecuteNonQuery();

				//Load the data in the department table to the DataGridView Control
				sqlCmd->CommandText = "SELECT * FROM department ORDER By id DESC";
				sqlDR = sqlCmd->ExecuteReader();
				sqlDT->Load(sqlDR);
				sqlDR->Close();
				dataGridView1->DataSource = sqlDT;
				dataGridView1->Columns[0]->Width = 50;
				dataGridView1->Columns[1]->Width = 500;
				sqlCmd->Cancel();
			}
				txtDepartment->Text = "";
				sqlConn->Close();
			}
		catch (Exception^ ex) {
			MessageBox::Show("Database Connection Error: " + ex->Message, "Data Entry Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);

			
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
			if (sqlDR != nullptr && !sqlDR->IsClosed) {
				sqlDR->Close();
			}
		}
	}

	private: System::Void btnFind_Click(System::Object^ sender, System::EventArgs^ e) {
		int departmentID = Convert::ToInt32(txtFind->Text->Trim());
		if (departmentID <= 0) {
			MessageBox::Show("Please valid Department ID: ", "Data Entry Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		try {
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "SELECT * FROM department where id = @deptID";
			sqlCmd->Parameters->AddWithValue("@deptID", departmentID);
			sqlDR = sqlCmd->ExecuteReader();

			if (sqlDR->Read()) {
				txtDepartment->Text = sqlDR["Department"]->ToString();
				globalDeptID = Convert::ToInt32(sqlDR["ID"]);
				sqlDT->Load(sqlDR);
				sqlDR->Close();
				dataGridView1->DataSource = nullptr;
				dataGridView1->DataSource = sqlDT;
				dataGridView1->Columns[0]->Width = 50;
				dataGridView1->Columns[1]->Width = 500;
				sqlDR->Close();
				sqlCmd->Cancel();
				sqlConn->Close();
			}
			else {
				MessageBox::Show("The Department ID does not exist", "Data Entry Error",
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
private: System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
	if (globalDeptID == 0 || txtDepartment->Text->Trim() == "") {
		MessageBox::Show("No Department Selected for update", "Select Department");
		return;
	}
	if (sqlConn->State == ConnectionState::Open) {
		sqlConn->Close();
	}
	String^ department = txtDepartment->Text;
	try {
		sqlConn->ConnectionString = ConnectionStr;
		sqlConn->Open();
		sqlCmd->Connection = sqlConn;
		sqlCmd->Parameters->Clear();
		sqlCmd->CommandText = "UPDATE department SET Department = @department where id = @deptID";
		sqlCmd->Parameters->AddWithValue("@department", department);
		sqlCmd->Parameters->AddWithValue("@deptID", globalDeptID);
		sqlCmd->ExecuteNonQuery();
		MessageBox::Show("Update is successful");

		//Load the data in the department table to the DataGridView Control
		sqlCmd->CommandText = "SELECT * FROM department ORDER By id DESC";
		sqlDR = sqlCmd->ExecuteReader();
		sqlDT->Load(sqlDR);
		sqlDR->Close();
		dataGridView1->DataSource = sqlDT;
		dataGridView1->Columns[0]->Width = 50;
		dataGridView1->Columns[1]->Width = 500;
		sqlCmd->Cancel();
		txtDepartment->Text = "";
		sqlConn->Close();
	}
	catch (Exception^ e) {
		MessageBox::Show("Database Connection Error: " + e->ToString(), "Data Entry Error",
			MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}
private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
	if (globalDeptID == 0 || txtDepartment->Text->Trim() == "") {
		MessageBox::Show("No Department Selected for update", "Select or Find Department");
		return;
	}
	if (sqlConn->State == ConnectionState::Open) {
		sqlConn->Close();
	}
	String^ department = txtDepartment->Text;
	try {
		sqlConn->ConnectionString = ConnectionStr;
		sqlConn->Open();
		sqlCmd->Connection = sqlConn;
		sqlCmd->Parameters->Clear();
		sqlCmd->CommandText = "DELETE FROM department where id = @deptID";
		sqlCmd->Parameters->AddWithValue("@deptID", globalDeptID);
		sqlCmd->ExecuteNonQuery();
		MessageBox::Show("The department is deleted successfully");
		//Load the data in the department table to the DataGridView Control
		LoadData();

		sqlCmd->Cancel();
		txtDepartment->Text = "";
		sqlConn->Close();
	}
	catch (Exception^ e) {
		MessageBox::Show("Database Connection Error: " + e->ToString(), "Data Entry Error",
			MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}
	   void LoadData() {
		   if (sqlConn->State == ConnectionState::Open) {
			   sqlConn->Close();
		   }
		   sqlConn->ConnectionString = ConnectionStr;
		   sqlConn->Open();
		   DataTable^ dt = gcnew DataTable();
		   MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT * FROM department", sqlConn);
		   da->Fill(dt);
		   dataGridView1->DataSource = dt;
		   dataGridView1->Columns[0]->Width = 50;
		   dataGridView1->Columns[1]->Width = 500;
	   }

private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
